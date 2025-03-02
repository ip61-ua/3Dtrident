# 3Dtrident

Es una aplicación de videoconsola retro cuya función es probar el funcionamiento de la consola en sí.

Progreso actual:

![Demostración](demo.gif)

# Objetivos

- [ ] [POR ACABAR] Pantalla para probar la entrada del hardware como _joysticks_, gatillos, cruceta...
- [ ] [PRÓXIMO] Pantalla para probar el táctil de la consola mediante un _paint_.
- [ ] [~] Apartado en donde _testear_ el micrófono, audio y volumen.
- [ ] [~] Comprobar el funcionamiento de la función _3D_ de la pantalla de la pantalla superior.
- [ ] [~] Pantalla de acerca de la aplicación.
- [ ] [~] Página en la que verificar el correcto funcionamiento de sensores como infrarrojo, giroscópio, acelerómetro...

# Estructura del proyecto

### Application

Punto de entrada de la aplicación.

### Hardware

Interfaz entre la I/O de la consola y el programador. Leer botones, *joysticks*, pantalla táctil, giroscópio...

### Pages

Interfaz para la declación de páginas y el manejo de estas. Basada en el funcionamiento de una máquina de estados finitos.
Para declarar nuevas páginas:

```c
// pages.h
extern Page PAGE_MYPAGE;

// page_mypage.h
extern Page PAGE_MYPAGE;

// page_mypage.c
static EntryPage entry (); // la función entry puede llamerse cómo quiera. Recomendable que sea static y no declararla en su .h.
Page PAGE_MYPAGE = entry;
```

# Compilación y contribución

Es necesario tener las librerías de desarrollo instaladas. Consulta [este sitio](https://devkitpro.org/wiki/Getting_Started).
Si trabajas desde un sistema _UNIX-like_, configura `pacman` siguiendo las instrucción de la wiki e instala el grupo `3ds-dev` para este proyecto.

Ubícate en la carpeta raíz del proyecto y sigue los siguientes comandos:

## Autocompetado de código

Puedes usar un archivo de configuración para el autocompletado de código. Para ello, debes tener instalado `clangd`. Más información [aquí](https://github.com/clangd/clangd).

Genera el archivo de configuración ejecutando:

```sh
make .clangd
```

Si eres usuario de windows, quizás te toque revisar manualmente el archivo generado.

## Generando el ejecutable

Genera el archivo ejecutable escribiendo:

```sh
make
```

Obtendrás en el directorio raíz al menos 2 archivos, `.3dsx` y `.elf`. Ejecuta cualquiera de los dos en la consola.

## Estilo de código

- Estilo de código _GNU_. Emplea un formateador de código como `clang-format`.
- Por convención: cada función de un módulo que pueda ser usada por otros módulos, su signatura deberá de empezar con el nombre al principio. Formato `<type> Module_func (<args>)`.

# Motivación

La razón de llevar a cabo este proyecto es la preservación de la consola. Así como el estudio de las capacidades y limitaciones de la misma.
Facilitar la consulta y comprobación de funciones y propiedades de la consola al usuario final o a un técnico que vaya a reparar la consola.
Por diversión, por amor al arte, por el *software* libre y por mejorar habilidades desarrollo de programas en bajo nivel.

# Créditos

- devkitPro [[github](https://github.com/devkitPro)] por las librerías de desarrollo para la consola.
- Inter [[github](https://github.com/rsms/inter)] por la tipografía personalizada empleda.
- Inspirado en 3DSident [[3DSident](https://github.com/joel16/3DSident)].
