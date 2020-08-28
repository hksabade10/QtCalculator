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
};
#endif // QTCALCULATOR_H
