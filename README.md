
# Fut

# Carrito de Fútbol con Mini ESP32

Proyecto educativo para aprender electrónica y programación embebida construyendo un carrito robótico tipo "futbolista", controlado por una **Mini ESP32**.

Este repositorio fue creado como material de apoyo para un curso, con la idea de que cualquier persona (aunque nunca haya usado un ESP32) pueda entender, armar y programar su propio carrito paso a paso.

---

## Tabla de contenido

- [¿Qué es este proyecto?](#-qué-es-este-proyecto)
- [Materiales necesarios](#-materiales-necesarios)
- [Diagrama de conexión](#-diagrama-de-conexión)
- [Instalación del entorno](#-instalación-del-entorno)
- [Cómo subir el código al ESP32](#-cómo-subir-el-código-al-esp32)
- [Código fuente (main)](src/carrito_futbol.ino)
- [Estructura del repositorio](#-estructura-del-repositorio)
- [Cómo usarlo](#-cómo-usarlo)
- [Problemas comunes](#-problemas-comunes)
- [Créditos](#-créditos)

---

## ¿Qué es este proyecto?

Es un carrito controlado a distancia (o de forma autónoma, según la etapa del curso) pensado como introducción práctica y divertida a:

- Programación en C/C++ para microcontroladores (ESP32)
- Control de motores
- Conceptos básicos de electrónica
- (Opcional) Conectividad WiFi/Bluetooth para controlarlo desde un celular

> *Foto o video o gif*

---

## Materiales necesarios

| Componente | Cantidad | Notas |
|---|---|---|
| ESP32 (DevKit) | 1 | Cualquier variante estándar sirve |
| Driver de motores (ej. L298N) | 1 | Para controlar los motores DC |
| Motores DC + llantas | 2-4 | Según el diseño del chasis |
| Batería / pack de pilas | 1 | Recomendado 7.4V–9V |
| Chasis (impreso o cortado) | 1 | Puede ser de acrílico, madera o 3D |
| Cables jumper | Varios | Macho-macho / macho-hembra |



---

##  Diagrama de conexión

>  *imagen del diagrama*

```
ESP32 Pin  →  Componente
GPIO     →  IN1 (Motor A)
GPIO     →  IN2 (Motor A)
GPIO     →  IN3 (Motor B)
GPIO     →  IN4 (Motor B)
```


---

## Instalación del entorno

1. Instala el [Arduino IDE](https://www.arduino.cc/en/software) (o PlatformIO si prefieres VS Code).
2. Agrega el soporte para ESP32:
   - Ve a `Archivo > Preferencias`
   - En "URLs adicionales de gestor de tarjetas" pega:
     ```
     https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
     ```
   - Luego ve a `Herramientas > Placa > Gestor de tarjetas` y busca "esp32", instálalo.
3. Selecciona tu placa en `Herramientas > Placa > ESP32 Dev Module`.

---

## Cómo subir el código al ESP32

1. Conecta tu ESP32 a la computadora con cable USB.
2. Abre el archivo principal del proyecto: [`src/carrito_futbol.ino`](src/carrito_futbol.ino)
3. Selecciona el puerto correcto en `Herramientas > Puerto`.
4. Da clic en el botón de subir (flecha →).
5. Si no sube, mantén presionado el botón **BOOT** de la placa mientras empieza a subir.

---

## Estructura del repositorio

```
carrito-futbol-esp32/
├── src/
│   └── carrito_futbol.ino   # Código fuente principal
├── imagenes/                # Fotos y diagramas del proyecto
├── docs/                    # Material extra del curso (slides, guías)
├── .gitignore
└── README.md
```

> Link directo al código: [`src/carrito_futbol.ino`](src/carrito_futbol.ino)

---

## Cómo usarlo


---

## Problemas comunes

- **No sube el código / "Failed to connect"** → mantén presionado BOOT al subir.
- **El motor gira al revés** → invierte los cables del motor correspondiente.
- **El ESP32 se reinicia solo** → revisa que la fuente de poder dé suficiente corriente.

---

## Créditos

Proyecto creado para fines educativos como parte de un curso de introducción a ESP32 y robótica.

**Autor:** 
**Contacto:** 