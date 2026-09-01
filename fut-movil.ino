#include <BluetoothSerial.h>
BluetoothSerial SerialBT;

// Definición de pines
const int IN1 = 27;     
const int IN3 = 33;    
//const int ENA = 21;     // Habilitar Motor A
const int IN2 = 25;     
const int IN4 = 32;     
//const int ENB = 17;     // Habilitar Motor B

void setup() {

  Serial.begin(115200); // Inicializar la comunicación serie 
  SerialBT.begin("Gera"); // Nombre del dispositivo Bluetooth

  // Configuración de pines
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
/*
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
*/
}

void loop() {
  // Si hay datos por Bluetooth
  if (SerialBT.available()) {
    char comando = SerialBT.read();

    switch (comando) {

        case 'F': // Adelante
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW); 
        break;

      case 'B': // Atras
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH); 
        break;

      case 'R': // Derecha
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        break;

      case 'L': // Izquierda
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        break;

      case 'S': // Stop
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
        break;
      default:
        break;
    }
  }

}