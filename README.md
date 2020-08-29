# Ejemplos_driverPCA9685
Códigos de ejemplo para el módulo controlador de servos PCA9685

![Módulo Controlador de servos PCA9685](https://naylampmechatronics.com/1175-large_default/modulo-controlador-de-servos-pca9685.jpg)

Información detallada de los ejemplos en: [Tutorial Controlador de servos PCA9685](https://naylampmechatronics.com/blog/41_Tutorial-M%C3%B3dulo-Controlador-de-servos-PCA9685.html)

## Contenido
* **SweepServo:** Este ejemplo se hace una barrido de 0 a 180° y después de 180° a 0°, el barrido se hace a todos los servos por igual.
* **SameServos:** Para controlar servos que tienen el mismo ancho de pulso, podemos mover cada servo a un ángulo de 0 a 180 grados.
* **DifferentServos:** Para controlar servos que tienen trabajan con diferente ancho de pulso, podemos mover cada servo a un ángulo de 0 a 180 grados
 
## Requerimientos
 **Software**
  * IDE Arduino
  * Librería  [Wire](https://www.arduino.cc/en/Reference/Wire) (Ya viene instalada en Arduino)
  * Librería  [PWM Servo Driver](https://github.com/adafruit/Adafruit-PWM-Servo-Driver-Library) de Adrafuit
  
 **Hardware**
  * [Arduino Uno](https://naylampmechatronics.com/arduino-tarjetas/8-arduino-uno-r3.html) (o cualquier modelo)
  * [Módulo Controlador de servos PCA9685](https://naylampmechatronics.com/drivers/142-modulo-controlador-de-servos-pca9685.html) 
  * Servomotor ([SG90](https://naylampmechatronics.com/servomotores/21-servo-sg90-15kg.html), [SG-5010](https://naylampmechatronics.com/servomotores/22-servo-sg-5010-6kg.html), [MG996R](https://naylampmechatronics.com/servomotores/343-servo-mg996r-11kg.html), etc)
  * Fuente DC 6V (Para alimentar los servomotores)
  
## Conexiones

  PCA9685  |Arduino Uno,Nano,Mini | Arduino Mega,DUE | Arduino Leonardo
  ----------|----------------------|------------------|----------------------
  GND      |   GND                 |   GND            |   GND
  OE       |   GND                 |   GND            |   GND
  SCL      |   A5                  |   21             |   3
  SDA      |   A4                  |   20             |   2 
  VCC      |   5V                  |   5V             |   5V
  +V      |    NC                  |   NC             |   NC 
   
No se puede cambiar de pines, los pines indicados son para la comunicación I2C 
   y son los pines SDA y SCL de cada placa respectivamente

## Dirección del módulo I2C
Por defecto 0x40 (01000000) o establecer por hardware : 0|1|A5|A4|A3|A2|A1|A0 

## Licencia
Los ejemplos son Open Source, desarrollados por el equipo de Naylamp Mechatronics bajo [licencia MIT](LICENSE)
 
## Links 
 * [Tutorial Controlador de servos PCA9685](https://naylampmechatronics.com/blog/41_Tutorial-M%C3%B3dulo-Controlador-de-servos-PCA9685.html)
 * [Módulo Controlador de servos PCA9685](https://naylampmechatronics.com/drivers/142-modulo-controlador-de-servos-pca9685.html) 
 * [Servomotores](https://naylampmechatronics.com/26-servomotores)
 * [Adafruit PWM Servo Driver Library](https://github.com/adafruit/Adafruit-PWM-Servo-Driver-Library)
