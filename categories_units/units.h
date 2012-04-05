#ifndef UNITS_H
#define UNITS_H

#include <QStringList>
#include "math/calculadora.h"

class Units
{
public:
    Units();

    bool setConvertion_and_Units(QString m_convertion);
    bool removeConvertion(QString m_convertion);
    int getUnitsCount(){return m_units.size();}
    int getConvertionsCount() const {return m_convertions.size();}
    QString getUnitsAt(int i);
    QString getConvertionsAt(int i) const;
    void removeAll();
    QStringList setValue(QString value, int unit_index);

    QStringList m_units;
    QStringList m_convertions;

private:
    //add's a convertion, no duplicates permitted
    void addConvertion(QString &convertion);
    //add's a unit, no duplicates permitted
    void addUnit(QString &unit);

    //auxiliar method to setValue(), to help solve indirect units, not explicit
    //defined in convertions
   // int getUnit_not_in_uncalculated_List(QList<int> list_uncalculated_units);

};

QDataStream & operator<< (QDataStream& stream, const Units& m_units);
QDataStream & operator>> (QDataStream& stream, Units& m_units);

#endif // UNITS_H
