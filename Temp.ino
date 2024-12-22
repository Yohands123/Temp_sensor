#include <DHT.h>

// Define the pin connected to the "S" (Signal) pin of the sensor
#define DHTPIN 2  // Digital pin 2
#define DHTTYPE DHT11  // DHT11 sensor type

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Start Serial Monitor for debugging
  Serial.begin(9600);
  Serial.println("Initializing DHT Sensor...");
  
  // Start the DHT sensor
  dht.begin();
}

void loop() {
  // Wait 2 seconds between sensor readings
  delay(2000);

  // Read temperature
  float temperature = dht.readTemperature(); // Temperature in Celsius

  // Check if the sensor reading failed
  if (isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print the temperature value to Serial Monitor
  Serial.print("Current Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  // Check if the temperature exceeds 26°C
  if (temperature > 26.0) {
    // Print notification to Serial Monitor
    Serial.println("ALERT: Temperature is above 26°C!");
  }
}
