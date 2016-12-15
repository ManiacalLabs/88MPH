#define SEG_COUNT 8
byte anodes[SEG_COUNT] = {
    5, //A
    6, //B
    7, //C
    8, //D
    9, //E
    10, //F
    11, //G
    12 //DP
};
//0b0GFEDCBA
//####
// A
//F B
// G
//E C
// D
//####

#define DIGIT_COUNT 2
byte cathodes[DIGIT_COUNT] = {
    14, //Display 0
    15 //Display 1
};

byte digits[10] = {
    0b00111111, //0
    0b00000110, //1
    0b01011011, //2
    0b01001111, //3
    0b01100110, //4
    0b01101101, //5
    0b01111101, //6
    0b00000111, //7
    0b01111111, //8
    0b01101111  //9
};
