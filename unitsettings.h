#ifndef UNITSETTINGS_H
#define UNITSETTINGS_H

#include <QDialog>
#include <QListWidgetItem>
#include <QTableWidgetItem>
#include "categories_units/categories_units.h"

namespace Ui {
class UnitSettings;
}

class UnitSettings : public QDialog
{
    Q_OBJECT
    
public:
    explicit UnitSettings(QWidget *parent = 0);
    ~UnitSettings();

    QList<Categories_units> m_CategoriesUnits;
    //QList<Categories_units> *m_categoriesList_ptr;
    int currentIndex;
    int currentIndexUnits;
    int returnValue;
    
    void showEvent(QShowEvent * event);

private slots:
    void setListWidgetUnits();

    void on_pushButton_NewCategories_clicked();

    void on_pushButton_DeleteCategories_clicked();

    void on_pushButton_ok_clicked();

    void on_pushButton_cancel_clicked();

    void on_tableWidget_categories_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn);

    void on_tableWidget_categories_cellChanged(int row, int column);

   // void on_tableWidget_categories_itemChanged(QTableWidgetItem *item);

    void on_pushButton_NewUnits_clicked();

    void on_tableWidget_units_cellChanged(int row, int column);

    void on_pushButton_DeleteUnits_clicked();

    void on_tableWidget_units_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn);

private:
    Ui::UnitSettings *ui;


    bool startEditing;
    bool bEditUnits;
};

#endif // UNITSETTINGS_H
