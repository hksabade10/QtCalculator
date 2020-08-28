#include "qtcalculator.h"
#include "ui_qtcalculator.h"

QtCalculator::QtCalculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QtCalculator)
{
    ui->setupUi(this);
}

QtCalculator::~QtCalculator()
{
    delete ui;
}

