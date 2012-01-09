#ifndef UNITSETTINGS_H
#define UNITSETTINGS_H

#include <QDialog>
#include <QListWidgetItem>
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
    int currentIndex;
    
    void showEvent(QShowEvent * event);

private slots:
    void setListWidgetUnits(int currentIndex);


    void on_listWidget_categories_itemClicked(QListWidgetItem *item);

    void on_listWidget_categories_itemChanged(QListWidgetItem *item);

    void on_pushButton_NewCategories_clicked();

private:
    Ui::UnitSettings *ui;
};

#endif // UNITSETTINGS_H
