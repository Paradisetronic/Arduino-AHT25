// Testprogramm für den AHT25-Temperatur- und Luftfeuchtigkeitssensor
#include <Wire.h>              // I2C-Bibliothek für die Kommunikation
#include <Adafruit_Sensor.h>   // Adafruit Unified Sensor-Basisbibliothek
#include <Adafruit_AHTX0.h>    // Hauptbibliothek für den AHT20/AHT21/AHT25-Sensor

// Sensorobjekt anlegen
Adafruit_AHTX0 aht;

void setup() {
  Serial.begin(9600);                     // Serielle Kommunikation starten
  Serial.println("AHT25: Initialisierung...");

  Wire.begin();                           // I2C starten

  // Versuch, den Sensor zu initialisieren
  if (!aht.begin()) {
    Serial.println("Fehler: AHT25 nicht gefunden (I2C)!");
    // Kein Abbruch, um Upload/Debugging trotzdem zu ermöglichen
  } else {
    Serial.println("AHT25 erfolgreich initialisiert.");
  }
}

void loop() {
  // Container für Messwerte
  sensors_event_t hum, temp;

  // Messung ausführen und Ergebnisse auslesen
  if (aht.getEvent(&hum, &temp)) {
    Serial.print("Temperatur: ");
    Serial.print(temp.temperature);
    Serial.println(" °C");

    Serial.print("Luftfeuchtigkeit: ");
    Serial.print(hum.relative_humidity);
    Serial.println(" %RH");
  } else {
    Serial.println("Hinweis: Keine Messung verfügbar (Sensor nicht angeschlossen?).");
  }

  delay(2000);  // 2 Sekunden Pause bis zur nächsten Messung
}




