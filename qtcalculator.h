#ifndef QTCALCULATOR_H
#define QTCALCULATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class QtCalculator; }
QT_END_NAMESPACE

class QtCalculator : public QMainWindow
{
    Q_OBJECT

public:
    QtCalculator(QWidget *parent = nullptr);
    ~QtCalculator();

private:
    Ui::QtCalculator *ui;

    double calcValue = 0;
    bool divTrigger = false;
    bool multTrigger = false;
    bool addTrigger = false;
    bool subTrigger = false;
    bool decimalFlag = false;

private slots:

    void NumPressed();
    void MathButtonPressed();
    void EqualButton();
    void DecimalButton();
    void ChangeNumberSign();
    void ClearDisplay();

};
#endif // QTCALCULATOR_H
