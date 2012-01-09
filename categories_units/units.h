#ifndef UNITS_H
#define UNITS_H

#include <QStringList>
#include "math/calculadora.h"

class Units
{
public:
    Units();

     bool setConvertion_and_Units(QString m_convertion);
     int getUnitsCount(){return m_units.size();}
     QString getUnitsAt(int i);
     QString getConvertionsAt(int i);
     void removeAll();
     QStringList setValue(QString value, int unit_index);

private:
    QStringList m_units;
    QStringList m_convertions;

    //add's a convertion, no duplicates permitted
    void addConvertion(QString &convertion);
    //add's a unit, no duplicates permitted
    void addUnit(QString &unit);




    //add's a conversation to the list, if it's already not there
    //return if true if sucessfully added, and false if the convertion already exists
    //bool addConvertion(QString &convertion);

    //add's a unit to the list, if it's already not there
    //return if true if sucessfully added, and false if the unit already exists
    //bool addUnit(QString &unit);


};

#endif // UNITS_H
