#include "TimerOne.h"
#include "display.h"

#define BTN_A 2
#define BTN_B 3

uint8_t _cur_value;
byte _digit_values[DIGIT_COUNT];

inline void disp_num(byte digit){
    static byte i;
    static byte _cd;

    _cd = _digit_values[digit];
    for(i = 0; i<SEG_COUNT; i++){
        digitalWrite(anodes[i], (_cd & _BV(i)) ? HIGH : LOW);
    }
}

#define PWM_STEPS 10
byte _pwm_level = 10;
byte _pwm_step = 0;
byte _digit = 0;
void plex(){
    static byte i;
    //disable ALL to prevent ghosting
    for(i=0; i<DIGIT_COUNT; i++){
        digitalWrite(cathodes[i], LOW);
    }

    if(_pwm_step < _pwm_level){
        disp_num(_digit);
        digitalWrite(cathodes[_digit], HIGH);
    }

    _pwm_step++;
    if(_pwm_step >= PWM_STEPS) _pwm_step = 0;

    _digit += 1;
    if(_digit >= DIGIT_COUNT) _digit = 0;

}

void set_value(uint8_t value){
    byte _v, i = 0;
    for(;i<DIGIT_COUNT; i++){
        _v = value % 10;
        _digit_values[i] = digits[_v];
        value = (value - _v) / 10;
    }
}

void set_dp(byte digit, bool state){
    if(state) _digit_values[digit] |= _BV(7);
    else _digit_values[digit] &= ~_BV(7);
}

void btn_a(){

}

void btn_b(){

}

void set_btn_inc_isr(bool state){
    if(state){
        attachInterrupt(digitalPinToInterrupt(BTN_A), btn_a, FALLING);
        attachInterrupt(digitalPinToInterrupt(BTN_B), btn_b, FALLING);
    }
    else{
        detachInterrupt(digitalPinToInterrupt(BTN_A));
        detachInterrupt(digitalPinToInterrupt(BTN_B));
    }

}

#define BTN_HOLD_TIME 1000
bool last_btn_a, last_btn_b; //last btn state
long t_btn_a, t_btn_b; //last btn press time
bool f_btn_a, f_btn_b; //btn hold flag
bool r_btn_a, r_btn_b; //btn reset flag
inline void check_btn_hold(){
    if(digitalRead(BTN_A) == LOW){
        if(!f_btn_a){
            if(!last_btn_a){
                last_btn_a = true;
                t_btn_a = millis();
            }
            else{
                if(millis() - t_btn_a >= BTN_HOLD_TIME)
                {
                    f_btn_a = true;
                }
            }
        }
    }
    else{
        if(f_btn_a && r_btn_a){
            f_btn_a = r_btn_a = last_btn_a = false;
        }
    }
}

void setup(){
    Serial.begin(115200);
    set_value(0);
    //Setup display multiplex timer
    Timer1.initialize(1000);
    Timer1.attachInterrupt(plex);

    //Setup btn pins
    pinMode(BTN_A, INPUT_PULLUP);
    pinMode(BTN_B, INPUT_PULLUP);
    last_btn_a = last_btn_b = false;
    t_btn_a = t_btn_b = 0;
    f_btn_a = f_btn_b = false;
    r_btn_a = r_btn_b = false;

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

    set_value(0);
    set_dp(0, true);
    set_dp(1, true);
}

uint8_t test_val = 0;
#define HOLD_BTN_A f_btn_a && !r_btn_a
#define HOLD_BTN_B f_btn_b && !r_btn_b
void loop(){
    check_btn_hold();
    if(HOLD_BTN_A){
        set_value(++test_val);
        r_btn_a = true;
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
