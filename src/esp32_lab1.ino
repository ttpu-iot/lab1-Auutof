
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

//Exercise 1: Solution

// /****************************************************/
// void setup(void) {
//     Serial.begin(115200);

//     pinMode(RED, OUTPUT);

// }

 /****************************************************/
// void loop(void) {

//     digitalWrite(RED,HIGH);
//     Serial.println("RED ON");

//     delay(500);

//     digitalWrite(RED,LOW);
//     Serial.println("RED OFF");
//     delay(500);
 
// }

// Exercise 2: Solution

/****************************************************/
// void setup(void) {
//     Serial.begin(115200);

//     pinMode(GRN, OUTPUT);
//     pinMode(BTN, INPUT);
// }

/****************************************************/

// void loop(void) {

//     static int prev_btn = LOW;
//     static int state = LOW;

//     int btn = digitalRead(BTN);

//     if (prev_btn == LOW && btn == HIGH)
//     {
//         state = ! state;

//         digitalWrite(GRN,state);

//         if (state == HIGH){
//             Serial.println("GREEN=1");
//         }
//         else{
//             Serial.println("GREEN=0");
//         }

//         delay(200);
//     }

//     prev_btn = btn;
// }

// Exercise 3: Solution

/****************************************************/
// void setup(void) {
//     Serial.begin(115200);

// }

/****************************************************/
// void loop(void) {
//     int val = analogRead(LSR);

//     static int counter = 0;

//     Serial.print(counter++);
//     Serial.print(") raw=");
//     Serial.print(val);

//     int volt = map(val, 0, 4095, 0, 3300);

//     Serial.print(";Volt=");
//     Serial.print(volt);
//     Serial.println("mV");

//     delay(500);
// }

// Exercise 4: Solution

/****************************************************/
// void turn_on_led(int ledcolor);

// void printLedColor(String color);

// void setup(void){
//     Serial.begin(115200);

//     pinMode(RED, OUTPUT);
//     pinMode(GRN, OUTPUT);
//     pinMode(BLU, OUTPUT);
//     pinMode(YLW, OUTPUT);
// }

/****************************************************/
// void loop(void) {
//     int val = analogRead(LSR);

//     if (val >= 0 && val <= 1023) {
//         // turn ON - BLUE led
//         turn_on_led(2);

//         printLedColor("BLUE");
//     }

//     else if (val >= 1024 && val <= 2047){
//     // turn .ON -. GREEN:led
//         turn_on_led(3);

//         printLedColor("GREEN");
//     }
    
//     else if (val >= 2048 && val <= 3071){
//     // turn .ON -.  YELLOW:led
//         turn_on_led(4);

//         printLedColor("YELLOW");
//     }

//     else if (val >= 3072 && val <= 4095){
//     // turn .ON -. RED:led
//         turn_on_led(1);

//         printLedColor("RED");
//     }
//     else{
//     //turn off all
//         turn_on_led(0);
//     }

//     delay(500);
// }

// // Print Color String (only ONCE)
// void printLedColor(String color)
// {
//     static String prevColor = "";

//     if (color != prevColor){
//     Serial.println(color);
//     prevColor = color;
//     }
// }

// // Turn on specific color Led only
// void turn_on_led(int ledcolor)
// {
//     // red=1,blue=2,green=3,yellow=4
//     int stateRed=LOW,stateBlu=LOW,stateGrn=LOW,stateYlw=LOW;

//     if(ledcolor == 1){
//         stateRed = HIGH;
//     }
//     else if(ledcolor == 2){
//         stateBlu = HIGH;
//     }
//     else if(ledcolor == 3){
//         stateGrn = HIGH;
//     }
//     else if(ledcolor == 4){
//         stateYlw = HIGH;
//     }

//     digitalWrite(RED,stateRed);
//     digitalWrite(BLU,stateBlu);
//     digitalWrite(GRN,stateGrn);
//     digitalWrite(YLW,stateYlw);
     
// }

//Exercise 5: Solution

// void flash_yellow(int duration_ms);
// /****************************************************/
// void setup(void){
//     Serial.begin(115200);

//     pinMode(YLW, OUTPUT);

//     pinMode(BTN, INPUT);
// }

// /****************************************************/
// void loop(void){
//     // detect button press
//     static int prev_btn = LOW;

//     int btn = digitalRead(BTN);

//     if (prev_btn == LOW && btn == HIGH){
//     // button press detected
//         int val = analogRead(LSR);

//         Serial.print("snapshot=");
//         Serial.println(val);

//         flash_yellow(1000);
//     }
//     prev_btn = btn;
// }

// //flash yellow led for a given duration
// void flash_yellow(int duration_ms)
// {
//     uint32_t starttime = millis();
//     uint32_t timediff = 0;

//     while(timediff < duration_ms){
//         digitalWrite(YLW, HIGH);
//         delay(100);
//         digitalWrite(YLW, LOW);
//         delay(300);

//         timediff = millis() - starttime;
//     }
// }

//Exercise 6: Solution

/****************************************************/
void setup(void){
    Serial.begin(115200);

    pinMode(BLU, OUTPUT);
    pinMode(GRN, OUTPUT);
    pinMode(YLW, OUTPUT);
    pinMode(RED, OUTPUT);
}

/****************************************************/
void loop(void){
    char msg = 0;

    if (Serial.available() > 0) {
        msg = Serial.read();
        Serial.write(msg);
    }

    if (msg == 'B') {
        digitalWrite(BLU, HIGH);
    }

    else if (msg == 'b') {
        digitalWrite(BLU, LOW);
    }

    else if (msg == 'G') {
        digitalWrite(GRN, HIGH);
    }

    else if (msg == 'g') {
        digitalWrite(GRN, LOW);
    }

        else if (msg == 'Y') {
        digitalWrite(YLW, HIGH);
    }

    else if (msg == 'y') {
        digitalWrite(YLW, LOW);
    }

        else if (msg == 'R') {
        digitalWrite(RED, HIGH);
    }

    else if (msg == 'r') {
        digitalWrite(RED, LOW);
    }
}