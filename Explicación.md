# Guía para personalizar tu carrito
 
¡Bienvenido! En esta guía vas a aprender a **cambiar cómo se maneja tu carrito** modificando solo unas pocas líneas de código.
 
La regla de oro: **copia, pega y prueba.** No necesitas entender todo el código, solo saber *dónde* pegar cada cosa.
 
---
 
## ¿Dónde se hacen los cambios?
 
Todo lo que hacemos está dentro de la función `processGamepad()`. Es la que decide **qué hace el carrito según lo que presionas en el control.**
 
Así se ve el original:
 
```cpp
void processGamepad(ControllerPtr gamepad) {
  int throttle = gamepad->throttle(); // R2
  int brake = gamepad->brake();       // L2
  int dpad = gamepad->dpad();
 
  if (throttle > UMBRAL) {
    adelante();
  } else if (brake > UMBRAL) {
    atras();
  } else if (dpad & 0x04) {
    derecha();
  } else if (dpad & 0x08) {
    izquierda();
  } else {
    detener();
  }
}
```
 
Léelo como una frase:
 
> **SI** aprieto R2 → ve adelante. **SI NO, SI** aprieto L2 → ve atrás. **SI NO, SI** … **SI NO** → detente.
 
Cada línea `if (...)` o `else if (...)` es **una condición**. Lo que está entre paréntesis es **qué botón** se revisa, y lo que está dentro de las llaves `{ }` es **qué hace el carrito**.
 
### Las 5 acciones disponibles
 
| Acción | Qué hace el carrito |
|---|---|
| `adelante();` | Avanza |
| `atras();` | Retrocede |
| `izquierda();` | Gira a la izquierda |
| `derecha();` | Gira a la derecha |
| `detener();` | Se queda quieto |
 
---
 
## Catálogo de controles (copia y pega)
 
Aquí está **cómo escribir cada botón** del control. Solo reemplaza lo que está entre paréntesis en el `if`.
 
### Botones de la derecha
 
| Botón Xbox | Botón PlayStation | Se escribe así |
|---|---|---|
| A | ✕ (Cruz) | `gamepad->a()` |
| B | ○ (Círculo) | `gamepad->b()` |
| X | □ (Cuadrado) | `gamepad->x()` |
| Y | △ (Triángulo) | `gamepad->y()` |
 
**Ejemplo:** que el carrito avance con el botón A.
 
```cpp
if (gamepad->a()) {
  adelante();
}
```
 
### Botones de los hombros (los de arriba)
 
| Botón | Se escribe así |
|---|---|
| L1 / LB | `gamepad->l1()` |
| R1 / RB | `gamepad->r1()` |
 
**Ejemplo:**
 
```cpp
if (gamepad->r1()) {
  adelante();
} else if (gamepad->l1()) {
  atras();
}
```
 
### Gatillos (los de abajo, R2 y L2)
 
Estos **no son solo "apretado o no"**: dan un número de **0 a 1023** según qué tanto los aprietes.
 
| Gatillo | Valor |
|---|---|
| R2 | `gamepad->throttle()` |
| L2 | `gamepad->brake()` |
 
Por eso se compara con `UMBRAL`: el carrito solo reacciona si aprietas **más de cierto valor**.
 
```cpp
if (gamepad->throttle() > UMBRAL) {
  adelante();
}
```
 
### Flechas (D-pad / cruceta)
 
| Flecha | Se escribe así |
|---|---|
| ⬆️ Arriba | `dpad & 0x01` |
| ⬇️ Abajo | `dpad & 0x02` |
| ➡️ Derecha | `dpad & 0x04` |
| ⬅️ Izquierda | `dpad & 0x08` |
 
**Ejemplo:** manejar todo con las flechas.
 
```cpp
if (dpad & 0x01) {
  adelante();
} else if (dpad & 0x02) {
  atras();
} else if (dpad & 0x04) {
  derecha();
} else if (dpad & 0x08) {
  izquierda();
} else {
  detener();
}
```
 
### Joysticks (palancas)
 
Los joysticks dan un número entre **-511 y +512**:
 
- **Centro** = alrededor de 0
- **Izquierda / Arriba** = números **negativos**
- **Derecha / Abajo** = números **positivos**
| Joystick | Eje | Se escribe así |
|---|---|---|
| Izquierdo | ↔️ horizontal | `gamepad->axisX()` |
| Izquierdo | ↕️ vertical | `gamepad->axisY()` |
| Derecho | ↔️ horizontal | `gamepad->axisRX()` |
| Derecho | ↕️ vertical | `gamepad->axisRY()` |
 
> ⚠️ **Ojo:** al empujar el joystick **hacia arriba** el número es **negativo**. Por eso para ir adelante usamos `< -200`.
 
Ponemos `200` como "zona muerta" para que el carrito no se mueva solo si el joystick no queda perfectamente en el centro.
 
**Ejemplo:** manejar con el joystick izquierdo.
 
```cpp
int x = gamepad->axisX();
int y = gamepad->axisY();
 
if (y < -200) {
  adelante();
} else if (y > 200) {
  atras();
} else if (x > 200) {
  derecha();
} else if (x < -200) {
  izquierda();
} else {
  detener();
}
```
 
### Apretar los joysticks (clic)
 
| Botón | Se escribe así |
|---|---|
| Clic joystick izquierdo | `gamepad->thumbL()` |
| Clic joystick derecho | `gamepad->thumbR()` |
 
---