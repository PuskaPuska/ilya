//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
// �������� ������: RegElemCreator
//
// ��������: �������� ���������� ������ �������� ���������
//
// �����: ������� ��������
//
// ���� ��������: 18.05.2020
//
// ���� ���������� ���������: 18.05.2020
//------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////

#include "RegElemCreator.h"
#include "DrawRegMeshElem.h"
#include "DialogPageRegMesh.h"
#include "Storage.h"

CRegElemCreator *CRegElemCreator::startPtr = new CRegElemCreator(true);

CRegElemCreator::CRegElemCreator(bool flag)
{
  CStorage *storage = &CStorage::instance();
  sprintf(elemName, "���������� �����");
  storage->SetMainElemName(elemName, "RegElem");
  int id = storage->factory.add<CRegElemCreator>("RegElem");
  storage->staticPtrs.push_back(this);
}

CRegElemCreator::CRegElemCreator() : CBaseElemCreator()
{
  drawElem = new CDrawRegMeshElem();
  //drawElem->SetElemName(elemName);
}

CRegElemCreator::~CRegElemCreator()
{
}

int CRegElemCreator::CreateDialogPage(QWidget *w)
{
  dialogPage = new CDialogPageRegMesh(w);
  dialogPage->SetCurElem(drawElem);
  return 0;
}