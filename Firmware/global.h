#include "display.h"
#include "buttons.h"

typedef struct {
    uint8_t speed;
    int rpm;
} obd_result;


bool _in_target_set = false;

#define BLINK_COUNT 3

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

#define PWM_STEPS 20
#define PWM_HIGH PWM_STEPS
#define PWM_LOW 5
volatile byte _pwm_step = 0;
bool _pwm_level = true;
volatile byte _digit = 0;

#define TIME_SPEED 88 //when this baby hits...
uint8_t _target_speed = TIME_SPEED;
#define SPEED_MAX 99

#define CONFIG_CHECK 42
#define CONFIG_BYTE 0
#define PWM_BYTE 1
#define TARGET_BYTE 2

#define LOW_RPM 250
#define LOW_RPM_MAX 3
byte low_rpm_count = 0;
#define ENGINE_OFF_SLEEP 60
bool engine_off = false;

uint8_t _cur_value;
byte _digit_values[DIGIT_COUNT];

int error_count = 0;

obd_result obd_data = {0, 0};
