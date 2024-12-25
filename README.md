# Arduino Signal Generator

## Descripción del Código

Este código está diseñado para generar diferentes tipos de señales utilizando un Arduino, permitiendo al usuario seleccionar entre una onda senoidal, una onda de diente de sierra, una señal ECG o una onda cuadrada. La selección de la señal se realiza mediante dos interruptores conectados a los pines digitales 8 y 9 del Arduino.

## Funcionamiento:

### 1. **Onda Senoidal**:
Cuando el primer interruptor (conectado al pin 8) está en estado bajo (LOW) y el segundo interruptor (conectado al pin 9) está en estado alto (HIGH), se genera una onda senoidal. El código realiza un cálculo para generar los valores de la onda senoidal, utilizando la función `sin()` para calcular el valor de la señal en cada uno de los 360 grados de la onda.

### 2. **Onda Diente de Sierra**:
Si el primer interruptor está en estado alto (HIGH) y el segundo está en estado bajo (LOW), se genera una onda de diente de sierra. En este caso, la señal aumenta linealmente desde 0 hasta 255 y luego se repite, creando una forma de onda triangular que representa un diente de sierra.

### 3. **Señal ECG**:
Si ambos interruptores están en estado bajo (LOW), se reproduce una señal ECG predefinida. Esta señal está almacenada en un arreglo llamado `ecgWave[]`, que contiene una serie de valores que representan los puntos de la onda ECG. Estos valores se envían secuencialmente al puerto de salida para generar la señal correspondiente.

### 4. **Onda Cuadrada**:
En cualquier otro caso, si ambos interruptores están en estado alto (HIGH), se genera una onda cuadrada. Esta señal alterna entre los valores 0 y 255, creando una forma de onda que tiene transiciones abruptas de bajo a alto.

## Control de la Frecuencia:
La frecuencia de las señales generadas se controla mediante la lectura de un valor de un pin analógico (A5). Este valor se mapea a un rango de tiempo para el cual se introduce un retraso con la función `delayMicroseconds(signalTime)`, ajustando así la frecuencia de la señal dependiendo de la entrada analógica.

El código hace uso del registro `PORTD` para manipular directamente las salidas digitales del Arduino, lo que permite generar las señales con un control más rápido. El uso de `delayMicroseconds()` permite ajustar con precisión el tiempo de emisión de cada señal, logrando así que cada tipo de onda tenga la frecuencia adecuada.

La siguiente figura muestra cómo se deben realizar las conexiones de la red con el Arduino y su punto de conexión para observar las señales en el osciloscopio:

![image](https://github.com/user-attachments/assets/b54d6322-8f1f-49d3-9239-a005777088f0)




