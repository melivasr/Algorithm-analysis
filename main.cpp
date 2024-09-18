#include <iostream>
#include <vector>
#include <QApplication>
#include "../Algorithm-analysis/headers/SortAlgorithms.h"
#include "../Algorithm-analysis/headers/LinkedList.h"
#include "../Algorithm-analysis/headers/Benchmark.h"
#include "../Algorithm-analysis/GraphPlotter.h"
#include "headers/TestDataGenerator.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    const int N = 1000;
    std::vector<int> valuesN = {100, 200, 400, 800, 1000};  // Ejemplo de tamaños N
    std::vector<long long> empiricalData;
    std::vector<long long> theoreticalData;

    for (int n : valuesN) {
        // Generar los datos de prueba
        std::vector<int> testData = TestDataGenerator::generateAverageCase(n);

        // Medir el tiempo empírico para BubbleSort
        long long empiricalTime = Benchmark::measureExecutionTime([&]() {
            SortAlgorithms::bubbleSort(testData);
        });

        // Complejidad teórica O(n^2) para BubbleSort
        long long theoreticalTime = n * n;  // Aproximación teórica

        empiricalData.push_back(empiricalTime);
        theoreticalData.push_back(theoreticalTime);
    }

    // Crear la ventana de la gráfica
    GraphPlotter chartPlotter;
    chartPlotter.plotGraph(empiricalData, theoreticalData, valuesN);

    chartPlotter.resize(800, 600);
    chartPlotter.show();

    return app.exec();
}
