
#include "../headers/Benchmark.h"
#include <chrono>
#include <functional>

long long Benchmark::measureExecutionTime(const std::function<void()>& func) {
    // Obtener el tiempo inicial en nanosegundos
    auto tiempo1 = std::chrono::high_resolution_clock::now();

    // Ejecutar el método que se desea medir
    func();

    // Obtener el tiempo final en nanosegundos
    auto tiempo2 = std::chrono::high_resolution_clock::now();

    // Calcular la diferencia en nanosegundos
    auto tiempoTardado = std::chrono::duration_cast<std::chrono::nanoseconds>(tiempo2 - tiempo1).count();

    return tiempoTardado;
}
