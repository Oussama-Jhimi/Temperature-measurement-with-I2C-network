#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Adresse I2C de l'Arduino (esclave)
#define SLAVE_ADDRESS 0x08

// Initialisation du module LCD (adresse I2C 0x27, écran 16x2)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Initialisation de la communication série
  Serial.begin(115200);

  // Initialisation du bus I2C
  Wire.begin(); // ESP32 en maître
  Serial.println("ESP32 configuré comme maître I2C.");

  // Initialisation de l'écran LCD
  lcd.begin(16, 2);
  lcd.backlight(); // Active le rétroéclairage
  lcd.setCursor(0, 0);
  lcd.print("Initialisation...");
  delay(2000);
}

void loop() {
  // Demander des données à l'Arduino
  Wire.requestFrom(SLAVE_ADDRESS, 16); // Taille max du message attendu (16 octets)

  // Lire les données envoyées par l'Arduino
  String receivedData = "";
  while (Wire.available()) {
    char c = Wire.read();
    receivedData += c;
  }

  // Décoder les données reçues
  float temperature = 0.0, humidity = 0.0;
  if (sscanf(receivedData.c_str(), "%f,%f", &temperature, &humidity) == 2) {
    // Affichage des données dans la console série
    Serial.print("Température: ");
    Serial.print(temperature);
    Serial.println(" °C");
    Serial.print("Humidité: ");
    Serial.print(humidity);
    Serial.println(" %");

    // Affichage des données sur l'écran LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(temperature, 1); // Affiche 1 décimale
    lcd.print("C");

    lcd.setCursor(0, 1);
    lcd.print("Hum: ");
    lcd.print(humidity, 1); // Affiche 1 décimale
    lcd.print("%");
  } else {
    Serial.println("Erreur de réception des données !");
  }

  delay(2000); // Pause avant la prochaine interrogation
}
