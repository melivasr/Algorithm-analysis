
#include "../headers/TestDataGenerator.h"
#include <algorithm>
#include <random>


std::vector<int> TestDataGenerator::generateWorstCase(int N) {
    // Peor caso: los datos están en orden descendente
    std::vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        arr[i] = N - i;
    }
    return arr;
}

std::vector<int> TestDataGenerator::generateBestCase(int N) {
    // Mejor caso: los datos están en orden ascendente
    std::vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        arr[i] = i;
    }
    return arr;
}

std::vector<int> TestDataGenerator::generateAverageCase(int N) {
    // Caso promedio: los datos están en orden aleatorio
    std::vector<int> arr(N);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, N);

    for (int i = 0; i < N; i++) {
        arr[i] = dis(gen);
    }
    return arr;
}
