#include <Servo.h>

//#include <SoftwareSerial.h>
//#define RX 6
//#define TX 7
//SoftwareSerial hc06(RX,TX); 

#define tv 8
#define clim 9 
#define lamp 10
#define porte 7

Servo door ;

String data ;
char etat;
int pos = 0;


void setup() {
 // hc06.begin(9600);
  Serial.begin(9600);
  door.attach(porte);
  door.write(pos);
  pinMode( tv , OUTPUT);
  pinMode( clim , OUTPUT);
  pinMode( lamp , OUTPUT);
 

}

void loop() {

    if(Serial.available()>0){
      etat = Serial.read();

      if (etat == 'o')  //allume la tv
      {
          digitalWrite(tv, HIGH);
          //Serial.write(data);
      }

      if (etat == 'k')  //éteins la tv
      {
          digitalWrite(tv,LOW);
      }

      if (etat == 'a' )  //allume la lampe
      {
          digitalWrite(lamp, HIGH);
      }

      if (etat == 'b')  //eteins la lampe
      {
          digitalWrite(lamp,LOW);
      }

      if (etat == 'e' )  //allume la clim
      {
          digitalWrite(clim, HIGH);
      }

      if (etat == 'f')  //eteins la clim
      {
          digitalWrite(clim,LOW);
      }

      if (etat == 'p' )  //ouvre la porte
      {
          for(pos=0; pos<=180; pos++)
          {
              door.write(pos);
              delay(10);
          }
      }

      if (etat == 'q')  //ferme la porte
      {
          for(pos=180; pos>00; pos--)
          {
              door.write(pos);
              delay(10);
          }
      }
      
      if (etat == 'y' ) // allumer tout 
      {
          digitalWrite(tv,1);
          digitalWrite(clim,1); 
          digitalWrite(lamp,1);
      }
      if (etat == 'z' ) //éteindre tout
      {
          digitalWrite(tv,0);
          digitalWrite(lamp,0);
          digitalWrite(clim,0);
      }
     
    }
    
  Serial.flush();
}
