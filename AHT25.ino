//      Test fuer AHT25 
#include <Wire.h>                      // I2C-Bibliothek
#include <Adafruit_Sensor.h>         // Adafruit Unified Sensor 
#include <Adafruit_AHTX0.h>        // Hauptbibliothek für AHT25

Adafruit_AHTX0 aht;              // Sensorobjekt anlegen

void setup() {
  Serial.begin(9600);
  Serial.println("AHT25: Initialisierung...");

  Wire.begin();            // I2C starten

  // Sensor initialisieren; gibt false zurueck, wenn keine Antwort kommt
  if (!aht.begin()) {
    Serial.println("Fehler: AHT25 nicht gefunden (I2C)!");
    // Kein endloses Stoppen -> wir laufen weiter, um Kompilierung/Upload zu testen
  } else {
    Serial.println("AHT25 erfolgreich initialisiert.");
  }
}

void loop() {
  sensors_event_t hum, temp;          // Mess-Container
  if (aht.getEvent(&hum, &temp)) {
    Serial.print("Temperatur: ");
    Serial.print(temp.temperature);
    Serial.println(" *C");

    Serial.print("Luftfeuchtigkeit: ");
    Serial.print(hum.relative_humidity);
    Serial.println(" %RH");
  } else {
    Serial.println("Hinweis: Keine Messung verfuegbar (Sensor nicht angeschlossen?).");
  }
  delay(2000);
}
