#ifndef TEST_DATA_GENERATOR_H
#define TEST_DATA_GENERATOR_H

#include <vector>

class TestDataGenerator {
public:
    static std::vector<int> generateWorstCase(int N);
    static std::vector<int> generateBestCase(int N);
    static std::vector<int> generateAverageCase(int N);
};

#endif // TEST_DATA_GENERATOR_H
