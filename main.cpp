#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include "headers/TestDataGenerator.h"
#include "headers/Benchmark.h"
#include "headers/MultiGraphPlotter.h"
#include <QApplication>
#include "headers/AlgorithmManager.h"


// Función unificada para ejecutar el algoritmo y generar las gráficas
void runAlgorithmAndPlot(MultiGraphPlotter* plotter, const std::function<void(std::vector<int>&)>& algorithmFunc,
                         const std::tuple<std::string, std::string, std::string>& complexities, const std::vector<int>& valuesN) {
    std::vector<long long> worstEmpirical, bestEmpirical, averageEmpirical;

    // Ejecutar los casos de prueba para cada valor de N
    for (int N : valuesN) {
        TestDataGenerator::runAllCases(N, algorithmFunc, worstEmpirical, bestEmpirical, averageEmpirical);
    }

    // Obtener las complejidades
    auto [worstComplexity, bestComplexity, averageComplexity] = complexities;

    // Generar y agregar las gráficas
    plotter->addGraph("Worst Case", worstEmpirical, Benchmark::calculateTheoreticalTimes(valuesN, worstComplexity), valuesN, QString::fromStdString(worstComplexity), 0, 0);
    plotter->addGraph("Best Case", bestEmpirical, Benchmark::calculateTheoreticalTimes(valuesN, bestComplexity), valuesN, QString::fromStdString(bestComplexity), 0, 1);
    plotter->addGraph("Average Case", averageEmpirical, Benchmark::calculateTheoreticalTimes(valuesN, averageComplexity), valuesN, QString::fromStdString(averageComplexity), 0, 2);
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    if (argc < 2) {
        std::cerr << "Debe especificar un algoritmo como argumento: 'BS', 'SS', 'MS', 'LL', 'BST'.\n";
        return 1;
    }

    std::string algorithmAbbr = argv[1];

    // Obtener los algoritmos y sus complejidades desde AlgorithmManager
    auto algorithms = AlgorithmManager::getAlgorithms();
    auto complexities = AlgorithmManager::getComplexities();

    // Verificar si el algoritmo especificado es válido
    if (algorithms.find(algorithmAbbr) == algorithms.end()) {
        std::cerr << "Error: Algoritmo no reconocido. Use 'BS', 'MS', 'SS', 'LL', o 'BST'.\n";
        return 1;
    }

    // Crear las gráficas
    MultiGraphPlotter plotter(QString::fromStdString(algorithmAbbr));

    // Definir los tamaños de N para cada algoritmo
    std::vector<int> valuesN = {100, 500, 1000, 5000};  // Tamaños comunes de N

    // Ejecutar las pruebas y generar gráficas
    runAlgorithmAndPlot(&plotter, algorithms[algorithmAbbr], complexities[algorithmAbbr], valuesN);

    plotter.resize(1600, 600);
    plotter.show();

    return app.exec();
}
