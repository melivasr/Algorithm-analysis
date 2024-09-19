#include "../../headers/SortAlgorithms.h"
#include <vector>

// Implementación del algoritmo Bubble Sort
void SortAlgorithms::bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    bool swapped; // Indicador de si hubo un intercambio
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]); // Intercambiar si el valor es mayor
                swapped = true;
            }
        }
        if (!swapped) { // Si no hubo intercambio, la lista ya está ordenada
            break;
        }
    }
}

// Implementación del algoritmo Selection Sort
void SortAlgorithms::selectionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j; // Encontrar el índice del valor mínimo
            }
        }
        std::swap(arr[i], arr[minIndex]); // Colocar el valor mínimo en su lugar
    }
}

// Función auxiliar para combinar sub-arreglos en Merge Sort
void SortAlgorithms::merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1), R(n2); // Arreglos temporales

    // Copiar datos a los sub-arreglos L y R
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    // Combinar los sub-arreglos en uno ordenado
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de L, si los hay
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de R, si los hay
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Implementación recursiva de Merge Sort
void SortAlgorithms::mergeSortRecursive(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Ordenar primero las mitades izquierda y derecha
        mergeSortRecursive(arr, left, mid);
        mergeSortRecursive(arr, mid + 1, right);

        // Combinar las dos mitades
        merge(arr, left, mid, right);
    }
}

// Función que inicia el proceso de Merge Sort
void SortAlgorithms::mergeSort(std::vector<int>& arr) {
    mergeSortRecursive(arr, 0, arr.size() - 1);
}
