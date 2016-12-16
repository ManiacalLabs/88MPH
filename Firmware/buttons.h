typedef struct {
    byte pin;
    bool last_state;
    long time_press;
    bool flag;
    bool reset;
} _button;

_button btns[2] = {
    {   //Button A
        2, //pin
        false, //last_state
        0, //time_press
        false, //flag
        false, //reset
    },
    {   //Button B
        3, //pin
        false, //last_state
        0, //time_press
        false, //flag
        false, //reset
    }
};

#define BTN_A btns[0]
#define BTN_B btns[1]
#define BTN_HOLD_TIME 600
#define HOLD_BTN_A BTN_A.flag && !BTN_A.reset
#define HOLD_BTN_B BTN_B.flag && !BTN_B.reset
