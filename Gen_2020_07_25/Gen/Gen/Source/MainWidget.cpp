//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
// Название модуля: MainWidget
//
// Описание: содержит описание главного диалога задания параметров расчета
//
// Автор: Никитин Вячеслав
//
// Дата создания: 17.04.2014
//
// Дата последнего изменения: 17.11.2014
//------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////

#include <QtGui>

#include "MainWidget.h"

CMainWidget::CMainWidget(QWidget *parent)
  : QWidget(parent)
{
  // инициализация параметров

  stopButton = new QPushButton(tr("Стоп"));
  runButton = new QPushButton(tr("Рассчитать"));
  QPushButton *contButton = new QPushButton(tr("Продолжить"));
  progressBar = new QProgressBar(this);
  progressBar->setMinimumSize(400, progressBar->height());

  stopButton->setEnabled(false);

  connect(stopButton, SIGNAL(clicked()), this, SLOT(OnStopBuatton()));
  connect(runButton, SIGNAL(clicked()), this, SLOT(OnRunButton()));
  connect(contButton, SIGNAL(clicked()), this, SLOT(OnContButton()));

  
  //viewTree->setContextMenuPolicy(Qt::CustomContextMenu);

  //// ждем сигнала для отображения меню
  //connect(viewTree, SIGNAL(customContextMenuRequested(QPoint)),
  //  this, SLOT(ShowContextMenu(QPoint)));

  //CreateTree();
  //viewTree->setCurrentIndex(0);

  newViewTree = new CWidgetTree(this);
  newSceneWidget = new CScene3D(this);

  connect(newViewTree, SIGNAL(itemTreeChanged ( int )), this, SLOT(OnItemTreeChange ( int )));
  connect(newViewTree, SIGNAL(copySourse (int)), this, SLOT(OnCopySourseButton (int)));
  connect(newViewTree, SIGNAL(addSourse ()), this, SLOT(OnAddSourseButton ()));
  connect(newViewTree, SIGNAL(addMeteo ()), this, SLOT(OnAddMeteoButton ()));
  connect(newViewTree, SIGNAL(delSourse (int)), this, SLOT(OnDelSourseButton (int)));
  connect(newViewTree, SIGNAL(delMeteo (int)), this, SLOT(OnDelMeteoButton (int)));
  connect(newViewTree, SIGNAL(copyMeteo (int)), this, SLOT(OnCopyMeteoButton (int)));
  //connect(newPagesWidget, SIGNAL(updateMeteo ()), this, SLOT(OnUpdateMeteo ()));
  //connect(newPagesWidget, SIGNAL(updateName ()), this, SLOT(OnUpdateNeme ()));
  //connect(newPagesWidget, SIGNAL(updateSource ()), this, SLOT(OnUpdateSource ()));

  QHBoxLayout *horizontalLayout = new QHBoxLayout;
  //horizontalLayout->addWidget(contentsWidget);
  horizontalLayout->addWidget(newViewTree);
  //horizontalLayout->addWidget(pagesWidget);
  horizontalLayout->addWidget(newSceneWidget);

  QHBoxLayout *buttonsLayout = new QHBoxLayout;
  buttonsLayout->addStretch(1);
  buttonsLayout->addWidget(runButton);
  buttonsLayout->addWidget(progressBar);
  buttonsLayout->addWidget(stopButton);
  //buttonsLayout->addWidget(contButton);

  //QLabel *numTracLabel = new QLabel(tr("Число траекторий:"));
  //numTracEdit = new CLineEdit(tr("10000"));

  //QLabel *typeSourseLabel = new QLabel(tr("Тип источника выброса:"));
  //typeSourserCombo = new QComboBox;
  //typeSourserCombo->addItem(tr("Взрывной выброс"));
  //typeSourserCombo->addItem(tr("Струйный выброс"));
  //typeSourserCombo->addItem(tr("Общий источник"));
  //connect(typeSourserCombo, SIGNAL(currentIndexChanged ( int )), this, SLOT(ChangeTypeSourse( int )));

  //QHBoxLayout *packagesLayout = new QHBoxLayout;
  ////packagesLayout->addWidget(typeSourseLabel, 0, 0);
  ////packagesLayout->addWidget(typeSourserCombo, 0, 1);
  //packagesLayout->addStretch(1);
  //packagesLayout->addWidget(numTracLabel);
  //packagesLayout->addWidget(numTracEdit);

  /*QGroupBox *packagesGroup = new QGroupBox(tr("Look for packages"));
  packagesGroup->setLayout(packagesLayout);*/

  QVBoxLayout *mainLayout = new QVBoxLayout;
  //mainLayout->addWidget(packagesGroup);
  //mainLayout->addLayout(packagesLayout);
  mainLayout->addLayout(horizontalLayout);
  //mainLayout->addWidget(expertCB);
  //mainLayout->addStretch(1);
  //mainLayout->addSpacing(12);
  mainLayout->addLayout(buttonsLayout);
  setLayout(mainLayout);

  setWindowTitle(tr("Задание параметров расчета"));

  //CreateContMenu();

  //setWindowType
  //Qt::WindowType = Qt::SubWindow;

  //isNameChanging = 0;
}

CMainWidget::~CMainWidget()
{
  //CCalcParams *calcParams = &CCalcParams::instance();
  //calcParams->SaveToolTipsToFile();
}

void CMainWidget::OnRunButton()
{
}

void CMainWidget::OnStopBuatton()
{
  setCursor(Qt::WaitCursor);
}

// функция проверки введенного числа на отсутсвие недопустимых символов
int CMainWidget::CheckStringIn(QString str, QString name)
{
  //if (!CheckString(str.toStdString().c_str(), str.count()))
  {
    char messag[512] = "Ошибка";
    //sprintf(messag, "Параметр '%s' введен не правильно!", name.toStdString().c_str());

    QMessageBox* pmbx =
      new QMessageBox(tr("Ошибка ввода данных"),
      tr(messag),
      QMessageBox::Critical,
      NULL,
      NULL,
      QMessageBox::Cancel | QMessageBox::Escape);
    int n = pmbx->exec(); 
    delete pmbx; 

    return -1;
  }

  return 0;
}

void CMainWidget::OnAddSourseButton()
{
  double newSourse;
}

void CMainWidget::OnDelSourseButton(int pos)
{
}

void CMainWidget::OnCopySourseButton(int pos)
{

}

void CMainWidget::OnCopyMeteoButton(int pos)
{

  UpdateDialog();
}

void CMainWidget::OnAddMeteoButton()
{
}

void CMainWidget::OnDelMeteoButton(int pos)
{
}

void CMainWidget::OnItemTreeChange(int numItem)
{
  int i = numItem;
}

int CMainWidget::UpdateDialog()
{
  //if (newSceneWidget->UpdatePages() < 0)
  //  return -1;

  if (newViewTree->UpdateTree() < 0)
    return -1;
  
  return 0;
}

void CMainWidget::OnStopedCalc()
{
  endButtonClicked();
}

void CMainWidget::OnSetCurPos(int curPos)
{
  progressBar->setValue(curPos);
}

// установить настройки по умолчанию
int CMainWidget::SetByDefault()
{
  UpdateDialog();

  return 0;
}

void CMainWidget::OnUpdateMeteo()
{
  UpdateDialog();
}

void CMainWidget::OnUpdateNeme()
{
}

void CMainWidget::OnUpdateSource()
{
  UpdateDialog();
  newViewTree->SetMainSourceCurr();
}