#include "SevSeg.h"

SevSeg sevseg; //Instantiate a seven segment controller object
int i=0;
int led=5,led1=6;
int c=0;
int let;
String readString;
void setnum(int n)
{
  static unsigned long timer = millis();
 static int deciSeconds = 0;
 
 if (millis() >= timer) {
 deciSeconds++; // 1000 milliSeconds is equal to 10 deciSecond
 timer += 1000; 
 if (deciSeconds == 10000) { // Reset to 0 after counting for 1000 seconds.
 deciSeconds=0;
 return;
 }
 sevseg.setNumber(n, 0);
 }

 sevseg.refreshDisplay(); // Must run repeatedly
    
}

void setstr(String s)
{
  static unsigned long timer = millis();
 static int deciSeconds = 0;
 
 if (millis() >= timer) {
 deciSeconds++; // 1000 milliSeconds is equal to 10 deciSecond
 timer += 1000; 
 if (deciSeconds == 10000) { // Reset to 0 after counting for 1000 seconds.
 deciSeconds=0;
 return;
 }
 char a[5];
 s.toCharArray(a,5);
 sevseg.setChars(a);
 }

 sevseg.refreshDisplay(); // Must run repeatedly
    
}
int flag=0;
void scroller(String s)
{
int n=s.length();
int i=0;
char a[4]="";

//a[0]=a[1]=a[2]=a[3]='';
//Serial.println(s);
//delay(30000);
while(i<n)
  {
  a[0]=a[1];
  a[1]=a[2];
  a[2]=a[3];
  a[3]=s.charAt(i);
  i++;
 //Serial.println(a[0]); 
 //delay(200000);
 //String res="ROSE";
 /*res=res+a[3];
 res=res+a[2];
 res=res+a[1];
 res=res+a[0];
 */
 String res="";
/* Serial.print(i);
 Serial.print(":");
 Serial.print(a[0]);
 Serial.print(a[1]);
 Serial.print(a[2]);
 Serial.println(a[3]);
 */
 res=res+a[0];
 res=res+a[1];
 res=res+a[2];
 res=res+a[3];
 if(i==4){flag=1;}
 

 
 if(flag==1){setstr(res);}
 //delay(2000);
 //delay(2000);
 if(i==n){i=0;}
 }
  
 
}

 void setup() {
  Serial.begin(9600);
 byte numDigits = 4; 
 byte digitPins[] = { 10,11,12,13};
 byte segmentPins[] = {2, 3, 4, 5, 6, 7, 8, 9};

sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins); 
// If your display is common anode type, please edit comment above line and uncomment below line
// sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins);
sevseg.setBrightness(90);
}

void loop() 
    {
     int var,pr;
  // put your ma
       while (!Serial.available()) {}
      while(Serial.available()>0)
      { 
      char c = Serial.read();  //gets one byte from serial buffer
      readString += c;
      //readString+="/";     
       
        //pr=Serial.read();
        //Serial.println(pr);
        //digitalWrite(led,HIGH);  
        delay(1000);
        }
      
  //rs=readString[:-2];

 
  
  if (readString.length() >0)
  {
    //Serial.print("Arduino received: ");  
    //Serial.println(readString); //see what was received
   String resultant="";
   resultant=resultant+"Cost of Bitcoin ";
   resultant=resultant+readString;
   resultant=resultant+" ";
   Serial.println(resultant);
   scroller(resultant);
   
  }

  delay(500);

  // serial write section

  //char ard_sends = '1';
  //Serial.print("Arduino sends: ");
  //Serial.println(ard_sends);
  //Serial.print("\n");
  Serial.flush();      
    
 
 //setnum(2400);
 //setnum(3411);
  //char b[]={'a','b','c','d'};
  //String str(b);
  //Serial.println(b);
  //delay(2000);
    
    }
    


 
