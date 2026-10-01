#  Retos: Personaliza tu carrito

¡Tu carrito ya funciona! Ahora vas a convertirte en **programador de controles**: tú decides qué botón hace qué.

## Cómo trabajar cada reto

1. **Lee la misión** y entiende qué se te pide.
2. **Busca en la `GUIA_CONTROLES.md`** cómo se escribe el botón o joystick que necesitas.
3. **Copia, pega y adapta** en la función `processGamepad()`.
4. **Sube el código al ESP32 y pruébalo** con el carrito.


> Si algo no funciona, no te frustres: revisa, ajusta y vuelve a probar. Cuando algo falla, ahí es donde más se aprende. 🔧

---

##  NIVEL 1: Cambios sencillos

En este nivel solo cambias **una cosa a la vez**. Son perfectos para entender cómo se conecta el código con lo que hace el carrito.

---

### 1.1 Piloto al revés

**Misión:** Imagina que un piloto prefiere manejar al revés. Haz que **R2 mueva el carrito hacia atrás** y **L2 hacia adelante**.

**¿Qué aprendes?** Que el botón y la acción son cosas separadas. El control no "sabe" qué hace el carrito; tú le asignas el trabajo.

**Pista:** Mira las condiciones de `throttle` y `brake`. Fíjate qué función se ejecuta dentro de cada una.

**Compruébalo:** Aprieta R2. Si el carrito retrocede, ¡vas bien!

---

### 1.2 Giros invertidos

**Misión:** Haz que al presionar la flecha **derecha** del control el carrito gire a la **izquierda**, y viceversa.

**¿Qué aprendes?** Lo mismo que el reto anterior pero con las flechas. Además, empiezas a reconocer cómo se lee un `dpad`.

**Pista:** Busca en el código dónde aparecen `0x04` y `0x08`. Revisa la tabla de flechas de la guía.

**Compruébalo:** Pon el carrito mirando hacia ti y presiona la flecha derecha. ¿Gira hacia donde esperabas?

---

### 1.3 Sensibilidad

**Misión:** Controla **qué tan fuerte** hay que apretar el gatillo para que el carrito reaccione. Haz dos pruebas:
- Que se mueva con solo rozar el gatillo.
- Que haya que apretarlo casi a fondo.

Anota qué números usaste: ______ y ______

**¿Qué aprendes?** Los gatillos no son "encendido o apagado": entregan un número según qué tanto los aprietes (de 0 a 1023). El `UMBRAL` es el límite que decide cuándo cuenta como "apretado".

**Pista:** Busca la palabra `UMBRAL` al inicio del programa. Es una sola línea.

**Compruébalo:** Con el umbral bajo, ¿el carrito se mueve aunque casi no aprietes? ¿Con el alto, tienes que hacer fuerza?

---

### 1.4 Sin gatillos

**Misión:** Olvídate de R2 y L2. Haz que el carrito avance con el botón **A** y retroceda con el botón **B**.

**¿Qué aprendes?** Los botones normales son más simples que los gatillos: solo están apretados o no, sin números de por medio. Por eso se escriben distinto.

**Pista:** Mira la sección "Botones de la derecha" de la guía. Fíjate que aquí no hay comparación con `UMBRAL`.

**Compruébalo:** ¿Avanza con A? ¿Retrocede con B? ¿Qué pasa si presionas los dos al mismo tiempo? (Anota qué pasó y por qué crees que fue.)

---

### 1.5 Giros con botones

**Misión:** Haz que el carrito gire a la **derecha con Y** y a la **izquierda con X**.

**¿Qué aprendes?** A agregar nuevas condiciones a una cadena de `if / else if` ya existente, sin romper lo demás.

**Pista:** Cada condición nueva se agrega como un `else if` más. Cuida que las llaves `{ }` queden bien cerradas.

**Compruébalo:** ¿Siguen funcionando los demás controles que ya tenías?

---

### 1.6 Botones de hombro

**Misión:** Haz que el carrito avance con **R1** y retroceda con **L1**.

**¿Qué aprendes?** A buscar por tu cuenta en la guía un botón que todavía no has usado. Esto es lo que hacen los programadores todo el tiempo: leer la documentación.

**Pista:** Están en la sección "Botones de los hombros".

**Compruébalo:** R1 y R2 están muy cerca en el control. ¿Los confundes al manejar? Piensa: ¿cuál te parece más cómodo?

---

## NIVEL 2: Un poco más de lógica

Aquí ya no basta con cambiar una palabra: tienes que **pensar** cómo se combinan las condiciones.

---

### 2.1 Joystick completo

**Misión:** Maneja el carrito **solo con el joystick izquierdo**: adelante, atrás, izquierda y derecha. Al soltarlo, el carrito debe detenerse.

**¿Qué aprendes?** Los joysticks entregan números, no solo "sí o no". Tú decides a partir de qué número cuenta como "empujado". Así funcionan los controles de videojuegos de verdad.

**Pistas:**
- El ejemplo de la guía solo resuelve **una** de las cuatro direcciones. Tú completas las otras tres.
- Recuerda que empujar **hacia arriba** da un número **negativo**.
- Necesitas dos variables: una para el eje horizontal (`axisX`) y otra para el vertical (`axisY`).

**Compruébalo:** Mueve el joystick suave y sin soltarlo del todo. ¿El carrito se mueve cuando no debería? Si es así, ajusta el número de la zona muerta.

---

### 2.2 Joystick derecho

**Misión:** Haz lo mismo que en el reto 2.1, pero con el joystick **derecho**.

**¿Qué aprendes?** Que cambiar de joystick es solo cambiar el "nombre" del eje. Si entendiste el reto anterior, este toma un minuto.

**Pista:** Revisa la tabla de joysticks en la guía. Los ejes del derecho empiezan con `axisR`.

**Compruébalo:** Verifica que el joystick izquierdo ya no mueva el carrito.

---

### 2.3 Joystick invertido

**Misión:** Haz que al empujar el joystick **hacia arriba** el carrito vaya **hacia atrás**, y al empujarlo hacia abajo vaya hacia adelante. 

**¿Qué aprendes?** Que puedes inventar controles "raros" a propósito. Es el mismo truco del reto 1.1, pero aplicado a un joystick.

**Pista:** No necesitas cambiar los números; piensa qué debe cambiar.

**Compruébalo:** Maneja el carrito con contoles invertidos.

---

### 2.4 Combinado: gatillos + joystick

**Misión:** Haz que **R2 y L2** controlen adelante y atrás, pero que **girar** se haga con el joystick (izquierda y derecha).

**¿Qué aprendes?** A mezclar distintos tipos de control en un solo programa. Así funcionan los controles de los carros de carreras en los videojuegos.

**Pistas:**
- Solo necesitas **un eje** del joystick (¿cuál?).
- Ordena bien las condiciones: primero gatillos, después giros, y al final `detener();`.

**Compruébalo:** ¿Puedes avanzar y girar a la vez? ¿Qué pasa si aprietas R2 mientras mueves el joystick? Explica por qué ocurre eso.

---

### 2.5 Freno de emergencia

**Misión:** Elige un botón y conviértelo en **freno de emergencia**: al presionarlo, el carrito se detiene **sin importar qué otra cosa estés presionando**.

**¿Qué aprendes?** Que el **orden** de las condiciones cambia todo. El programa lee de arriba hacia abajo y se queda con la primera que se cumple. Esta es una de las ideas más importantes de la programación.

**Pistas:**
- Piensa en dónde debe ir esta condición para que se revise **primero**.
- Investiga qué hace la palabra `return;` (puedes preguntarle a tu profe o buscarla).

**Compruébalo:** Mantén apretado R2 (el carrito avanza) y luego presiona tu botón de freno. ¿Se detiene? Si no, revisa en qué lugar pusiste la condición.

---

### 2.6 La voz del carrito

**Misión:** Haz que el carrito "hable": que en el **Monitor Serial** aparezca un mensaje distinto para cada movimiento (adelante, atrás, izquierda, derecha). ¡Hazlo con tu propio estilo!

**¿Qué aprendes?** A usar el Monitor Serial para ver qué está pensando el ESP32. Es la herramienta que más usan los programadores para encontrar errores.

**Pista:** Revisa "Herramientas útiles" en la guía. El mensaje va **dentro** de las llaves de cada condición, junto a la acción.

**Compruébalo:** Abre el Monitor Serial (velocidad 115200) y maneja el carrito. ¿Aparecen tus mensajes?

---

### 2.7 Detective del control

**Misión:** Descubre los números secretos del control. Usa la herramienta de "ver valores en vivo" y responde:
- ¿Qué número aparece en `dpad` con cada flecha? ______
- ¿Coincide con la tabla de la guía? ______
- ¿Qué pasa si presionas **dos flechas a la vez**? ______
- ¿Qué valores salen en `axisX` y `axisY` cuando el joystick está quieto? ¿Es exactamente 0? ______

**¿Qué aprendes?** A **investigar y comprobar** en vez de creer ciegamente. Un buen programador siempre mide antes de asumir.

**Pista:** Pega la línea de "valores en vivo" al inicio de `processGamepad()`, sube el código y abre el Monitor Serial.

**Compruébalo:** Con tus respuestas, explica con tus palabras por qué el programa usa una "zona muerta" en los joysticks.

---

## Reto final: ¡Diseña tu propio control!

**Misión:** Combina todo lo que aprendiste y crea **tu propio esquema de control**. Debe cumplir:
- Al menos **un joystick o gatillo** (algo de valores numéricos).
- Al menos **un botón** normal.
- Un **freno de emergencia**.
- **Mensajes** en el Monitor Serial.

**Intercambio:** Cuando termines, pasa tu carrito a otro equipo. Ellos tienen que manejarlo **sin que les expliques nada**, solo descubriendo los controles. Luego cambian los papeles.

**Gran final:** Un circuito con conos. ¿Qué equipo lo completa más rápido con el control del otro?
