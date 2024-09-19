#ifndef MULTIGRAPHPLOTTER_H
#define MULTIGRAPHPLOTTER_H

#include <QWidget>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QGridLayout>

QT_CHARTS_USE_NAMESPACE

class MultiGraphPlotter : public QWidget {
public:
    MultiGraphPlotter(const QString& algorithmName, QWidget *parent = nullptr);

    void addGraph(const QString& caseName, const std::vector<long long>& empiricalData,
                  const std::vector<long long>& theoreticalData, const std::vector<int>& valuesN,
                  const QString& theoreticalComplexity, int row, int col);

private:
    QGridLayout *mainLayout;
    void createExitButton(QVBoxLayout *layout);
    void addAlgorithmTitle(QVBoxLayout *layout, const QString& algorithmName);
};

#endif // MULTIGRAPHPLOTTER_H
