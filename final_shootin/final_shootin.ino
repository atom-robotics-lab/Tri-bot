#include <Servo.h>
int lowch5=990;
int midch5=1493;
int highch5=1980;
int ping=20;
int ch5; //motor
int IN1=11;
int IN2=12;
int PWM_Channel = 0; // PWM channel for motor speed control
int PWM_Frequency = 5000; // Frequency of PWM signal
int PWM_Resolution = 8; // Resolution of PWM signal (8 bits, values from 0-255)
const int maxSpeed = 200; // Maximum allowed speed for the motor, adjust based on your motor's capabilities
Servo myServo;
void setup() {
  pinMode(5, INPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  myServo.attach(4);
  Serial.begin(9600);
  delay(100);
}
// void open(){
//   myServo.write(180);
//   delay(1000);
//   myservo.write(90);

// }fvoid shoot(){
  // if (ch5>=1015){
    // digitalWrite(IN1, HIGH);
    // digitalWrite(IN2, LOW);
    // }
  // else if (ch5<=1015){
  //   digitalWrite(IN1, LOW);
  //   digitalWrite(IN2, HIGH);
  //   Serial.println("motor stopped");
  // }
  
void loop() {
  // delay(50);
  ch5 = pulseIn(5, HIGH, 25000);
  Serial.print("ch5: ");
  Serial.println(ch5);
  
  if (ch5>=1550 && ch5<=2060){
  myServo.write(180);
  Serial.println("writing to servo");

  myServo.write(90);
  Serial.println("stopping servo");
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  Serial.println("motor chalaying");
  } else {
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
  }
}