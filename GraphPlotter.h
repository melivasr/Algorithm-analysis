#ifndef CHART_PLOTTER_H
#define CHART_PLOTTER_H

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QWidget>

QT_CHARTS_USE_NAMESPACE

class GraphPlotter : public QWidget {
public:
    GraphPlotter(QWidget *parent = nullptr);

    void plotGraph(const std::vector<long long>& empiricalData, const std::vector<long long>& theoreticalData, const std::vector<int>& valuesN);
};

#endif // CHART_PLOTTER_H
