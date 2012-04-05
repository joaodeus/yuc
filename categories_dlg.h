#ifndef CATEGORIES_DLG_H
#define CATEGORIES_DLG_H

#include <QDialog>
#include <QModelIndex>
#include "categories_units/categories_units.h"

namespace Ui {
class categories_dlg;
}

class categories_dlg : public QDialog
{
    Q_OBJECT
    
public:
    explicit categories_dlg(QWidget *parent = 0);
    ~categories_dlg();

    QList<Categories_units> *m_categoriesList_ptr;
    int index_selected;
    void showEvent(QShowEvent * event);
    
private slots:
    void on_listWidget_categories_clicked(const QModelIndex &index);

private:
    Ui::categories_dlg *ui;
};

#endif // CATEGORIES_DLG_H
