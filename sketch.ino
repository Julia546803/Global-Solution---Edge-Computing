#include <DHT.h>
#include <LiquidCrystal.h>

#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

// LCD
LiquidCrystal lcd(7, 8, 3, 4, 5, 6);

// SENSORES
const int ldrPin = A0;
const int sensorSolo = A1;

// LEDS
const int greenLed = 9;
const int yellowLed = 10;
const int redLed = 11;
const int buzzer = 12;
const int irrigador = 13; // LED AZUL

bool jaApitou = false;

void setup() {

  pinMode(greenLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(irrigador, OUTPUT);

  Serial.begin(9600);

  dht.begin();

  lcd.begin(16, 2);

  lcd.setCursor(3, 0);
  lcd.print("Orbit Agro");

  lcd.setCursor(0, 1);
  lcd.print("Inicializando!!!");

  delay(3000);
  lcd.clear();
}

void loop() {

  // LEITURA DOS SENSORES
  int ldrValue = analogRead(ldrPin);
  int leituraSolo = analogRead(sensorSolo);

  // SIMULA A UMIDADE DO SOLO
  float umidadeSolo = 100 - (leituraSolo * 100.0 / 1023.0);

  float temperatura = dht.readTemperature();
  float umidadeAr = dht.readHumidity();

  if (isnan(temperatura) || isnan(umidadeAr)) {
    temperatura = 0;
    umidadeAr = 0;
  }

  // CLASSIFICAÇÃO DO SOLO
  String statusSolo;

  if (umidadeSolo < 20) {
    statusSolo = "SECO";
  } 
  else if (umidadeSolo <= 60) {
    statusSolo = "IDEAL";
  } 
  else if (umidadeSolo <= 70) {
    statusSolo = "UMIDO";
  } 
  else {
    statusSolo = "EXCESSO";
  }

  // CLASSIFICAÇÃO DA TEMPERATURA
  String statusTemp;

  if (temperatura < 20) {
    statusTemp = "Baixa";
  }
  else if (temperatura <= 30) {
    statusTemp = "Ideal";
  }
  else {
    statusTemp = "Alta";
  }

  // CLASSIFICAÇÃO DA LUZ
  String statusLuz = "";

  if (ldrValue > 600) {
    statusLuz = "BAIXA";
  }
  else if (ldrValue > 400) {
    statusLuz = "IDEAL";
  }
  else {
    statusLuz = "ALTA";
  }

  // CONTROLE DOS LEDS
  if (statusSolo == "SECO") {

    digitalWrite(redLed, HIGH);
    digitalWrite(yellowLed, LOW);
    digitalWrite(greenLed, LOW);

    // LIGA IRRIGAÇÃO
    digitalWrite(irrigador, HIGH);

    // APITA O BUZZER
    if (!jaApitou) {

      tone(buzzer, 1000);
      delay(300);
      noTone(buzzer);

      jaApitou = true;
    }
  }

  else if (statusSolo == "IDEAL") {

    digitalWrite(redLed, LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(greenLed, HIGH);

    digitalWrite(irrigador, LOW);

    jaApitou = false;
  }

  else if (statusSolo == "UMIDO") {
    digitalWrite(redLed, LOW);
    digitalWrite(yellowLed, HIGH);
    digitalWrite(greenLed, LOW);

    digitalWrite(irrigador, LOW);

    jaApitou = false;
  }

  else {

    digitalWrite(redLed, HIGH);
    digitalWrite(yellowLed, LOW);
    digitalWrite(greenLed, LOW);

    digitalWrite(irrigador, LOW);

    jaApitou = false;
  }


  // SERIAL MONITOR
  Serial.print("LDR: ");
  Serial.print(ldrValue);

  Serial.print(" | Solo: ");
  Serial.print(umidadeSolo);
  Serial.print("%");

  Serial.print(" | Temperatura: ");
  Serial.print(temperatura);
  Serial.print("C");

  Serial.print(" | Ar: ");
  Serial.print(umidadeAr);
  Serial.println("%");

  // LCD - TELA PRINCIPAL
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Solo:");
  lcd.print((int)umidadeSolo);
  lcd.print("%");

  lcd.setCursor(0, 1);

  if (statusSolo == "SECO") {
    if (statusLuz == "ALTA") {
      lcd.print("Irrig.Imediato");

    } else {
      lcd.print("Irrigando...");
    }
  } 

  else if (statusSolo == "IDEAL") {
    lcd.print("Solo Ideal");
  } 
  
  else if (statusSolo == "UMIDO") {
    lcd.print("Solo Umido");
  } 
  
  else {
    lcd.print("Excesso Agua");
  }

  delay(3000);

  // LCD - TELA STATUS DO AMBIENTE
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.print((int)temperatura);
  lcd.print("C - ");
  lcd.print(statusTemp);

  lcd.setCursor(0, 1);

  lcd.print("Ar:");
  lcd.print((int)umidadeAr);
  lcd.print("% Luz:");

  if (statusLuz == "BAIXA") {
    lcd.print("Baixa");
  }
  else if (statusLuz == "IDEAL") {
    lcd.print("Ideal");
  }
  else {
    lcd.print("Alta");
  }

  delay(5000);
}