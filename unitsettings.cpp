#include "unitsettings.h"
#include "ui_unitsettings.h"

#include "globalfunctions.h"


UnitSettings::UnitSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UnitSettings)
{
    ui->setupUi(this);
    currentIndex=0;
}

UnitSettings::~UnitSettings()
{
    delete ui;
}

void UnitSettings::showEvent(QShowEvent * event)
{
    ui->listWidget_categories->clear();

    for(int i=0;i<m_CategoriesUnits.size();i++)
    {
        if (ui->listWidget_categories->item(i) == 0)
        {
            ui->listWidget_categories->addItem(m_CategoriesUnits.at(i).m_category);
            ui->listWidget_categories->item(i);
           // ui->listWidget_categories->item(i)->setFlags (ui->listWidget_categories->item(i)->flags () | Qt::ItemIsEditable);
        }
    }


    ui->listWidget_categories->setCurrentRow(currentIndex);
    setListWidgetUnits(currentIndex);

}

void UnitSettings::setListWidgetUnits(int currentIndex)
{
    ui->listWidget_units->clear();
    for(int j=0;j<m_CategoriesUnits[currentIndex].m_units.getUnitsCount();j++)
    {
        ui->listWidget_units->addItem(m_CategoriesUnits[currentIndex].m_units.getConvertionsAt(j));
    }
}

void UnitSettings::on_listWidget_categories_itemClicked(QListWidgetItem *item)
{
    currentIndex = ui->listWidget_categories->currentRow();
    setListWidgetUnits(currentIndex);
}

void UnitSettings::on_listWidget_categories_itemChanged(QListWidgetItem *item)
{
    currentIndex = ui->listWidget_categories->currentRow();
    setListWidgetUnits(currentIndex);
}

void UnitSettings::on_pushButton_NewCategories_clicked()
{
    Categories_units categorie;
    m_CategoriesUnits.append(categorie);
    ui->listWidget_categories->addItem("");
    int i=ui->listWidget_categories->count();
    ui->listWidget_categories->setFocus();
    ui->listWidget_categories->setCurrentRow(i);
}
