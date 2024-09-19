#ifndef ALGORITHM_MANAGER_H
#define ALGORITHM_MANAGER_H

#include <functional>
#include <map>
#include <vector>
#include <string>

class AlgorithmManager {
public:
    static std::map<std::string, std::function<void(std::vector<int>&)>> getAlgorithms();
    static std::map<std::string, std::tuple<std::string, std::string, std::string>> getComplexities();
};

#endif // ALGORITHM_MANAGER_H
