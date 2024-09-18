#include <iostream>
#include <vector>
#include "../Algorithm-analysis/headers/SortAlgorithms.h"
#include "../Algorithm-analysis/headers/LinkedList.h"
#include "../Algorithm-analysis/headers/Benchmark.h"

int main() {
    // Ejemplo de medición para BubbleSort
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    long long time = Benchmark::measureExecutionTime([&]() {
        SortAlgorithms::bubbleSort(arr);
    });

    std::cout << "BubbleSort execution time: " << time << " nanoseconds\n";

    // Ejemplo de uso de LinkedList
    LinkedList list;
    list.insert(5);
    list.insert(10);
    list.insert(15);
    list.display();

    // Ejemplo de búsqueda en LinkedList
    std::cout << "Search for 10: " << (list.search(10) ? "Found" : "Not Found") << "\n";

    return 0;
}
