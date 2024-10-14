#include <iostream>
#include <thread>       // Biblioteca estándar de hilos
#include <vector>       // Para manejar las hebras en un vector
#include <mutex>        // Para la sincronización de los recursos compartidos
#include <cstdlib>      // Para generar números aleatorios
#include <chrono>       // Para las pausas con tiempo aleatorio

std::mutex mtx;  // Mutex para sincronizar el acceso a la consola y otros recursos compartidos
std::vector<int> posiciones;  // Para almacenar el orden de llegada de los autos

// Función que simula el avance de cada auto
void carrera_auto(int id, int distancia) {
    int posicion = 0;  // Distancia recorrida por el auto
    while (posicion < distancia) {
        // Genera un avance aleatorio entre 1 y 10 metros
        int avance = rand() % 10 + 1;
        posicion += avance;

        // Bloquea el acceso a la consola para mostrar el avance de forma sincronizada
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "Auto" << id << " avanza " << avance << " metros (total: " << posicion << " metros)" << std::endl;

        // Pausa de tiempo aleatorio entre 100 y 500 milisegundos (simulando la velocidad)
        std::this_thread::sleep_for(std::chrono::milliseconds(100 + rand() % 400));
    }

    // Cuando el auto termina, se almacena su ID en el vector de posiciones finales
    std::lock_guard<std::mutex> lock(mtx);
    posiciones.push_back(id);
    std::cout << "Auto" << id << " termina la carrera!" << std::endl;
}

int main(int argc, char* argv[]) {
    // Validación de los argumentos de entrada
    if (argc != 3) {
        std::cerr << "Uso: ./carrera <distancia_total> <numero_autos>" << std::endl;
        return 1;
    }

    // Conversión de los parámetros de entrada
    int M = std::atoi(argv[1]);  // Distancia total de la carrera
    int N = std::atoi(argv[2]);  // Número de autos

    // Validación de los valores de M y N
    if (M <= 0 || N <= 0) {
        std::cerr << "Los parámetros deben ser mayores que 0." << std::endl;
        return 1;
    }

    // Vector de hilos (uno por cada auto)
    std::vector<std::thread> autos;

    // Creación de hebras para cada auto
    for (int i = 0; i < N; i++) {
        autos.push_back(std::thread(carrera_auto, i, M));  // Crear una hebra para cada auto
    }

    // Esperar a que todas las hebras terminen
    for (auto& auto_thread : autos) {
        auto_thread.join();  // Sincronización: Esperar a que cada auto termine la carrera
    }

    // Mostrar el orden final de llegada
    std::cout << "Orden de llegada:" << std::endl;
    for (int i = 0; i < posiciones.size(); i++) {
        std::cout << i + 1 << ": Auto" << posiciones[i] << std::endl;
    }

    return 0;
}
