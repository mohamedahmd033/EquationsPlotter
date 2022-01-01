#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include "Equation_Plotter.h"
using namespace std;

Equation_Plotter plotter;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(979,951);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_PlotButton_clicked()
{
    string equation;
    string XaxisLabel;
    string YaxisLabel;
    errorType error;
    float max_x;
    float min_x;
    float max_y;
    float min_y;
    float step;


    equation = ui->functionInput->text().toStdString();
    XaxisLabel = ui->xLabel->text().toStdString();
    YaxisLabel = ui->yLabel->text().toStdString();
    max_x = ui->maxXspinBox->value();
    min_x = ui->minXspinBox->value();
    max_y = ui->maxYspinBox->value();
    min_y = ui->minYspinBox->value();
    step =  ui->stepSpinBox->value();


    plotter.setEquation(equation);
    plotter.setMax_x(max_x);
    plotter.setMin_x(min_x);
    plotter.setMax_y(max_y);
    plotter.setMin_y(min_y);
    plotter.setStep(step);
    plotter.setXaxisLabel(XaxisLabel);
    plotter.setYaxisLabel(YaxisLabel);

     ui->statusField->clear();


    if(plotter.checkConfigErrors()==true)
    {
        ui->statusField->setStyleSheet("QTextBrowser {color : red; }");
        ui->statusField->setText( QString::fromStdString( plotter.getErrorConfig() ) );
    }
    else
    {
        if(plotter.equationIsValid() == true)
        {
            ui->statusField->setStyleSheet("QTextBrowser {color : blue; }");
            ui->statusField->setText( "f(x) = "+QString::fromStdString( plotter.getEquation() ) );
            makePlot();
        }
        else
        {

            ui->statusField->setStyleSheet("QTextBrowser {color : red; }");
            ui->statusField->setText( QString::fromStdString( plotter.getEquationError() ) );

            //ui->statusField->setHtml("<font color='red'>"+Qerror+"</font>");



        }
    }
}


void MainWindow::makePlot()
{
    string textOut;
    // generate data:
     plotter.insert_XandY_values();

    // create graph and assign data to it:
     ui->customPlot->addGraph();
     ui->customPlot->graph(0)->setData(QVector<double>::fromStdVector (plotter.getXvalues()),
                                       QVector<double>::fromStdVector (plotter.getYvalues()));

     // give the axes some labels:
     ui->customPlot->xAxis->setLabel(QString::fromStdString( plotter.getXaxisLabel() ));
     ui->customPlot->yAxis->setLabel(QString::fromStdString( plotter.getYaxisLabel() ));

     // set axes ranges, so we see all data:
     ui->customPlot->xAxis->setRange(plotter.getMin_x(), plotter.getMax_x());
     ui->customPlot->yAxis->setRange(plotter.getMin_y(), plotter.getMax_y());
     ui->customPlot->replot();

     //print status data
     textOut = "f(x) = " + plotter.getEquation() + "\n"\
             + "Min of x: " + to_string(plotter.getMin_x()) + "          Max of x: " + to_string(plotter.getMax_x()) + "\n"\
             + "Min of y: " + to_string(plotter.getMin_y()) + "          Max of y: " + to_string(plotter.getMax_y()) + "\n";

     ui->statusField->setStyleSheet("QTextBrowser {color : blue }");
     ui->statusField->setText( QString::fromStdString(textOut) );
}
