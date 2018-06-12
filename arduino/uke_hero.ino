#include <Wire.h>
#include <ZX_Sensor.h>

/* Buttons */
const int red = 3; //0 | 255
const int blue = 5; //1 | 254
const int green = 6; //2 | 253
const int black = 7; //3 | 252
const int white = 8; //4 | 251
const int yellow = 11; //5 | 250

int buttonArray[6] = {red, blue, green, black, white, yellow};
int stateArray[6] = {};

/* Gesture sensor*/
const int gesture_sensor = 249; //const for max
const int ZX_ADDR = 0x10; // ZX Sensor I2C address
ZX_Sensor zx_sensor = ZX_Sensor(ZX_ADDR);
uint8_t x_pos;
uint8_t z_pos;

void setup() {
  Serial.begin(9600);
  Serial.println();

  /* Initialize buttons */
  for (int i=0; i<6; i++) {
    pinMode(buttonArray[i],INPUT_PULLUP);
    stateArray[i] = 0;
  }

  /* Initialize gesture sensor */
//  if (zx_sensor.init()) {
//    Serial.println("Sensor initialization complete");
//  }
//  else {
//    Serial.println("Error: could not initialize sensor");
//  }
//
//  /* Check gesture sensor model version */
//  uint8_t ver; 
//  ver = zx_sensor.getModelVersion();
//  if ( ver == ZX_ERROR ) {
//    Serial.println("Error reading model version number");
//  } else {
//    Serial.print("Model version: ");
//    Serial.println(ver);
//  }
//  if ( ver != ZX_MODEL_VER ) {
//    Serial.print("Model version needs to be ");
//    Serial.print(ZX_MODEL_VER);
//    Serial.print(" to work with this library. Stopping.");
//    while(1);
//  }
//
//  ver = zx_sensor.getRegMapVersion();
//  if ( ver == ZX_ERROR ) {
//    Serial.println("Error reading register map version number");
//  } else {
//    Serial.print("Register Map Version: ");
//    Serial.println(ver);
//  }
//  if ( ver != ZX_REG_MAP_VER ) {
//    Serial.print("Register map version needs to be ");
//    Serial.print(ZX_REG_MAP_VER);
//    Serial.print(" to work with this library. Stopping.");
//    while(1);
//  }
  
}

void loop() {

  a2dStep();
  delay(10);
  for (int i=0; i<6; i++) {

//    if (stateArray[i] != digitalRead(buttonArray[i])) {
//      stateArray[i] = digitalRead(buttonArray[i]);
//      Serial.write(255);
//      Serial.write(buttonArray[i]);
//      Serial.write(stateArray[i]); 
//    }
    // Only write if there's a change in state
    /* For debugging */
    /* 
    switch (i) {
      case 0: Serial.print("Reading from red: ");
              Serial.println(stateArray[i]);
              break;
      case 1: Serial.print("Reading from blue: ");
              Serial.println(stateArray[i]);
              break;
      case 2: Serial.print("Reading from green: ");
              Serial.println(stateArray[i]);
              break;
      case 3: Serial.print("Reading from black: ");
              Serial.println(stateArray[i]);
              break;
      case 4: Serial.print("Reading from white: ");
              Serial.println(stateArray[i]);
              break;
      case 5: Serial.print("Reading from yellow: ");
              Serial.println(stateArray[i]);
              break;
    } */
  }
 
}

void a2dStep() {
  Serial.write(255); //send separator byte
  for (int i=0; i<6; i++) { 
    stateArray[i] = digitalRead(buttonArray[i]);
    Serial.write(stateArray[i]);
    //Serial.println(stateArray[i]);
    Serial.write(buttonArray[i]);
//  Serial.println(stateArray[i]);
//  Serial.println(buttonArray[i]);
  }

//  if (zx_sensor.positionAvailable()) {
//    x_pos = zx_sensor.readX();
//    if (x_pos != ZX_ERROR) {
//      //Serial.print("X: ");
//      //Serial.print(x_pos);
//      Serial.write(x_pos);
//    }
//    z_pos = zx_sensor.readZ();
//    if (z_pos != ZX_ERROR) {
//      //Serial.print(" Z: ");
//      //Serial.println(z_pos);
//      Serial.write(z_pos);
//    }
//  }
}

