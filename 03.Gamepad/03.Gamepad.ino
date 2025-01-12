/*
   Gamepad module provides three different mode namely Digital, JoyStick and Accerleometer.

   You can reduce the size of library compiled by enabling only those modules that you want to
   use. For this first define CUSTOM_SETTINGS followed by defining INCLUDE_modulename.

   Explore more on: https://thestempedia.com/docs/dabble/game-pad-module/
*/
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>
#include <AFMotor.h>
#include <Servo.h>



const int motor1 = 2;
const int motor2 = 3;
const int motora1 = 4;
const int motora2 = 7;
const int motorENA = 5;
const int motorENB = 6;
const int water_pump = 8;
const int water_pump2 = 9;

int servo_ve = 110;
int servo_ho = 80;
int servo_ze = 0;

Servo servo_v;
Servo servo_h;
Servo servo_z;




//AF_DCMotor motor1(1, MOTOR12_1KHZ); 
//AF_DCMotor motor2(2, MOTOR12_1KHZ); 



void setup() {
  // put your setup code here, to run once:
  Serial.begin(250000);      // make sure your Serial Monitor is also set at this baud rate.
  Dabble.begin(9600);      //Enter baudrate of your bluetooth.Connect bluetooth on Bluetooth port present on evive.
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motorENA, OUTPUT);
  pinMode(motora1, OUTPUT);
  pinMode(motora2, OUTPUT);
  pinMode(motorENB, OUTPUT);
  pinMode(water_pump, OUTPUT);
  pinMode(water_pump2, OUTPUT);
  
  servo_v.attach(10);
  servo_h.attach(11);
  servo_z.attach(12);
  
  servo_v.write(servo_ve);
  servo_h.write(servo_ho);
  servo_z.write(servo_ze);
  
}

void loop() {
  Dabble.processInput();             //this function is used to refresh data obtained from smartphone.Hence calling this function is mandatory in order to get data properly from your mobile.
  if (GamePad.isUpPressed())
  {
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, HIGH);
    digitalWrite(motora1, HIGH);
    digitalWrite(motora2, LOW);
    analogWrite(motorENA,100);
    analogWrite(motorENB,100);
    delay(100);
  }

  if (GamePad.isDownPressed())
  {
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, LOW);
    digitalWrite(motora1, LOW);
    digitalWrite(motora2, HIGH);
    analogWrite(motorENA,100);
    analogWrite(motorENB,100);
    delay(100);
  }

  if (GamePad.isSelectPressed())
  {
    if (servo_ze < 80)
      servo_ze = servo_ze + 5;
      servo_z.write(servo_ze);
      delay(100);
    
    
  }

  if (GamePad.isStartPressed())
  {
    if (servo_ze > 0)
      servo_ze = servo_ze - 5;
      servo_z.write(servo_ze);
      delay(100);
   
  }

  if (GamePad.isTrianglePressed())
  {
    if (servo_ve < 145)
      servo_ve = servo_ve + 5;
      servo_v.write(servo_ve);
      delay(100);
    

  }

  if (GamePad.isCrossPressed())
  {
    if (servo_ve > 80)
      servo_ve = servo_ve - 5;
      servo_v.write(servo_ve);
      delay(100);
    
  }

  if (GamePad.isCirclePressed())
  {
    if (servo_ho > 0)
      servo_ho = servo_ho - 5;
      servo_h.write(servo_ho);
      delay(100);
  }

  if (GamePad.isSquarePressed())
  {
    if (servo_ho < 175)
      servo_ho = servo_ho + 5;
      servo_h.write(servo_ho);
      delay(100);
  }

  if (GamePad.isRightPressed())
  {
    digitalWrite(water_pump, HIGH);
    digitalWrite(water_pump2, LOW);
    delay(100);
  }

  if (GamePad.isLeftPressed())
  {
    digitalWrite(water_pump, LOW);
    digitalWrite(water_pump2, HIGH);
    delay(100);
  }
  
  else;
  {
    delay(100);
    analogWrite(motorENA,0);
    analogWrite(motorENB,0);
    
    
  }




  
  Serial.print('\t');

  int a = GamePad.getAngle();
  Serial.print("Angle: ");
  Serial.print(a);
  Serial.print('\t');
  int b = GamePad.getRadius();
  Serial.print("Radius: ");
  Serial.print(b);
  Serial.print('\t');
  float c = GamePad.getXaxisData();
  Serial.print("x_axis: ");
  Serial.print(c);
  Serial.print('\t');
  float d = GamePad.getYaxisData();
  Serial.print("y_axis: ");
  Serial.println(d);
  Serial.println();
}
