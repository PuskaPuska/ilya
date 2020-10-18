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

#ifndef SPHEREELEMCREATOR_H
#define SPHEREELEMCREATOR_H

#include "BaseElemCreator.h"

class CSphereElemCreator : public CBaseElemCreator
{
public:
  CSphereElemCreator();
  CSphereElemCreator(const bool flag);
  ~CSphereElemCreator();

private:
  static CSphereElemCreator *startPtr;

protected:
  virtual int CreateDialogPage(QWidget *w);
};

#endif