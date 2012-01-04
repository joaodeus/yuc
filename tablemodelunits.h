#ifndef TABLEMODELUNITS_H
#define TABLEMODELUNITS_H

#include <QAbstractTableModel>
#include "categories_units/categories_units.h"



class TableModelUnits : public QAbstractTableModel
{
public:
    TableModelUnits(QObject *parent=0);
    TableModelUnits(QList<Categories_units> CategoriesUnitsList, QObject *parent=0);

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role=Qt::EditRole);
    bool insertRows(int position, int rows, const QModelIndex &index=QModelIndex());
    bool removeRows(int position, int rows, const QModelIndex &index=QModelIndex());

    QList<Categories_units> getList();
private:
    QList<Categories_units> m_CategoriesUnits_List;

};

#endif // TABLEMODELUNITS_H
