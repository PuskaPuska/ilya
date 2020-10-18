//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
// Название модуля: WidgetTree
//
// Описание: содержит описание виджета дерева настроек
//
// Автор: Никитин Вячеслав
//
// Дата создания: 21.09.2014
//
// Дата последнего изменения: 22.10.2014
//------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////

#ifndef WIDGETTREE_H
#define WIDGETTREE_H

#include <QTreeWidget>

//class QListWidget;
//class QListWidgetItem;
//class QStackedWidget;
//class QComboBox;
//class QLineEdit;
//class QTreeWidget;
class QTreeWidgetItem;
//class QMenu;
//class QCheckBox;

class CWidgetTree : public QTreeWidget
{
  Q_OBJECT

signals:
  void itemTreeChanged(int newItem);
  void copySourse(int numSourse);
  void hideSourse(int numSourse);
  void addSourse();
  void delSourse(int numSourse);
  void addMeteo();
  void delMeteo(int numMeteo);
  void copyMeteo(int numMeteo);

public:
  int AddNewItem(int indItem);

  CWidgetTree(QWidget *parent = 0);
  int SetExpertMode(int isProfi = false);
  int UpdateTree();
  int UpdateMeteoNames();
  int UpdateSourceNames();
  int SetMainSourceCurr();

  public slots:
    void ChangePage(QTreeWidgetItem *current, QTreeWidgetItem *previous);
    void OnItemDoubleClicked ( QTreeWidgetItem * item, int column );
    void EnterPressed();
    void ShowContextMenu(QPoint pointIn);
    void OnItemRename();
    void OnCopySourseButton();
    void OnHideSourseButton();
    void OnAddMeteoButton();
    void OnDelMeteoButton();
    void OnAddSourseButton();
    void OnDelSourseButton();
    void OnCopyMeteoButton();
    void OnHideMeteoButton();

protected:

private:
  QTreeWidgetItem *mainSourseItem;
  QTreeWidgetItem *mainMeteoItem;
  QTreeWidgetItem *mainCalcParamItem;
  QTreeWidgetItem *mainResultItem;
  QTreeWidgetItem **expertPages;

  QMenu *contTreeMenuSourse;
  QMenu *contTreeMenuMeteo;

  int isNameChanging;

  int expretPageCount;
  int isLoadData;

  ~CWidgetTree();

  void CreateTree();
  void keyPressEvent ( QKeyEvent * e );
  void CreateContMenu();
  int GetSerialNum(QTreeWidgetItem *item);
  int SetEnableSourse(int isEnable);
  //int SetEnableMeteo(int isEnable)
};

#endif