#include "MultiGraphPlotter.h"
#include <QtCharts/QValueAxis>

MultiGraphPlotter::MultiGraphPlotter(QWidget *parent) : QWidget(parent) {
    // Crear un grid layout para organizar los gráficos en filas y columnas
    QGridLayout *gridLayout = new QGridLayout(this);
    setLayout(gridLayout);
}

void MultiGraphPlotter::addGraph(const QString& algorithmName, const std::vector<long long>& empiricalData,
                                 const std::vector<long long>& theoreticalData, const std::vector<int>& valuesN,
                                 const QString& theoreticalComplexity, int row, int col) {
    // Crear las series de datos
    QLineSeries *empiricalSeries = new QLineSeries();
    QLineSeries *theoreticalSeries = new QLineSeries();

    // Factor de escala para hacer que la línea teórica sea más visible
    double scalingFactor = 8.0;

    // Llenar los datos empíricos y teóricos (aplicando un factor de escala a los teóricos)
    for (size_t i = 0; i < valuesN.size(); ++i) {
        empiricalSeries->append(valuesN[i], empiricalData[i]);
        theoreticalSeries->append(valuesN[i], theoreticalData[i] * scalingFactor);  // Escalar los valores teóricos
    }

    empiricalSeries->setName(algorithmName + " Empirical");
    theoreticalSeries->setName("Theoretical: " + theoreticalComplexity);

    // Crear un gráfico para los datos
    QChart *chart = new QChart();
    chart->addSeries(empiricalSeries);
    chart->addSeries(theoreticalSeries);
    chart->setTitle(algorithmName);
    chart->createDefaultAxes();

    // Ajustar ejes
    QValueAxis *axisX = new QValueAxis();
    axisX->setTitleText("Input Size N");
    axisX->setRange(valuesN.front(), valuesN.back());  // Ajuste del rango del eje X
    chart->setAxisX(axisX, empiricalSeries);

    QValueAxis *axisY = new QValueAxis();

    // Ajustar el rango del eje Y para incluir los valores teóricos escalados
    long long maxEmpirical = *std::max_element(empiricalData.begin(), empiricalData.end());
    long long maxTheoretical = *std::max_element(theoreticalData.begin(), theoreticalData.end()) * scalingFactor;

    axisY->setTitleText("Execution Time (ns)");
    axisY->setRange(0, std::max(maxEmpirical, maxTheoretical) * 1.2);  // Aumentamos el rango del eje Y para dar espacio
    chart->setAxisY(axisY, empiricalSeries);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Añadir el gráfico a las posiciones específicas del grid
    QGridLayout *gridLayout = static_cast<QGridLayout *>(this->layout());
    gridLayout->addWidget(chartView, row, col);
}
