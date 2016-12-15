

byte anodes[] = {
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

byte cathodes[] = {
    14, //Display 0
    15 //Display 1
};

byte digits[] = {
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

void disp_num(byte digit, bool dp){
    static byte i = 0;
    for(i = 0; i<7; i++){
        digitalWrite(anodes[i], (digits[digit] & _BV(i)) ? HIGH : LOW);
    }
    digitalWrite(anodes[7], dp ? HIGH : LOW);
}

void setup(){
    byte i = 0;
    for(i=0; i<2; i++){
        pinMode(cathodes[i], OUTPUT);
        digitalWrite(cathodes[i], LOW);
    }
    for(i=0; i<8; i++){
        pinMode(anodes[i], OUTPUT);
        digitalWrite(anodes[i], LOW);
    }


    pinMode(13, OUTPUT);
}

void flip_digit(){
    static bool digit = false;
    digitalWrite(cathodes[byte(!digit)], HIGH);
    digitalWrite(cathodes[byte(digit)], LOW);
    digit =  !digit;
}

void loop(){
    byte i;
    for(i = 0; i < 10; i++){
        disp_num(i, false);
        flip_digit();
        delay(500);
    }
    // digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
    // delay(250);               // wait for a second
    // digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
    // delay(250);
}
