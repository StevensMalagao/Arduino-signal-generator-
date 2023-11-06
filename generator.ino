const int switchPin1 = 8;  
const int switchPin2 = 9;  

int switchState1 = 0; 
int switchState2 = 0;

int ecgWave[] = {
73,74,75,75,74,73,73,73,73,72,71,69,68,67,67,67,
68,68,67,65,62,61,59,57,56,55,55,54,54,54,55,55,
55,55,55,55,54,53,51,50,49,49,52,61,77,101,132,
169,207,238,255,254,234,198,154,109,68,37,17,5,
0,1,6,13,20,28,36,45,52,57,61,64,65,66,67,68,68,
69,70,71,71,71,71,71,71,71,71,72,72,72,73,73,74,
75,75,76,77,78,79,80,81,82,83,84,86,88,91,93,96,
98,100,102,104,107,109,112,115,118,121,123,125,
126,127,127,127,127,127,126,125,124,121,119,116,
113,109,105,102,98,95,92,89,87,84,81,79,77,76,75,
74,73,72,70,69,68,67,67,67,68,68,68,69,69,69,69,
69,69,69,70,71,72,73,73,74,74,75,75,75,75,75,75,
74,74,73,73,73,73,72,72,72,71,71,71,71,71,71,71,
70,70,70,69,69,69,69,69,70,70,70,69,68,68,67,67,
67,67,66,66,66,65,65,65,65,65,65,65,65,64,64,63,
63,64,64,65,65,65,65,65,65,65,64,64,64,64,64,64,
64,64,65,65,65,66,67,68,69,71,72,73};

int ecgWaveLength = sizeof(ecgWave) / sizeof(int);


void setup() {

  for (int i = 0; i <= 7; i++) {
    pinMode(i, OUTPUT);
  }

  pinMode(switchPin1, INPUT);
  pinMode(switchPin2, INPUT);
}

void loop() {
 
  switchState1 = digitalRead(switchPin1);
  switchState2 = digitalRead(switchPin2);

  
  if (switchState1 == HIGH && switchState2 == HIGH) {
    // Onda senoidal
    for (int i = 0; i < 360; i++) {
      int val = 127 + 127 * sin(i * 3.14159 / 180.0);
      PORTD = val;
      delayMicroseconds(20);
    }
  } else if (switchState1 == HIGH && switchState2 == LOW) {
    // Onda diente de sierra
    for (int i = 0; i < 256; i++) {
      PORTD = i;
      delayMicroseconds(20);
    }
  } else if (switchState1 == LOW && switchState2 == HIGH) {
    // Señal ECG más detallada
    for (int i = 0; i < ecgWaveLength; i++) {
      PORTD = ecgWave[i];
      delayMicroseconds(20);  
    }
  }
}