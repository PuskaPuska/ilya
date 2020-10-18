//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
// �������� ������: DialogAddSourse
//
// ��������: �������� �������� ���������������� ������� ���������� ������ ���������
//
// �����: ������� ��������
//
// ���� ��������: 17.05.2014
//
// ���� ���������� ���������: 31.08.2014
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

  QLabel *typeSourseLabel = new QLabel(tr("��� ����� �����:"));
  typeSourserCombo = new QComboBox;
  for (int i = 0; i < storage->mainElemNames.size(); i++)
    typeSourserCombo->addItem(tr(storage->mainElemNames[i].c_str()));
  //typeSourserCombo->addItem(tr("������������"));
  //typeSourserCombo->addItem(tr("������������� ���������������� �����"));
  //typeSourserCombo->addItem(tr("������������� ������������� �����"));

  QPushButton *okButton = new QPushButton(tr("��"));
  QPushButton *canselButton = new QPushButton(tr("������"));
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

  setWindowTitle(tr("����� ��� �����"));

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