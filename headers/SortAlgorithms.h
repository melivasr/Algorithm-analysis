#ifndef SORT_ALGORITHMS_H
#define SORT_ALGORITHMS_H

#include <vector>

class SortAlgorithms {
public:
    static void bubbleSort(std::vector<int>& arr);
    static void selectionSort(std::vector<int>& arr);
    static void mergeSort(std::vector<int>& arr);

private:
    static void merge(std::vector<int>& arr, int left, int mid, int right);
    static void mergeSortRecursive(std::vector<int>& arr, int left, int right);
};

#endif // SORT_ALGORITHMS_H

