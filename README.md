# Arduino-signal-generator

Este código permite generar diferentes tipos de señales utilizando un Arduino. Se han implementado varias formas de onda, como la onda senoidal, diente de sierra, cuadrada y una señal ECG, las cuales se pueden seleccionar mediante dos interruptores conectados a los pines digitales 8 y 9.

Onda Senoidal: Cuando el primer interruptor (switchPin1) está en estado bajo (LOW) y el segundo interruptor (switchPin2) está en estado alto (HIGH), se genera una onda senoidal.

Onda Diente de Sierra: Si el primer interruptor está en estado alto (HIGH) y el segundo en estado bajo (LOW), se genera una onda de diente de sierra. Esta onda aumenta linealmente desde 0 hasta 255, repitiéndose continuamente.

Señal ECG: Cuando ambos interruptores están en estado bajo (LOW), se reproduce una señal predefinida de un ECG. Esta señal se almacena en un arreglo de valores que representan los puntos de la onda, y se envía al puerto de salida del Arduino.

Onda Cuadrada: En cualquier otro caso, si ambos interruptores están en estado alto (HIGH), se genera una onda cuadrada. En esta señal, el valor oscila entre 0 y 255, alternando de forma abrupta en intervalos definidos.

El código utiliza el registro PORTD para controlar las salidas digitales del Arduino, lo que permite generar las señales de forma rápida. La temporización de cada señal se ajusta utilizando delayMicroseconds, controlando así la frecuencia de las ondas.

La siguiente imagen muestra cómo se deben realizar las conexiones de la red con el Arduino y su punto de conexión para observar las señales en el osciloscopio:

![image](https://github.com/user-attachments/assets/7a650b0a-33af-47c6-92f7-f16c93a45082)


