int relay1=2; 
int relay2=3;
int relay3=4;
int relay4=5;

#define echoPin1 6
#define trigPin1 7

long duration;
int distance; 
  
String datain;
void setup() {
  // put your setup code here, to run once:

Serial.begin(9600); 
pinMode(relay1,OUTPUT);
pinMode(relay2,OUTPUT);
pinMode(relay3,OUTPUT);
pinMode(relay4,OUTPUT); 

pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);

}
int obstacle(int trigPinx, int echoPinx) {
  digitalWrite(trigPinx, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPinx, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinx, LOW);

  duration = pulseIn(echoPinx, HIGH);

  distance = duration * 0.034 / 2;
  return distance;
}
void loop() {
  // put your main code here, to run repeatedly: 
  int dist1 = obstacle(trigPin1,echoPin1);
  if (dist1 < 10 ){
   digitalWrite(relay1,LOW);
        digitalWrite(relay2,LOW);
        digitalWrite(relay3,LOW);
        digitalWrite(relay4,LOW);
  }
  
  delay(100);
  
  if(Serial.available())
  {
    while(Serial.available() > 0)
    {
       char c = Serial.read(); 
      datain +=c;
      delay(100);
      }
      Serial.println(datain);
      if(datain=="*forward#")
      {
        Serial.println("FORWARD ON");
        digitalWrite(relay1,HIGH);
        digitalWrite(relay2,LOW);
        digitalWrite(relay3,HIGH);
        digitalWrite(relay4,LOW);
        }
        else if(datain=="*backward#")
        {
        digitalWrite(relay1,LOW);
        digitalWrite(relay2,HIGH);
        digitalWrite(relay3,LOW);
        digitalWrite(relay4,HIGH); 
          Serial.println("BACKWORD");
          }

          else if(datain=="*right#")
        {
          Serial.println("right");
          digitalWrite(relay1,HIGH);
          digitalWrite(relay2,LOW);
          digitalWrite(relay3,LOW);
          digitalWrite(relay4,HIGH);
          }
          else if(datain=="*left#")
        {
          Serial.println("LEFT ON");
          digitalWrite(relay1,LOW);
          digitalWrite(relay2,HIGH);
          digitalWrite(relay3,HIGH);
           digitalWrite(relay4,LOW);
          }

       else if(datain=="*stop#")
      {
        Serial.println("stop");
        digitalWrite(relay1,LOW);
        digitalWrite(relay2,LOW);
        digitalWrite(relay3,LOW);
        digitalWrite(relay4,LOW);
        }     
     datain="";
    }
}
