//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
// �������� ������: BaseElemCreator
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

#ifndef BASEELEMCREATOR_H
#define BASEELEMCREATOR_H

#include "BaseDrawElem.h"
#include "DialogBasePage.h"

class CBaseElemCreator
{
public:
  CBaseElemCreator();
  ~CBaseElemCreator();

  CBaseDrawElem *GetElem();
  CDialogBasePage *GetDialog(QWidget *w);

protected:
  CBaseDrawElem *drawElem;
  CDialogBasePage *dialogPage;
  char elemName[256];

  virtual int CreateDialogPage(QWidget *w);
};

#endif