#include <Keyboard.h>       // Biblioteca para simular teclado (HID)

const int Pot = A1;         // Potenciômetro no pino A1
int valPot;                 // Valor lido do potenciômetro

void setup() {
  Serial.begin(9600);       // Para monitoramento
  pinMode(Pot, INPUT);
  Keyboard.begin();         // Inicia modo teclado HID
}

void loop() {
  valPot = analogRead(Pot);  // Lê o valor do potenciômetro (0 a 1023)
  Serial.println(valPot);    // Mostra o valor no monitor serial

  if (valPot < 500) {
    // Mapeia o valor para um delay entre 50 e 1000 ms
    int pressDelay = map(valPot, 0, 499, 50, 1000);

    // Pressiona e solta a tecla 'r'
    Keyboard.press('r');
    delay(50);               // Tempo segurando a tecla
    Keyboard.release('r');

    delay(pressDelay);       // Tempo entre pressões
  } else {
    delay(100);              // Não pressiona nada, só aguarda
  }
}
