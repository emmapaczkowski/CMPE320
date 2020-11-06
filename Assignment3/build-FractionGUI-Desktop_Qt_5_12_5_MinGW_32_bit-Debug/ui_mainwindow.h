/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout_2;
    QLineEdit *FracOneNum;
    QLineEdit *FracOneDenum;
    QSpinBox *spinBox;
    QGridLayout *gridLayout_6;
    QLineEdit *FracTwoDenum;
    QLineEdit *FracTwoNum;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *gridLayout_4;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayout_7;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *Calculate;
    QLabel *calOutput;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 210, 801, 80));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        FracOneNum = new QLineEdit(horizontalLayoutWidget);
        FracOneNum->setObjectName(QString::fromUtf8("FracOneNum"));

        gridLayout_2->addWidget(FracOneNum, 0, 0, 1, 1);

        FracOneDenum = new QLineEdit(horizontalLayoutWidget);
        FracOneDenum->setObjectName(QString::fromUtf8("FracOneDenum"));

        gridLayout_2->addWidget(FracOneDenum, 1, 0, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_2);

        spinBox = new QSpinBox(horizontalLayoutWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        horizontalLayout_2->addWidget(spinBox);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        FracTwoDenum = new QLineEdit(horizontalLayoutWidget);
        FracTwoDenum->setObjectName(QString::fromUtf8("FracTwoDenum"));

        gridLayout_6->addWidget(FracTwoDenum, 1, 0, 1, 1);

        FracTwoNum = new QLineEdit(horizontalLayoutWidget);
        FracTwoNum->setObjectName(QString::fromUtf8("FracTwoNum"));

        gridLayout_6->addWidget(FracTwoNum, 0, 0, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_6);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));

        horizontalLayout_2->addLayout(gridLayout_4);

        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(0, 60, 801, 80));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(2);
        sizePolicy.setVerticalStretch(2);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(19);
        label->setFont(font);

        horizontalLayout_3->addWidget(label);

        gridLayoutWidget_4 = new QWidget(centralwidget);
        gridLayoutWidget_4->setObjectName(QString::fromUtf8("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(0, 320, 811, 80));
        gridLayout_7 = new QGridLayout(gridLayoutWidget_4);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_4, 0, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_3, 0, 0, 1, 1);

        Calculate = new QPushButton(gridLayoutWidget_4);
        Calculate->setObjectName(QString::fromUtf8("Calculate"));

        gridLayout_7->addWidget(Calculate, 0, 1, 1, 1);

        calOutput = new QLabel(gridLayoutWidget_4);
        calOutput->setObjectName(QString::fromUtf8("calOutput"));

        gridLayout_7->addWidget(calOutput, 1, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", "Emma's Fraction Calculator App!", nullptr));
        Calculate->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        calOutput->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
