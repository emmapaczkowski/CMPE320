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
    Fraction answer;
    fracOneNumer = ui->FracOneNum->text();
    fracTwoNumer = ui->FracTwoNum->text();
    fracOneDenumer = ui->FracOneDenum->text();
    fracTwoDenumer = ui->FracTwoDenum->text();

    QRegExp re("\\d*");  // a digit (\d), zero or more times (*)
    if (!re.exactMatch(fracOneNumer) || !re.exactMatch(fracTwoNumer) || !re.exactMatch(fracOneDenumer) || !re.exactMatch(fracTwoDenumer)) {
        ui->calOutput->setText("Please ensure you are only using numeric values.");
        return;
    } else if(!(ui->addition->isChecked() || ui->subtraction->isChecked() || ui->multiplication->isChecked() || ui->division->isChecked())) {
         ui->calOutput->setText("Please select an operator ");
         return;
    }

    int f1n = fracOneNumer.toInt();
    int f1d = fracOneDenumer.toInt();
    int f2n = fracTwoNumer.toInt();
    int f2d = fracTwoDenumer.toInt();

    if(f1d == 0 || f2d == 0){
         ui->calOutput->setText("You can not have zero in the denumerator. Please try again!");
         return;
    } else {
         ui->calOutput->setText(" ");
    }

    Fraction fracOne(f1n, f1d);
    Fraction fracTwo(f2n, f2d);

    if (ui->addition->isChecked()) {
       answer = fracOne + fracTwo;
    } else if (ui->subtraction->isChecked()) {
       answer = fracOne - fracTwo;
    } else if (ui->multiplication->isChecked()) {
       answer = fracOne * fracTwo;
    } else if (ui->division->isChecked()) {
       answer = fracOne / fracTwo;
    }

    int numerator = answer.numerator();
    int denominator = answer.denominator();

    ui->numerator->setText(QString::number(numerator));
    ui->seperator->setText("---");
    ui->denominator->setText(QString::number(denominator));
    //ui->calOutput->setText(QString::number(f1n));


}

