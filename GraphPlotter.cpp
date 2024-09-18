#include "GraphPlotter.h"
#include <QtCharts/QValueAxis>
#include <QVBoxLayout>

GraphPlotter::GraphPlotter(QWidget *parent) : QWidget(parent) {}

void GraphPlotter::plotGraph(const std::vector<long long>& empiricalData, const std::vector<long long>& theoreticalData, const std::vector<int>& valuesN) {
    QLineSeries *empiricalSeries = new QLineSeries();
    QLineSeries *theoreticalSeries = new QLineSeries();

    // Agregar los puntos para los tiempos empíricos
    for (size_t i = 0; i < valuesN.size(); ++i) {
        empiricalSeries->append(valuesN[i], empiricalData[i]);
        theoreticalSeries->append(valuesN[i], theoreticalData[i]);
    }

    empiricalSeries->setName("Empirical Times");
    theoreticalSeries->setName("Theoretical Times");

    QChart *chart = new QChart();
    chart->addSeries(empiricalSeries);
    chart->addSeries(theoreticalSeries);
    chart->setTitle("Empirical vs Theoretical Times");
    chart->createDefaultAxes();

    // Ejes
    QValueAxis *axisX = new QValueAxis();
    axisX->setTitleText("Input Size N");
    chart->setAxisX(axisX, empiricalSeries);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Execution Time (ns)");
    chart->setAxisY(axisY, empiricalSeries);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Agregar el gráfico a un layout de la ventana
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(chartView);
    setLayout(layout);
}

