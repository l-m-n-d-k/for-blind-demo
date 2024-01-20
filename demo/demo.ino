#include <NewPing.h>

#define N 2
#define NE 3
#define E 4
#define SE 5
#define S 6
#define SW 7
#define W 8
#define NW 9  

#define forword_sensor A0
#define up_sensor A1
#define right_sensor A2
#define left_sensor A3
#define back_sensor A4

#define MAX_DISTANCE 200 // Изменено максимальное расстояние на 2 метра

NewPing sonar_sensors[] = {
  NewPing(forword_sensor, forword_sensor, MAX_DISTANCE),
  NewPing(right_sensor, right_sensor, MAX_DISTANCE),
  NewPing(left_sensor, left_sensor, MAX_DISTANCE),
  NewPing(back_sensor, back_sensor, MAX_DISTANCE),
  NewPing(up_sensor, up_sensor, MAX_DISTANCE),
};

void setup() {
  Serial.begin(9600);
  
  pinMode(N, OUTPUT);
  pinMode(NE, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(SE, OUTPUT);
  pinMode(S, OUTPUT);
  pinMode(SW, OUTPUT);
  pinMode(W, OUTPUT);
  pinMode(NW, OUTPUT);
  
  start();
}

void start() {
  int dly = 300;
  
  digitalWrite(N, HIGH);
  delay(dly);
  digitalWrite(N, LOW);
  digitalWrite(NE, HIGH);
  delay(dly);
  digitalWrite(NE, LOW);
  digitalWrite(E, HIGH);
  delay(dly);
  digitalWrite(E, LOW);
  digitalWrite(SE, HIGH);
  delay(dly);
  digitalWrite(SE, LOW);
  digitalWrite(S, HIGH);
  delay(dly);
  digitalWrite(S, LOW);
  digitalWrite(SW, HIGH);
  delay(dly);
  digitalWrite(SW, LOW);
  digitalWrite(W, HIGH);
  delay(dly);
  digitalWrite(W, LOW);
  digitalWrite(NW, HIGH);
  delay(dly);
  digitalWrite(NW, LOW);
}

void loop() {
  for (int i = 0; i < sizeof(sonar_sensors) / sizeof(sonar_sensors[0]); i++) {
    unsigned int distanceSm = sonar_sensors[i].ping();
    
    // Добавляем логику включения светодиодов в зависимости от расстояния
    
    // Для forword_sensor 
    if (i == 0 && distanceSm < 200) {
      digitalWrite(N, HIGH);
    }
    else {
        digitalWrite(N, LOW);
    }
    
    // Для right_sensor 
   	if (i == 1 && distanceSm < 200) {
      digitalWrite(E, HIGH);
    }
    else {
        digitalWrite(E, LOW);
    
    // Для left_sensor 
   	if (i == 2 && distanceSm < 200) {
      digitalWrite(W, HIGH);
    }
    else {
        digitalWrite(W, LOW);
      
    // Для back_sensor 
   	if (i == 3 && distanceSm < 200) {
      digitalWrite(S, HIGH);
    }
    else {
        digitalWrite(S, LOW);
    
   	// Для up_sensor 
   	if (i == 4 && distanceSm < 200) {
      digitalWrite(NE, HIGH);
      digitalWrite(SE, HIGH);
      digitalWrite(SW, HIGH);
      digitalWrite(NW, HIGH);
      delay(100);
      digitalWrite(NE, LOW);
      digitalWrite(SE, LOW);
      digitalWrite(SW, LOW);
      digitalWrite(NW, LOW);
      delay(100);
      digitalWrite(NE, HIGH);
      digitalWrite(SE, HIGH);
      digitalWrite(SW, HIGH);
      digitalWrite(NW, HIGH);
      delay(100);
      digitalWrite(NE, LOW);
      digitalWrite(SE, LOW);
      digitalWrite(SW, LOW);
      digitalWrite(NW, LOW);
    }
    else {
      digitalWrite(NE, LOW);
      digitalWrite(SE, LOW);
      digitalWrite(SW, LOW);
      digitalWrite(NW, LOW);
    }
    
    
    delay(50); // Задержка в 50 мс между генерируемыми волнами. 29 мс – минимально допустимое значение
  }
}
