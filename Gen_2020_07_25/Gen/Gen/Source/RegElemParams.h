//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
// �������� ������: RegElemParams
//
// ��������: �������� �������� ������ �������� � �������� ���������� ���������� �������
//
// �����: ������� ��������
//
// ���� ��������: 07.06.2020
//
// ���� ���������� ���������: 07.06.2020
//------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////

#ifndef REGELEMPARAMS_H
#define REGELEMPARAMS_H

#include "BaseElemParams.h"

class CRegElemParams : public CBaseElemParams
{
public:
  CRegElemParams();
  ~CRegElemParams();

  float minPoint[3];
  float maxPoint[3];
  double detla[3];

  CRegElemParams &operator = (CRegElemParams &a);
};

#endif