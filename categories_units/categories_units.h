#ifndef CATEGORIES_UNITS_H
#define CATEGORIES_UNITS_H

#include <QString>
#include <QStringList>
#include "categories_units/units.h"

class Categories_units
{
public:
    Categories_units();

    QString m_category;
   // QStringList m_units;
    Units m_units;

    void setCategory(const QString &category){m_category=category;}
    bool addConvertion(const QString &convertion){return m_units.setConvertion_and_Units(convertion);}

    int getUnitsCount(){return m_units.getUnitsCount();}


};

#endif // CATEGORIES_UNITS_H
