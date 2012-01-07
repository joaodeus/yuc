#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCore/QCoreApplication>
#include <QDebug>
#include "unitsettings.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Categories_units units;
    units.setCategory("Temperature");
    units.addConvertion("Celsius = Kelvin - 273.15");
    units.addConvertion("Kelvin = Celsius + 273.15");
    units.addConvertion("Fahrenheit = Celsius * 1.8 + 32");
    units.addConvertion("Celsius = Fahrenheit+4");



    Categories_units units2;
    units2.setCategory("Distance");
    units2.addConvertion("m = 0.001*Km");
    units2.addConvertion("Km = 1000*m");

    m_CategoriesUnits_List.append(units);
    m_CategoriesUnits_List.append(units2);


    int current_category_index=0;
    setComboBoxCategories(current_category_index);
    setTableWidgetUnits(*ui->tableWidget_units_results, m_CategoriesUnits_List[current_category_index]);


   // m_tableModelCategoriesUnits = new TableModelUnits(this);
    //ui->tableView_units->setModel(m_tableModelCategoriesUnits);

}

MainWindow::~MainWindow()
{

    delete ui;
}

bool MainWindow::setTableWidgetUnits(QTableWidget &table, Categories_units &units)
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
    }

    return true;
}


void MainWindow::setComboBoxCategories(int &current_index)
{
    ui->comboBox_categories->clear();

    for(int i=0;i<m_CategoriesUnits_List.size();i++)
    {
        ui->comboBox_categories->addItem(m_CategoriesUnits_List[i].m_category);
    }

    if (current_index < ui->comboBox_categories->count())
        ui->comboBox_categories->setCurrentIndex(current_index);
    else
        current_index=-1;

}

void MainWindow::setOrientation(ScreenOrientation orientation)
{
#if defined(Q_OS_SYMBIAN)
    // If the version of Qt on the device is < 4.7.2, that attribute won't work
    if (orientation != ScreenOrientationAuto) {
        const QStringList v = QString::fromAscii(qVersion()).split(QLatin1Char('.'));
        if (v.count() == 3 && (v.at(0).toInt() << 16 | v.at(1).toInt() << 8 | v.at(2).toInt()) < 0x040702) {
            qWarning("Screen orientation locking only supported with Qt 4.7.2 and above");
            return;
        }
    }
#endif // Q_OS_SYMBIAN

    Qt::WidgetAttribute attribute;
    switch (orientation) {
#if QT_VERSION < 0x040702
    // Qt < 4.7.2 does not yet have the Qt::WA_*Orientation attributes
    case ScreenOrientationLockPortrait:
        attribute = static_cast<Qt::WidgetAttribute>(128);
        break;
    case ScreenOrientationLockLandscape:
        attribute = static_cast<Qt::WidgetAttribute>(129);
        break;
    default:
    case ScreenOrientationAuto:
        attribute = static_cast<Qt::WidgetAttribute>(130);
        break;
#else // QT_VERSION < 0x040702
    case ScreenOrientationLockPortrait:
        attribute = Qt::WA_LockPortraitOrientation;
        break;
    case ScreenOrientationLockLandscape:
        attribute = Qt::WA_LockLandscapeOrientation;
        break;
    default:
    case ScreenOrientationAuto:
        attribute = Qt::WA_AutoOrientation;
        break;
#endif // QT_VERSION < 0x040702
    };
    setAttribute(attribute, true);
}

void MainWindow::showExpanded()
{
#if defined(Q_OS_SYMBIAN) || defined(Q_WS_SIMULATOR)
    showFullScreen();
#elif defined(Q_WS_MAEMO_5)
    showMaximized();
#else
    show();
#endif
}

void MainWindow::showEvent(QShowEvent * event)
{
    //ui->tableWidget_units_results->setRowCount(m_CategoriesUnits_List.length());


}

void MainWindow::on_actionEdit_triggered()
{
    UnitSettings dlg;
    dlg.exec();
}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{

}

void MainWindow::on_comboBox_categories_currentIndexChanged(int index)
{
    current_category_index=index;
    setTableWidgetUnits(*ui->tableWidget_units_results, m_CategoriesUnits_List[index]);
}

void MainWindow::on_tableWidget_units_results_itemChanged(QTableWidgetItem *item)
{
    qDebug()<<item->text();
    qDebug()<<item->row();
    QStringList result = m_CategoriesUnits_List[current_category_index].m_units.setValue(item->text(), item->row());

    setTableWidgetSolutions(result);

}

void MainWindow::setTableWidgetSolutions(QStringList &solutions)
{

    for (int l=0;l<solutions.size();l++)
    {
        if (ui->tableWidget_units_results->item(l,1) == 0)
        {
            QTableWidgetItem *newItem = new QTableWidgetItem();
            ui->tableWidget_units_results->setItem(l,1, newItem);
        }
        ui->tableWidget_units_results->item(l,1)->setText(solutions.at(l));
    }
}
