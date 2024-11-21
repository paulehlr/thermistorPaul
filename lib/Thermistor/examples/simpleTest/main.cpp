#include <Arduino.h>
#include "thermistor.h"

// Constants for thermistor calculations
const double Rref = 50000;      // Reference resistor value in ohms
const double R0 = 47000;        // Thermistor resistance at 25°C in ohms
const double Beta = 3750;      // Beta coefficient of the thermistor
const unsigned samplingBits = 10; // ADC resolution in bits
const int thermistorPin = A1;  // Analog pin connected to the thermistor

// Create a Thermistor object with the specified parameters
Thermistor thermistor(Rref, R0, Beta, samplingBits);

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  // Set thermistor pin as input
  pinMode(thermistorPin, INPUT);
}

void loop() {
  // Read the analog value from the thermistor
  int adcValue = analogRead(thermistorPin);
  
  // Calculate temperature in Celsius using the Thermistor object
  double tempC = thermistor.getTemperature(adcValue, 'C');
  
  // Print ADC value and temperature to serial monitor
  Serial.print("Valeur ADC : ");
  Serial.println(adcValue);
  Serial.print("Température : ");
  Serial.print(tempC);
  Serial.println(" °C");
  
  // Wait for 5 seconds before next reading
  delay(5000); 
}