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

#ifndef REGELEMCREATOR_H
#define REGELEMCREATOR_H

#include "BaseElemCreator.h"

class CRegElemCreator : public CBaseElemCreator
{
public:
  CRegElemCreator();
  CRegElemCreator(const bool flag);
  ~CRegElemCreator();

private:
  static CRegElemCreator *startPtr;

protected:
  virtual int CreateDialogPage(QWidget *w);
};

#endif