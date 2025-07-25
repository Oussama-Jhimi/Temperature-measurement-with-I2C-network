#include <Wire.h>
#include <Adafruit_AHTX0.h>

// Création de l'objet capteur
Adafruit_AHTX0 aht;

// Adresse I2C de l'Arduino (esclave)
#define SLAVE_ADDRESS 0x08

float temperature = 0.0, humidity = 0.0;

void setup() {
  // Initialisation de la communication série
  Serial.begin(9600);

  // Initialisation du capteur AHT10
  if (!aht.begin()) {
    Serial.println("Impossible de trouver un AHT10, vérifiez vos connexions !");
    while (1);
  }
  Serial.println("AHT10 initialisé.");

  // Initialisation en tant qu'esclave I2C
  Wire.begin(SLAVE_ADDRESS);
  Wire.onRequest(sendData); // Appelé lorsqu'une donnée est demandée par le maître

  Serial.println("Arduino configuré comme esclave I2C.");
}

void loop() {
  // Lecture des valeurs du capteur
  sensors_event_t humidityEvent, tempEvent;
  aht.getEvent(&humidityEvent, &tempEvent);

  // Stockage des données dans des variables globales
  temperature = tempEvent.temperature;
  humidity = humidityEvent.relative_humidity;

  // Affichage des valeurs dans la console série
  Serial.print("Température: ");
  Serial.print(temperature);
  Serial.println(" °C");
  Serial.print("Humidité: ");
  Serial.print(humidity);
  Serial.println(" %");

  delay(2000); // Pause avant la prochaine lecture
}

// Fonction appelée lorsque l'ESP32 demande des données
void sendData() {
  // Envoi des données sous forme de chaîne formatée
  String data = String(temperature, 1) + "," + String(humidity, 1); // Exemple: "25.3,60.2"
  Wire.write(data.c_str()); // Envoi des données au maître
}
