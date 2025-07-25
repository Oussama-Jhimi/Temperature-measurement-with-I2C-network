#include <Wire.h>
#include <Adafruit_AHTX0.h>

// Création de l'objet capteur
Adafruit_AHTX0 aht;
const int motorPin1 = 9;
void setup() {
  // Initialisation de la communication série
  Serial.begin(9600);
  pinMode(motorPin1, OUTPUT);
  // Initialisation du capteur AHT10
  if (!aht.begin()) {
    Serial.println("Impossible de trouver un AHT10, vérifiez vos connexions !");
    while (1);
  }
  Serial.println("AHT10 capteur de température et d'humidité initialisé.");
}

void loop() {
  // Lecture des valeurs du capteur
  sensors_event_t humidity, temp;
  aht.getEvent(&humidity, &temp);

  // Affichage des valeurs
  Serial.print("Température: ");
  Serial.print(temp.temperature);
  Serial.println(" °C");

  // Ajoutez ici des actions de contrôle basées sur la température lue, par exemple :
  if (temp.temperature > 31.0) {
    // Action à entreprendre si la température dépasse 25°C
    digitalWrite(motorPin1, 1);
  }
  else if (temp.temperature < 30) {
    // Action à entreprendre si la température dépasse 25°C
    digitalWrite(motorPin1, 0);
  }

  // Pause de 2 secondes avant la prochaine lecture
  delay(2000);
}
