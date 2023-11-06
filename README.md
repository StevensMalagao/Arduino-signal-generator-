# Arduino-signal-generator-
Estructura General
El código se divide en dos partes principales: setup() y loop().

setup(): Es una función que se ejecuta una vez al inicio. Aquí se configuran los pines de los interruptores y los pines de salida.
loop(): Es una función que se ejecuta continuamente después de setup(). Contiene la lógica principal para generar las formas de onda.
Variables y Configuración Inicial
Se definen dos constantes switchPin1 y switchPin2 para leer el estado de dos interruptores.
Se inicializan las variables switchState1 y switchState2 para almacenar el estado actual de estos interruptores.
ecgWave[] es un array que almacena los valores para simular una señal electrocardiográfica (ECG).
Se calcula la longitud del array ecgWave para su uso posterior en la generación de la onda ECG.
Configuración de Pines
En el setup(), se configuran los pines 0 a 7 como salidas y los pines correspondientes a los interruptores como entradas.
Generación de Ondas
En el bucle principal loop(), se lee el estado de los interruptores para decidir qué forma de onda generar.
Si ambos interruptores están en alto, se genera una onda senoidal.
Si switchPin1 está en alto y switchPin2 en bajo, se genera una onda diente de sierra.
Si switchPin1 está en bajo y switchPin2 en alto, se reproduce la señal ECG detallada del array ecgWave.
Técnicas de Generación de Ondas
Para la onda senoidal, se utiliza la función sin() y se itera sobre 360 grados para generar los valores.
La onda diente de sierra se genera mediante un bucle que incrementa el valor del puerto D directamente.
La señal ECG utiliza un bucle for para iterar sobre cada valor del array ecgWave y enviarlo al puerto D.
Manejo de Puertos
El código utiliza PORTD para escribir directamente en el puerto D del microcontrolizador, lo que permite una operación más rápida que la función digitalWrite().
Delays
delayMicroseconds(20) se utiliza para controlar el tiempo entre cada muestra de la señal, esencial para determinar la frecuencia de la onda.
Este código muestra un ejemplo avanzado de manipulación directa de puertos en un microcontrolador Arduino para generar señales electrónicas, lo que puede ser útil para aplicaciones que requieren representar señales biométricas o para la enseñanza de conceptos de electrónica y procesamiento de señales.
