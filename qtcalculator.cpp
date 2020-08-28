#include "qtcalculator.h"
#include "ui_qtcalculator.h"


QtCalculator::QtCalculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QtCalculator)
{
    ui->setupUi(this);

    ui->Display->setText(QString::number(calcValue));

    QPushButton* numButton[10];

    for(int i = 0; i < 10; i++)
    {
        QString buttonName = "Button" + QString::number(i);
        numButton[i] = QtCalculator::findChild<QPushButton*>(buttonName);
        connect(numButton[i], SIGNAL(released()), this, SLOT(NumPressed()));
    }

    connect(ui->Decimal, SIGNAL(released()), this, SLOT(DecimalButton()));

    connect(ui->Add, SIGNAL(released()), this, SLOT(MathButtonPressed()));
    connect(ui->Subtract, SIGNAL(released()), this, SLOT(MathButtonPressed()));
    connect(ui->Multiply, SIGNAL(released()), this, SLOT(MathButtonPressed()));
    connect(ui->Divide, SIGNAL(released()), this, SLOT(MathButtonPressed()));

    connect(ui->Equal, SIGNAL(released()), this, SLOT(EqualButton()));

    connect(ui->ChangeSign, SIGNAL(released()), this, SLOT(ChangeNumberSign()));

    connect(ui->Clear, SIGNAL(released()), this, SLOT(ClearDisplay()));
}

QtCalculator::~QtCalculator()
{
    delete ui;
}

void QtCalculator::NumPressed()
{
    QPushButton* button = (QPushButton*) sender();
    QString buttonValue = button->text();
    QString displayValue = ui->Display->text();

    if(QString::compare(displayValue, "0", Qt::CaseInsensitive) == 0)
    {
        ui->Display->setText(buttonValue);
    }
    else
    {
        QString newValue = displayValue + buttonValue;
        if(decimalFlag)
        {
            double dblNewValue = newValue.toDouble();
            ui->Display->setText(QString::number(dblNewValue, 'g', 16));
        }
        ui->Display->setText(newValue);
    }
}

void QtCalculator::MathButtonPressed()
{
    divTrigger = false;
    multTrigger = false;
    addTrigger = false;
    subTrigger = false;
    decimalFlag = false;

    calcValue = ui->Display->text().toDouble();

    QPushButton* button = (QPushButton*) sender();
    QString buttonValue = button->text();

    if(QString::compare(buttonValue, "/", Qt::CaseInsensitive) == 0)
    {
        divTrigger = true;
    }
    else if(QString::compare(buttonValue, "*", Qt::CaseInsensitive) == 0)
    {
        multTrigger = true;
    }
    else if(QString::compare(buttonValue, "+", Qt::CaseInsensitive) == 0)
    {
        addTrigger = true;
    }
    else if(QString::compare(buttonValue, "-", Qt::CaseInsensitive) == 0)
    {
        subTrigger = true;
    }
    ui->Display->setText("");

}

void QtCalculator::EqualButton()
{
    double solution = 0.0;
    double displayValue = ui->Display->text().toDouble();
    decimalFlag = false;

    if(addTrigger || subTrigger || multTrigger || divTrigger)
    {
        if(addTrigger)
        {
            solution = calcValue + displayValue;
        }
        else if(subTrigger)
        {
            solution = calcValue - displayValue;
        }
        else if(multTrigger)
        {
            solution = calcValue * displayValue;
        }
        else if(divTrigger)
        {
            solution = calcValue / displayValue;
        }
    }
    ui->Display->setText(QString::number(solution));
}

void QtCalculator::DecimalButton()
{
    if(!decimalFlag)
    {
        QString displayValue = ui->Display->text();
        QString newValue = displayValue + ".";

        ui->Display->setText(newValue);

        decimalFlag = true;
    }
}

void QtCalculator::ChangeNumberSign()
{
    QString qstrDisplayValue = ui->Display->text();
    QRegExp reg("[-]?[0-9.]*");
    if(reg.exactMatch(qstrDisplayValue))
    {
        double displayValue = qstrDisplayValue.toDouble();
        double displayValueSign = -1 * displayValue;
        ui->Display->setText(QString::number(displayValueSign));
    }
}

void QtCalculator::ClearDisplay()
{
    decimalFlag = false;
    calcValue = 0;
    ui->Display->setText(QString::number(calcValue));
}

