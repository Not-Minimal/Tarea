# Proyecto Carrera de Autos en Hilos

## Descripci  n

Este proyecto simula una carrera de autos utilizando hebras (threads) en C++. Cada auto avanza una cantidad aleatoria de metros(10 max) en intervalos de tiempo aleatorios hasta completar una distancia espec  fica, simulando>

La cantidad m  xima de autos (hebras) est   limitada por el n  mero m  ximo de hebras que puede manejar tu CPU, lo cual se calcula din  micamente dentro del programa. Si se intenta utilizar m  s autos de los que soporta la >

## Archivos del Proyecto

### `carrera.cpp`
El archivo `carrera.cpp` contiene todo el c  digo fuente del proyecto, donde se simulan los autos y su avance en la carrera mediante hilos.

### `Makefile`
El archivo `Makefile` facilita la compilaci  n del programa. Al utilizar el comando `make`, se generar   el ejecutable `carrera`, que se puede ejecutar en la terminal para correr la simulaci  n de la carrera.

## Compilaci  n y Ejcuci  n

### Requisitos
- Un compilador de C++ compatible con C++11 o superior (por ejemplo, `g++`).
- GNU Make (para usar el Makefile).

### Instrucciones para Compilar

Para compilar el programa, existe el archivo `Makefile` en el mismo directorio que `carrera.cpp`. Luego, ejecute el siguiente comando en la terminal:

```bash
make 
```
### Intrucciones para Ejecutar

Una vez que el programa est   compilado, pued ejecutarlo con el siguiente comando:
```bash
./carrera <distancia_total> <numero_autos> 
```
- <distancia_total>: La distancia que cada auto debe recorrer para completar la carrera (en metros).
- <numero_autos>: La cantidad de autos que participar  n en la carrera. Nota: El n  mero de autos no puede exceder la cantidad de hebras soportadas por tu CP

### Uso del Makefile

El Makefile est   configurado para simplificarel proceso de compilaci  n y limpiar el directorio de archivos generados. Los comandos disponibles so:
- make: Compila el programa y genera el ejecutable carrera.
- make clean: Elimina el ejecutable generado (carrera).
