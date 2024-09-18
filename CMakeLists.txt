cmake_minimum_required(VERSION 3.28)
project(Algorithm_analysis)

# Usar C++17
set(CMAKE_CXX_STANDARD 17)

# Encontrar Qt5 (incluyendo el módulo QtCharts)
find_package(Qt5 REQUIRED COMPONENTS Widgets Charts)

# Incluir directorios de encabezados para Qt5
include_directories(${Qt5Widgets_INCLUDE_DIRS} ${Qt5Charts_INCLUDE_DIRS})

# Agregar las bibliotecas de Qt5
link_directories(${Qt5Widgets_LIBRARY_DIRS} ${Qt5Charts_LIBRARY_DIRS})

# Definir flags para el compilador y el enlazador
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
set(CMAKE_LDFLAGS "${CMAKE_LDFLAGS}")

# Archivos fuente del proyecto
add_executable(Algorithm_analysis main.cpp
        source/SortAlgorithms.cpp
        headers/SortAlgorithms.h
        source/LinkedList.cpp
        headers/LinkedList.h
        source/Benchmark.cpp
        headers/Benchmark.h
        source/BinarySearchTree.cpp
        headers/BinarySearchTree.h
        source/TestDataGenerator.cpp
        headers/TestDataGenerator.h
        GraphPlotter.cpp
        GraphPlotter.h)

# Especificar que el proyecto usa las bibliotecas de Qt5
target_link_libraries(Algorithm_analysis Qt5::Widgets Qt5::Charts)
