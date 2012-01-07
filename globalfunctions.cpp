#include "globalfunctions.h"

QStringList getCategoriesUnits(QList<Categories_units> &m_listCategoriesUnits, QString m_Categorie)
{
    for(int i=0;i<m_listCategoriesUnits.size();i++)
    {
        if (m_listCategoriesUnits.at(i).m_category == m_Categorie)
        {
           // return m_listCategoriesUnits.at(i).m_units;
        }
    }

    return QStringList();
}

