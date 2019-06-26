#include "calulatorresult.h"

#define ADDITION "+"
#define SUBTRACTION "-"
#define EQUALTO "="
enum arithmetictype{
    none = 0,
    additon,
    subtraction
};

CalulatorResult::CalulatorResult()
{

}

QString CalulatorResult::resolveequestion(QString str_value)
{
    qDebug("In 'CalculateResult' function..");
    double d_result = 0;
    QString qstr_equ = str_value;
    if(qstr_equ.contains(ADDITION) || qstr_equ.contains(SUBTRACTION))
    {
        QString str_value1;
        int i=0;
        int aritheticType = none;
        while (i < qstr_equ.length()) {
            QString qstr_value = qstr_equ.at(i);
            if((qstr_value == ADDITION) || (qstr_value == SUBTRACTION)) {
                if(i == 0)
                {
                    if(qstr_value == SUBTRACTION)
                        str_value1.append(qstr_value);
                    i++;
                    continue;
                }
                if(aritheticType == additon)
                {
                    d_result = this->addvalue(d_result,str_value1.toDouble());
                    str_value1.clear();
                    aritheticType = none;
                } else if(aritheticType == subtraction)
                {
                    d_result = this->Substractvalue(d_result,str_value1.toDouble());
                    str_value1.clear();
                    aritheticType = none;
                }
                if(qstr_value == SUBTRACTION)
                {
                    aritheticType =  subtraction;
                    d_result = this->addvalue(d_result,str_value1.toDouble());
                    str_value1.clear();
                } else if(qstr_value == ADDITION) {
                    aritheticType = additon;
                    d_result = this->addvalue(d_result,str_value1.toDouble());
                    str_value1.clear();
                }
            } else {
                str_value1.append(qstr_value);
            }
            i++;
        }
        if(aritheticType == additon)
        {
            d_result = this->addvalue(d_result,str_value1.toDouble());
            str_value1.clear();
        } else if(aritheticType == subtraction)
        {
            d_result = this->Substractvalue(d_result,str_value1.toDouble());
            str_value1.clear();
        }
        aritheticType = none;
        return QString::number(d_result,'g',15);
    } else {
        return qstr_equ;
    }
}

double CalulatorResult::addvalue(double _d_value1, double _d_value2)
{
    qDebug("In 'addvalue' function.");
    return _d_value1 + _d_value2;

}

double CalulatorResult::Substractvalue(double _d_value1, double _d_value2)
{
    qDebug("In 'Substractvalue' function");
    return _d_value1 - _d_value2;
}

