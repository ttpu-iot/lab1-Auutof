
// RED - D15
// Green - D4
// Blue - D22
// Yellow - D23

// button - D14
// light sensor - D33

#include "Arduino.h"
#define RED 15
#define GRN 4
#define BLU 22
#define YLW 23

#define BTN 14 //button port
#define LSR 33 //light sensor port

// //exercise 1: Solution
// /****************************************************/
// void setup(void) {
//     Serial.begin(9600);

//     pinMode(RED, OUTPUT);

// }


// /****************************************************/
// void loop(void) {

//     digitalWrite(RED,HIGH);
//     Serial.println("RED ON");

//     delay(500);

//     digitalWrite(RED,LOW);
//     Serial.println("RED OFF");
//     delay(500);
 
// }

// Exercise 2: Solution

void setup(void) {

pinMode(GRN, OUTPUT);
pinMode(BTN, INPUT);
}

void loop(void) {
static int led_state = 0;

static int prev_btn_state = LOW;

int btn_state = digitalRead(BTN);

if (btn_state == HIGH && prev_btn_state == LOW){
    // button has just been pressed
digitalWrite(GRN, !led_state);

led_state = !led_state;
}

prev_btn_state = btn_state;
}
