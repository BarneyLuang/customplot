#include "mainwindow.h"
#include "ui_mainwindow.h"

const int Plot1_MinY = 0;
const int Plot1_MaxY = 2000;
const float Plot1_MaxX = 2.0;
const QColor TextColor = Qt::red;
const int TextWidth =5;
const int Plot_Screen_Point_Count = 20;
const QColor Plot1_LineColor  = Qt::blue;
const int Plot_PI = 3.5;
const int Plot_Sample_Frequency =1;
const int Plot_Signal_Frequency =2;
const int LineWidth =1;
const QColor Plot1_DotColor = Qt::green;
const int DotWidth =5;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    ui->setupUi(this);

    // 设置纵坐标名称
    ui->widgetPlot->yAxis->setLabel("应变应力(单位:με)");

    // 设置纵坐标范围
    ui->widgetPlot->yAxis->setRange(Plot1_MinY, Plot1_MaxY);

    // 设置横坐标范围
    ui->widgetPlot->xAxis->setRange(0, Plot1_MaxX);

    //设置坐标颜色/坐标名称颜色
    ui->widgetPlot->yAxis->setLabelColor(TextColor);
    ui->widgetPlot->xAxis->setTickLabelColor(TextColor);
    ui->widgetPlot->yAxis->setTickLabelColor(TextColor);
    ui->widgetPlot->xAxis->setBasePen(QPen(TextColor, TextWidth));
    ui->widgetPlot->yAxis->setBasePen(QPen(TextColor, TextWidth));
    ui->widgetPlot->xAxis->setTickPen(QPen(TextColor, TextWidth));
    ui->widgetPlot->yAxis->setTickPen(QPen(TextColor, TextWidth));
    ui->widgetPlot->xAxis->setSubTickPen(QPen(TextColor, TextWidth));
    ui->widgetPlot->yAxis->setSubTickPen(QPen(TextColor, TextWidth));
    ui->widgetPlot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->widgetPlot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);

    //设置画布背景色
    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(80, 80, 80));
    plotGradient.setColorAt(1, QColor(50, 50, 50));
    ui->widgetPlot->setBackground(plotGradient);

    //设置坐标背景色
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(80, 80, 80));
    axisRectGradient.setColorAt(1, QColor(30, 30, 30));
    ui->widgetPlot->axisRect()->setBackground(axisRectGradient);

    //设置图例提示位置及背景色
    ui->widgetPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop | Qt::AlignRight);
    ui->widgetPlot->legend->setBrush(QColor(255, 255, 255, 200));

    // 字体
    QFont tickLabelFont("微软雅黑", 12, QFont::Light);
    ui->widgetPlot->xAxis->setTickLabelFont(tickLabelFont);
    ui->widgetPlot->yAxis->setTickLabelFont(tickLabelFont);
    ui->widgetPlot->yAxis->setLabelFont(tickLabelFont);

    // 曲线
    QVector<double> plot_keys;
    QVector<double> plot_values;
    for (int i=0; i<Plot_Screen_Point_Count; i++)
    {
        double xValue = i / Plot_Sample_Frequency;
        double yValue = 1000 * sin(2 * Plot_PI * Plot_Signal_Frequency * xValue);
        plot_keys.append(xValue);
        plot_values.append(yValue);
    }
    ui->widgetPlot->addGraph();
    ui->widgetPlot->graph(0)->setName("力度值(单位:N)");
    ui->widgetPlot->graph(0)->setPen(QPen(Plot1_LineColor, LineWidth));
    ui->widgetPlot->graph(0)->setScatterStyle(
                QCPScatterStyle(QCPScatterStyle::ssCircle,
                                QPen(Plot1_DotColor, LineWidth),
                                QBrush(Plot1_DotColor), DotWidth));

    // 设置静态曲线的横坐标范围及自适应横坐标
    ui->widgetPlot->xAxis->setRange(0, Plot1_MaxX, Qt::AlignLeft);

    ui->widgetPlot->graph(0)->setData(plot_keys, plot_values);
    ui->widgetPlot->graph(0)->rescaleAxes();

    ui->widgetPlot->replot();

}

MainWindow::~MainWindow()
{
    delete ui;
}
