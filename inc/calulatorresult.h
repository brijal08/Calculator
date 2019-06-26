#ifndef CALULATORRESULT_H
#define CALULATORRESULT_H

#include <QObject>
#include <QString>

class CalulatorResult:public QObject
{
    Q_OBJECT
public:
    CalulatorResult();
    Q_INVOKABLE QString resolveequestion(QString str_value);
private:
    double addvalue(double _d_value1, double _d_value2);
    double Substractvalue(double _d_value1, double _d_value2);
};

#endif // CALULATORRESULT_H
