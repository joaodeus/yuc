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


bool setTableWidget(QTableWidget &table, Categories_units &units)
{

    table.setRowCount(units.getUnitsCount());
    table.setColumnCount(2);

    for (int l=0;l<units.getUnitsCount();l++)
    {
        if (table.item(l,0) == 0)
        {
            QTableWidgetItem *newItem = new QTableWidgetItem();
            table.setItem(l,0, newItem);
        }
        table.item(l,0)->setText(units.m_units.getUnitsAt(l));
        table.item(l,0)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

        if (table.item(l,1) == 0)
        {
            QTableWidgetItem *newItem = new QTableWidgetItem();
            table.setItem(l,1, newItem);
            table.item(l,1)->setText("");
        }
        //table.item(l,1)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    }

    return true;
}
