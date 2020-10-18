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

#include "RegElemParams.h"

CRegElemParams::CRegElemParams() : CBaseElemParams()
{
  for (int i = 0; i < 3; i++)
  {
    minPoint[i] = -1;
    maxPoint[i] = 1;
    detla[i] = 10;
  }
}
CRegElemParams::~CRegElemParams()
{

}

CRegElemParams &CRegElemParams::operator = (CRegElemParams &a)
{
  for (int i = 0; i < 3; i++)
  {
    minPoint[i] = a.minPoint[i];
    maxPoint[i] = a.maxPoint[i];
    detla[i] = a.detla[i];
  }
  return a;
}
