/****************************************************************************************
Different Servos  
 
  Para controlar servos que tienen trabajan con diferente ancho de pulso, podemos mover cada servo a un ángulo de 0 a 180 grados
 
 Conexiones:
  ------------------------------------------------------------------------
  PCA9685  -> Arduino Uno,Nano,Mini | Arduino Mega,DUE | Arduino Leonardo
  ------------------------------------------------------------------------
  GND      ->   GND                 |   GND            |   GND
  OE       ->   GND                 |   GND            |   GND
  SCL      ->   A5                  |   21             |   3
  SDA      ->   A4                  |   20             |   2 
  VCC      ->   5V                  |   5V             |   5V
  +V       ->    NC                  |   NC             |   NC 
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

// anchos de pulso en cuentas para posición 0° y 180°
unsigned int pos0[16]=  {172,172,172,246,246,172,246,200,200,150,160,172,172,172,200,246}; 
unsigned int pos180[16]={565,256,256,492,492,565,492,550,550,600,590,565,565,565,550,492}; 

void setup() {
  servos.begin();  
  servos.setPWMFreq(60); //Frecuencia PWM de 60Hz o T=16,66ms
}

void setServo(uint8_t n_servo, int angulo) {
  int duty;
  duty=map(angulo,0,180,pos0[n_servo], pos180[n_servo]);
  servos.setPWM(n_servo, 0, duty);  
}

void loop() {
  
    setServo(0,30); //Mover servo 0 a un ángulo 30°
    setServo(2,90);
    setServo(4,180);
    setServo(6,120);
    setServo(8,0);
    setServo(10,30);
    setServo(12,90);
    setServo(14,180);
    delay(1000);
    setServo(1,30);
    setServo(3,90);
    setServo(5,180);
    setServo(7,120);
    setServo(9,30);
    setServo(11,90);
    setServo(13,180);
    setServo(15,120);
    delay(1000);
    setServo(0,45);
    setServo(2,180);
    setServo(4,90);
    setServo(6,60);
    setServo(8,45);
    setServo(10,160);
    setServo(12,180);
    setServo(14,0);
    delay(1000);
    setServo(1,120);
    setServo(3,0);
    setServo(5,90);
    setServo(7,60);
    setServo(9,120);
    setServo(11,180);
    setServo(13,0);
    setServo(15,90);
    delay(1000);
    
}
