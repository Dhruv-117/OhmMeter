#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int sensorPin = A0;
const float inputVoltage = 5.0;
const float knownResistor = 470.0;

int analogValue = 0;
float outputVoltage = 0.0;
float unknownResistance = 0.0;

int readStableAnalog(int pin, int samples = 10) {
  long total = 0;
  for (int i = 0; i < samples; i++) {
    total += analogRead(pin);
    delay(5);
  }
  return total / samples;
}

void setup() {
  lcd.begin(16, 2);
  lcd.print("Resistor Meter");
  delay(1500);
  lcd.clear();
}

void loop() {
  analogValue = readStableAnalog(sensorPin);

  if (analogValue > 0) {
    outputVoltage = (analogValue * inputVoltage) / 1024.0;

    if (outputVoltage > 0.9) {
      float ratio = (inputVoltage / outputVoltage) - 1.0;
      unknownResistance = knownResistor * ratio;

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("  - Resistance -");
      lcd.setCursor(0, 1);

      if (unknownResistance >= 1000.0) {
        lcd.print("   ");
        lcd.print(unknownResistance / 1000.0, 2);
        lcd.print(" K ohm");
      } else {
        lcd.print("    ");
        lcd.print(unknownResistance, 0);
        lcd.print(" ohm");
      }
    } else {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(" Measuring...");
      lcd.setCursor(0, 1);
      lcd.print(" Insert Resistor ");
    }
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Insert Resistor");
  }

  delay(1500);
}
