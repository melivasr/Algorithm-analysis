#include <map>
#include "../../headers/SortAlgorithms.h"
#include "../../headers/BinarySearchTree.h"
#include "../../headers/LinkedList.h"
#include "../../headers/TestDataGenerator.h"
#include "../../headers/Benchmark.h"
#include "../../headers/MultiGraphPlotter.h"
#include "../../headers/AlgorithmManager.h"
#include <random>

std::map<std::string, std::function<void(std::vector<int>&)>> AlgorithmManager::getAlgorithms() {
    return {
        // Algoritmos de ordenamiento
        {"BS", SortAlgorithms::bubbleSort},
        {"SS", SortAlgorithms::selectionSort},
        {"MS", SortAlgorithms::mergeSort},

        // LinkedList: Medir solo el tiempo de búsqueda
        {"LL", [](std::vector<int>& arr) {
            LinkedList list;
            for (int data : arr) {
                list.insert(data);  // Lista ordenada al insertar
            }
            // Medir los tiempos de búsqueda
            Benchmark::measureExecutionTime([&]() { list.search(arr.front()); });  // Mejor caso
            Benchmark::measureExecutionTime([&]() { list.search(arr.back()); });   // Peor caso
            Benchmark::measureExecutionTime([&]() { list.search(arr[arr.size() / 2]); });  // Caso promedio
        }},

        // Binary Search Tree: Medir solo el tiempo de inserción
        {"BST", [](std::vector<int>& arr) {
            BinarySearchTree bst;
            Benchmark::measureExecutionTime([&]() { bst.insert(arr[arr.size() / 2]); });
            Benchmark::measureExecutionTime([&]() {
                for (int i = 0; i < arr.size(); i++) {
                    bst.insert(arr[i]);  // Inserción en orden (peor caso)
                }
            });
            std::shuffle(arr.begin(), arr.end(), std::default_random_engine());
            Benchmark::measureExecutionTime([&]() {
                for (int data : arr) {
                    bst.insert(data);  // Inserción aleatoria (caso promedio)
                }
            });
        }},
    };
}

std::map<std::string, std::tuple<std::string, std::string, std::string>> AlgorithmManager::getComplexities() {
    return {
        {"BS", {"O(n^2)", "O(n)", "O(n^2)"}},  // Bubble Sort
        {"SS", {"O(n^2)", "O(n^2)", "O(n^2)"}}, // Selection Sort
        {"MS", {"O(n log n)", "O(n log n)", "O(n log n)"}}, // Merge Sort
        {"LL", {"O(n)", "O(1)", "O(n)"}},  // Linked List
        {"BST", {"O(n)", "O(log n)", "O(log n)"}}  // Binary Search Tree
    };
}
