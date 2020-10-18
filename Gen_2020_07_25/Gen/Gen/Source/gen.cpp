#include "gen.h"
#include <QFileDialog>
#include "Scene3D.h"
#include <QtGui>      // ���������� ������ QtGui
#include "DialogAddNewMesh.h"
#include "Storage.h"
#include "BaseElemCreator.h"

Gen::Gen(QWidget *parent, Qt::WFlags flags)
    : QMainWindow(parent, flags)
{
  ui.setupUi(this);
  resize(1000, 700);
  // ������� ������� ����
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

// ������ �� ���� - ����� ������
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

// ������ �� ���� - ��������� ������
void Gen::LoadCalc()
{
  QString strFilter;
  QString strOfFilter(tr("���� ������� *.stl ;; ��� ����� *.*"));
  QString strOfNameD(tr("�������� ����� � ������������� ������"));
  QString str = QFileDialog::getOpenFileName(this, strOfNameD, "", strOfFilter, &strFilter);

  CStorage *storage = &CStorage::instance();
  CBaseElemCreator *bCreator = storage->CreateNewMainElem("Surf");
  pagesWidget->addWidget(bCreator->GetDialog(pagesWidget));
  viewTree->AddNewItem(storage->elemContainer.size() -  1);
  storage->elemContainer[storage->elemContainer.size() - 1]->ReadDataFromFile(str);
  //widResualt->open(str);
  //storData->LoadDataFCI(str.toStdString().c_str());
}

// ������ �� ���� - ��������� ���������
void Gen::LoadParams()
{
  //if (dialogParams->UpdateParams(false) < 0)
  //  return;

  QString strFilter;
  QString strOfFilter(tr("���� ������� *.stl ;; ��� ����� *.*"));
  QString strOfNameD(tr("�������� ����� ����������"));
  QString str = QFileDialog::getOpenFileName(this, strOfNameD, "", strOfFilter, &strFilter);

  //calcParams->LoadFromFile(str.toStdString().c_str());

  //if (dialogParams->UpdateDialog() < 0)
  //  return;
}

// ������ �� ���� - ��������� ������
void Gen::SaveCalc()
{
  QString strFilter;
  QString strOfFilter(tr("���� ������� *.fci ;; ����������� *.bmp"));
  QString strOfNameD(tr("���������� �����������"));
  QString str = QFileDialog::getSaveFileName(this, strOfNameD, "", strOfFilter, &strFilter);

  //storData->SaveDataFCI(str.toStdString().c_str());
}

// ������ �� ���� - ��������� ���������
void Gen::SaveParams()
{
  //if (dialogParams->UpdateParams(false) < 0)
  //  return;

  QString strFilter;
  QString strOfFilter(tr("���������� *.pst"));
  QString strOfNameD(tr("���������� ���������� ������"));
  QString str = QFileDialog::getSaveFileName(this, strOfNameD, "", strOfFilter, &strFilter);

  //calcParams->SaveToFile(str.toStdString().c_str());
}

// ������� �������� ����
void Gen::CreateMenuBar()
{
  //char buff[512];

  QMenu *mainMenu = menuBar()->addMenu(tr("&����"));

  menuNewMesh = new QAction(tr("&����� �����"), this);
  menuNewMesh->setStatusTip(tr("������� ����� �����"));
  connect(menuNewMesh, SIGNAL(triggered()), this, SLOT(NewCalc()));
  mainMenu->addAction(menuNewMesh);

  mainMenu->addSeparator();

  menuLoadCalc = new QAction(tr("��������� �&������������ �����"), this);
  menuLoadCalc->setStatusTip(tr("��������� ������������� ����� �� �����"));
  connect(menuLoadCalc, SIGNAL(triggered()), this, SLOT(LoadCalc()));
  mainMenu->addAction(menuLoadCalc);

  menuLoadParams = new QAction(tr("��������� &��������� �������"), this);
  menuLoadParams->setStatusTip(tr("��������� �� ����� ����� ����������� ��������� �������"));
  connect(menuLoadParams, SIGNAL(triggered()), this, SLOT(LoadParams()));
  mainMenu->addAction(menuLoadParams);

  mainMenu->addSeparator();

  menuSaveCalc = new QAction(tr("��������� ������������� �����"), this);
  menuSaveCalc->setStatusTip(tr("��������� ������������� ����� � ����"));
  connect(menuSaveCalc, SIGNAL(triggered()), this, SLOT(SaveCalc()));
  mainMenu->addAction(menuSaveCalc);

  menuSaveParams = new QAction(tr("��������� ��������� �������"), this);
  menuSaveParams->setStatusTip(tr("��������� � ���� ������� ��������� ���������� �������"));
  connect(menuSaveParams, SIGNAL(triggered()), this, SLOT(SaveParams()));
  mainMenu->addAction(menuSaveParams);

  mainMenu->addSeparator();

  menuClose = new QAction(tr("�������"), this);
  menuClose->setStatusTip(tr("����� �� ���������"));
  connect(menuClose, SIGNAL(triggered()), this, SLOT(close()));
  mainMenu->addAction(menuClose);

  mainMenu = menuBar()->addMenu(tr("&���������"));

  //menuShowHist = new QAction(tr("��������� ������"), this);
  //menuShowHist->setStatusTip(tr("���������� ������� �� ������������ ������"));
  //connect(menuShowHist, SIGNAL(triggered()), this, SLOT(ShowHist()));
  //mainMenu->addAction(menuShowHist);

  //menuShowRes = new QAction(tr("���������� ���������"), this);
  //menuShowRes->setStatusTip(tr("����� ����������� ������� � ����������� ����"));
  //connect(menuShowRes, SIGNAL(triggered()), this, SLOT(ShowRes()));
  //mainMenu->addAction(menuShowRes);
  //menuShowRes->setEnabled(false);

  //mainMenu = menuBar()->addMenu(tr("�� �����"));

  //menuInsMapX = new QAction(tr("������� �� ����� MapX"), this);
  //menuInsMapX->setStatusTip(tr("������� ���������� ������ �� ����� ��� ������� MapX"));
  //connect(menuInsMapX, SIGNAL(triggered()), this, SLOT(InsMapX()));
  //mainMenu->addAction(menuInsMapX);

  //menuInsImg = new QAction(tr("������� �� ����������� �����"), this);
  //menuInsImg->setStatusTip(tr("������� ���������� ������ �� ����������� �� ����� ����������� �����"));
  //connect(menuInsImg, SIGNAL(triggered()), this, SLOT(InsImg()));
  //mainMenu->addAction(menuInsImg);
}

void Gen::OnItemTreeChange(int numItem)
{
  int i = numItem;
  pagesWidget->SetCurWidget(i);
}
