#include "tablemodelunits.h"

TableModelUnits::TableModelUnits(QObject *parent)
{

}


TableModelUnits::TableModelUnits(QList<Categories_units> CategoriesUnitsList, QObject *parent)
     : QAbstractTableModel(parent)
 {
     m_CategoriesUnits_List=CategoriesUnitsList;
 }


int TableModelUnits::rowCount(const QModelIndex &parent) const
 {
     Q_UNUSED(parent);
     return m_CategoriesUnits_List.size();
 }

 int TableModelUnits::columnCount(const QModelIndex &parent) const
 {
     Q_UNUSED(parent);
     return 2;
 }

 QVariant TableModelUnits::data(const QModelIndex &index, int role) const
  {
      if (!index.isValid())
          return QVariant();

      if (index.row() >= m_CategoriesUnits_List.size() || index.row() < 0)
          return QVariant();

      /*if (role == 32) //first user constant role
      {

      }*/

      /*if (role == Qt::DisplayRole) {
          QPair<QString, QString> pair = listOfPairs.at(index.row());

          if (index.column() == 0)
              return pair.first;
          else if (index.column() == 1)
              return pair.second;
      }*/


      return QVariant();
  }

 QVariant TableModelUnits::headerData(int section, Qt::Orientation orientation, int role) const
 {
    if (role != Qt::DisplayRole)
      return QVariant();

    if (orientation == Qt::Horizontal) {
      switch (section) {
          case 0:
              return tr("Units");

          case 1:
              return tr(" - ");

          default:
              return QVariant();
      }
    }
    return QVariant();

 }

 bool TableModelUnits::insertRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED(index);
    beginInsertRows(QModelIndex(), position, position+rows-1);

    for (int row=0; row < rows; row++) {
      //QPair<QString, QString> pair(" ", " ");
      //listOfPairs.insert(position, pair);
      Categories_units units;
      m_CategoriesUnits_List.insert(position,units);

    }

    endInsertRows();
    return true;
}

 bool TableModelUnits::removeRows(int position, int rows, const QModelIndex &index)
 {
     Q_UNUSED(index);
     beginRemoveRows(QModelIndex(), position, position+rows-1);

     for (int row=0; row < rows; ++row)
     {
         m_CategoriesUnits_List.removeAt(position);
     }

     endRemoveRows();
     return true;
 }


 bool TableModelUnits::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole)
    {
         /* int row = index.row();

          QPair<QString, QString> p = listOfPairs.value(row);

          if (index.column() == 0)
                  p.first = value.toString();
          else if (index.column() == 1)
                  p.second = value.toString();
          else
              return false;

          listOfPairs.replace(row, p);*/
          emit(dataChanged(index, index));

    return true;
    }

    return false;
}

Qt::ItemFlags TableModelUnits::flags(const QModelIndex &index) const
{
    if (!index.isValid())
      return Qt::ItemIsEnabled;

    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}


QList<Categories_units> TableModelUnits::getList()
{
    return m_CategoriesUnits_List;
}



