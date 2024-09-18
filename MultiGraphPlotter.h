#ifndef MULTIGRAPHPLOTTER_H
#define MULTIGRAPHPLOTTER_H

#include <QWidget>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QGridLayout>

QT_CHARTS_USE_NAMESPACE

class MultiGraphPlotter : public QWidget {
public:
    MultiGraphPlotter(QWidget *parent = nullptr);

    // Función que acepta el nombre del algoritmo y la complejidad teórica
    void addGraph(const QString& algorithmName, const std::vector<long long>& empiricalData,
                  const std::vector<long long>& theoreticalData, const std::vector<int>& valuesN,
                  const QString& theoreticalComplexity, int row, int col);

private:
    QGridLayout *mainLayout;  // Disposición en cuadrícula para contener gráficos y etiquetas
};

#endif // MULTIGRAPHPLOTTER_H
