#include "../../headers/TestDataGenerator.h"
#include "../../headers/Benchmark.h"
#include <algorithm>
#include <random>

// Peor caso: los datos están en orden descendente
std::vector<int> TestDataGenerator::generateWorstCase(int N) {
    std::vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        arr[i] = N - i;
    }
    return arr;
}

// Mejor caso: los datos están en orden ascendente
std::vector<int> TestDataGenerator::generateBestCase(int N) {
    std::vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        arr[i] = i;
    }
    return arr;
}

// Caso promedio: datos aleatorios
std::vector<int> TestDataGenerator::generateAverageCase(int N) {
    std::vector<int> arr(N);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, N);

    for (int i = 0; i < N; i++) {
        arr[i] = dis(gen);
    }
    return arr;
}

// Nueva función para ejecutar el algoritmo en los tres casos y medir el tiempo
void TestDataGenerator::runAllCases(int N, const std::function<void(std::vector<int>&)>& algorithm,
                                    std::vector<long long>& worstCaseTimes, std::vector<long long>& bestCaseTimes,
                                    std::vector<long long>& averageCaseTimes) {
    // Peor caso
    std::vector<int> worstCaseData = generateWorstCase(N);
    worstCaseTimes.push_back(Benchmark::measureExecutionTime([&]() { algorithm(worstCaseData); }));

    // Mejor caso
    std::vector<int> bestCaseData = generateBestCase(N);
    bestCaseTimes.push_back(Benchmark::measureExecutionTime([&]() { algorithm(bestCaseData); }));

    // Caso promedio
    std::vector<int> averageCaseData = generateAverageCase(N);
    averageCaseTimes.push_back(Benchmark::measureExecutionTime([&]() { algorithm(averageCaseData); }));
}
