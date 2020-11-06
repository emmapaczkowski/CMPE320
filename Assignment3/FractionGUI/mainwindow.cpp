#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "fractionLibrary/fraction.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Emma's Fraction Calculator Application");
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString fracOneNumer;
QString fracTwoNumer;
QString fracOneDenumer;
QString fracTwoDenumer;

void MainWindow::on_Calculate_clicked()
{
    fracOneNumer = ui->FracOneNum->text();
    fracTwoNumer = ui->FracTwoNum->text();
    fracOneDenumer = ui->FracOneDenum->text();
    fracTwoDenumer = ui->FracTwoDenum->text();

    QRegExp re("\\d*");  // a digit (\d), zero or more times (*)
    if (!re.exactMatch(fracOneNumer) || !re.exactMatch(fracTwoNumer) || !re.exactMatch(fracOneDenumer) || !re.exactMatch(fracTwoDenumer)) {
        ui->calOutput->setText("Please ensure you are only using numeric values.");
        return;
    } else {
         ui->calOutput->setText(" ");

    }

    bool ok;
    int f1n = fracOneNumer.toInt(&ok);
    if (!ok) {
      // ui->calOutput->setText("Failed to convert");
    }
    int f1d = fracOneDenumer.toInt();
    int f2n = fracTwoNumer.toInt();
    int f2d = fracTwoDenumer.toInt();
    Fraction one = (f1d, f1d);
    //ui->calOutput->setText("worked");
    //ui->calOutput->setText(QString::number(f1n));


}

