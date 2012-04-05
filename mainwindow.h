#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QList>
#include <QTableWidget>
#include <QSignalMapper>
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

    void showEvent(QShowEvent * event);
    //void on_comboBox_categories_currentIndexChanged(int index);
    void on_tableWidget_units_results_itemChanged(QTableWidgetItem *item);
    void setTextfromBtnClicked(const QString &);
    void clicked_del();
    void clicked_clear();


    void on_pushButton_categories_clicked();

    void on_actionSettings_triggered();

    void on_actionAbout_triggered();

    void on_actionCategories_triggered();

    void on_pushButton_show_hide_clicked();

    void on_pushButton_plus_minus_clicked();

    void on_pushButton_update_clicked();

    void on_actionFormat_triggered();

    void on_actionReset_triggered();

    void on_actionHelp_triggered();

    void on_pushButton_exit_clicked();

    void on_pushButton_settings_clicked();

private:
    Ui::MainWindow *ui;
    QSignalMapper *mapper;
    int counter;

    QList<Categories_units> m_CategoriesUnits_List;
   // TableModelUnits *m_tableModelCategoriesUnits;

    int current_category_index;


   // bool setTableWidgetUnits(QTableWidget &table, Categories_units &units);
    void setTableWidgetSolutions(QStringList &solutions);

    void loadInitialConversions();

};

#endif // MAINWINDOW_H
