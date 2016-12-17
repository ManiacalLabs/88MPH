#include <EEPROM.h>
#include "TimerOne.h"
#include "display.h"
#include "buttons.h"
#include "MsTimer2.h"

uint8_t _cur_value;
byte _digit_values[DIGIT_COUNT];

#define CONFIG_CHECK 42
#define CONFIG_BYTE 0
bool _pwm_level = true;
#define PWM_BYTE 1
uint8_t _target_speed = 88;
#define TARGET_BYTE 2
#define SPEED_MAX 199

void write_config(){
    EEPROM.write(CONFIG_BYTE, CONFIG_CHECK);
    EEPROM.write(PWM_BYTE, _pwm_level);
    EEPROM.write(TARGET_BYTE, _target_speed);
}

void read_config(){
    if(EEPROM.read(CONFIG_BYTE) != CONFIG_CHECK){
        write_config();
    }

    _pwm_level = EEPROM.read(PWM_BYTE);
    _target_speed = EEPROM.read(TARGET_BYTE);
}

inline void disp_num(byte digit){
    static byte i;
    static byte _cd;

    _cd = _digit_values[digit];
    for(i = 0; i<SEG_COUNT; i++){
        digitalWrite(anodes[i], (_cd & _BV(i)) ? HIGH : LOW);
    }
}

#define PWM_STEPS 20
#define PWM_HIGH PWM_STEPS
#define PWM_LOW 5
volatile byte _pwm_step = 0;
volatile byte _digit = 0;
void plex(){
    static byte i;
    //disable ALL to prevent ghosting
    for(i=0; i<DIGIT_COUNT; i++){
        digitalWrite(cathodes[i], LOW);
    }

    if(_pwm_step < (_pwm_level ? PWM_HIGH : PWM_LOW)){
        disp_num(_digit);
        digitalWrite(cathodes[_digit], HIGH);
    }

    _digit += 1;
    if(_digit >= DIGIT_COUNT){
        _digit = 0;
        _pwm_step++;
        if(_pwm_step >= PWM_STEPS) _pwm_step = 0;
    }

}

void set_dp(byte digit, bool state){
    if(state) _digit_values[digit] |= _BV(7);
    else _digit_values[digit] &= ~_BV(7);
}

void set_value(uint8_t value){
    static byte _v, i = 0;
    _v = i = 0;
    static bool dp, lt10;
    lt10 = value < 10; // less than 10 values need no preceeding 0's
    // if(value > 99) value = 99; //can't show over 99 anyways
    for(;i < DIGIT_COUNT; i++){
        dp = _digit_values[i] & _BV(7);
        _v = value % 10;
        if(lt10 && i > 0) _digit_values[i] = 0b00000000;
        else _digit_values[i] = digits[_v];
        if(dp) _digit_values[i] |= _BV(7);
        value = (value - _v) / 10;
    }
}

inline void check_btn(_button *btn){
    static bool state;
    state = (digitalRead(btn->pin) == LOW);
    if(!state && btn->hold_flag && btn->reset){
        btn->hold_clear = true;
    }
    else if(!(btn->hold_flag || btn->press_flag)){
        if(state){
            btn->count++;
            if(btn->count >= BTN_HOLD_TIME / BTN_SCAN_PERIOD) btn->hold_flag = true;
        }
        else{
            if(btn->count >= BTN_PRESS_TIME / BTN_SCAN_PERIOD) btn->press_flag = true;
        }
    }

    if(btn->hold_flag || btn->press_flag) btn->count = 0;
}

inline void clear_btn(_button *btn){
    if(btn->reset){
        if(btn->press_flag){
            btn->press_flag = btn->reset = false;
        }
        else if(btn->hold_flag && btn->hold_clear){
            btn->hold_flag = btn->reset = btn->hold_clear = false;
        }
    }
}

void check_btns(){
    check_btn(&BTN_A);
    check_btn(&BTN_B);
}

void clear_btns(){
    clear_btn(&BTN_A);
    clear_btn(&BTN_B);
}

uint8_t get_speed(){
    static uint8_t speed;

    if(_target_speed == 0) return 88;
    else{
        speed = (millis() / 100) % 99;
        //map target speed to 88mph for proper scaling
        speed = map(speed, 0, _target_speed, 0, 88);
    }

    return speed;
}

bool wait_obd(){
    return true; //millis() > 4000;
}

#define WAIT_STEPS 8
byte _wait_step = 0;
byte _wait_frames[WAIT_STEPS][2] = {
    //note, 0 is right, 1 is left
    //So these are reverse ordered from the physical layout
    {0b00000011, 0b00000000},
    {0b00000110, 0b00000000},
    {0b00001100, 0b00000000},
    {0b00001000, 0b00001000},
    {0b00000000, 0b00011000},
    {0b00000000, 0b00110000},
    {0b00000000, 0b00100001},
    {0b00000001, 0b00000001}
};

void draw_waiting(){
    _digit_values[0] = _wait_frames[_wait_step][0];
    _digit_values[1] = _wait_frames[_wait_step][1];
    _wait_step++;
    if(_wait_step >= WAIT_STEPS) _wait_step = 0;
}
uint8_t test_val = 76;
bool _in_target_set = false;

#define BLINK_COUNT 3
void blink_target(){
    for(byte i=0; i < BLINK_COUNT; i++){
        _digit_values[0] = _digit_values[1] = 0b00000000;
        delay(250);
        set_value(_target_speed);
        if(i < BLINK_COUNT - 1)
            delay(250);
    }
}
inline void start_target_set(){
    _in_target_set = true;
    set_dp(0, false);
    set_dp(1, false);

    blink_target();
}

inline void stop_target_set(){
    _in_target_set = false;

    write_config();

    blink_target();
    set_dp(0, true);
    set_dp(1, false);
}

void loop(){
    if(HOLD_BTN_A){
        if(_in_target_set){
            stop_target_set();
        }
        else{
            start_target_set();
        }

        BTN_A.reset = true;
    }
    if(!_in_target_set){
        if(HOLD_BTN_B){
            _pwm_level = !_pwm_level;
            write_config();
            BTN_B.reset = true;
        }
    }

    if(_in_target_set){
        if(HOLD_BTN_B){
            _target_speed = 88;
            BTN_B.reset = true;
        }
        else if(PRESS_BTN_A){
            _target_speed++;
            if(_target_speed > 99) _target_speed = 0;
            BTN_A.reset = true;
        }
        else if(PRESS_BTN_B){
            _target_speed--;
            if(_target_speed > 99) _target_speed = 99;
            BTN_B.reset = true;
        }
        set_value(_target_speed);
    }
    else{
        //get speed
        set_value(get_speed());
    }

    clear_btns();
}

void setup(){
    Serial.begin(115200);

    //make sure 0 before init anything else
    set_value(0);
    set_dp(0, false);
    set_dp(1, false);

    //load config
    read_config();

    //Setup btn pins
    pinMode(BTN_A.pin, INPUT_PULLUP);
    pinMode(BTN_B.pin, INPUT_PULLUP);

    //Initialize 7-seg displays
    byte i = 0;
    for(i=0; i<DIGIT_COUNT; i++){
        pinMode(cathodes[i], OUTPUT);
        digitalWrite(cathodes[i], LOW);
    }
    for(i=0; i<SEG_COUNT; i++){
        pinMode(anodes[i], OUTPUT);
        digitalWrite(anodes[i], LOW);
    }

    //Setup timer for plex
    Timer1.initialize(500);
    Timer1.attachInterrupt(plex);

    //Setup timer for buttons
    MsTimer2::set(BTN_SCAN_PERIOD, check_btns);
    MsTimer2::start();

    while(!wait_obd()){
        draw_waiting();
        delay(75);
    }
}
