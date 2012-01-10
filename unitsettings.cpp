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

    ui->tableWidget_categories->horizontalHeader()->hide();
    ui->tableWidget_categories->setRowCount(m_CategoriesUnits.size());
    ui->tableWidget_categories->setColumnCount(1);

    for(int i=0;i<m_CategoriesUnits.size();i++)
    {
        if (ui->tableWidget_categories->item(i,0) == 0)
        {
            QTableWidgetItem *newItem = new QTableWidgetItem();
            ui->tableWidget_categories->setItem(i,0, newItem);
        }
        ui->tableWidget_categories->item(i,0)->setText(m_CategoriesUnits.at(i).m_category);
    }

    ui->tableWidget_categories->setCurrentCell(currentIndex,0);
    setListWidgetUnits(currentIndex);

}

void UnitSettings::setListWidgetUnits(int currentIndex)
{
    ui->tableWidget_units->setRowCount(m_CategoriesUnits[currentIndex].m_units.getUnitsCount());
    ui->tableWidget_units->setColumnCount(1);

    for(int j=0;j<m_CategoriesUnits[currentIndex].m_units.getUnitsCount();j++)
    {
        if (ui->tableWidget_units->item(j,0) == 0)
        {
            QTableWidgetItem *newItem = new QTableWidgetItem();
            ui->tableWidget_units->setItem(j,0, newItem);
        }
        ui->tableWidget_units->item(j,0)->setText(m_CategoriesUnits[currentIndex].m_units.getConvertionsAt(j));
    }
}

void UnitSettings::on_listWidget_categories_itemClicked(QListWidgetItem *item)
{
    //currentIndex = ui->listWidget_categories->currentRow();
    setListWidgetUnits(currentIndex);
}

void UnitSettings::on_listWidget_categories_itemChanged(QListWidgetItem *item)
{
   // currentIndex = ui->listWidget_categories->currentRow();
    setListWidgetUnits(currentIndex);
}

void UnitSettings::on_pushButton_NewCategories_clicked()
{
    /*
    Categories_units categorie;
    m_CategoriesUnits.append(categorie);
    ui->listWidget_categories->addItem("");
    int i=ui->listWidget_categories->count();
    ui->listWidget_categories->setFocus();
    ui->listWidget_categories->setCurrentRow(i);
    */
}
