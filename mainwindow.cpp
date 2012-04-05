#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCore/QCoreApplication>
#include <QDebug>
#include <QFile>
#include "unitsettings.h"
#include "format_dlg.h"
#include "globalfunctions.h"
#include "categories_dlg.h"
#include "about_dlg.h"
#include "help_dlg.h"
#include "settings_dlg.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    counter = 0;//counter to avoid recursion overflow with itemChanged() method

    QFile file("conversions.dat");

    if (file.open(QIODevice::ReadOnly)) // if file exists reads from file
    {
        QDataStream in(&file);
        in>>m_CategoriesUnits_List;
        in>>current_category_index;
        file.close();

    }
    else //if file does not exists reads from defaul constructor settings
    {
        loadInitialConversions();
    }

   // setTableWidget(*ui->tableWidget_units_results, m_CategoriesUnits_List[current_category_index]);


    mapper = new QSignalMapper(this);

    connect(ui->pushButton_0, SIGNAL(clicked()), mapper, SLOT(map()));
    connect(ui->pushButton_1, SIGNAL(clicked()), mapper, SLOT(map()));
    connect(ui->pushButton_2, SIGNAL(clicked()), mapper, SLOT(map()));
    connect(ui->pushButton_3, SIGNAL(clicked()), mapper, SLOT(map()));
    connect(ui->pushButton_4, SIGNAL(clicked()), mapper, SLOT(map()));
    connect(ui->pushButton_5, SIGNAL(clicked()), mapper, SLOT(map()));
    connect(ui->pushButton_6, SIGNAL(clicked()), mapper, SLOT(map()));
    connect(ui->pushButton_7, SIGNAL(clicked()), mapper, SLOT(map()));
    connect(ui->pushButton_8, SIGNAL(clicked()), mapper, SLOT(map()));
    connect(ui->pushButton_9, SIGNAL(clicked()), mapper, SLOT(map()));
    connect(ui->pushButton_dot, SIGNAL(clicked()), mapper, SLOT(map()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), mapper, SLOT(map()));
    connect(ui->pushButton_E, SIGNAL(clicked()), mapper, SLOT(map()));


    mapper->setMapping(ui->pushButton_0,"0");
    mapper->setMapping(ui->pushButton_1,"1");
    mapper->setMapping(ui->pushButton_2,"2");
    mapper->setMapping(ui->pushButton_3,"3");
    mapper->setMapping(ui->pushButton_4,"4");
    mapper->setMapping(ui->pushButton_5,"5");
    mapper->setMapping(ui->pushButton_6,"6");
    mapper->setMapping(ui->pushButton_7,"7");
    mapper->setMapping(ui->pushButton_8,"8");
    mapper->setMapping(ui->pushButton_9,"9");
    mapper->setMapping(ui->pushButton_dot,".");
    mapper->setMapping(ui->pushButton_minus,"-");
    mapper->setMapping(ui->pushButton_E,"E");


    connect(mapper,SIGNAL(mapped(const QString &)), this,SLOT(setTextfromBtnClicked(const QString &)));
    connect(ui->pushButton_del,SIGNAL(clicked()),this,SLOT(clicked_del()));
    connect(ui->pushButton_clear,SIGNAL(clicked()),this,SLOT(clicked_clear()));

    /*
    ui->pushButton_settings->hide();
    ui->pushButton_exit->hide();
#if defined(Q_WS_S60)
    ui->pushButton_settings->show();
    ui->pushButton_exit->show();
#endif
*/

}

MainWindow::~MainWindow()
{

    QFile file("conversions.dat");
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);   // we will serialize the data into the file
    out<<m_CategoriesUnits_List;
    out<<current_category_index;
    file.close();

    delete ui;
}


void MainWindow::loadInitialConversions()
{
    m_CategoriesUnits_List.clear();

    Categories_units angle;
    angle.setCategory("Angle");
    angle.addConvertion("degree = radian*180/3.1415926535");
    angle.addConvertion("radian = degree*3.1415926535/180");

    //angle.addConvertion("degree = grad*200/3.1415926535");
    //angle.addConvertion("grad = degree*3.1415926535/200");

    m_CategoriesUnits_List.append(angle);

    /*pi rad = 200 grad
3.1415926535897932384
degree
radian
grad*/


    Categories_units area;
    area.setCategory("Area");
    area.addConvertion("meter2 = acre*4046.8564224");
    area.addConvertion("acre = meter2/4046.8564224");

    area.addConvertion("meter2 = are*100");
    area.addConvertion("are = meter2/100");

    area.addConvertion("meter2 = centimeter2/10000");
    area.addConvertion("centimeter2 = meter2*10000");

    area.addConvertion("meter2 = foot2/10.76391041671");//1m2 = 10,76391041671 pés quadrados (ft²)
    area.addConvertion("foot2 = meter2*10.76391041671");

    area.addConvertion("meter2 = hectare*10000");
    area.addConvertion("hectare = meter2/10000");

    area.addConvertion("meter2 = inch2/1550.0031000062");
    area.addConvertion("inch2 = meter2*1550.0031000062");

    area.addConvertion("meter2 = kilometer2*1000000");
    area.addConvertion("kilometer2 = meter2/1000000");

    area.addConvertion("mile2 = kilometer2/2.589988110336");
    area.addConvertion("kilometer2 = mile2*2.589988110336");

    area.addConvertion("meter2 = millimeter2/1000000");
    area.addConvertion("millimeter2 = meter2*1000000");

    area.addConvertion("foot2 = yard2*9");
    area.addConvertion("yard2 = foot2/9");

    m_CategoriesUnits_List.append(area);




    Categories_units bits_bytes;
    bits_bytes.setCategory("Bits & Bytes");
    bits_bytes.addConvertion("bit = byte*8");
    bits_bytes.addConvertion("byte = bit/8");

    bits_bytes.addConvertion("byte = Kilobyte*1024");
    bits_bytes.addConvertion("Kilobyte = byte/1024");

    bits_bytes.addConvertion("Kilobyte = Megabyte*1024");
    bits_bytes.addConvertion("Megabyte = Kilobyte/1024");
    m_CategoriesUnits_List.append(bits_bytes);
    /*
Kilobyte
Megabyte
   Gigabyte
 Terabyte
Petabyte
      */

    Categories_units distance;
    distance.setCategory("Distance");
    distance.addConvertion("m = 1000*Km");
    distance.addConvertion("Km = 0.001*m");

    distance.addConvertion("dm = 10*m");
    distance.addConvertion("m = 0.1*dm");

    distance.addConvertion("cm = 10*dm");
    distance.addConvertion("dm = 0.1*cm");

    distance.addConvertion("mm = 10*cm");
    distance.addConvertion("cm = 0.1*mm");

    distance.addConvertion("cm = 2.54*inch");
    distance.addConvertion("inch = cm/2.54");

    distance.addConvertion("foot = yard*3");
    distance.addConvertion("yard = foot/3");

    distance.addConvertion("foot = miles*5280");
    distance.addConvertion("miles = foot/5280");

    distance.addConvertion("Km = miles*1.609");    
    distance.addConvertion("miles = Km/1.609");

    m_CategoriesUnits_List.append(distance);


    Categories_units energy;
    energy.setCategory("Energy");
    energy.addConvertion("kJ = Btu*1.0550559");
    energy.addConvertion("Btu = kJ/1.0550559");

    energy.addConvertion("kJ = J/1000");
    energy.addConvertion("J = kJ*1000");

    energy.addConvertion("cal = J/4.1868");
    energy.addConvertion("J = cal*4.1868");

    energy.addConvertion("cal = kcal*1000");
    energy.addConvertion("kcal = cal/1000");

    energy.addConvertion("N_m = J");
    energy.addConvertion("J = N_m");

    energy.addConvertion("kgf_m = kcal*426.93478");
    energy.addConvertion("kcal = kgf_m/426.93478");

    energy.addConvertion("kW_h = kcal/859.84523");
    energy.addConvertion("kcal = kW_h*859.84523");

    energy.addConvertion("kW_h = N_m/3600000");
    energy.addConvertion("N_m = kW_h*3600000");

    energy.addConvertion("therm = Btu/100000");
    energy.addConvertion("Btu = therm*100000");
    m_CategoriesUnits_List.append(energy);

/*
W
kW
MK
hp
cv
BTU
kJ_h
kcal_h
*/
    Categories_units illumination;
    illumination.setCategory("Illumination");

    illumination.addConvertion("lux = ft_candle*10.76391041671");
    illumination.addConvertion("ft_candle = lux/10.76391041671");

    illumination.addConvertion("lux = meter_candle");
    illumination.addConvertion("meter_candle = lux");

    illumination.addConvertion("lux = lumen_m2");
    illumination.addConvertion("lumen_m2 = lux");

    illumination.addConvertion("lux = phot*10000");
    illumination.addConvertion("phot = lux/10000");

    m_CategoriesUnits_List.append(illumination);


    /*
Km
m
dm
cm
mm
microns
angstrons
milhas
ya jardas
ft feet
in polegadas
milha nautica

*/

    Categories_units SI_prefix;
    SI_prefix.setCategory("SI prefix");
    SI_prefix.addConvertion("peta = unit/1E15");
    SI_prefix.addConvertion("unit = peta*1E15");
    SI_prefix.addConvertion("tera = unit/1E12");
    SI_prefix.addConvertion("unit = tera*1E12");
    SI_prefix.addConvertion("giga = unit/1E9");
    SI_prefix.addConvertion("unit = giga*1E9");
    SI_prefix.addConvertion("mega = unit/1E6");
    SI_prefix.addConvertion("unit = mega*1E6");
    SI_prefix.addConvertion("kilo = unit/1E3");
    SI_prefix.addConvertion("unit = kilo*1E3");
    SI_prefix.addConvertion("hecto = unit/100");
    SI_prefix.addConvertion("unit = hecto*100");
    SI_prefix.addConvertion("deka = unit/10");
    SI_prefix.addConvertion("unit = deka*10");
    m_CategoriesUnits_List.append(SI_prefix);
    /*
      peta
      tera
      giga
      mega
      kilo
      hecto
      deka
      base unit 1
      deci 1E-1
      centi 1E-2
      mili 1E-3
      micro 1E-6
      nano 1E-9
      pico 1E-12
      femto 1E-15
*/


    Categories_units temperature;
    temperature.setCategory("Temperature");
    temperature.addConvertion("Celsius = Kelvin -273.15");
    temperature.addConvertion("Celsius= (Fahrenheit - 32)*5/9");
    temperature.addConvertion("Kelvin=Celsius+273.15");
    temperature.addConvertion("Fahrenheit=Celsius*1.8 + 32");
    temperature.addConvertion("Fahrenheit = Kelvin*9/5-459.67");
    temperature.addConvertion("Kelvin=( Fahrenheit +459.67)*5/9");
    temperature.addConvertion("Rankine=(Celsius+273.15)*9/5");
    temperature.addConvertion("Celsius=(Rankine-491.67)*5/9");
    temperature.addConvertion("Reaumur=Celsius*4/5");
    temperature.addConvertion("Celsius=Reaumur*5/4");
    //[°C] = [°Ré] × 5/4
    m_CategoriesUnits_List.append(temperature);




    Categories_units time;
    time.setCategory("Time");
    time.addConvertion("s = 60*min");
    time.addConvertion("min = s/60");
    time.addConvertion("min = 60*h");
    time.addConvertion("h = min/60");
    time.addConvertion("day = h/24");
    time.addConvertion("h = day*24");
    m_CategoriesUnits_List.append(time);


    Categories_units volume;
    volume.setCategory("Volume");
    volume.addConvertion("liter = dl/10");
    volume.addConvertion("dl = liter*10");

    volume.addConvertion("liter = cl/100");
    volume.addConvertion("cl = liter*100");

    volume.addConvertion("liter = ml/1000");
    volume.addConvertion("ml = liter*1000");

    volume.addConvertion("m3 = dm3/1000");
    volume.addConvertion("dm3 = m3*1000");

    volume.addConvertion("liter = dm3");
    volume.addConvertion("dm3 = liter");

    volume.addConvertion("dm3 = cm3/1000");
    volume.addConvertion("cm3 = dm3*1000");

    volume.addConvertion("cm3 = mm3/1000");
    volume.addConvertion("mm3 = cm3*1000");
    m_CategoriesUnits_List.append(volume);


    Categories_units pressure;
    pressure.setCategory("Pressure");
    pressure.addConvertion("Pa = atm*101325");
    pressure.addConvertion("atm = Pa/101325");

    pressure.addConvertion("bar = atm*1.01325");
    pressure.addConvertion("atm = bar/1.01325");

    pressure.addConvertion("psi = atm*14.6959487755");
    pressure.addConvertion("atm = psi/14.6959487755");

    pressure.addConvertion("atm = mmHg/760");
    pressure.addConvertion("mmHg = atm*760");

    m_CategoriesUnits_List.append(pressure);

    /*
Pa
atm
psi
bar*/




    current_category_index=0;
}

/*
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

        if (table.item(l,1) == 0)
        {
            QTableWidgetItem *newItem = new QTableWidgetItem();
            table.setItem(l,1, newItem);
            table.item(l,1)->setText("");
        }
        table.item(l,1)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    }

    return true;
}
*/


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
    //showMaximized();
#elif defined(Q_WS_MAEMO_5)
    showMaximized();
#else
    show();
#endif
}

void MainWindow::showEvent(QShowEvent * event)
{
    double verticalSize=1;
#if defined(Q_WS_S60)
   verticalSize = 1.5;
#endif

    //ui->tableWidget_units_results->setRowCount(m_CategoriesUnits_List.length());

  /* double  wi = ui->tableWidget_units_results->verticalHeader()->size().height();
   double  wsi = ui->tableWidget_units_results->verticalHeader()->size().width();

   double  wii = ui->tableWidget_units_results->horizontalHeader()->size().width();

   double s = ui->tableWidget_units_results->size().width();
   double ss = ui->tableWidget_units_results->size().width() * 0.5;
*/

   ui->tableWidget_units_results->horizontalHeader()->hide();
   ui->tableWidget_units_results->verticalHeader()->hide();

    //int wi = ui->tableWidget_units_results->verticalHeader()->sizeHint().width();



   // ui->tableWidget_units_results->horizontalHeader()->setDefaultSectionSize(
     //            (ui->tableWidget_units_results->size().width() * 0.5));

    ui->tableWidget_units_results->horizontalHeader()->setDefaultSectionSize(int(
                 ui->tableWidget_units_results->size().width() * 0.5  ));




  //  ui->tableWidget_units_results->horizontalHeader()->setResizeMode(QHeaderView::Interactive);
    ui->tableWidget_units_results->horizontalHeader()->setResizeMode(QHeaderView::Stretch);



    ui->tableWidget_units_results->verticalHeader()->setDefaultSectionSize(
                int(verticalSize*ui->tableWidget_units_results->verticalHeader()->defaultSectionSize()));



    setTableWidget(*ui->tableWidget_units_results, m_CategoriesUnits_List[current_category_index]);


}


void MainWindow::on_tableWidget_units_results_itemChanged(QTableWidgetItem *item)
{

    qDebug()<<item->text();
    /*QStringList solutions = m_CategoriesUnits_List[current_category_index].m_units.setValue(item->text(), item->row());

    counter++;


    if (counter <= solutions.size()+1)
    {
        setTableWidgetSolutions(solutions);
    }
    else
    {
        counter = 0;
    }
    */

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

        if (ui->tableWidget_units_results->item(l,1)->text() != solutions.at(l))
        {
            ui->tableWidget_units_results->item(l,1)->setText(solutions.at(l));
        }
    }

}

void MainWindow::clicked_del()
{
    int r = ui->tableWidget_units_results->currentRow();
    int c = 1;//ui->tableWidget_units_results->currentColumn();

    if (r < 0 )//|| c < 0)
        return;

   QString str;
   str = ui->tableWidget_units_results->item(r,c)->text();
   str.remove(str.size()-1,1);
   ui->tableWidget_units_results->item(r,c)->setText(str);

   QStringList result = m_CategoriesUnits_List[current_category_index].m_units.setValue(str, r);
   setTableWidgetSolutions(result);
}

void MainWindow::clicked_clear()
{
    int r = ui->tableWidget_units_results->currentRow();
    int c = 1;//ui->tableWidget_units_results->currentColumn();

    if (r < 0 )//|| c < 0)
        return;

    ui->tableWidget_units_results->item(r,c)->setText("");
    clicked_del();
}


void MainWindow::setTextfromBtnClicked(const QString &str)
{
    int row = ui->tableWidget_units_results->currentRow();
    int col=1;

    if (row < 0)
        return;

    if (ui->tableWidget_units_results->item(row,col) == 0)
    {
        QTableWidgetItem *newItem = new QTableWidgetItem();
        ui->tableWidget_units_results->setItem(row,col, newItem);
    }
    QString s = ui->tableWidget_units_results->item(row,col)->text();
    s=s+str;
    ui->tableWidget_units_results->item(row,col)->setText(s);


    QStringList result = m_CategoriesUnits_List[current_category_index].m_units.setValue(s, row);
    setTableWidgetSolutions(result);

}

void MainWindow::on_pushButton_categories_clicked()
{
    categories_dlg dlg;
    dlg.m_categoriesList_ptr = &m_CategoriesUnits_List;

#if defined(Q_WS_S60)
   //dlg.setWindowState(dlg.windowState() | Qt::WindowMaximized);
   dlg.setWindowState(dlg.windowState() | Qt::WindowFullScreen);
#endif

    dlg.index_selected =current_category_index;
   // if (dlg.exec() == QDialog::Accepted)
    dlg.exec();
    // {
        current_category_index = dlg.index_selected;
        setTableWidget(*ui->tableWidget_units_results, m_CategoriesUnits_List[current_category_index]);
   // }

}



void MainWindow::on_actionSettings_triggered()
{
    UnitSettings dlg;

#if defined(Q_WS_S60)
   //dlg.setWindowState(dlg.windowState() | Qt::WindowMaximized);
   dlg.setWindowState(dlg.windowState() | Qt::WindowFullScreen);
#endif

   //dlg.m_categoriesList_ptr = &m_CategoriesUnits_List;
   dlg.m_CategoriesUnits = m_CategoriesUnits_List;
   dlg.currentIndex = current_category_index;


   dlg.exec();

   if (dlg.returnValue == 1)
   {
       m_CategoriesUnits_List = dlg.m_CategoriesUnits;
       current_category_index = dlg.currentIndex;
       setTableWidget(*ui->tableWidget_units_results, m_CategoriesUnits_List[current_category_index]);

       m_CategoriesUnits_List = dlg.m_CategoriesUnits;
   }
}

void MainWindow::on_actionAbout_triggered()
{
    About_Dlg dlg;

#if defined(Q_WS_S60)
   //dlg.setWindowState(dlg.windowState() | Qt::WindowMaximized);
   dlg.setWindowState(dlg.windowState() | Qt::WindowFullScreen);
#endif
    dlg.exec();
}

void MainWindow::on_actionCategories_triggered()
{
    categories_dlg dlg;
    dlg.m_categoriesList_ptr = &m_CategoriesUnits_List;

#if defined(Q_WS_S60)
   dlg.setWindowState(dlg.windowState() | Qt::WindowMaximized);
   //dlg.setWindowState(dlg.windowState() | Qt::WindowFullScreen);
#endif

    dlg.index_selected =current_category_index;
    if (dlg.exec() == QDialog::Accepted)
    {
        current_category_index = dlg.index_selected;
        setTableWidget(*ui->tableWidget_units_results, m_CategoriesUnits_List[current_category_index]);
    }
}

void MainWindow::on_pushButton_show_hide_clicked()
{
    if (ui->frame_keypad->isVisible())
    {
        ui->frame_keypad->hide();
        ui->pushButton_show_hide->setText("Show");
    }
    else
    {
        ui->frame_keypad->show();
        ui->pushButton_show_hide->setText("Hide");
    }
}

void MainWindow::on_pushButton_plus_minus_clicked()
{
    int r = ui->tableWidget_units_results->currentRow();
    int c = 1;//ui->tableWidget_units_results->currentColumn();

    if (r < 0 )//|| c < 0)
        return;

   QString str;
   str = ui->tableWidget_units_results->item(r,c)->text();
   //str.remove(str.size()-1,1);
   if (str.size() > 0)
   {
       if (str.at(0) == '-')
           str.remove(0,1);
       else
           str.insert(0,"-");

   }

   ui->tableWidget_units_results->item(r,c)->setText(str);

   QStringList result = m_CategoriesUnits_List[current_category_index].m_units.setValue(str, r);
   setTableWidgetSolutions(result);
}

void MainWindow::on_pushButton_update_clicked()
{
    int r = ui->tableWidget_units_results->currentRow();
    int c = 1;//ui->tableWidget_units_results->currentColumn();

    if (r < 0 )//|| c < 0)
        return;

    QString str = ui->tableWidget_units_results->item(r,c)->text();


    ui->tableWidget_units_results->item(r,c)->setText(str);

    QStringList result = m_CategoriesUnits_List[current_category_index].m_units.setValue(str, r);
    setTableWidgetSolutions(result);
}

void MainWindow::on_actionFormat_triggered()
{
    Format_Dlg dlg;

#if defined(Q_WS_S60)
   dlg.setWindowState(dlg.windowState() | Qt::WindowMaximized);
   //dlg.setWindowState(dlg.windowState() | Qt::WindowFullScreen);
#endif
    dlg.exec();
}

void MainWindow::on_actionReset_triggered()
{
    int ret = QMessageBox::warning(this, tr("Reset"),
                                    tr("Reset to factory default?\n"
                                       "All your saved formulas will be lost!"),
                                   // QMessageBox::Save | QMessageBox::Discard
                                   QMessageBox::Ok
                                    | QMessageBox::Cancel);//,
                                    //QMessageBox::Save);


    if (ret == QMessageBox::Ok)
    {
        QFile file("conversions.dat");
        if (!file.remove())
            qDebug()<<"Unable to reset settings";
        loadInitialConversions();
        current_category_index = 0;
        setTableWidget(*ui->tableWidget_units_results, m_CategoriesUnits_List[current_category_index]);
    }

}

void MainWindow::on_actionHelp_triggered()
{
    help_dlg dlg;
#if defined(Q_WS_S60)
   //dlg.setWindowState(dlg.windowState() | Qt::WindowMaximized);
   dlg.setWindowState(dlg.windowState() | Qt::WindowFullScreen);
#endif

    dlg.exec();
}

void MainWindow::on_pushButton_exit_clicked()
{
    close();
}

void MainWindow::on_pushButton_settings_clicked()
{
    settings_dlg dlg;

#if defined(Q_WS_S60)
   //dlg.setWindowState(dlg.windowState() | Qt::WindowMaximized);
   dlg.setWindowState(dlg.windowState() | Qt::WindowFullScreen);
#endif

   dlg.exec();


   if (dlg.index_selected == 0)
   {
       on_actionSettings_triggered();
   }

   if (dlg.index_selected == 1)
   {
       on_actionReset_triggered();
   }

   if (dlg.index_selected == 2)
   {
       on_actionHelp_triggered();
   }

   if (dlg.index_selected == 3)
   {
       on_actionAbout_triggered();
   }


}
