#include "categories_dlg.h"
#include "ui_categories_dlg.h"

categories_dlg::categories_dlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::categories_dlg)
{
    ui->setupUi(this);

}

categories_dlg::~categories_dlg()
{
    delete ui;
}


void categories_dlg::showEvent(QShowEvent * event)
{

    for (int i=0;i<m_categoriesList_ptr->size();i++)
    {
        ui->listWidget_categories->addItem(m_categoriesList_ptr->at(i).m_category);
    }



    /*
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
*/
}

void categories_dlg::on_listWidget_categories_clicked(const QModelIndex &index)
{
    index_selected = index.row();
    close();
}
