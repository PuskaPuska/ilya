//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
// �������� ������: SphereElemParams
//
// ��������: �������� �������� ������ �������� � �������� ���������� 
// �������� �����
//
// �����: ������� ��������
//
// ���� ��������: 03.07.2020
//
// ���� ���������� ���������: 03.07.2020
//------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////

#ifndef SPHEREELEMPARAMS_H
#define SPHEREELEMPARAMS_H

#include "BaseElemParams.h"

class CSphereElemParams : public CBaseElemParams
{
public:
  CSphereElemParams();
  ~CSphereElemParams();

  float center[3];
  double radius;

  CSphereElemParams &operator = (CSphereElemParams &a);
};

#endif