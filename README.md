# Digital Resistor Meter Using Arduino & LCD

This project is a simple **digital resistor meter** built using an **Arduino**, a **16×2 LCD**, and a **voltage divider circuit**. It measures the value of an unknown resistor and displays it in **ohms or kilo-ohms** on the LCD screen.

---
## Working Principle

The unknown resistor is connected in series with a known resistor to form a **voltage divider**. The Arduino reads the output voltage from the divider using an analog pin. Based on this voltage, the value of the unknown resistor is calculated and displayed on the LCD.

To improve stability and reduce noise, multiple analog readings are averaged before performing the calculation.

---
## Formula Used

This project works on the **Voltage Divider Principle**.

Let:

* ( V_{in} ) = Input Voltage (5V)
* ( R_2 ) = Known Resistor (470Ω)
* ( R_1 ) = Unknown Resistor
* ( V_{out} ) = Output Voltage

### Voltage Divider Equation:

[
V_{out} = V_{in} \times \frac{R_2}{R_1 + R_2}
]

Rearranging to find the unknown resistance:
[
R_1 = R_2 \times \left(\frac{V_{in}}{V_{out}} - 1\right)
]

---
### Arduino ADC Voltage Conversion:

Since Arduino has a 10-bit ADC:
[
V_{out} = \frac{\text{Analog Reading} \times V_{in}}{1024}
]

---
### Final Formula Used in Code:

[
R_1 = 470 \times \left(\frac{5}{V_{out}} - 1\right)
]

--
## Components Used

* Arduino Uno
* 16×2 LCD Display
* 470Ω Known Resistor
* Breadboard
* Jumper Wires
* Unknown Resistor

---
## Features

* Automatic resistance measurement
* Displays values in **Ohms** and **Kilo-ohms**
* Stable output using analog averaging
* User-friendly LCD display

---
## Applications

* Electronics laboratory experiments
* Educational demonstrations
* Quick testing of resistors
* Mini project for ECE students

---
## Author- Dhruv Khodke 

Developed as an Arduino mini project for understanding **voltage division and resistance measurement**.

Hawk Codes in Hardware!
