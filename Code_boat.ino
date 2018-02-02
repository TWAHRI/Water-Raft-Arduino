

int pin1Moteur1=A1; //pin de commande moteur 1
int pin2Moteur1=A0; // pin de commande moteur 1
int pinPMoteur1=9;// pin PWM moteur 1
int pin1Moteur2=8; // pin de commande moteur 2
int pin2Moteur2=7; // pin de commande moteur 2
int pinPMoteur2=6; // pin PWM moteur 2
int pin1Moteur3=3; // pin de commande moteur 3
int pin2Moteur3=4; // pin de commande moteur 3
int pinPMoteur3=5; // pin PWM moteur 3

char str[2],i;
void forward()
{  analogWrite(pinPMoteur1,255); 
   digitalWrite(pin1Moteur1, 0);
   digitalWrite(pin2Moteur1, 1);
   analogWrite(pinPMoteur2,210); 
   digitalWrite(pin1Moteur2, 0);
   digitalWrite(pin2Moteur2,1);
}
void backward()
{
   analogWrite(pinPMoteur1,225); 
   digitalWrite(pin1Moteur1, 1);
   digitalWrite(pin2Moteur1, 0);
   analogWrite(pinPMoteur2,225); 
   digitalWrite(pin1Moteur2, 1);
   digitalWrite(pin2Moteur2,0);
}
void left()
{
   analogWrite(pinPMoteur1,225); 
  digitalWrite(pin1Moteur1, 0);
   digitalWrite(pin2Moteur1, 1);
   analogWrite(pinPMoteur2,225); 
   digitalWrite(pin1Moteur2, 1);
   digitalWrite(pin2Moteur2,0);
}
void right()
{
  analogWrite(pinPMoteur1,225); 
  digitalWrite(pin1Moteur1, 1);
   digitalWrite(pin2Moteur1, 0);
   analogWrite(pinPMoteur2,225); 
   digitalWrite(pin1Moteur2, 0);
   digitalWrite(pin2Moteur2,1);
}
void Stop()
{
   analogWrite(pinPMoteur1,0); 
  digitalWrite(pin1Moteur1, 0);
   digitalWrite(pin2Moteur1, 0);
   analogWrite(pinPMoteur2,0); 
   digitalWrite(pin1Moteur2, 0);
   digitalWrite(pin2Moteur2,0);
}
void Up()
{
   analogWrite(pinPMoteur3,200); 
   digitalWrite(pin1Moteur3, 1);
   digitalWrite(pin2Moteur3, 0);
}
void Down()
{  analogWrite(pinPMoteur3,200); 
   digitalWrite(pin1Moteur3, 0);
   digitalWrite(pin2Moteur3, 1);
}
void Stop3()
{
   analogWrite(pinPMoteur3,0); 
  digitalWrite(pin1Moteur3, 0);
   digitalWrite(pin2Moteur3, 0);
}

void setup() 
{
  Serial.begin(9600);
  pinMode(pin1Moteur1, OUTPUT);
  pinMode(pin2Moteur1, OUTPUT);
  pinMode(pinPMoteur1, OUTPUT);
  pinMode(pin1Moteur2, OUTPUT);
  pinMode(pin2Moteur2, OUTPUT);
  pinMode(pinPMoteur2, OUTPUT);
  pinMode(pin1Moteur3, OUTPUT);
  pinMode(pin2Moteur3, OUTPUT);
  pinMode(pinPMoteur3, OUTPUT);
}
void loop() 
{
  while(Serial.available())
  {
    char ch=Serial.read();
    str[i++]=ch;
    
    if(str[i-1]=='1')
    {
     Serial.println("Forward");
     forward();
     i=0;
    }
    else if(str[i-1]=='2')
    {
     Serial.println("Left");
     right();
     i=0;
    }
    else if(str[i-1]=='3')
    {
      Serial.println("Right");
      left();
      i=0;
    }
    
    else if(str[i-1]=='4')
    {
      Serial.println("Backward");
      backward();
      i=0;
    }
    else if(str[i-1]=='5')
    {
      Serial.println("Stop");
      Stop();
      i=0;
    }
    else if(str[i-1]=='6')
    {
      Serial.println("Tack Up");
      Up();
      i=0;
    }
     else if(str[i-1]=='7')
     {
      Serial.println("Tack Down");
      Down();
      i=0;
    }
    else if(str[i-1]=='8')
    {
      Serial.println("Stop3");
      Stop3();
      i=0;
    }
    delay(100);
  }
}
