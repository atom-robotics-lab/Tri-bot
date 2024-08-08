#include <ps5Controller.h>

int   fwd = 15;
int   bwd = 16;
int   lft = 17;
int   rgt = 18;


void notify()
{
  digitalWrite(fwd, ps5.Left());
  digitalWrite(bwd, ps5.Down());
  digitalWrite(lft, ps5.Right());
  digitalWrite(rgt, ps5.Up()); 
}

void onConnect()
{
  Serial.println("Connected!.");

}

void onDisConnect()
{
  Serial.println("Disconnected!.");    
}

void setUpPinModes()
{
  pinMode(fwd, OUTPUT);
  pinMode(bwd, OUTPUT);
  pinMode(lft, OUTPUT);
  pinMode(rgt, OUTPUT);      
}

void forwardbackward(){

  if (ps5.Up() == 1) {
    digitalWrite(fwd, HIGH);
    Serial.println("Going forward");
  }

  else if (ps5.Down() == 1){
    digitalWrite(bwd, HIGH);
    Serial.println("Going backward");
  }
}

void leftright(){

  if (ps5.Left() == 1){
    digitalWrite(lft, HIGH);
    Serial.println("Going left");
  }

  else if (ps5.Right() == 1){
    digitalWrite(rgt, HIGH);
    Serial.println("Going right");
  }
}

void setup() 
{
  setUpPinModes();
  Serial.begin(115200);
  ps5.attach(notify);
  ps5.attachOnConnect(onConnect);
  ps5.attachOnDisconnect(onDisConnect);
  ps5.begin("ac:36:1b:53:ef:31");
  while (ps5.isConnected() == false) 
  { 
    Serial.println("PS5 controller not found");
    delay(300);
  } 
  Serial.println("Ready.");
}

void loop() 
{

if ((ps5.Left() == 1 || ps5.Right() == 1) || (ps5.Up() == 1 || ps5.Down() == 1)){

  if (ps5.Left() == 1 || ps5.Right() == 1){
    leftright();
    // Serial.println("leftright");
  }


  else if (ps5.Up() == 1 || ps5.Down() == 1){
    forwardbackward();
    // Serial.println("forwardbackward");

  }
}

else if ((ps5.Left() == 0 || ps5.Right() == 0) || (ps5.Up() == 0 || ps5.Down() == 0)){
  Serial.println("At rest");
  digitalWrite(fwd, LOW);
  digitalWrite(bwd, LOW);
  digitalWrite(lft, LOW);
  digitalWrite(rgt, LOW); 

}


}










