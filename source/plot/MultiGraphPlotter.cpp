#include "../../headers/MultiGraphPlotter.h"
#include <QtCharts/QValueAxis>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QApplication>

MultiGraphPlotter::MultiGraphPlotter(const QString& algorithmName, QWidget *parent) : QWidget(parent) {
    // Crear un layout vertical
    QVBoxLayout *layout = new QVBoxLayout;

    // Agregar el título del algoritmo
    addAlgorithmTitle(layout, algorithmName);

    // Crear un grid layout para organizar los gráficos en filas y columnas
    mainLayout = new QGridLayout;
    layout->addLayout(mainLayout);

    // Crear y agregar el botón de salida
    createExitButton(layout);

    setLayout(layout);
}

void MultiGraphPlotter::addAlgorithmTitle(QVBoxLayout *layout, const QString& algorithmName) {
    QLabel *algorithmTitle = new QLabel("Running: " + algorithmName);
    QFont font = algorithmTitle->font();
    font.setPointSize(16);
    algorithmTitle->setFont(font);
    algorithmTitle->setAlignment(Qt::AlignCenter);
    layout->addWidget(algorithmTitle);
}

void MultiGraphPlotter::createExitButton(QVBoxLayout *layout) {
    QPushButton *exitButton = new QPushButton("Salir");
    QFont font = exitButton->font();
    font.setPointSize(14);
    exitButton->setFont(font);
    exitButton->setStyleSheet("background-color: red; color: white;");
    layout->addWidget(exitButton);
    connect(exitButton, &QPushButton::clicked, QApplication::instance(), &QApplication::quit);
}
void MultiGraphPlotter::addGraph(const QString& caseName, const std::vector<long long>& empiricalData,
                                 const std::vector<long long>& theoreticalData, const std::vector<int>& valuesN,
                                 const QString& theoreticalComplexity, int row, int col) {
    QLineSeries *empiricalSeries = new QLineSeries();
    QLineSeries *theoreticalSeries = new QLineSeries();

    // Factor de escala predeterminado
    double scalingFactor = 5.0;

    // Aplicar el factor de escala solo a los teóricos si es necesario
    for (size_t i = 0; i < valuesN.size(); ++i) {
        empiricalSeries->append(valuesN[i], empiricalData[i]);
        theoreticalSeries->append(valuesN[i], theoreticalData[i] * scalingFactor);
    }

    empiricalSeries->setName(caseName + " Empirical");
    theoreticalSeries->setName("Theoretical: " + theoreticalComplexity);

    // Crear un gráfico para los datos
    QChart *chart = new QChart();
    chart->addSeries(empiricalSeries);
    chart->addSeries(theoreticalSeries);
    chart->setTitle(caseName);

    // Configurar ejes
    QValueAxis *axisX = new QValueAxis();
    axisX->setTitleText("Input Size N");
    axisX->setRange(valuesN.front(), valuesN.back());

    QValueAxis *axisY = new QValueAxis();
    long long maxEmpirical = *std::max_element(empiricalData.begin(), empiricalData.end());
    long long maxTheoretical = *std::max_element(theoreticalData.begin(), theoreticalData.end()) * scalingFactor;
    axisY->setTitleText("Execution Time (ns)");
    axisY->setRange(0, std::max(maxEmpirical, maxTheoretical) * 1.2);

    // Añadir ejes y series al gráfico
    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);
    empiricalSeries->attachAxis(axisX);
    empiricalSeries->attachAxis(axisY);
    theoreticalSeries->attachAxis(axisX);
    theoreticalSeries->attachAxis(axisY);

    // Añadir el gráfico al layout
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setFixedSize(580, 500);
    mainLayout->addWidget(chartView, row, col);
}
