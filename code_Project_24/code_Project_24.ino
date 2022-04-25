/*
 By:Farkad Adnan
 E-mail: farkad.hpfa95@gmail.com
 inst : farkadadnan
 #farkadadnan , #farkad_adnan , فرقد عدنان#
 FaceBook: كتاب عالم الاردوينو
 inst : arduinobook
 #كتاب_عالم_الاردوينو  #كتاب_عالم_الآردوينو 
 */
#include <Servo.h>

Servo servohori;
Servo servoverti; 

int servoh = 0;
int servohLimitHigh = 160;
int servohLimitLow = 60;

int servov = 0; 
int servovLimitHigh = 160;
int servovLimitLow = 60;

int ldrtopl = 2; //top left 
int ldrtopr = 1; //top right 
int ldrbotl = 3; // bottom left 
int ldrbotr = 0; // bottom right 

 void setup () {
  servohori.attach(10);
  servohori.write(60);
  servoverti.attach(9);
  servoverti.write(60);
  Serial.begin(9600);
  delay(500);
 }
void loop(){
  servoh = servohori.read();
  servov = servoverti.read();
   int topl = analogRead(ldrtopl);
  int topr = analogRead(ldrtopr);
  int botl = analogRead(ldrbotl);
  int botr = analogRead(ldrbotr);

  int avgtop = (topl + topr) ;  
  int avgbot = (botl + botr) ; 
  int avgleft = (topl + botl) ;
  int avgright = (topr + botr) ; 

  if (avgtop < avgbot){
    servoverti.write(servov +1);
    if (servov > servovLimitHigh) { 
      servov = servovLimitHigh;
     }
    delay(10);
  }
  else if (avgbot < avgtop){
    servoverti.write(servov -1);
    if (servov < servovLimitLow){
    servov = servovLimitLow;
  }
    delay(10);
  }
  else {
    servoverti.write(servov);
  }
  
  if (avgleft > avgright){
    servohori.write(servoh +1);
    if (servoh > servohLimitHigh)
    {
    servoh = servohLimitHigh;
    }
    delay(10);
  }
  else if (avgright > avgleft){
    servohori.write(servoh -1);
    if (servoh < servohLimitLow)
     {
     servoh = servohLimitLow;
     }
    delay(10);
  }
  else {
    servohori.write(servoh);
  }
  delay(50);
}
