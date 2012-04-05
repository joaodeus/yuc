#ifndef HELP_DLG_H
#define HELP_DLG_H

#include <QDialog>
//#include <QWebView>

namespace Ui {
class help_dlg;
}

class help_dlg : public QDialog
{
    Q_OBJECT
    
public:
    explicit help_dlg(QWidget *parent = 0);
    ~help_dlg();
    
private slots:
    void on_pushButton_ok_clicked();

private:
    Ui::help_dlg *ui;
};

#endif // HELP_DLG_H
