
#include "../../headers/Benchmark.h"
#include <chrono>
#include <cmath>
#include <functional>
#include <iostream>
#include <ostream>


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
std::vector<long long> Benchmark::calculateTheoreticalTimes(const std::vector<int>& valuesN, const std::string& complexity) {
    std::vector<long long> theoreticalTimes;

    for (int n : valuesN) {
        if (complexity == "O(n^2)") {
            theoreticalTimes.push_back(n * n);
        } else if (complexity == "O(n log n)") {
            theoreticalTimes.push_back(n * std::log2(n));
        } else if (complexity == "O(n)") {
            theoreticalTimes.push_back(n);
        } else if (complexity == "O(log n)") {
            theoreticalTimes.push_back(std::log2(n));
        } else if (complexity == "O(1)") {
            theoreticalTimes.push_back(1);  // Tiempo constante para cualquier N
        } else {
            std::cerr << "Complejidad desconocida: " << complexity << std::endl;
            return {};  // Retorna un vector vacío si la complejidad es desconocida
        }
    }

    return theoreticalTimes;
}

