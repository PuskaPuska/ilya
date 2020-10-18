#include "gen.h"
#include <QFileDialog>
#include "Scene3D.h"
#include <QtGui>      // подключаем модуль QtGui
#include "DialogAddNewMesh.h"
#include "Storage.h"
#include "BaseElemCreator.h"

Gen::Gen(QWidget *parent, Qt::WFlags flags)
    : QMainWindow(parent, flags)
{
  ui.setupUi(this);
  resize(1000, 700);
  // создаем главное меню
  CreateMenuBar();

  //CMainWidget *mainWidget = new CMainWidget(this);
  //setCentralWidget(mainWidget);


  QSplitter *horizontalSplitter = new QSplitter(Qt::Horizontal, this);
  setCentralWidget(horizontalSplitter);

  QSplitter *verticalSplitter2 = new QSplitter(Qt::Vertical, horizontalSplitter);
  viewTree = new CWidgetTree(verticalSplitter2);
  pagesWidget = new CPagesWidget(verticalSplitter2);

  QSplitter *verticalSplitter = new QSplitter(Qt::Vertical, horizontalSplitter);
  CScene3D *newSceneWidget = new CScene3D(verticalSplitter);
  //messagesListView = new QListView(verticalSplitter); 
  //messagesListView->addColumn(tr("Subject")); 
  //messagesListView->addColumn(tr("Sender")); 
  //messagesListView->addColumn(tr("Date")); 
  //messagesListView->setAllColumnsShowFocus(true); 
  //messagesListView->setShowSortIndicator(true); 
  //messagesListView->setResizeMode(QListView::AllColumns); 

  QTextEdit* textEdit = new QTextEdit(verticalSplitter); 
  textEdit->setReadOnly(true); 

  //horizontalSplitter->setResizeMode(newViewTree, 
  //  QSplitter::KeepSize); 
  //verticalSplitter->setResizeMode(newSceneWidget, 
  //  QSplitter::KeepSize); 

  newSceneWidget->resize(700, 600);

  connect(viewTree, SIGNAL(itemTreeChanged ( int )), this, SLOT(OnItemTreeChange ( int )));

  setWindowTitle(tr("Mesh generator"));
}

Gen::~Gen()
{

}

// сигнал из меню - Новый расчет
void Gen::NewCalc()
{
  CStorage *storage = &CStorage::instance();
  double typeNewMesh;
  CDialogAddNewMesh *dlg = new CDialogAddNewMesh(this);
  dlg->SetParams(&typeNewMesh);
  if (dlg->exec())
  {
    int tNewMesh = (typeNewMesh + 0.1);
    CBaseElemCreator *bCreator = storage->CreateNewMainElem(tNewMesh);
    pagesWidget->addWidget(bCreator->GetDialog(pagesWidget));
    //pagesWidget->setCurrentIndex(1);
    //storage->elemContainer.push_back(bCreator->GetElem());
    //storage->elemContainer[storage->elemContainer.size() - 1]->SetElemName(storage->mainElemNames[tNewMesh].c_str());
    viewTree->AddNewItem(storage->elemContainer.size() -  1);
  }
  //if (dialogParams->SetByDefault() < 0)
  //  return;
}

// сигнал из меню - Загрузить расчет
void Gen::LoadCalc()
{
  QString strFilter;
  QString strOfFilter(tr("Файл расчета *.stl ;; Все файлы *.*"));
  QString strOfNameD(tr("Открытие файла с поверхностной сеткой"));
  QString str = QFileDialog::getOpenFileName(this, strOfNameD, "", strOfFilter, &strFilter);

  CStorage *storage = &CStorage::instance();
  CBaseElemCreator *bCreator = storage->CreateNewMainElem("Surf");
  pagesWidget->addWidget(bCreator->GetDialog(pagesWidget));
  viewTree->AddNewItem(storage->elemContainer.size() -  1);
  storage->elemContainer[storage->elemContainer.size() - 1]->ReadDataFromFile(str);
  //widResualt->open(str);
  //storData->LoadDataFCI(str.toStdString().c_str());
}

// сигнал из меню - Загрузить параметры
void Gen::LoadParams()
{
  //if (dialogParams->UpdateParams(false) < 0)
  //  return;

  QString strFilter;
  QString strOfFilter(tr("Файл расчета *.stl ;; Все файлы *.*"));
  QString strOfNameD(tr("Открытие файла постановки"));
  QString str = QFileDialog::getOpenFileName(this, strOfNameD, "", strOfFilter, &strFilter);

  //calcParams->LoadFromFile(str.toStdString().c_str());

  //if (dialogParams->UpdateDialog() < 0)
  //  return;
}

// сигнал из меню - Сохранить расчет
void Gen::SaveCalc()
{
  QString strFilter;
  QString strOfFilter(tr("Файл расчета *.fci ;; Изображение *.bmp"));
  QString strOfNameD(tr("Сохранение результатов"));
  QString str = QFileDialog::getSaveFileName(this, strOfNameD, "", strOfFilter, &strFilter);

  //storData->SaveDataFCI(str.toStdString().c_str());
}

// сигнал из меню - Сохранить параметры
void Gen::SaveParams()
{
  //if (dialogParams->UpdateParams(false) < 0)
  //  return;

  QString strFilter;
  QString strOfFilter(tr("Постановка *.pst"));
  QString strOfNameD(tr("Сохранение постановки задачи"));
  QString str = QFileDialog::getSaveFileName(this, strOfNameD, "", strOfFilter, &strFilter);

  //calcParams->SaveToFile(str.toStdString().c_str());
}

// функция создания меню
void Gen::CreateMenuBar()
{
  //char buff[512];

  QMenu *mainMenu = menuBar()->addMenu(tr("&Файл"));

  menuNewMesh = new QAction(tr("&Новая сетка"), this);
  menuNewMesh->setStatusTip(tr("Создать новую сетку"));
  connect(menuNewMesh, SIGNAL(triggered()), this, SLOT(NewCalc()));
  mainMenu->addAction(menuNewMesh);

  mainMenu->addSeparator();

  menuLoadCalc = new QAction(tr("Загрузить п&оверхностную сетку"), this);
  menuLoadCalc->setStatusTip(tr("Загрузить поверхностную сетку из файла"));
  connect(menuLoadCalc, SIGNAL(triggered()), this, SLOT(LoadCalc()));
  mainMenu->addAction(menuLoadCalc);

  menuLoadParams = new QAction(tr("Загрузить &параметры расчета"), this);
  menuLoadParams->setStatusTip(tr("Загрузить из файла ранее сохраненные параметры расчета"));
  connect(menuLoadParams, SIGNAL(triggered()), this, SLOT(LoadParams()));
  mainMenu->addAction(menuLoadParams);

  mainMenu->addSeparator();

  menuSaveCalc = new QAction(tr("Сохранить поверхностную сетку"), this);
  menuSaveCalc->setStatusTip(tr("Сохранить поверхностную сетку в файл"));
  connect(menuSaveCalc, SIGNAL(triggered()), this, SLOT(SaveCalc()));
  mainMenu->addAction(menuSaveCalc);

  menuSaveParams = new QAction(tr("Сохранить параметры расчета"), this);
  menuSaveParams->setStatusTip(tr("Сохранить в файл текущие настройки параметров расчета"));
  connect(menuSaveParams, SIGNAL(triggered()), this, SLOT(SaveParams()));
  mainMenu->addAction(menuSaveParams);

  mainMenu->addSeparator();

  menuClose = new QAction(tr("Закрыть"), this);
  menuClose->setStatusTip(tr("Выход из программы"));
  connect(menuClose, SIGNAL(triggered()), this, SLOT(close()));
  mainMenu->addAction(menuClose);

  mainMenu = menuBar()->addMenu(tr("&Результат"));

  //menuShowHist = new QAction(tr("Построить график"), this);
  //menuShowHist->setStatusTip(tr("Построение графика по рассчитанным данным"));
  //connect(menuShowHist, SIGNAL(triggered()), this, SLOT(ShowHist()));
  //mainMenu->addAction(menuShowHist);

  //menuShowRes = new QAction(tr("Отобразить результат"), this);
  //menuShowRes->setStatusTip(tr("Вывод результатов расчета в графическом виде"));
  //connect(menuShowRes, SIGNAL(triggered()), this, SLOT(ShowRes()));
  //mainMenu->addAction(menuShowRes);
  //menuShowRes->setEnabled(false);

  //mainMenu = menuBar()->addMenu(tr("На карту"));

  //menuInsMapX = new QAction(tr("Нанести на карту MapX"), this);
  //menuInsMapX->setStatusTip(tr("Нанести полученные данные на карту ГИС системы MapX"));
  //connect(menuInsMapX, SIGNAL(triggered()), this, SLOT(InsMapX()));
  //mainMenu->addAction(menuInsMapX);

  //menuInsImg = new QAction(tr("Нанести на изображение карты"), this);
  //menuInsImg->setStatusTip(tr("Нанести полученные данные на загруженное из файла изображение карты"));
  //connect(menuInsImg, SIGNAL(triggered()), this, SLOT(InsImg()));
  //mainMenu->addAction(menuInsImg);
}

void Gen::OnItemTreeChange(int numItem)
{
  int i = numItem;
  pagesWidget->SetCurWidget(i);
}
