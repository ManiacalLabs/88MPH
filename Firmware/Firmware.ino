#include "TimerOne.h"
#include "display.h"
#include "buttons.h"

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
            btn->flag = btn->reset = btn->last_state = false;
        }
    }
}

inline void check_buttons(){
    check_btn_hold(&BTN_A);
    check_btn_hold(&BTN_B);
}

void btn_a(){

}

void btn_b(){

}

void set_btn_inc_isr(bool state){
    if(state){
        attachInterrupt(digitalPinToInterrupt(BTN_A.pin), btn_a, FALLING);
        attachInterrupt(digitalPinToInterrupt(BTN_B.pin), btn_b, FALLING);
    }
    else{
        detachInterrupt(digitalPinToInterrupt(BTN_A.pin));
        detachInterrupt(digitalPinToInterrupt(BTN_B.pin));
    }

}

void setup(){
    //make sure 0 before init anything else
    set_value(0);

    Serial.begin(115200);

    //Setup display multiplex timer
    Timer1.initialize(1000);
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

    set_value(0);
    set_dp(0, true);
    set_dp(1, true);
}

uint8_t test_val = 0;

void loop(){
    check_buttons();
    if(HOLD_BTN_A){
        set_value(++test_val);
        BTN_A.reset = true;
    }
    if(HOLD_BTN_B){
        set_value(--test_val);
        BTN_B.reset = true;
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
