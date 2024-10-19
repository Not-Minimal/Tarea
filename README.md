# Proyecto Carrera de Autos en Hilos

## Descripción

Este proyecto simula una carrera de autos utilizando hebras (threads) en C++. Cada auto avanza una cantidad aleatoria de metros(10 max) en intervalos de tiempo aleatorios hasta completar una distancia especifica.
Simulando la cantidad maxima de autos(hebras) que estan limitadas por el numero maximo de hebras que puede manejar la CPU actual, lo cual se calcula dinamicamente dentro del programa.

## Archivos del Proyecto

### `carrera.cpp`
El archivo `carrera.cpp` contiene todo el codigo fuente del proyecto, donde se simulan los autos y su avance en la carrera mediante hilos.

### `Makefile`
El archivo `Makefile` facilita la compilación del programa. Al utilizar el comando `make`, se genera el ejecutable `carrera`, que se puede ejecutar en la terminal para correr la simulación de la carrera.

## Compilación y Ejecución

### Requisitos
- Un compilador de C++ compatible con C++11 o superior (por ejemplo, `g++`).
- GNU Make (para usar el Makefile).

### Instrucciones para Compilar

Para compilar el programa, existe el archivo `Makefile` en el mismo directorio que `carrera.cpp`. Luego, ejecute el siguiente comando en la terminal:

```bash
make 
```
### Intrucciones para Ejecutar

Una vez que el programa este compilado, puede ejecutarlo con el siguiente comando:
```bash
./carrera <distancia_total> <numero_autos> 
```
- <distancia_total>: La distancia que cada auto debe recorrer para completar la carrera (en metros).
- <numero_autos>: La cantidad de autos que participan en la carrera. Nota: El numero de autos no puede exceder la cantidad de hebras soportadas por la CPU.

### Uso del Makefile

El Makefile está configurado para simplificar el proceso de compilación y limpiar el directorio de archivos generados. Los comandos disponibles son:
- make: Compila el programa y genera el ejecutable carrera.
- make clean: Elimina el ejecutable generado (carrera).
