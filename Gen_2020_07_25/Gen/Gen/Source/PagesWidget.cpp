//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
// �������� ������: PagesWidget
//
// ��������: �������� �������� �������� ������� ������� ���������� �������
//
// �����: ������� ��������
//
// ���� ��������: 17.04.2014
//
// ���� ���������� ���������: 17.11.2014
//------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////

#include <QtGui>

#include "PagesWidget.h"
#include "DialogPageRegMesh.h"

CPagesWidget::CPagesWidget(QWidget *parent)
  : QStackedWidget(parent)
{

  CDialogBasePage *currentDialog = new CDialogBasePage;
  addWidget(currentDialog);

  //CDialogPageRegMesh *dlg = new CDialogPageRegMesh;
  //addWidget(dlg);
  //setCurrentIndex(1);
}

CPagesWidget::~CPagesWidget()
{
}

void CPagesWidget::SetCurWidget(const int &pos)
{
  setCurrentIndex(pos+1);
}