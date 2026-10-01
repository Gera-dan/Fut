# Respuestas de la actividad

> No subas este archivo al repositorio de los estudiantes, o ponlo en una rama o repositorio privado.
>
> Cada respuesta muestra solo lo que cambia dentro de `processGamepad()`. Hay más de una forma correcta de resolver casi todos los retos.

---

## NIVEL 1

### 1.1 Piloto al revés (R2 atrás, L2 adelante)

Se intercambian las funciones:

```cpp
if (throttle > UMBRAL) {
  atras();
} else if (brake > UMBRAL) {
  adelante();
}
```

### 1.2 Giros invertidos

```cpp
} else if (dpad & 0x04) {
  izquierda();
} else if (dpad & 0x08) {
  derecha();
}
```

### 1.3 Sensibilidad

Se cambia la constante al inicio del programa:

```cpp
const int UMBRAL = 10;   // muy sensible
const int UMBRAL = 800;  // hay que apretar casi a fondo
```

### 1.4 Adelante con A, atrás con B

```cpp
if (gamepad->a()) {
  adelante();
} else if (gamepad->b()) {
  atras();
}
```

(Los giros del D-pad se dejan como `else if` debajo.)

### 1.5 Giros con Y y X

```cpp
} else if (gamepad->y()) {
  derecha();
} else if (gamepad->x()) {
  izquierda();
}
```

### 1.6 Hombros

```cpp
if (gamepad->r1()) {
  adelante();
} else if (gamepad->l1()) {
  atras();
}
```

---

## NIVEL 2

### 2.1 Joystick izquierdo completo

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

### 2.2 Joystick derecho

Igual que el anterior, cambiando los ejes:

```cpp
int x = gamepad->axisRX();
int y = gamepad->axisRY();
```

### 2.3 Joystick invertido

Se intercambian las acciones de arriba y abajo:

```cpp
if (y < -200) {
  atras();
} else if (y > 200) {
  adelante();
}
```

### 2.4 Gatillos + joystick para girar

```cpp
int x = gamepad->axisX();

if (throttle > UMBRAL) {
  adelante();
} else if (brake > UMBRAL) {
  atras();
} else if (x > 200) {
  derecha();
} else if (x < -200) {
  izquierda();
} else {
  detener();
}
```

### 2.5 Freno de emergencia

Debe ir **al inicio de la función**, antes de los demás `if`:

```cpp
if (gamepad->x()) {
  detener();
  return;
}
```

`return;` termina la función en ese momento, así que ninguna otra condición se revisa.

**Error común:** ponerlo al final. Ahí nunca se alcanza si otra condición anterior ya se cumplió.

### 2.6 Voz del carrito

```cpp
if (throttle > UMBRAL) {
  Serial.println("¡Voy adelante!");
  adelante();
} else if (brake > UMBRAL) {
  Serial.println("¡Reversa!");
  atras();
}
```

### 2.7 Detective del control

- Con los valores estándar de Bluepad32: arriba = `1`, abajo = `2`, derecha = `4`, izquierda = `8`.
- Al presionar dos flechas a la vez, los valores se **suman** (por ejemplo, arriba + derecha = `5`). Por eso se usa `&` en vez de `==`: así detecta la flecha aunque haya otra presionada.

---

## Errores frecuentes

| Síntoma | Causa probable |
|---|---|
| No compila, error de "expected `}`" | Falta o sobra una llave |
| No compila, error de "expected `;`" | Falta el `;` después de una acción |
| El carrito no se detiene al soltar todo | Borraron el `else { detener(); }` |
| Un botón nunca responde | Hay otro `if` más arriba que se cumple primero |
| El joystick va al revés de lo esperado | Olvidaron que arriba es **negativo** |
| El carrito se mueve solo con el joystick | La zona muerta es muy pequeña (usar 200 o más) |
| El control no conecta | Reiniciar el ESP32 y poner el control en modo de emparejamiento |
| Error con `l1()`, `r1()` o `thumbL()` | Versión de Bluepad32 distinta; actualizar la librería |