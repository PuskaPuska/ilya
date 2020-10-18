//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
// �������� ������: DialogPageSphere
//
// ��������: �������� �������� �������� ������� ���������� �������� �����
//
// �����: ������� ��������
//
// ���� ��������: 03.07.2020
//
// ���� ���������� ���������: 03.07.2020
//------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////


#include <QtGui>

#include "DialogPageSphere.h"
#include "SphereElemParams.h"

CDialogPageSphere::CDialogPageSphere(QWidget *parent)
  : CDialogBasePage(parent)
{
  SetPageName("�� ������", "�� ������");

  CreateDialogElems();
}

CDialogPageSphere::~CDialogPageSphere()
{
}

int CDialogPageSphere::CreateDialogElems()
{
  QLabel *minLabel = new QLabel("�����:");
  QHBoxLayout *minCoorHLayout = new QHBoxLayout;
  for (int i=0; i<3; i++)
  {
    cenP[i] = new CLineEdit(tr("0"));
    minCoorHLayout->addWidget(cenP[i]);
  }
  cenP[0]->SetName(tr("x"));
  cenP[1]->SetName(tr("y"));
  cenP[2]->SetName(tr("z"));

  QLabel *radLabel = new QLabel("������:");
  rad = new CLineEdit(tr("0.5"));
  rad->SetName(tr("������"));


  setParams = new QPushButton(tr("���������"));
  connect(setParams, SIGNAL(clicked()), this, SLOT(OnSetParamsButton()));

  QVBoxLayout *allVLayout = new QVBoxLayout;
  allVLayout->addWidget(minLabel);
  allVLayout->addLayout(minCoorHLayout);
  allVLayout->addWidget(radLabel);
  allVLayout->addWidget(rad);
  allVLayout->setAlignment(Qt::AlignCenter);
  allVLayout->addWidget(setParams);

  delete baseLayout;
  delete nullLabel;
  setLayout(allVLayout);
  return 0;
}

void CDialogPageSphere::OnSetParamsButton()
{
  CSphereElemParams params;
  for (int i = 0; i < 3; i++)
  {
    if (!cenP[i]->IsCorrect())
      return;
    params.center[i] = cenP[i]->text().toDouble();
  }
  params.radius = rad->text().toDouble();
  curElem->ChangeParams(params);
}