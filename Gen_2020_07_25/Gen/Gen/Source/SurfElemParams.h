//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
// �������� ������: SurfElemParams
//
// ��������: �������� �������� ������ �������� � �������� ���������� 
// �������� �����������
//
// �����: ������� ��������
//
// ���� ��������: 23.07.2020
//
// ���� ���������� ���������: 23.07.2020
//------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////

#ifndef SURFELEMPARAMS_H
#define SURFELEMPARAMS_H

#include "BaseElemParams.h"

class CSurfElemParams : public CBaseElemParams
{
public:
  CSurfElemParams();
  ~CSurfElemParams();

  CSurfElemParams &operator = (CSurfElemParams &a);
};
#endif