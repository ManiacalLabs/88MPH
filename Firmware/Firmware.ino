#include "TimerOne.h"
#include "display.h"

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

void setup(){
    set_value(0);
    //Setup display multiplex timer
    Timer1.initialize(2500);
    Timer1.attachInterrupt(plex);

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
void loop(){
    set_value(test_val);
    set_dp(0, test_val % 2 == 0);
    set_dp(1, test_val % 2 != 0);
    delay(200);
    test_val += 1;
    if(test_val >= 9) {
        test_val = 0;
        _pwm_level -= 2;
        if(_pwm_level == 0 || _pwm_level > PWM_STEPS){
            _pwm_level = PWM_STEPS;
        }
    }
}
