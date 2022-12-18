#include <Arduino.h>

int a;
int f = 60;
float fs = 500.0;
int sig[500];
float t;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 500; i++) {
    t = (float)i/fs;
    sig[i] = (int) (127.0*(sin(2*3.14*f*t)+1.0))*100000;
  }
}

void loop() {
  for (int i = 0; i < 500; i++) {
    if (sig[i] < 1250000 && sig[i] != 0){
      a = -1;
    } else {
      a = 1;
    }
    Serial.println(a*sig[i]);
    analogWrite(25, a*sig[i]);
    delay(2);
  }
}