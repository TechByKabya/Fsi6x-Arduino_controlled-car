// rc controlled BOT__by kabya Ghosh

//date:6.6.2022
//-------------------------------------------------------------------------
// we used  relay to  on/off camera  tx
// we used  relay2 to on/off light
// we used  swtich,swtich2,swtich3  to store transmitter aux channel value 
// we used  value,value1 &  value3   to read  transmitter aux channel value 
// we used  speed_slow  for devide pwm value 
// we used  a,b,c,d,x,y,z,k  to map pwm value in 0-255
//--------------------------------------------------------------------------                                                                                                                                                                                                                                                                                                                                                                         #define inputPin1 2      //tranamitter pin to arduino
#define inputPin2 4       //transmitter puls input pins 
#define inputPin1 2 
#define RPWMa 12
#define LPWMa 10
#define ENAa 5
#define RPWMb 8           //define bts7960 to arduino connection
#define LPWMb 7 
#define ENAb 11
#define value 3
#define value2 6
#define value3 13
#define relay 9
#define relay2 A0
int speed_slow =6;
int d;
int c;
int a;
int b;
int x;                    //store pwm value 
int y;
int z;
int k;
int swtich;
int swtich2;
int swtich3;

float pulsewidth1 = 0;   //rc transmitter puls read
float pulsewidth2 = 0;


void setup() {
  
  Serial.begin(9600);
  digitalWrite(RPWMa,LOW);
  digitalWrite(LPWMa,LOW);  //first we have to stop all the motors, if transmitter is not connected
  digitalWrite(RPWMb,LOW);
  digitalWrite(LPWMb,LOW);
  
  pinMode(inputPin1, INPUT);
  pinMode(inputPin2, INPUT);
  
  pinMode(value, INPUT);
  pinMode(value2, INPUT);
  pinMode(value3, INPUT);
    
  pinMode(relay, OUTPUT);
  pinMode(relay2, OUTPUT);
   
  pinMode(RPWMa,OUTPUT);
  pinMode(LPWMa,OUTPUT);
  pinMode(ENAa,OUTPUT);       //motor driver pin 
  pinMode(RPWMb,OUTPUT);
  pinMode(LPWMb,OUTPUT);
  pinMode(ENAb,OUTPUT);
   
}

void loop() {
 
   pulsewidth1 = pulseIn(2, HIGH);   // rc transmitter puls store 
   pulsewidth2 = pulseIn(4, HIGH);
   swtich= digitalRead(value);
   
   swtich2= digitalRead(value2); 
   swtich3= digitalRead(value3);
         
//   Serial.println(swtich2); 
//   Serial.println(pulsewidth2);
//   Serial.println(pulsewidth1);

 if (swtich2 == 0)
{
   digitalWrite(RPWMa,LOW);
   digitalWrite(LPWMa,LOW); //Right motor turn left

  
   digitalWrite(RPWMb,LOW);
   digitalWrite(LPWMb,LOW);
  

}
else if (pulsewidth1 > 1550 & pulsewidth2 > 1550 & pulsewidth1 !=0 & pulsewidth2 !=0)
{
  a = map(pulsewidth2, 1550, 1960, 0, 255);
  if (a<0)a=0;
  if (a>255)a=255;
  digitalWrite(RPWMa,HIGH);
  digitalWrite(LPWMa,LOW);     //Right motor forward
  analogWrite(ENAa,a);
  
  digitalWrite(RPWMb,HIGH);
  digitalWrite(LPWMb,LOW);     //left motor forward
  analogWrite(ENAb,a/speed_slow);
}

 

else if (pulsewidth1 > 1550 & pulsewidth2 < 1450 & pulsewidth2 !=0 )
{
  b = map(pulsewidth1, 1550, 1960, 0, 255);
  if (b<0)b=0;
  if (b>255)b=255;
  digitalWrite(RPWMa,HIGH);
  digitalWrite(LPWMa,LOW);     //Right motor forward
  analogWrite(ENAa,b/speed_slow);
  
  digitalWrite(RPWMb,HIGH);
  digitalWrite(LPWMb,LOW);     //left motor forward
  analogWrite(ENAb,b);
}
else if (pulsewidth1 < 1450 & pulsewidth2 > 1550 & pulsewidth1 !=0 & pulsewidth2 !=0 )
{
  c = map(pulsewidth1, 1450, 1000, 0, 255);
  if (c<0)c=0;
  if (c>255)c=255;
  digitalWrite(RPWMa,LOW);
  digitalWrite(LPWMa,HIGH); //Right motor backward
  analogWrite(ENAa,c);
  
  digitalWrite(RPWMb,LOW);
  digitalWrite(LPWMb,HIGH); //left motor backward
  analogWrite(ENAb,c/speed_slow);
}
else if (pulsewidth1 < 1450 & pulsewidth2 < 1450 & pulsewidth2!=0 & pulsewidth1!=0 )
{
  d = map(pulsewidth1, 1450, 1000, 0, 255);
  if (d<0)d=0;
  if (d>255)d=255;
  digitalWrite(RPWMa,LOW);
  digitalWrite(LPWMa,HIGH); //Right motor backward
  analogWrite(ENAa,d/speed_slow);
  
  digitalWrite(RPWMb,LOW);
  digitalWrite(LPWMb,HIGH); //left motor backward
  analogWrite(ENAb,d);
}


else if (pulsewidth1 > 1550 & pulsewidth1 !=0 ) 
{
   x = map(pulsewidth1, 1550, 1960, 0, 255);
   if (x<0)x=0;
   if (x>255)x=255;
  digitalWrite(RPWMa,HIGH);
  digitalWrite(LPWMa,LOW);     //Right motor forward
  analogWrite(ENAa,x);
  
  digitalWrite(RPWMb,HIGH);
  digitalWrite(LPWMb,LOW);     //left motor forward
  analogWrite(ENAb,x);

  
//   Serial.println("fwd");
//   Serial.println(x);
}


else if (pulsewidth1 < 1450 & pulsewidth1 !=0  )
{
 y = map(pulsewidth1, 1450, 1000, 0, 255);
  if (y<0)y=0;
  if (y>255)y=255;
  digitalWrite(RPWMa,LOW);
  digitalWrite(LPWMa,HIGH); //Right motor backward
  analogWrite(ENAa,y);
  
  digitalWrite(RPWMb,LOW);
  digitalWrite(LPWMb,HIGH); //left motor backward
  analogWrite(ENAb,y);
  
 
//  Serial.println("back");
//  Serial.println(y);

}

else if (pulsewidth2 > 1550 & pulsewidth2 !=0 )
{
   k = map(pulsewidth2, 1550, 1960, 0, 255);
  if (k<0)k=0;
  if (k>255)k=255;
  digitalWrite(RPWMa,LOW);
  digitalWrite(LPWMa,HIGH); //Right motor turn right
  analogWrite(ENAa,k);
  
  digitalWrite(RPWMb,HIGH);
  digitalWrite(LPWMb,LOW);     //left motor turn right
  analogWrite(ENAb,k);
  
//  Serial.println("right");
//  Serial.println(k);
}
else if (pulsewidth2 < 1450 & pulsewidth2 !=0)
{
   z = map(pulsewidth2, 1450, 1000, 0, 255);
  if (z<0)z=0;
  if (z>255)z=255;
   digitalWrite(RPWMa,HIGH);
   digitalWrite(LPWMa,LOW); //Right motor turn left
   analogWrite(ENAa,z);
  
   digitalWrite(RPWMb,LOW);
   digitalWrite(LPWMb,HIGH); //left motor turn left
   analogWrite(ENAb,z);
  
//  Serial.println("left");
//  Serial.println(z);
}




else
{
   digitalWrite(RPWMa,LOW);
   digitalWrite(LPWMa,LOW); //Right motor turn left

  
   digitalWrite(RPWMb,LOW);
   digitalWrite(LPWMb,LOW);
//Serial.println("stop");
}
 if (swtich==1)
   {
    digitalWrite(9,HIGH);
   }
 if (swtich==0)
   {
    digitalWrite(relay,LOW);               // turn on/off light & camera based on tx signal
   }
  if (swtich3==1)
   {
    digitalWrite(relay2,HIGH);
   }
 if (swtich3==0)
   {
    digitalWrite(relay2,LOW);
   }

}


