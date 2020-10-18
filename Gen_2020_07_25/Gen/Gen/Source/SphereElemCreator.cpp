//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
// �������� ������: SphereElemCreator
//
// ��������: �������� ���������� ������ �������� �������� �����
//
// �����: ������� ��������
//
// ���� ��������: 03.07.2020
//
// ���� ���������� ���������: 03.07.2020
//------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////

#include "SphereElemCreator.h"
#include "DrawSphereElem.h"
#include "DialogPageSphere.h"
#include "Storage.h"

CSphereElemCreator *CSphereElemCreator::startPtr = new CSphereElemCreator(true);

CSphereElemCreator::CSphereElemCreator(bool flag)
{
  CStorage *storage = &CStorage::instance();
  sprintf(elemName, "�����");
  storage->SetDopElemName(elemName, "Sphere");
  int id = storage->factory.add<CSphereElemCreator>("Sphere");
  storage->staticPtrs.push_back(this);
}

CSphereElemCreator::CSphereElemCreator() : CBaseElemCreator()
{
  drawElem = new CDrawSphereElem();
  //drawElem->SetElemName(elemName);
}

CSphereElemCreator::~CSphereElemCreator()
{
}

int CSphereElemCreator::CreateDialogPage(QWidget *w)
{
  dialogPage = new CDialogPageSphere(w);
  dialogPage->SetCurElem(drawElem);
  return 0;
}