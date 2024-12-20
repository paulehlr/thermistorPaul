Thermistor Library for Temperature Measurement

Overview

This project implements a custom thermistor library for accurate temperature measurement using Arduino or similar microcontrollers. The library provides a simple interface to calculate temperature based on ADC (Analog-to-Digital Converter) readings from a thermistor circuit.

Features

Easy-to-use Thermistor class
Support for different temperature units (Kelvin, Celsius, Fahrenheit)
Customizable thermistor parameters
Accurate temperature calculation using the Beta parameter model

Library Structure

The library consists of two main files:
  thermistor.h: Header file containing the Thermistor class declaration
  thermistor.cpp: Implementation file with the Thermistor class methods

Customization

You can customize the thermistor parameters in the constructor to match your specific thermistor and circuit setup:
  Rref: Reference resistor value in ohms
  R0: Thermistor resistance at reference temperature (usually 25°C) in ohms
  Beta: Beta coefficient of the thermistor
  samplingBitsNumber: ADC resolution (default 10 bits for most Arduino boards)
  Vcc: Supply voltage (default 5V)
  T0: Reference temperature in Kelvin (default 298.15K, which is 25°C)
