#include "unitsettings.h"
#include "ui_unitsettings.h"
#include "globalfunctions.h"
#include <QDebug>


UnitSettings::UnitSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UnitSettings)
{
    ui->setupUi(this);
    currentIndex = 0;
    currentIndexUnits = 0;
    returnValue = -1;
    startEditing=false;

    bEditUnits=true;
}

UnitSettings::~UnitSettings()
{
    delete ui;
}

void UnitSettings::showEvent(QShowEvent * event)
{


    //ui->tableWidget_categories->setRowCount(m_categoriesList_ptr->size());
    ui->tableWidget_categories->setRowCount(m_CategoriesUnits.size());
    ui->tableWidget_categories->setColumnCount(1);

    for(int i=0;i<m_CategoriesUnits.size();i++)
    {
        if (ui->tableWidget_categories->item(i,0) == 0)
        {
            QTableWidgetItem *newItem = new QTableWidgetItem();
            ui->tableWidget_categories->setItem(i,0, newItem);
        }
        //ui->tableWidget_categories->item(i,0)->setText(m_categoriesList_ptr->at(i).m_category);
        ui->tableWidget_categories->item(i,0)->setText(m_CategoriesUnits.at(i).m_category);
    }

    ui->tableWidget_categories->setCurrentCell(currentIndex,0);
    //setListWidgetUnits();


    double verticalSize=1;
#if defined(Q_WS_S60)
   verticalSize = 1.5;
#endif


    QStringList headerlistCategories;
    headerlistCategories.append("Categories");
    ui->tableWidget_categories->setHorizontalHeaderLabels(headerlistCategories);
    ui->tableWidget_categories->verticalHeader()->hide();
     ui->tableWidget_categories->horizontalHeader()->setDefaultSectionSize(
                ui->tableWidget_categories->size().width());
    ui->tableWidget_categories->horizontalHeader()->setResizeMode(QHeaderView::Interactive);

    ui->tableWidget_categories->verticalHeader()->setDefaultSectionSize(
                int(verticalSize*ui->tableWidget_categories->verticalHeader()->defaultSectionSize()));





    QStringList headerlistUnits;
    headerlistUnits.append("Convertions");
    ui->tableWidget_units->setHorizontalHeaderLabels(headerlistUnits);
    ui->tableWidget_units->verticalHeader()->hide();
    ui->tableWidget_units->horizontalHeader()->setDefaultSectionSize(
                ui->tableWidget_units->size().width());


    ui->tableWidget_units->horizontalHeader()->setResizeMode(QHeaderView::Interactive);


    ui->tableWidget_units->verticalHeader()->setDefaultSectionSize(
                int(verticalSize*ui->tableWidget_units->verticalHeader()->defaultSectionSize()));



    startEditing=true;
}

void UnitSettings::setListWidgetUnits()
{
    if ( (currentIndex < 0) || (currentIndex >= m_CategoriesUnits.size()) )
    {
        ui->tableWidget_units->setRowCount(0);
        return;
    }

    //int max = m_categoriesList_ptr->at(currentIndex).m_units.getConvertionsCount();
    int max = m_CategoriesUnits.at(currentIndex).m_units.getConvertionsCount();

    ui->tableWidget_units->setRowCount(max);
    ui->tableWidget_units->setColumnCount(1);

    int row=ui->tableWidget_units->rowCount();
    int col = ui->tableWidget_units->columnCount();

   // int max = m_categoriesList_ptr[currentIndex].m_units.getConvertionsCount();
    bEditUnits=false;
    for(int r=0;r<max;r++)
    {
        QString str = m_CategoriesUnits.at(currentIndex).m_units.getConvertionsAt(r);


        if (ui->tableWidget_units->item(r,0) == 0)
        {
            QTableWidgetItem *newItem = new QTableWidgetItem(str);
            ui->tableWidget_units->setItem(r,0, newItem);
        }
        else
        {
            ui->tableWidget_units->item(r,0)->setText(str);
            //ui->tableWidget_units->item(j,0)->setText("ola");
        }
        //QString str  = m_categoriesList_ptr->at(currentIndex).m_units.getConvertionsAt(j);
    }
    bEditUnits=true;

}


void UnitSettings::on_pushButton_NewCategories_clicked()
{
    Categories_units categorie;
    //m_categoriesList_ptr->append(categorie);
    m_CategoriesUnits.append(categorie);

    int r = ui->tableWidget_categories->rowCount();
    ui->tableWidget_categories->setRowCount(r+1);

    if (ui->tableWidget_categories->item(r,0) == 0)
    {
        QTableWidgetItem *newItem = new QTableWidgetItem();
        ui->tableWidget_categories->setItem(r,0, newItem);
    }

    ui->tableWidget_categories->scrollToBottom();
}

void UnitSettings::on_pushButton_DeleteCategories_clicked()
{
    if ( (currentIndex < 0) || (currentIndex >= m_CategoriesUnits.size()))
    {
        QMessageBox::about(this,tr("Invalid Category selected"),tr("First select the Category you want to delete.") );
        return;
    }

    QString str = m_CategoriesUnits.at(currentIndex).m_category;


    QString str2=QString("Delete category %1 ?\nNote that all unit convertions of this category will be deleted.\nAre you sure ?").arg(str);
    int r = QMessageBox::warning(this,str,str2, QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
    if (r == QMessageBox::Yes)
    {

       // int rrr = ui->tableWidget_categories->rowCount();

        m_CategoriesUnits.removeAt(currentIndex);
        ui->tableWidget_categories->removeRow(currentIndex);

    }
}

void UnitSettings::on_pushButton_DeleteUnits_clicked()
{
    if ( (currentIndexUnits <0) || (currentIndexUnits >= m_CategoriesUnits[currentIndex].m_units.getConvertionsCount()) )
        return;

    QString str_remove = ui->tableWidget_units->item(currentIndexUnits,0)->text();

    QString str_message=QString("Delete '%1' ?\nAre you sure ?").arg(str_remove);
    int r = QMessageBox::warning(this,str_remove,str_message, QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
    if (r == QMessageBox::Yes)
    {
        m_CategoriesUnits[currentIndex].m_units.removeConvertion(str_remove);
        //m_categoriesList_ptr->operator [](currentIndex).m_units.removeConvertion(ui->tableWidget_units->itemAt(currentIndexUnits,0)->text());
        ui->tableWidget_units->removeRow(currentIndexUnits);

    }

}

void UnitSettings::on_pushButton_NewUnits_clicked()
{
    ui->tableWidget_units->setRowCount(ui->tableWidget_units->rowCount()+1);
    ui->tableWidget_units->scrollToBottom();
}


void UnitSettings::on_pushButton_ok_clicked()
{
    returnValue = 1;
    close();
}

void UnitSettings::on_pushButton_cancel_clicked()
{
    returnValue = 0;
    close();
}

void UnitSettings::on_tableWidget_categories_cellChanged(int row, int column)
{
    //this function is called when the user changes the text inside the tablewidget
    if (startEditing == false)
        return;

    currentIndex = row;
    qDebug()<<"conteudo da celula muda";
    //m_categoriesList_ptr->operator [](row).m_category = ui->tableWidget_categories->item(row,column)->text();

    //we update the category name
    m_CategoriesUnits[row].m_category = ui->tableWidget_categories->item(row,column)->text();

}


void UnitSettings::on_tableWidget_categories_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn)
{
    //this function is called when the user changes from one cell to other
   // qDebug()<<"mudei de celula";
    currentIndex = currentRow;
    setListWidgetUnits();
}


void UnitSettings::on_tableWidget_units_cellChanged(int row, int column)
{
    if (startEditing == false)
        return;

    if (bEditUnits == false)
        return;

    currentIndexUnits = row;
    QString str;
  //  str = ui->tableWidget_units->item(row,column)->text();
  //  qDebug()<<str;
   // m_categoriesList_ptr->operator [](row).m_units.setConvertion_and_Units(
     //   ui->tableWidget_units->item(row,column)->text());
  //  m_CategoriesUnits[currentIndex].m_units.setConvertion_and_Units(
    //            ui->tableWidget_units->item(row,column)->text());


    m_CategoriesUnits[currentIndex].m_units.removeAll();

    for (int i=0;i<ui->tableWidget_units->rowCount();i++)
    {
        if (ui->tableWidget_units->item(i,column) != 0)
        {

             m_CategoriesUnits[currentIndex].m_units.setConvertion_and_Units(
                         ui->tableWidget_units->item(i,column)->text());
        }
    }

}

void UnitSettings::on_tableWidget_units_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn)
{
    currentIndexUnits = currentRow;
}
