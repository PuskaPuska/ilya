//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
// Название модуля: DialogAddSourse
//
// Описание: содержит описание вспомогательного диалога добавления нового источника
//
// Автор: Никитин Вячеслав
//
// Дата создания: 17.05.2014
//
// Дата последнего изменения: 31.08.2014
//------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////

#include <QtGui>
#include "DialogAddNewMesh.h"
#include "Storage.h"

CDialogAddNewMesh::CDialogAddNewMesh(QWidget *parent)
  : CDialogBaseAux(parent)
{
  CreateDialogElems();
}

CDialogAddNewMesh::~CDialogAddNewMesh()
{
}

int CDialogAddNewMesh::CreateDialogElems()
{
  CStorage *storage = &CStorage::instance();

  QLabel *typeSourseLabel = new QLabel(tr("Тип новой сетки:"));
  typeSourserCombo = new QComboBox;
  for (int i = 0; i < storage->mainElemNames.size(); i++)
    typeSourserCombo->addItem(tr(storage->mainElemNames[i].c_str()));
  //typeSourserCombo->addItem(tr("Нерегулярная"));
  //typeSourserCombo->addItem(tr("Поверхностная триангуляционная сетка"));
  //typeSourserCombo->addItem(tr("Поверхностная многоугольная сетка"));

  QPushButton *okButton = new QPushButton(tr("ОК"));
  QPushButton *canselButton = new QPushButton(tr("Отмена"));
  connect(okButton, SIGNAL(clicked()), this, SLOT(OnOkButton()));
  connect(canselButton, SIGNAL(clicked()), this, SLOT(close()));

  QHBoxLayout *buttonHLayout = new QHBoxLayout;
  buttonHLayout->addStretch(1);
  buttonHLayout->addWidget(okButton);
  buttonHLayout->addWidget(canselButton);

  QVBoxLayout *mainVLayout = new QVBoxLayout;
  mainVLayout->addWidget(typeSourseLabel);
  mainVLayout->addWidget(typeSourserCombo);
  mainVLayout->addLayout(buttonHLayout);

  setLayout(mainVLayout);

  setWindowTitle(tr("Выбор тип сетки"));

  return 0;
}

int CDialogAddNewMesh::SetParams(double *paramsIn)
{
  if (paramsIn == NULL)
    return -1;

  params = paramsIn;

  return 0;
}

void CDialogAddNewMesh::OnOkButton()
{
  if (params == NULL)
    return;

  *params = typeSourserCombo->currentIndex();

  accept();
}