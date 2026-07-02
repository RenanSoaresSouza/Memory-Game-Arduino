#include <Arduino.h>

// constante dos pinos dos leds
#define REDpin 2
#define YELLOWpin 5
#define BLUEpin 4
#define GREENpin 3
#define BUTTONaction 8
#define Buzzer 6
//constante do Input dos Botoes

// usando lista simplesmente encadeada como modelo para armazenamento dos rounds do jogo da memória


class Game {
  private:
    int round[100];
    int tam = 0;
  public:
    Game(){
      int data = random(2,6);
      round[0] = data;
      tam++;

    }
    int verify(){
      digitalWrite(BUTTONaction,HIGH);
      pinMode(REDpin,INPUT);
      pinMode(GREENpin,INPUT);
      pinMode(BLUEpin,INPUT);
      pinMode(YELLOWpin,INPUT);
      
      int data = -1;
      for (int x=0;x<tam;x++){
        data = -1;
        while (data == -1){
          if (digitalRead(REDpin) == 1){
            data = REDpin;
          }
          else if (digitalRead(BLUEpin) == 1){
            data = BLUEpin;
          }
          else if (digitalRead(GREENpin) == 1){
            data = GREENpin;
          }
          else if (digitalRead(YELLOWpin) == 1){
            data = YELLOWpin;
          }
          if (data > 0){
            //digitalWrite(Buzzer,HIGH);
            while(digitalRead(REDpin)    || 
                  digitalRead(GREENpin)  ||
                  digitalRead(YELLOWpin) || 
                  digitalRead(BLUEpin));
            delay(50);
            //digitalWrite(Buzzer,LOW);
            if (data == round[x]){
              break;
            } else {
              return -1;
            }
          }
        }
      }
      digitalWrite(BUTTONaction,LOW);
      return 0;
    }
    int nextround(){
      int data = random(2,6);
      if (tam == 100){
        return -1;
      }
      round[tam] = data;
      tam++;
    
      return 0; // inserido com sucesso

    }
    void showgame(){
      pinMode(REDpin,OUTPUT);
      pinMode(GREENpin,OUTPUT);
      pinMode(BLUEpin,OUTPUT);
      pinMode(YELLOWpin,OUTPUT);
      for(int x =0; x<tam;x++){
        int data =round[x];
        Serial.print(data);
        //digitalWrite(Buzzer,HIGH);
        digitalWrite(data,HIGH);
        delay(200);
        digitalWrite(data,LOW);
        //digitalWrite(Buzzer,LOW);
        delay(200);
      }
    }
    void lose(){
      pinMode(REDpin,OUTPUT);
      pinMode(BLUEpin,OUTPUT);
      pinMode(GREENpin,OUTPUT);
      pinMode(YELLOWpin,OUTPUT);
        for (int x=0;x<10;x++){
          digitalWrite(Buzzer,HIGH);
          digitalWrite(REDpin,HIGH);
          digitalWrite(GREENpin,HIGH);
          digitalWrite(BLUEpin,HIGH);
          digitalWrite(YELLOWpin,HIGH);
          delay(100);
          digitalWrite(Buzzer,LOW);
          digitalWrite(REDpin,LOW);
          digitalWrite(GREENpin,LOW);
          digitalWrite(BLUEpin,LOW);
          digitalWrite(YELLOWpin,LOW);
          delay(100);
        }
    }
};
void setup() {
  randomSeed(analogRead(A0));
  pinMode(BUTTONaction,OUTPUT);
  //pinMode(Buzzer,OUTPUT);
  Serial.begin(115200);
}

void loop() {
Game game = Game();
int data = 0;
  while (data == 0){
    delay(1000);
    game.showgame();
    data = game.verify();
    if (data == 0){
      game.nextround();
    }
  }
  game.lose();
}

