
#include "../headers/Benchmark.h"
#include <chrono>
#include <functional>


// Implementación de la función measureExecutionTime
long long Benchmark::measureExecutionTime(const std::function<void()>& func) {
    // Obtener el tiempo inicial
    auto tiempo1 = std::chrono::high_resolution_clock::now();

    // Ejecutar la función
    func();

    // Obtener el tiempo final
    auto tiempo2 = std::chrono::high_resolution_clock::now();

    // Calcular el tiempo en nanosegundos
    auto tiempoTardado = std::chrono::duration_cast<std::chrono::nanoseconds>(tiempo2 - tiempo1).count();

    return tiempoTardado;
}
