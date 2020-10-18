#ifndef GEN_H
#define GEN_H

#include <QtGui/QMainWindow>
#include "ui_gen.h"
#include "PagesWidget.h"
#include "WidgetTree.h"


class Gen : public QMainWindow
{
    Q_OBJECT

public:
    Gen(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~Gen();

    CWidgetTree *viewTree;

private:
    Ui::GenClass ui;

    QAction *menuNewMesh;
    QAction *menuLoadCalc;
    QAction *menuLoadParams;
    QAction *menuSaveCalc;
    QAction *menuSaveParams;
    QAction *menuClose;

    CPagesWidget *pagesWidget;

    void CreateMenuBar();

private slots:
    void NewCalc();
    void LoadCalc();
    void LoadParams();
    void SaveCalc();
    void SaveParams();
    void OnItemTreeChange(int numItem);

};

#endif // GEN_H
