//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
// �������� ������: DrawSphereElem
//
// ��������: �������� ������ ����������� �������� �����
//
// �����: ������� ��������
//
// ���� ��������: 03.07.2020
//
// ���� ���������� ���������: 03.07.2020
//------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////

#ifndef DRAWSPHEREELEM_H
#define DRAWSPHEREELEM_H

#include "BaseDrawElem.h"
#include "SphereElemParams.h"

class CDrawSphereElem : public CBaseDrawElem
{
public:
  CDrawSphereElem();
  ~CDrawSphereElem();

  CSphereElemParams *myParams;

  virtual int Draw();
  virtual int ChangeParams(CBaseElemParams &params);
};

#endif