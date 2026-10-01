#include <Arduino.h>
#include <Bluepad32.h>

ControllerPtr myControllers[BP32_MAX_GAMEPADS];

// Definición de pines
const int IN2 = 19;     
const int IN4 = 18;    
//const int ENA = 21;     // Habilitar Motor A
const int IN1 = 21;     
const int IN3 = 23;     
//const int ENB = 17;     // Habilitar Motor B

const int UMBRAL = 100; // throttle/brake van de 0 a 1023

// ---------- Funciones de movimiento ----------

void detener() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void adelante() { 
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void atras() { 
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void derecha() {  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void izquierda() { 
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// ---------- Callbacks del gamepad ----------

void onConnectedController(ControllerPtr ctl) {
  for (int i = 0; i < BP32_MAX_GAMEPADS; i++) {
    if (myControllers[i] == nullptr) {
      Serial.printf("Control conectado, index=%d\n", i);
      myControllers[i] = ctl;
      return;
    }
  }
  Serial.println("Control conectado, pero no hay espacio libre");
}

void onDisconnectedController(ControllerPtr ctl) {
  for (int i = 0; i < BP32_MAX_GAMEPADS; i++) {
    if (myControllers[i] == ctl) {
      Serial.printf("Control desconectado, index=%d\n", i);
      myControllers[i] = nullptr;
      return;
    }
  }
}

// ---------- Lógica del gamepad ----------

void processGamepad(ControllerPtr gamepad) {
  int throttle = gamepad->throttle(); // R2
  int brake = gamepad->brake();       // L2
  int dpad = gamepad->dpad();

  Serial.printf("throttle:%d brake:%d dpad:0x%02x\n", throttle, brake, dpad);

  if (throttle > UMBRAL) {
    adelante();
  } else if (brake > UMBRAL) {
    atras();
  } else if (dpad & 0x04) { // "derecha" - a confirmar con tu control
    derecha();
  } else if (dpad & 0x08) { // "izquierda" - a confirmar con tu control
    izquierda();
  } else {
    detener();
  }
}

// ---------- Setup ----------

void setup() {
  Serial.begin(115200);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  BP32.setup(&onConnectedController, &onDisconnectedController);
  BP32.forgetBluetoothKeys();
}

// ---------- Loop principal ----------

void loop() {
  BP32.update();

  for (int i = 0; i < BP32_MAX_GAMEPADS; i++) {
    ControllerPtr myController = myControllers[i];
    if (myController && myController->isConnected() && myController->isGamepad()) {
      processGamepad(myController);
      break; // usamos solo el primer control conectado
    }
  }
}