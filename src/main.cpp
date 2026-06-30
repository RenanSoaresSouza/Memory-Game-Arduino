#include <Arduino.h>

// constante dos pinos dos leds
#define REDpin 2
#define YELLOWpin 3
#define BLUEpin 4
#define GREENpin 5

// usando lista simplesmente encadeada como modelo para armazenamento dos rounds do jogo da memória
typedef struct Round {
  int data;
  struct Round *next;

} Round;


class Game {
  private:
    Round *current =(Round*)malloc(sizeof(Round));
  public:
    Game(){
      int data = random(2,6);
      this->current->data = data;
      this->current->next = NULL;

    }
    int nextround(){
      int data = random(2,6);
      Round *aux = this->current;
      Round *round =(Round*)malloc(sizeof(Round));
      if (round == NULL) return -1; // verifica se tem espaço para ser alocado

      while (aux && aux->next){
        aux = aux->next;
      }
      round->data = data;
      round->next = NULL;
      aux->next = round;
      return 0; // inserido com sucesso

    }
    int Input(int data){
      if (this->current->data == data){
        return 1;
      } else {
        return 0;
      }
    }
    void showgame(){
      Round *aux = this->current;
      while(aux){
        int data =(int)aux->data;
        Serial.print(data);
        aux = aux->next;
      }
    }
};

void setup() {
  randomSeed(analogRead(A0));
  pinMode(REDpin,OUTPUT);
  pinMode(YELLOWpin,OUTPUT);
  pinMode(BLUEpin,OUTPUT);
  pinMode(GREENpin,OUTPUT);
  Serial.begin(115200);

}

void loop() {
}

