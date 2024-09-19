cmake_minimum_required(VERSION 3.28)
project(Algorithm_analysis)

# Usar C++17
set(CMAKE_CXX_STANDARD 17)

# Habilitar moc para clases Qt (necesario para Q_OBJECT)
set(CMAKE_AUTOMOC ON)

# Encontrar Qt5 (incluyendo el módulo QtCharts)
find_package(Qt5 REQUIRED COMPONENTS Widgets Charts)

# Incluir directorios de encabezados para Qt5
include_directories(${Qt5Widgets_INCLUDE_DIRS} ${Qt5Charts_INCLUDE_DIRS})

# Agregar las bibliotecas de Qt5
link_directories(${Qt5Widgets_LIBRARY_DIRS} ${Qt5Charts_LIBRARY_DIRS})

# Archivos fuente del proyecto
add_executable(Algorithm_analysis main.cpp
        source/algorithms/SortAlgorithms.cpp
        headers/SortAlgorithms.h
        source/algorithms/LinkedList.cpp
        headers/LinkedList.h
        source/utilities/Benchmark.cpp
        headers/Benchmark.h
        source/algorithms/BinarySearchTree.cpp
        headers/BinarySearchTree.h
        source/utilities/TestDataGenerator.cpp
        headers/TestDataGenerator.h
        source/plot/MultiGraphPlotter.cpp
        headers/MultiGraphPlotter.h
        source/utilities/AlgorithmManager.cpp
        headers/AlgorithmManager.h)

# Especificar que el proyecto usa las bibliotecas de Qt5
target_link_libraries(Algorithm_analysis Qt5::Widgets Qt5::Charts)
