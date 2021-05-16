#include <IRremote.h>      //must copy IRremote library to arduino libraries
#include <Servo.h>
#define plus 0x80412701

  //clockwise rotation button
#define minus 0x8041A702//counter clockwise rotation button
    
int RECV_PIN = D1;       //IR receiver pin
Servo servo;
int val;                //rotation angle
bool cwRotation, ccwRotation;  //the states of rotation

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  servo.attach(D1);     //servo pin
  pinMode(D0,OUTPUT);
}

void loop() 
{
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value

    if (results.value == plus)
    {
      digitalWrite(D0,HIGH);
      servo.write(120);
      delay(1000);
    }

    if (results.value == minus)
    {
     digitalWrite(D0,LOW);
      servo.write(-120);
      delay(1000);
    }
  }
  }
