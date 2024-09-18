#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <functional>

class Benchmark {
public:
    // Declaración de la función que mide el tiempo de ejecución en nanosegundos
    static long long measureExecutionTime(const std::function<void()>& func);
};

#endif // BENCHMARK_H
