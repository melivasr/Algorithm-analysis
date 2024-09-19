# Proyecto de Análisis de Algoritmos

Este proyecto analiza los tiempos de ejecución empíricos y teóricos de algoritmos de ordenamiento y operaciones en estructuras de datos. Visualiza el rendimiento utilizando gráficas para comparar las complejidades de peor, mejor y caso promedio para cada algoritmo.

## Tabla de Contenidos

- [Descripción del Proyecto](#descripción-del-proyecto)
- [Características](#características)
- [Instalación](#instalación)
- [Uso](#uso)
- [Algoritmos](#algoritmos)
- [Consideraciones](#consideraciones)

## Descripción del Proyecto

Este proyecto implementa y evalúa varios algoritmos, incluyendo algoritmos de ordenamiento (Bubble Sort, Selection Sort, Merge Sort) y operaciones en estructuras de datos como LinkedList y Árboles BinarySearchTree. Los algoritmos se prueban bajo diferentes casos (peor, mejor y promedio) y se comparan sus tiempos de ejecución con las complejidades teóricas. Los resultados se muestran en gráficos interactivos.

## Características

- **Algoritmos de Ordenamiento:** Bubble Sort, Selection Sort, Merge Sort.
- **Estructuras de Datos:** LinkedList Search, BinarySearchTree Insert
- **Medición de Tiempos Empíricos:** Mide los tiempos reales de ejecución utilizando datos reales.
- **Cálculo de Tiempos Teóricos:** Compara los tiempos empíricos con las complejidades teóricas.
- **Visualización de Gráficas:** Muestra los tiempos empíricos y teóricos en gráficos interactivos.

## Instalación

### Prerrequisitos

Asegúrate de tener instalados los siguientes componentes:

- **Compilador de C++** (compatible con C++17)
- **CMake** (versión 3.28 o superior)
- **Bibliotecas de Qt5** (Qt5 Widgets y Qt5 Charts)

### Instalación en Ubuntu

1. Instala las dependencias de Qt5 desde la terminal:

    ```bash
    sudo apt-get update
    sudo apt-get install qt5-default libqtcharts5-dev
    ```

2. Clona el repositorio:

    ```bash
    git clone https://github.com/melivasr/Algorithm_analysis.git
    cd Algorithm_analysis
    ```

3. Compila el proyecto usando CMake:

    ```bash
    mkdir build
    cd build
    cmake ..
    make
    ```

4. Ejecuta el ejecutable:

    ```bash
    ./Algorithm_analysis <algoritmo>
    ```

    Reemplaza `<algoritmo>` con uno de los siguientes códigos:
    - `BS` para Bubble Sort
    - `SS` para Selection Sort
    - `MS` para Merge Sort
    - `LL` para la operación de búsqueda en LinkedList
    - `BST` para la operación de inserción en BinarySearchTree

### Instalación en Windows

Este proyecto fue desarrollado y probado en Linux (Ubuntu), por lo que pueden existir variaciones en su comportamiento al ejecutarse en Windows. Si deseas ejecutarlo en Windows, asegúrate de instalar las bibliotecas de Qt5 compatibles y un compilador adecuado. Puedes usar herramientas como **WSL (Windows Subsystem for Linux)** para emular un entorno de Linux en tu sistema Windows.

## Uso

A continuación, un ejemplo de ejecución:

```bash
./Algorithm_analysis BS
```
Los gráficos deben mostrarse de la siguiente manera:

![Gráficos de ejecución](https://github.com/user-attachments/assets/fe6a2665-5af7-4062-b318-6ac38c8329c6)
