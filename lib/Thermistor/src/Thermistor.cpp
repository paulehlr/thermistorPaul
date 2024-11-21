#include "thermistor.h"
#include <math.h>

// Constructor for the Thermistor class
Thermistor::Thermistor(double Rref, double R0, double Beta, 
                       unsigned samplingBitsNumber, double Vcc, double T0) {
    // Initialize class members with provided values
    this->Rref = Rref;
    this->R0 = R0;
    this->Beta = Beta;
    this->samplingBitsNumber = samplingBitsNumber;
    this->Vcc = Vcc;
    this->T0 = T0;
}

// Method to calculate temperature based on ADC value
double Thermistor::getTemperature(double adc, char unit)
{
    // Calculate maximum possible ADC value: 2^n - 1
    double Adc = pow(2, samplingBitsNumber) - 1;

    // Apply the general formula to calculate temperature in Kelvin
    double tempK = 1.0 / ((1.0 / T0) +
                          (1.0 / Beta) *log((R0 * (Adc / adc - 1)) / Rref));
    
    // Convert to Celsius if requested
    if (unit == 'C') 
    {
        return tempK - ZERO_CELSIUS; 
    }
    // Convert to Fahrenheit if requested
    else if (unit == 'F') {
        return (tempK - ZERO_CELSIUS) * 9/5 + 32;
    }

    // Return temperature in Kelvin by default
    return tempK;
}