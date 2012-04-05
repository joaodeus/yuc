#ifndef SETTINGS_DLG_H
#define SETTINGS_DLG_H

#include <QDialog>
#include <QModelIndex>

namespace Ui {
class settings_dlg;
}

class settings_dlg : public QDialog
{
    Q_OBJECT
    
public:
    explicit settings_dlg(QWidget *parent = 0);
    ~settings_dlg();

    int index_selected;

private slots:
    void on_listWidget_clicked(const QModelIndex &index);

private:
    Ui::settings_dlg *ui;
};

#endif // SETTINGS_DLG_H
