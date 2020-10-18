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
// Дата последнего изменения: 17.11.2014
//------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////

#include <QtGui>

#include "WidgetTree.h"
#include "Storage.h"

CWidgetTree::CWidgetTree(QWidget *parent)
  : QTreeWidget(parent)
{
  //QHBoxLayout *mainLayout = new QHBoxLayout;
  //mainLayout->addWidget(renderArea);
  //setLayout(mainLayout);
  //setCentralWidget(renderArea);

  isLoadData = 0;

  setContextMenuPolicy(Qt::CustomContextMenu);

  // ждем сигнала для отображения меню
  connect(this, SIGNAL(customContextMenuRequested(QPoint)),
    this, SLOT(ShowContextMenu(QPoint)));

  CreateTree();
  CreateContMenu();

  isNameChanging = 0;

  SetExpertMode(0);
}

CWidgetTree::~CWidgetTree()
{

}

void CWidgetTree::CreateTree()
{
  expretPageCount = 0;
  expertPages = new QTreeWidgetItem *[expretPageCount];
  setMinimumWidth(250);
  setMaximumWidth(400);
  setColumnCount(1);
  QTreeWidgetItem *HederItem = new QTreeWidgetItem;
  HederItem->setText(0, tr("Дерево элементов"));
  //HederItem->setText(1, tr(""));
  setHeaderItem(HederItem);
  setColumnWidth(0, 230);

  //QTreeWidgetItem *item2 = new QTreeWidgetItem;
  //item2->setText(0, tr("Параметры местности"));
  //addTopLevelItem(item2);

  //mainMeteoItem = new QTreeWidgetItem;
  //mainMeteoItem->setText(0, tr("Состояние атмосферы"));
  //addTopLevelItem(mainMeteoItem);

  //mainSourseItem = new QTreeWidgetItem;
  //mainSourseItem->setText(0, tr("Источники"));
  //addTopLevelItem(mainSourseItem);

  //mainCalcParamItem = new QTreeWidgetItem;
  //mainCalcParamItem->setText(0, tr("Параметры расчета"));
  //addTopLevelItem(mainCalcParamItem);

  //QTreeWidgetItem *item4 = new QTreeWidgetItem;
  //item4->setText(0, tr("Граничные условия"));
  //mainCalcParamItem->addChild(item4);

  //expertPages[0] = new QTreeWidgetItem;
  //expertPages[0]->setText(0, tr("«Тонкая настройка»"));
  //mainCalcParamItem->addChild(expertPages[0]);

  //mainResultItem = new QTreeWidgetItem;
  //mainResultItem->setText(0, tr("Результаты"));
  //addTopLevelItem(mainResultItem);

  //QTreeWidgetItem *item11 = new QTreeWidgetItem;
  //item11->setText(0, tr("Расчет плотностей"));
  //mainResultItem->addChild(item11);

  //QTreeWidgetItem *item10 = new QTreeWidgetItem;
  //item10->setText(0, tr("Координаты"));
  //item11->addChild(item10);

  ////QTreeWidgetItem *item12 = new QTreeWidgetItem;
  ////item12->setText(0, tr("Времена"));
  ////item11->addChild(item12);

  //expertPages[2] = new QTreeWidgetItem;
  //expertPages[2]->setText(0, tr("Времена"));
  //item11->addChild(expertPages[2]);

  //QTreeWidgetItem *item13 = new QTreeWidgetItem;
  //item13->setText(0, tr("Расчет концентраций"));
  //mainResultItem->addChild(item13);

  //QTreeWidgetItem *item14 = new QTreeWidgetItem;
  //item14->setText(0, tr("Координаты"));
  //item13->addChild(item14);

  ////QTreeWidgetItem *item15 = new QTreeWidgetItem;
  ////item15->setText(0, tr("Времена"));
  ////item13->addChild(item15);

  ////QTreeWidgetItem *item16 = new QTreeWidgetItem;
  ////item16->setText(0, tr("Высоты"));
  ////item13->addChild(item16);

  //expertPages[3] = new QTreeWidgetItem;
  //expertPages[3]->setText(0, tr("Времена"));
  //item13->addChild(expertPages[3]);

  //expertPages[4] = new QTreeWidgetItem;
  //expertPages[4]->setText(0, tr("Высоты"));
  //item13->addChild(expertPages[4]);

  //expertPages[1] = new QTreeWidgetItem;
  //expertPages[1]->setText(0, tr("Расчет дозовых нагрузок"));
  //mainResultItem->addChild(expertPages[1]);

  connect(this,
    SIGNAL(currentItemChanged(QTreeWidgetItem *,QTreeWidgetItem *)),
    this, SLOT(ChangePage(QTreeWidgetItem *,QTreeWidgetItem *)));

  connect(this,
    SIGNAL(itemDoubleClicked ( QTreeWidgetItem *, int )),
    this, SLOT(OnItemDoubleClicked ( QTreeWidgetItem *, int )));

  setColumnWidth(0, 170);
  //setCurrentItem(item2);
}

int CWidgetTree::AddNewItem(int indItem)
{
  CStorage *storage = &CStorage::instance();
  QTreeWidgetItem *item = new QTreeWidgetItem;
  item->setText(0, storage->elemContainer[indItem]->GetElemName());
  addTopLevelItem(item);
  setCurrentItem(item);
  return 0;
}

void CWidgetTree::CreateContMenu()
{
  contTreeMenuSourse = new QMenu(this);

  QAction *menuInsSourse = new QAction(tr("Добавить источник"), this);
  menuInsSourse->setStatusTip(tr("Добавить новый источник"));
  connect(menuInsSourse, SIGNAL(triggered()), this, SLOT(OnAddSourseButton()));
  contTreeMenuSourse->addAction(menuInsSourse);

  QAction *menuDelSourse = new QAction(tr("Удалить источник"), this);
  menuDelSourse->setStatusTip(tr("Удалить выделенный источник"));
  connect(menuDelSourse, SIGNAL(triggered()), this, SLOT(OnDelSourseButton()));
  contTreeMenuSourse->addAction(menuDelSourse);

  QAction *menuCopySourse = new QAction(tr("Дублировать источник"), this);
  menuCopySourse->setStatusTip(tr("Дублировать выделенный источник"));
  connect(menuCopySourse, SIGNAL(triggered()), this, SLOT(OnCopySourseButton()));
  contTreeMenuSourse->addAction(menuCopySourse);

  QAction *menuHideSourse = new QAction(tr("Деактивировать источник"), this);
  menuHideSourse->setStatusTip(tr("Деактивировать выделенный источник"));
  connect(menuHideSourse, SIGNAL(triggered()), this, SLOT(OnHideSourseButton()));
  contTreeMenuSourse->addAction(menuHideSourse);

  QAction *menuShowSourse = new QAction(tr("Активировать источник"), this);
  menuShowSourse->setStatusTip(tr("Активировать выделенный источник"));
  connect(menuShowSourse, SIGNAL(triggered()), this, SLOT(OnHideSourseButton()));
  contTreeMenuSourse->addAction(menuShowSourse);

  QAction *menuRenameSourse = new QAction(tr("Переименовать источник"), this);
  menuRenameSourse->setStatusTip(tr("Переименовать выделенный источник"));
  connect(menuRenameSourse, SIGNAL(triggered()), this, SLOT(OnItemRename()));
  contTreeMenuSourse->addAction(menuRenameSourse);

  contTreeMenuMeteo = new QMenu(this);

  QAction *menuInsMeteo = new QAction(tr("Добавить временной слой"), this);
  menuInsMeteo->setStatusTip(tr("Добавить новый временной слой"));
  connect(menuInsMeteo, SIGNAL(triggered()), this, SLOT(OnAddMeteoButton()));
  contTreeMenuMeteo->addAction(menuInsMeteo);

  QAction *menuDelMeteo = new QAction(tr("Удалить слой"), this);
  menuDelMeteo->setStatusTip(tr("Удалить выделенный слой"));
  connect(menuDelMeteo, SIGNAL(triggered()), this, SLOT(OnDelMeteoButton()));
  contTreeMenuMeteo->addAction(menuDelMeteo);

  QAction *menuCopyMeteo = new QAction(tr("Дублировать слой"), this);
  menuCopyMeteo->setStatusTip(tr("Дублировать выделенный слой"));
  connect(menuCopyMeteo, SIGNAL(triggered()), this, SLOT(OnCopyMeteoButton()));
  contTreeMenuMeteo->addAction(menuCopyMeteo);

  QAction *menuHideMeteo = new QAction(tr("Деактивировать слой"), this);
  menuHideMeteo->setStatusTip(tr("Деактивировать выделенный слой"));
  connect(menuHideMeteo, SIGNAL(triggered()), this, SLOT(OnHideMeteoButton()));
  contTreeMenuMeteo->addAction(menuHideMeteo);

  QAction *menuShowMeteo = new QAction(tr("Активировать слой"), this);
  menuShowMeteo->setStatusTip(tr("Активировать выделенный слой"));
  connect(menuShowMeteo, SIGNAL(triggered()), this, SLOT(OnHideMeteoButton()));
  contTreeMenuMeteo->addAction(menuShowMeteo);

  QAction *menuRenameMeteo = new QAction(tr("Переименовать слой"), this);
  menuRenameMeteo->setStatusTip(tr("Переименовать выделенный слой"));
  connect(menuRenameMeteo, SIGNAL(triggered()), this, SLOT(OnItemRename()));
  contTreeMenuMeteo->addAction(menuRenameMeteo);
}

void CWidgetTree::OnItemDoubleClicked ( QTreeWidgetItem * item, int column )
{
  if (column != 0)
    return;

  if (item->parent() == NULL)
    return;

  if (item->parent() != mainSourseItem &&  item->parent() != mainMeteoItem)
    return;

  //viewTree->itemWidget(item, 0)->setVisible(true);
  QLineEdit *pageNameEdit = new QLineEdit(item->text(0));

  setItemWidget(item, 0, pageNameEdit);
  itemWidget(item, 0)->setWhatsThis("Название");
  connect(pageNameEdit, SIGNAL(returnPressed()), SLOT(EnterPressed()));
  isNameChanging = 1;
}

void CWidgetTree::EnterPressed()
{
  QTreeWidgetItem *curItem = currentItem();
  QLineEdit *pageNameEdit = (QLineEdit*) itemWidget(curItem, 0);

  removeItemWidget(curItem, 0);
}

void CWidgetTree::keyPressEvent ( QKeyEvent * e )
{
  if (isNameChanging)
  {
    if(e->key() == Qt::Key_Escape)
    {
      QTreeWidgetItem *curItem = currentItem();
      removeItemWidget(curItem, 0);
      isNameChanging = 0;
      return;
    }
  }
}

void CWidgetTree::ShowContextMenu(QPoint pointIn)
{
  QTreeWidgetItem *curItem = currentItem();
  //curItem = curItem->parent()->takeChild(viewTree->currentIndex().row());
  int curIndex = currentIndex().row();

  // получаем глобальные координаты
  QPoint globalPos;
  // если запрос от QAbstractScrollArea
  if (sender()->inherits("QAbstractScrollArea"))
    globalPos = ((QAbstractScrollArea*)sender())->viewport()->mapToGlobal(pointIn);
  // если от других виджетов
  else
    globalPos = mapToGlobal(pointIn);

  int isNeedShowMenuSourse = 0;

  if (curItem == mainSourseItem)
  {  
    //if (curItem->childCount() == 0)
    {
      contTreeMenuSourse->actions()[0]->setVisible(true);
      contTreeMenuSourse->actions()[1]->setVisible(false);
      contTreeMenuSourse->actions()[2]->setVisible(false);
      contTreeMenuSourse->actions()[3]->setVisible(false);
      contTreeMenuSourse->actions()[4]->setVisible(false);
      contTreeMenuSourse->actions()[5]->setVisible(false);
      isNeedShowMenuSourse = 1;
    }
  }
  if (curItem->parent() != NULL)
  {
    if (curItem->parent() == mainSourseItem)
    { 
      contTreeMenuSourse->actions()[0]->setVisible(true);
      contTreeMenuSourse->actions()[1]->setVisible(true);
      contTreeMenuSourse->actions()[2]->setVisible(true);
      if (curItem->textColor(0) == Qt::red)
      {
        contTreeMenuSourse->actions()[3]->setVisible(false);
        contTreeMenuSourse->actions()[4]->setVisible(true);
      }
      else
      {
        contTreeMenuSourse->actions()[3]->setVisible(true);
        contTreeMenuSourse->actions()[4]->setVisible(false);
      }
      //contTreeMenuSourse->actions()[5]->setVisible(true);
      //contTreeMenuSourse->actions()[2]->setVisible(false);
      //contTreeMenuSourse->actions()[3]->setVisible(false);
      //contTreeMenuSourse->actions()[4]->setVisible(false);
      contTreeMenuSourse->actions()[5]->setVisible(false);

      isNeedShowMenuSourse = 1;
    }
  }

  int isNeedShowMenuMeteo = 0;

  if (curItem == mainMeteoItem)
  {  
    int i;
    for (i=0; i<curItem->childCount(); i++)
      if (curItem->child(i)->textColor(0) == Qt::red)
      {
        contTreeMenuMeteo->actions()[0]->setVisible(false);
        contTreeMenuMeteo->actions()[1]->setVisible(false);
        contTreeMenuMeteo->actions()[2]->setVisible(false);
        contTreeMenuMeteo->actions()[3]->setVisible(false);
        contTreeMenuMeteo->actions()[4]->setVisible(false);
        contTreeMenuMeteo->actions()[5]->setVisible(false);
        isNeedShowMenuMeteo = 1;
        break;
      }
    if (isNeedShowMenuMeteo == 0)
    {
      contTreeMenuMeteo->actions()[0]->setVisible(true);
      contTreeMenuMeteo->actions()[1]->setVisible(false);
      contTreeMenuMeteo->actions()[2]->setVisible(false);
      contTreeMenuMeteo->actions()[3]->setVisible(false);
      contTreeMenuMeteo->actions()[4]->setVisible(false);
      contTreeMenuMeteo->actions()[5]->setVisible(false);
      isNeedShowMenuMeteo = 1;
    }
  }
  if (curItem->parent() != NULL)
  {
    if (curItem->parent() == mainMeteoItem)
    { 
      int i;
      for (i=0; i<curItem->parent()->childCount(); i++)
        if (curItem->parent()->child(i)->textColor(0) == Qt::red)
        {
          contTreeMenuMeteo->actions()[0]->setVisible(false);
          contTreeMenuMeteo->actions()[1]->setVisible(false);
          contTreeMenuMeteo->actions()[2]->setVisible(false);
          if (curItem->textColor(0) == Qt::red)
          {
            contTreeMenuMeteo->actions()[3]->setVisible(false);
            contTreeMenuMeteo->actions()[4]->setVisible(true);
          }
          else
          {
            contTreeMenuMeteo->actions()[3]->setVisible(true);
            contTreeMenuMeteo->actions()[4]->setVisible(false);
          }
          contTreeMenuMeteo->actions()[5]->setVisible(true);
          isNeedShowMenuMeteo = 1;
          break;
        }
      if (isNeedShowMenuMeteo == 0)
      {
        contTreeMenuMeteo->actions()[0]->setVisible(true);
        contTreeMenuMeteo->actions()[1]->setVisible(true);
        contTreeMenuMeteo->actions()[2]->setVisible(true);
        if (curItem->textColor(0) == Qt::red)
        {
          contTreeMenuMeteo->actions()[3]->setVisible(false);
          contTreeMenuMeteo->actions()[4]->setVisible(true);
        }
        else
        {
          contTreeMenuMeteo->actions()[3]->setVisible(true);
          contTreeMenuMeteo->actions()[4]->setVisible(false);
        }
        contTreeMenuMeteo->actions()[5]->setVisible(true);

        isNeedShowMenuMeteo = 1;
      }
    }
  }

  if (isNeedShowMenuSourse)
    // отображаем меню и обрабатываем пользовательский выбор
    contTreeMenuSourse->popup(globalPos);

  if (isNeedShowMenuMeteo)
    // отображаем меню и обрабатываем пользовательский выбор
    contTreeMenuMeteo->popup(globalPos);
}

void CWidgetTree::OnItemRename()
{
  QTreeWidgetItem *curItem = currentItem();
  OnItemDoubleClicked(curItem, 0);
}

void CWidgetTree::OnCopySourseButton()
{
  QTreeWidgetItem *curItem = currentItem();

  if (curItem->parent() == NULL)
    return;

  if (curItem->parent() != mainSourseItem)
    return;

  int i;
  for (i=0; i<mainSourseItem->childCount(); i++)
  {
    if (mainSourseItem->child(i) == curItem)
      break;
  }

  emit copySourse(i);

  isLoadData = 1;
  OnAddSourseButton();
  isLoadData = 0;
}

void CWidgetTree::OnHideSourseButton()
{
  QTreeWidgetItem *curItem = currentItem();

  if (curItem->parent() == NULL)
    return;

  if (curItem->parent() != mainSourseItem)
    return;

  QFont font;

  UpdateSourceNames();

  //if (curItem->textColor(0) == Qt::red)
  //{
  //  curItem->setTextColor(0, Qt::black);
  //  font.setStrikeOut(false);
  //  curItem->setFont(0, font);
  //  ((CDialogPageSourseParams*)currentParam)->isEnable = 0;
  //}
  //else
  //{
  //  curItem->setTextColor(0, Qt::red);
  //  font.setStrikeOut(true);
  //  curItem->setFont(0, font);
  //  ((CDialogPageSourseParams*)currentParam)->isEnable = 1;
  //}

  int i;
  for (i=0; i<mainSourseItem->childCount(); i++)
  {
    if (mainSourseItem->child(i) == curItem)
      break;
  }
  emit hideSourse(i);
}


void CWidgetTree::OnAddMeteoButton()
{
  if (isNameChanging)
  {
    isNameChanging = 0;
    return;
  }

  if (isLoadData == 0)
    emit addMeteo();


  QTreeWidgetItem *item = new QTreeWidgetItem;

  // Диалог "Временной слой"

  UpdateMeteoNames();

  setCurrentItem(item);
}

void CWidgetTree::OnDelMeteoButton()
{
  update();
  QTreeWidgetItem *curItem = currentItem();

  if (curItem->parent() == NULL)
    return;

  if (curItem->parent() != mainMeteoItem)
    return;

  int curIndex = currentIndex().row();

  emit delMeteo(curIndex);

  curItem = mainMeteoItem->takeChild(curIndex);
  delete curItem;

  if (mainMeteoItem->childCount() == 0)
    setCurrentItem(mainMeteoItem);
  else
    setCurrentItem(mainMeteoItem->child(0));

  UpdateMeteoNames();
}


void CWidgetTree::OnAddSourseButton()
{
  if (isNameChanging)
  {
    isNameChanging = 0;
    return;
  }

  if (isLoadData == 0)
    emit addSourse();

  QTreeWidgetItem *item = new QTreeWidgetItem;

  // основной диалог источника
}

void CWidgetTree::OnDelSourseButton()
{
  update();
  QTreeWidgetItem *curItem = currentItem();

  if (curItem->parent() == NULL)
    return;

  if (curItem->parent() != mainSourseItem)
    return;

  int curIndex = currentIndex().row();

  curItem = mainSourseItem->takeChild(curIndex);
  delete curItem;

  if (mainSourseItem->childCount() == 0)
    setCurrentItem(mainSourseItem);
  else
    setCurrentItem(mainSourseItem->child(0));

  emit delSourse(curIndex);
}

int CWidgetTree::SetExpertMode(int isExpert)
{
  int i;
  for (i=0; i<expretPageCount; i++)
    expertPages[i]->setHidden(1-isExpert);

  return 0;
}

int CWidgetTree::GetSerialNum(QTreeWidgetItem *item)
{
  int i, j, k, l, count = 0;
  int isExit = 0;
  QTreeWidgetItem* item1, *item2, *item3;
  for(i=0; i < topLevelItemCount(); i++)
  {
    if (isExit == 1)
      break;

    item1 = topLevelItem(i);
    if (item1 == item)
    {
      isExit = 1;
      break;
    }
    count++;

    for (j=0; j<item1->childCount(); j++)
    {
      if (isExit == 1)
        break;

      item2 = item1->child(j);
      if (item2 == item)
      {
        isExit = 1;
        break;
      }
      count++;

      for (k=0; k<item2->childCount(); k++)
      {
        if (isExit == 1)
          break;

        item3 = item2->child(k);
        if (item3 == item)
        {
          isExit = 1;
          break;
        }
        count++;

        for (l=0; l<item3->childCount(); l++)
        {
          if (isExit == 1)
            break;

          if (item3->child(l) == item)
          {
            isExit = 1;
            break;
          }
          count++;
        }
      }
    }
  }

  return count;
}

void CWidgetTree::ChangePage(QTreeWidgetItem *current, QTreeWidgetItem *previous)
{
  if (!current)
    current = previous;

  //int i, j, k, count = 0;
  //int isExit = 0;

  QWidget *prevWidget = itemWidget(previous, 0);
  if (prevWidget != NULL)
  {
    //QString str = prevWidget->whatsThis();
    if (prevWidget->whatsThis() == "Название")
      removeItemWidget(previous, 0);
  }

  emit itemTreeChanged(GetSerialNum(current));

}


int CWidgetTree::UpdateTree()
{
  isLoadData = 1;
  int i, count = mainSourseItem->childCount();

  UpdateMeteoNames();

  isLoadData = 0;

  setCurrentItem(mainMeteoItem);
  return 0;
}

int CWidgetTree::SetEnableSourse(int isEnable)
{
  QTreeWidgetItem *curItem = currentItem();

  QFont font;

  return 0;
}

int CWidgetTree::UpdateMeteoNames()
{
  int i;
  return 0;
}

int CWidgetTree::UpdateSourceNames()
{
  int i;
  return 0;
}

int CWidgetTree::SetMainSourceCurr()
{
  setCurrentItem(mainSourseItem);
  return 0;
}

void CWidgetTree::OnCopyMeteoButton()
{
  QTreeWidgetItem *curItem = currentItem();

  if (curItem->parent() == NULL)
    return;

  if (curItem->parent() != mainMeteoItem)
    return;

  int i;
  for (i=0; i<mainMeteoItem->childCount(); i++)
  {
    if (mainMeteoItem->child(i) == curItem)
      break;
  }

  emit copyMeteo(i);

  //UpdateTree();

  setCurrentItem(mainMeteoItem->child(i));
}

void CWidgetTree::OnHideMeteoButton()
{
  QTreeWidgetItem *curItem = currentItem();

  if (curItem->parent() == NULL)
    return;

  if (curItem->parent() != mainMeteoItem)
    return;

  QFont font;

  UpdateMeteoNames();
}