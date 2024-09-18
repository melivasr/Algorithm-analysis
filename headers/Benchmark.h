#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <chrono>
#include <functional>

class Benchmark {
public:
    static long long measureExecutionTime(const std::function<void()>& func);
};

#endif // BENCHMARK_H
