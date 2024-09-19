#ifndef TEST_DATA_GENERATOR_H
#define TEST_DATA_GENERATOR_H

#include <vector>
#include <functional>

class TestDataGenerator {
public:
    static std::vector<int> generateWorstCase(int N);
    static std::vector<int> generateBestCase(int N);
    static std::vector<int> generateAverageCase(int N);

    // Nueva función para generar todos los casos y ejecutar el algoritmo
    static void runAllCases(int N, const std::function<void(std::vector<int>&)>& algorithm,
                            std::vector<long long>& worstCaseTimes, std::vector<long long>& bestCaseTimes,
                            std::vector<long long>& averageCaseTimes);
};

#endif // TEST_DATA_GENERATOR_H
