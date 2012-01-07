#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QList>
#include <QTableWidget>
#include "tablemodelunits.h"
#include "categories_units/categories_units.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    enum ScreenOrientation {
        ScreenOrientationLockPortrait,
        ScreenOrientationLockLandscape,
        ScreenOrientationAuto
    };

    explicit MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();

    // Note that this will only have an effect on Symbian and Fremantle.
    void setOrientation(ScreenOrientation orientation);

    void showExpanded();

private slots:
    void on_actionEdit_triggered();
    void showEvent(QShowEvent * event);


    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_comboBox_categories_currentIndexChanged(int index);

    void on_tableWidget_units_results_itemChanged(QTableWidgetItem *item);

private:
    Ui::MainWindow *ui;

    QList<Categories_units> m_CategoriesUnits_List;
   // TableModelUnits *m_tableModelCategoriesUnits;

    int current_category_index;

    void setComboBoxCategories(int &current_index);
    bool setTableWidgetUnits(QTableWidget &table, Categories_units &units);
    void setTableWidgetSolutions(QStringList &solutions);

};

#endif // MAINWINDOW_H
