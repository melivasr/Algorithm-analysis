#include <iostream>
#include <vector>
#include <cmath>
#include <QApplication>

#include "MultiGraphPlotter.h"
#include "../Algorithm-analysis/headers/SortAlgorithms.h"
#include "../Algorithm-analysis/headers/LinkedList.h"
#include "../Algorithm-analysis/headers/Benchmark.h"
#include "../Algorithm-analysis/GraphPlotter.h"
#include "headers/TestDataGenerator.h"
#include "../Algorithm-analysis/headers/BinarySearchTree.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Diferentes valores de N para realizar las pruebas
    std::vector<int> valuesN = {100, 200, 400, 800, 1600, 3200};

    // Datos para los tres casos de BubbleSort
    std::vector<long long> bubbleSortWorstEmpirical, bubbleSortWorstTheoretical;
    std::vector<long long> bubbleSortBestEmpirical, bubbleSortBestTheoretical;
    std::vector<long long> bubbleSortAverageEmpirical, bubbleSortAverageTheoretical;

    // Datos para los tres casos de MergeSort
    std::vector<long long> mergeSortWorstEmpirical, mergeSortWorstTheoretical;
    std::vector<long long> mergeSortBestEmpirical, mergeSortBestTheoretical;
    std::vector<long long> mergeSortAverageEmpirical, mergeSortAverageTheoretical;

    // Ejecución de pruebas para BubbleSort
    for (int n : valuesN) {
        // Peor caso: datos ordenados en orden inverso
        std::vector<int> testDataWorst = TestDataGenerator::generateWorstCase(n);
        long long empiricalTimeWorst = Benchmark::measureExecutionTime([&]() {
            SortAlgorithms::bubbleSort(testDataWorst);
        });
        long long theoreticalTimeWorst = n * n;  // O(n^2)
        bubbleSortWorstEmpirical.push_back(empiricalTimeWorst);
        bubbleSortWorstTheoretical.push_back(theoreticalTimeWorst);

        // Mejor caso: datos ya ordenados
        std::vector<int> testDataBest = TestDataGenerator::generateBestCase(n);
        long long empiricalTimeBest = Benchmark::measureExecutionTime([&]() {
            SortAlgorithms::bubbleSort(testDataBest);
        });
        long long theoreticalTimeBest = n;  // O(n) para BubbleSort en mejor caso
        bubbleSortBestEmpirical.push_back(empiricalTimeBest);
        bubbleSortBestTheoretical.push_back(theoreticalTimeBest);

        // Caso promedio: datos aleatorios
        std::vector<int> testDataAverage = TestDataGenerator::generateAverageCase(n);
        long long empiricalTimeAverage = Benchmark::measureExecutionTime([&]() {
            SortAlgorithms::bubbleSort(testDataAverage);
        });
        long long theoreticalTimeAverage = n * n;  // O(n^2)
        bubbleSortAverageEmpirical.push_back(empiricalTimeAverage);
        bubbleSortAverageTheoretical.push_back(theoreticalTimeAverage);
    }

    // ======================= Aquí colocamos el código de MergeSort ========================
    // Ejecución de pruebas para MergeSort
    for (int n : valuesN) {
        // Peor caso: datos ordenados en orden inverso
        std::vector<int> testDataWorst = TestDataGenerator::generateWorstCase(n);
        long long empiricalTimeWorst = Benchmark::measureExecutionTime([&]() {
            SortAlgorithms::mergeSort(testDataWorst);
        });
        long long theoreticalTimeWorst = n * std::log2(n);  // O(n log n)
        mergeSortWorstEmpirical.push_back(empiricalTimeWorst);
        mergeSortWorstTheoretical.push_back(theoreticalTimeWorst);

        // Mejor caso: datos ya ordenados
        std::vector<int> testDataBest = TestDataGenerator::generateBestCase(n);
        long long empiricalTimeBest = Benchmark::measureExecutionTime([&]() {
            SortAlgorithms::mergeSort(testDataBest);
        });
        long long theoreticalTimeBest = n * std::log2(n);  // O(n log n)
        mergeSortBestEmpirical.push_back(empiricalTimeBest);
        mergeSortBestTheoretical.push_back(theoreticalTimeBest);

        // Caso promedio: datos aleatorios
        std::vector<int> testDataAverage = TestDataGenerator::generateAverageCase(n);
        long long empiricalTimeAverage = Benchmark::measureExecutionTime([&]() {
            SortAlgorithms::mergeSort(testDataAverage);
        });
        long long theoreticalTimeAverage = n * std::log2(n);  // O(n log n)
        mergeSortAverageEmpirical.push_back(empiricalTimeAverage);
        mergeSortAverageTheoretical.push_back(theoreticalTimeAverage);
    }

    // Crear una única ventana con todos los gráficos en una cuadrícula
    MultiGraphPlotter multiGraphPlotter;

    // Graficar los tres casos para BubbleSort
    multiGraphPlotter.addGraph("BubbleSort (Worst Case)", bubbleSortWorstEmpirical, bubbleSortWorstTheoretical, valuesN, "O(n^2)", 0, 0);
    multiGraphPlotter.addGraph("BubbleSort (Best Case)", bubbleSortBestEmpirical, bubbleSortBestTheoretical, valuesN, "O(n)", 0, 1);
    multiGraphPlotter.addGraph("BubbleSort (Average Case)", bubbleSortAverageEmpirical, bubbleSortAverageTheoretical, valuesN, "O(n^2)", 0, 2);

    // Graficar los tres casos para MergeSort
    multiGraphPlotter.addGraph("MergeSort (Worst Case)", mergeSortWorstEmpirical, mergeSortWorstTheoretical, valuesN, "O(n log n)", 1, 0);
    multiGraphPlotter.addGraph("MergeSort (Best Case)", mergeSortBestEmpirical, mergeSortBestTheoretical, valuesN, "O(n log n)", 1, 1);
    multiGraphPlotter.addGraph("MergeSort (Average Case)", mergeSortAverageEmpirical, mergeSortAverageTheoretical, valuesN, "O(n log n)", 1, 2);

    multiGraphPlotter.resize(1200, 800);
    multiGraphPlotter.show();

    return app.exec();
}
