#ifndef CALCULATORCPP_H
#define CALCULATORCPP_H

#include <QObject>

class CalculatorCPP
{
public:
    CalculatorCPP();
    QString ButtonSelected(Qstring str_value);
private:
    QString CalculateResult();
    double addvalue(double _d_value1,double _d_value2);
    double Substractvalue(double _d_value1, double _d_value2);
};

#endif // CALCULATORCPP_H
