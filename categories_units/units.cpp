#include "units.h"

Units::Units()
{
}

bool Units::setConvertion_and_Units(QString m_convertion)
{
    Calculadora calc;
    QStringList variables;
    if (calc.isConvertion_equation(m_convertion, variables))
    {
        return false;
    }

    addConvertion(m_convertion);
    addUnit(variables[0]);
    addUnit(variables[1]);
    return true;
}

QString Units::getUnitsAt(int i)
{
    return m_units.at(i);
}

void Units::addConvertion(QString &convertion)
{
    m_convertions.append(convertion);
    m_convertions.removeDuplicates();
}


void Units::addUnit(QString &unit)
{
    m_units.append(unit);
    m_units.removeDuplicates();
}

void Units::removeAll()
{
    m_convertions.clear();
    m_units.clear();
}

QStringList Units::setValue(QString value, int unit_index)
{
    if (unit_index >= m_units.size())
        return QStringList();

    Calculadora calc;
    double x = calc.f(value).r;
    if (calc.ERRO)
        return QStringList();

    QStringList list_results;
    QStringList list_var;

    QString unit_selected = m_units.at(unit_index);


    for (int i=0;i<m_units.size();i++)
    {
        list_results.append("");
        if (i != unit_index)
        {
            for (int j=0;j<m_convertions.size();j++)
            {
                calc.GetVariaveis(m_convertions.at(j),list_var);
                if ( (m_units.at(i) == list_var.at(0)) && (list_var.at(1) == unit_selected) )
                {
                    QStringList conversion_formula;
                    conversion_formula=m_convertions.at(j).split("=");
                    Complexo y = calc.fx(conversion_formula[1],x,unit_selected);

                    if (calc.ERRO)
                        return QStringList();

                    list_results[i]=ComplexoToQString(y);

                }
            }
        }
        else
            list_results[i]=value;
    }


    return list_results;
}


/*
bool Units::addConvertion(QString &convertion)
{
    for (int i=0;i<m_convertions.size();i++)
    {
        if (m_convertions.at(i) == convertion)
            return false;
    }
    m_convertions.append(convertion);
    return true;
}*/

/*
bool Units::addUnit(QString &unit)
{
    for (int i=0;i<m_units.size();i++)
    {
        if (m_units.at(i) == unit)
            return false;
    }
    m_units.append(unit);
    return true;
}*/
