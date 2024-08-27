//ch3 ch2 is forwardback, ch1 ch4 leftright
int lowCh1 = 1087;
int midCh1 = 1453;
int highCh1 = 1826;
int lowCh3 = 1020;
int midCh3 = 1395;
int highCh3 = 1798;
int ping = 20;
int ch1;//throttle
int ch3;//L/R

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
  pinMode(12, INPUT);
  pinMode(13, INPUT);
  pinMode(INA1, OUTPUT);
  pinMode(INB1, OUTPUT);
  pinMode(P1, OUTPUT);
  pinMode(RP, OUTPUT);
  pinMode(LP, OUTPUT);
  pinMode(R_EN, OUTPUT);
  pinMode(L_EN, OUTPUT);
  Serial.begin(9600);
  delay(100);
}
void loop() {
  delay(50);
    digitalWrite(R_EN, HIGH);
  digitalWrite(L_EN, HIGH);

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
    // digitalWrite(INA2, LOW);
    // digitalWrite(INB2, LOW); //Motor 2 stop 
    analogWrite(P1, 0);
    analogWrite(RP, 0);
    analogWrite(LP, 0);

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
      digitalWrite(INB1, LOW); 
      analogWrite(P1, 255);
      analogWrite(RP, 255);
      analogWrite(LP, 0);
       
  }
  //forward
  else if (ch3>=midCh3+ping && ch3<=highCh3) 
  {
    int val2 = map(ch3, midCh3+ping, highCh3, 0, 255);

    Serial.print("FORWARD");
    Serial.print(val2);
    digitalWrite(INA1, LOW);
    digitalWrite(INB1, HIGH); //Motor 1 forward 
    // digitalWrite(INA2, LOW);
    // digitalWrite(INB2, HIGH); //Motor 2 backward
    // analogWrite(P1, val2);
    // analogWrite(P2, val2);  
    analogWrite(P1, 255);
    analogWrite(RP, 0);
    analogWrite(LP, 255);  
  } 
  Serial.println("");
}

  
void leftright() {
  // right
  if (ch1>=midCh1+ping && ch1<=highCh1) {
      int val4 = map(ch1, midCh1-ping, lowCh1, 0, 255);
      Serial.print("LEFT");
      Serial.println(val4);
      digitalWrite(INA1, HIGH); // motor bec
      digitalWrite(INB1, LOW); 
      // digitalWrite(INA2, HIGH); //motor for
      // digitalWrite(INB2, LOW); 
      // analogWrite(P1, val4);
      // analogWrite(P2, val4);  
      analogWrite(P1, 255);
      analogWrite(RP, 0);
      analogWrite(LP, 255);
      
      
      
  }
    // left
  if (ch1>=lowCh1 && ch1<=midCh1-ping) {
  int val3 = map(ch1, midCh1+ping, highCh1, 0, 255);
      
      Serial.print("RIGHT");
      Serial.println(val3);
      Serial.print(val3);
      digitalWrite(INA1, LOW);
      digitalWrite(INB1, HIGH); //Motor 1 forward 
      // digitalWrite(INA2, LOW);
      // digitalWrite(INB2, HIGH); //Motor 2 backward
      // analogWrite(P1, val3);
      // analogWrite(P2, val3);
      analogWrite(P1, 255);
      analogWrite(RP, 255);
      analogWrite(LP, 0); 

  }
  Serial.println("");
}
