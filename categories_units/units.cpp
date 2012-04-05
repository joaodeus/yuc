#include "units.h"

Units::Units()
{
}

bool Units::setConvertion_and_Units(QString m_convertion)
{
    Calculadora calc;
    QStringList variables;
    if (!calc.isConvertion_equation(m_convertion, variables))
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

QString Units::getConvertionsAt(int i) const
{
    if (i >= m_convertions.size())
        return QString();

    return m_convertions.at(i);
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

    QStringList list_results;
    Calculadora calc;
    double x = calc.f(value).r;
    if (calc.ERRO)
    {
        //////////////////////
        //display a error
        for (int i=0;i<m_units.size();i++)
        {
            list_results.append("");

            if (i != unit_index)
                list_results[i]="";//"Error"
            else
                list_results[i]=value;
        }
        /////////////////////

        return list_results;
    }



    QStringList list_var;
    bool exist_conversion_formula;
    QString unit_selected = m_units.at(unit_index);

    QList<int> list_uncalculated_units;
    QList<int> list_calculated_units;


    for (int i=0;i<m_units.size();i++)
    {
        list_results.append("");
        if (i != unit_index)
        {
            exist_conversion_formula = false;

            for (int j=0;j<m_convertions.size();j++)
            {
                calc.GetVariaveis(m_convertions.at(j),list_var);
                if ( (m_units.at(i) == list_var.at(0)) && (list_var.at(1) == unit_selected) )
                {
                    QStringList conversion_formula;
                    conversion_formula = m_convertions.at(j).split("=");
                    Complexo y = calc.fx(conversion_formula[1],x,unit_selected);

                    if (calc.ERRO)
                    {
                        list_results[i]="Convertion formula error!!!";
                    }
                    else
                    {
                        list_results[i]=ComplexoToQString(y);
                        exist_conversion_formula = true;
                    }                    
                    break;
                }                
            }

            if (exist_conversion_formula == false)
            {
                list_uncalculated_units.append(i);  //stores the index's of the uncalculated units
            }
            else
            {
                list_calculated_units.append(i);    //stores the index's of the calculated units
            }

        }
        else
            list_results[i]=value;
    }


    //if thee were uncalculated units, lets try to calculated,
    //based on existens calculated units and converstions

    bool calculated_Another_Unit;

    do
    {
        calculated_Another_Unit = false;
        for (int i=0;i<list_uncalculated_units.size();i++)
        {
            for (int j=0;j<list_calculated_units.size();j++)
            {
                for(int c=0;c<m_convertions.size();c++)
                {
                    calc.GetVariaveis(m_convertions.at(c),list_var);

                    if ( (list_var[0] == m_units.at(list_uncalculated_units.at(i)))
                         && (list_var[1] == m_units.at(list_calculated_units.at(j))) )
                    {

                        QStringList conversion_formula;
                        conversion_formula = m_convertions.at(c).split("=");
                        x = calc.f(list_results.at(list_calculated_units.at(j))).r;
                        Complexo y = calc.fx(conversion_formula[1],x,list_var[1]);

                        if (calc.ERRO)
                        {
                            list_results[list_uncalculated_units.at(i)]="Convertion formula error!!!";
                        }
                        else
                        {
                            list_results[list_uncalculated_units.at(i)]=ComplexoToQString(y);
                            list_calculated_units.insert(j+1,list_uncalculated_units.at(i));
                            list_uncalculated_units.removeAt(i);
                            c = m_convertions.size();
                            j = list_calculated_units.size();
                            i = list_uncalculated_units.size();
                            calculated_Another_Unit = true;

                        }

                    }

                }
            }
        }

    }
    while (calculated_Another_Unit == true);

   /* do
    {
        calculated_Another_Unit = false;

        for (int i=0;i<list_uncalculated_units.size();i++)
        {

            for (int j=0;j<m_units.size();j++)
            {
                if (j != list_uncalculated_units.at(i))
                {
                    unit_selected = m_units.at(j);

                    for (int c=0;c<m_convertions.size();c++)
                    {
                        calc.GetVariaveis(m_convertions.at(c),list_var);

                        if ( (m_units.at(list_uncalculated_units.at(i)) == list_var.at(0))
                             && (list_var.at(1) == unit_selected) )
                        {

                            QStringList conversion_formula;
                            conversion_formula = m_convertions.at(c).split("=");
                            x = calc.f(list_results.at(j)).r;
                            Complexo y = calc.fx(conversion_formula[1],x,unit_selected);

                            if (calc.ERRO)
                            {
                                list_results[list_uncalculated_units.at(i)]="Convertion formula error!!!";
                            }
                            else
                            {
                                list_results[list_uncalculated_units.at(i)]=ComplexoToQString(y);
                                calculated_Another_Unit = true;
                                c = m_convertions.size();
                                j = m_units.size();
                                list_uncalculated_units.removeAt(i);
                            }

                        }

                    }
                }

            }

        }

    }
    while (calculated_Another_Unit == true);*/



    return list_results;
}

/*
int Units::getUnit_not_in_uncalculated_List(QList<int> list_uncalculated_units)
{
    bool exist;

    for (int i=0;i<m_units.size();i++)
    {
        exist=false;
        for (int j=0;j<list_uncalculated_units.size();j++)
        {
            if (i == list_uncalculated_units.at(j))
            {
                exist=true;
            }
        }

        if (exist == false)
            return i;
    }

    return -1;
}
*/


bool Units::removeConvertion(QString m_convertion)
{
    m_convertions.removeAll(m_convertion);
    m_units.clear();

    for(int i=0;i<m_convertions.size();i++)
    {
        setConvertion_and_Units(m_convertions.at(i));
    }

    return true;
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


QDataStream & operator<< (QDataStream& stream, const Units& m_units)
{
    stream<<m_units.m_convertions;
    stream<<m_units.m_units;

    return stream;
}

QDataStream & operator>> (QDataStream& stream, Units& m_units)
{
    stream>>m_units.m_convertions;
    stream>>m_units.m_units;

    return stream;
}
