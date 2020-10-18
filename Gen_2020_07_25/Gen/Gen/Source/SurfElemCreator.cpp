//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
// �������� ������: SurfElemCreator
//
// ��������: �������� ���������� ������ �������� �������� �����������
//
// �����: ������� ��������
//
// ���� ��������: 23.07.2020
//
// ���� ���������� ���������: 23.07.2020
//------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////

#include "SurfElemCreator.h"
#include "DrawSurfElem.h"
#include "DialogPageSurf.h"
#include "Storage.h"

CSurfElemCreator *CSurfElemCreator::startPtr = new CSurfElemCreator(true);

CSurfElemCreator::CSurfElemCreator(bool flag)
{
  CStorage *storage = &CStorage::instance();
  sprintf(elemName, "������������� �����");
  storage->SetMainElemName(elemName, "Surf");
  int id = storage->factory.add<CSurfElemCreator>("Surf");
  storage->staticPtrs.push_back(this);
}

CSurfElemCreator::CSurfElemCreator() : CBaseElemCreator()
{
 // drawElem = new CDrawSurfElem();
  //drawElem->SetElemName(elemName);
}

CSurfElemCreator::~CSurfElemCreator()
{
}

int CSurfElemCreator::CreateDialogPage(QWidget *w)
{
  dialogPage = new CDialogPageSurf(w);
  dialogPage->SetCurElem(drawElem);
  return 0;
}