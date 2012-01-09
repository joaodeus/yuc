#ifndef GLOBALFUNCTIONS_H
#define GLOBALFUNCTIONS_H

#include <QTableWidget>
#include "categories_units/categories_units.h"

QStringList getCategoriesUnits(QList<Categories_units> &m_listCategoriesUnits, QString m_Categorie);

bool setTableWidget(QTableWidget &table, Categories_units &units);
//bool setListWidgetCategories(QListWidget &list, Categories_units &units);

#endif // GLOBALFUNCTIONS_H
