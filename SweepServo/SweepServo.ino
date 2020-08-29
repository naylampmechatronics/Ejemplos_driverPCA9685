/****************************************************************************************
 Sweep Servo
 
  Este ejemplo se hace una barrido de 0 a 180° y después de 180° a 0°, el barrido se hace a todos los servos por igual.
 
 Conexiones:
  ------------------------------------------------------------------------
  PCA9685  -> Arduino Uno,Nano,Mini | Arduino Mega,DUE | Arduino Leonardo
  ------------------------------------------------------------------------
  GND      ->   GND                 |   GND            |   GND
  OE       ->   GND                 |   GND            |   GND
  SCL      ->   A5                  |   21             |   3
  SDA      ->   A4                  |   20             |   2 
  VCC      ->   5V                  |   5V             |   5V
  +V      ->    NC                  |   NC             |   NC 
  ------------------------------------------------------------------------
  *No se puede cambiar de pines, los pines indicados son para la comunicación I2C 
   y son los pines SDA y SCL de cada placa respectivamente

 Dirección del módulo I2C:
  Por defecto 0x40 (01000000) o establecer por hardware : 0|1|A5|A4|A3|A2|A1|A0 
  
 Ejemplo desarrollado por Naylamp Mechatronics bajo licencia MIT (puede copiar, modificar, integrar o redistribuir)
 
 Última modificación el 28/08/2020

 Requiere librería: https://github.com/adafruit/Adafruit-PWM-Servo-Driver-Library

 Más información en:
   -https://naylampmechatronics.com/blog/41_Tutorial-M%C3%B3dulo-Controlador-de-servos-PCA9685.html
   -https://github.com/naylampmechatronics/Ejemplos_driverPCA9685

**************************************************************************************************/
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver servos = Adafruit_PWMServoDriver(0x40);

unsigned int pos0=172; // ancho de pulso en cuentas para posición 0°
unsigned int pos180=565; // ancho de pulso en cuentas para la posición 180°

void setup() {
  servos.begin();  
  servos.setPWMFreq(60); //Frecuencia PWM de 60Hz o T=16,66ms
}


void loop() {
  
  for (int duty = pos0; duty < pos180; duty=duty+10) {
    for(int n=0;n<16;n++)
    {
      servos.setPWM(n,0,duty);
    }   
  }
  delay(1000);
  for (int duty = pos180; duty > pos0; duty=duty-10) {
    for(int n=0;n<16;n++)
    {
      servos.setPWM(n,0,duty);
    }   
  }
  delay(1000);
}
