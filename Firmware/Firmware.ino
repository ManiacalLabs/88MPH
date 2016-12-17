#include <EEPROM.h>
#include "TimerOne.h"
#include "display.h"
#include "buttons.h"

uint8_t _cur_value;
byte _digit_values[DIGIT_COUNT];

#define CONFIG_CHECK 42
#define CONFIG_BYTE 0
bool _pwm_level = true;
#define PWM_BYTE 1
byte _target_speed = 88;
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
#define PWM_HIGH 20
#define PWM_LOW 5
byte _pwm_step = 0;
byte _digit = 0;
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
    byte _v, i = 0;
    static bool dp;
    for(;i<DIGIT_COUNT; i++){
        dp = _digit_values[i] & _BV(7);
        _v = value % 10;
        _digit_values[i] = digits[_v];
        if(dp) _digit_values[i] |= _BV(7);
        value = (value - _v) / 10;
    }
}

inline void check_btn_hold(_button *btn){
    if(digitalRead(btn->pin) == LOW){
        if(!btn->flag){
            if(!btn->last_state){
                btn->last_state = true;
                btn->time_press = millis();
            }
            else{
                if(millis() - btn->time_press >= BTN_HOLD_TIME)
                {
                    btn->flag = true;
                }
            }
        }
    }
    else{
        if(btn->flag && btn->reset){
            btn->flag = btn->reset = false;
        }
        btn->last_state = false;
    }
}

inline void check_buttons(){
    check_btn_hold(&BTN_A);
    check_btn_hold(&BTN_B);
}

#define BTN_PRESS_TIME 5

long _t_btn_a;
void btn_a(){
    // _target_speed++;
    // if(_target_speed > 99) _target_speed = 1;
    static bool state;
    state = digitalRead(BTN_A.pin);
    if(state){
        if((millis() - _t_btn_a) >= BTN_PRESS_TIME){
            _target_speed++;
            if(_target_speed > 99) _target_speed = 1;
        }
    }
    else{
        _t_btn_a = millis();
    }
}

long _t_btn_b;
void btn_b(){
    static bool state;
    state = digitalRead(BTN_B.pin);
    if(state){
        if((millis() - _t_btn_b) >= BTN_PRESS_TIME){
            _target_speed--;
            if(_target_speed < 1) _target_speed = 99;
        }
    }
    else{
        _t_btn_b = millis();
    }
}

void set_btn_inc_isr(bool state){
    if(state){
        attachInterrupt(digitalPinToInterrupt(BTN_A.pin), btn_a, CHANGE);
        attachInterrupt(digitalPinToInterrupt(BTN_B.pin), btn_b, CHANGE);
    }
    else{
        detachInterrupt(digitalPinToInterrupt(BTN_A.pin));
        detachInterrupt(digitalPinToInterrupt(BTN_B.pin));
    }
}

void setup(){
    Serial.begin(115200);

    //make sure 0 before init anything else
    set_value(0);
    set_dp(0, false);
    set_dp(1, false);

    //load config
    read_config();

    //Setup display multiplex timer
    Timer1.initialize(500);
    Timer1.attachInterrupt(plex);

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
}

uint8_t test_val = 0;
bool _in_target_set = false;

void loop(){
    check_buttons();
    if(HOLD_BTN_A){
        if(_in_target_set){
            _in_target_set = false;
            set_btn_inc_isr(false);
            set_dp(0, false);
            set_dp(1, false);
        }
        else{
            _in_target_set = true;
            set_btn_inc_isr(true);
            set_dp(0, true);
            set_dp(1, true);
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
        // Serial.println(_target_speed);
        set_value(_target_speed);
        // delay(250);
    }
    else{
        set_value(test_val++);
        if(test_val > 99) test_val = 0;
        delay(200);
    }
    // set_value(test_val);
    // set_dp(0, test_val % 2 == 0);
    // set_dp(1, test_val % 2 != 0);
    // delay(200);
    // test_val += 1;
    // if(test_val >= 9) {
    //     test_val = 0;
    //     _pwm_level -= 2;
    //     if(_pwm_level == 0 || _pwm_level > PWM_STEPS){
    //         _pwm_level = PWM_STEPS;
    //     }
    // }
}
