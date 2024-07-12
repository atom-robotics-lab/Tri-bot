//ch3 ch2 is forwardback, ch1 ch4 leftright
int lowCh1 = 1180;
int midCh1 = 1550;
int highCh1 = 1975;
int lowCh3 = 1019;
int midCh3 = 1400;
int highCh3 = 1800;
int ping = 20;
int ch1;//throttle
int ch3;//L/R
int INA1 = 3;  
int INB1 = 4;
int INA2 = 6;
int INB2 = 7;
int P1 = 2;
int P2 = 5;
void setup() {
  pinMode(12, INPUT);
  pinMode(13, INPUT);
  pinMode(INA1, OUTPUT);
  pinMode(INB1, OUTPUT);
  pinMode(INA2, OUTPUT);
  pinMode(INB2, OUTPUT);
  Serial.begin(9600);
  delay(100);
}
void loop() {
  delay(50);
  ch1 = pulseIn(12, HIGH, 25000);
  // delay(10);
  ch3 = pulseIn(13, HIGH, 25000);
  // delay(50);

  Serial.print("rc_ch1: ");
  Serial.print(ch1);
  Serial.print(" | ");
  Serial.print("rc_ch3: ");
  Serial.print(ch3);
  Serial.println(" ");

  delay(50);

  if ((ch1>=lowCh1 && ch1<= highCh1) || (ch3>=lowCh3 && ch3<=highCh3)) {
    if (ch1>=lowCh1 && ch1<= highCh1) {
      leftright();
    }
    if (ch3>=lowCh3 && ch3<=highCh3) {
      forwardbackward();
    }
    if ((ch1<=midCh1+ping && ch1>=midCh1-ping) && (ch3>=midCh3-ping && ch3<=midCh3+ping)) {

    digitalWrite(INA1, LOW);
    digitalWrite(INB1, LOW); //Motor 1 stop 
    digitalWrite(INA2, LOW);
    digitalWrite(INB2, LOW); //Motor 2 stop 
    analogWrite(P1, 0);
    analogWrite(P2, 0);
    Serial.print("At Rest\n");
  }

  } 
  
}
void forwardbackward() {
  //backward
  if (ch3>=lowCh3 && ch3<= midCh3-ping ) {
      int val1 = map(ch3,midCh3-ping, lowCh3, 0, 255);
      Serial.print("BACKWARD");
      Serial.print(val1);
      digitalWrite(INA1, HIGH);
      digitalWrite(INB1, LOW); //Motor 1 forward 
      digitalWrite(INA2, HIGH);
      digitalWrite(INB2, LOW); //Motor 2 forward
      analogWrite(P1, val1);
      analogWrite(P2, val1);  

  }
  //forward
  else if (ch3>=midCh3+ping && ch3<=highCh3) 
  {
    int val2 = map(ch3, midCh3+ping, highCh3, 0, 255);

    Serial.print("FORWARD");
    Serial.print(val2);
    digitalWrite(INA1, LOW);
    digitalWrite(INB1, HIGH); //Motor 1 forward 
    digitalWrite(INA2, LOW);
    digitalWrite(INB2, HIGH); //Motor 2 backward
    analogWrite(P1, val2);
    analogWrite(P2, val2);  
  } 
  Serial.println("");
}

  
void leftright() {
  // right
  if (ch1>=midCh1+ping && ch1<=highCh1) {
      int val3 = map(ch1, midCh1+ping, highCh1, 0, 255);

      Serial.print("RIGHT");
      Serial.println(val3);
      Serial.print(val3);
      digitalWrite(INA1, HIGH);
      digitalWrite(INB1, LOW); //Motor 1 forward 
      digitalWrite(INA2, LOW);
      digitalWrite(INB2, HIGH); //Motor 2 backward
      analogWrite(P1, val3);
      analogWrite(P2, val3);  
  }
    // left
  if (ch1>=lowCh1 && ch1<=midCh1-ping) {
    int val4 = map(ch1, midCh1-ping, lowCh1, 0, 255);
    Serial.print("LEFT");
    Serial.println(val4);
      digitalWrite(INA1, LOW); // motor bec
      digitalWrite(INB1, HIGH); 
      digitalWrite(INA2, HIGH); //motor for
      digitalWrite(INB2, LOW); 
      analogWrite(P1, val4);
      analogWrite(P2, val4);  
  }
  Serial.println("");
}