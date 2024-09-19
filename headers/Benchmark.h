#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <functional>
#include <string>

class Benchmark {
public:
    // Declaración de la función que mide el tiempo de ejecución en nanosegundos
    static long long measureExecutionTime(const std::function<void()>& func);
    // Funcion para calcular los tiempos teóricos en función de la complejidad
    static std::vector<long long> calculateTheoreticalTimes(const std::vector<int>& valuesN, const std::string& complexity);
};
#endif // BENCHMARK_H
