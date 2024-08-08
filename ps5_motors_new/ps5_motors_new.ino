int fwdpin = 9;
int bwdpin = 10;
int lftpin = 11;
int rgtpin = 12;
int fwd;
int bwd;
int lft;
int rgt;

// df ke pins

int INA1 = 3;  
int INB1 = 4;
int P1 = 2;

//bts ke pins

int RP = 5; 
int LP = 6;
int R_EN = 8;
int L_EN = 7;


void setup() {

  pinMode(fwdpin, INPUT);
  pinMode(bwdpin, INPUT);
  pinMode(lftpin, INPUT);
  pinMode(rgtpin, INPUT);

  pinMode(INA1, OUTPUT);
  pinMode(INB1, OUTPUT);
  pinMode(P1, OUTPUT);
  pinMode(RP, OUTPUT);
  pinMode(LP, OUTPUT);
  pinMode(R_EN, OUTPUT);
  pinMode(L_EN, OUTPUT);
  delay(100);
}
void loop() {

  fwd = digitalRead(fwdpin);
  bwd = digitalRead(bwdpin);
  lft = digitalRead(lftpin);
  rgt = digitalRead(rgtpin);

  delay(50);
  digitalWrite(R_EN, HIGH);
  digitalWrite(L_EN, HIGH);


  // Serial.print("rc_ch1: ");
  // Serial.print(ch1);
  // Serial.print(" | ");
  // Serial.print("rc_ch3: ");
  // Serial.print(ch3);
  // Serial.println(" ");
  // if ((ch1>=lowCh1 && ch1<= highCh1) || (ch3>=lowCh3 && ch3<=highCh3)) {
  //   if (ch1>=lowCh1 && ch1<= highCh1) {
  //     leftright();
  //   }
  //   if (ch3>=lowCh3 && ch3<=highCh3) {
  //     forwardbackward();
  //   }
  //   if ((ch1<=midCh1+ping && ch1>=midCh1-ping) && (ch3>=midCh3-ping && ch3<=midCh3+ping)) {

  //   digitalWrite(INA1, LOW);
  //   digitalWrite(INB1, LOW); //Motor 1 stop 
  //   // digitalWrite(INA2, LOW);
  //   // digitalWrite(INB2, LOW); //Motor 2 stop 
  //   analogWrite(P1, 0);
  //   analogWrite(RP, 0);
  //   analogWrite(LP, 0);

  //   Serial.print("At Rest\n");
  // }

   if ((fwd == 1 || bwd == 1) || (lft == 1 || rgt == 1)) {
    if (lft == 1 || rgt == 1) {
      leftright();
    }
    else if (fwd == 1 || bwd == 1) {
      forwardbackward();
    }
}

  else if ((fwd == 0 || bwd == 0) && (lft == 0 || rgt == 0)) {
    
    digitalWrite(INA1, LOW);
    digitalWrite(INB1, LOW); //Motor 1 stop 
    analogWrite(P1, 0);
    analogWrite(RP, 0);
    analogWrite(LP, 0);

    Serial.print("At Rest\n");
  }
} 
  

void forwardbackward() {
  //backward
  // if (ch3>=lowCh3 && ch3<= midCh3-ping ) 
    if (bwd == 1){

      Serial.print("BACKWARD");
      // Serial.print(val1);
      digitalWrite(INA1, HIGH);
      digitalWrite(INB1, LOW); //Motor 1 forward 
      analogWrite(P1, 255);
      analogWrite(RP, 0);
      analogWrite(LP, 255);
       
  }
  //forward
  else if (fwd == 1) 
  {
    // int val2 = map(ch3, midCh3+ping, highCh3, 0, 255);

    Serial.print("FORWARD");
    // Serial.print(val2);
    digitalWrite(INA1, LOW);
    digitalWrite(INB1, HIGH); //Motor 1 forward 
    analogWrite(P1, 255);
    analogWrite(RP, 255);
    analogWrite(LP, 0);  
  } 
  Serial.println("");
}

  
void leftright() {
  // right
  if (rgt == 1) {
      // int val3 = map(ch1, midCh1+ping, highCh1, 0, 255);

      Serial.print("RIGHT");
      // Serial.println(val3);
      // Serial.print(val3);
      digitalWrite(INA1, HIGH);
      digitalWrite(INB1, LOW); //Motor 1 forward 
      analogWrite(P1, 255);
      analogWrite(RP, 255);
      analogWrite(LP, 0);
  }
    // left
  if (lft == 1) {
    // int val4 = map(ch1, midCh1-ping, lowCh1, 0, 255);
    Serial.print("LEFT");
    // Serial.println(val4);
      digitalWrite(INA1, LOW); // motor bec
      digitalWrite(INB1, HIGH); 
      analogWrite(P1, 255);
      analogWrite(RP, 0);
      analogWrite(LP, 255); 

  }
  Serial.println("");
}