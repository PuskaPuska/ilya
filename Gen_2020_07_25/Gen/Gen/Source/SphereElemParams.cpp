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

#include "SphereElemParams.h"

CSphereElemParams::CSphereElemParams() : CBaseElemParams()
{
  for (int i = 0; i < 3; i++)
  {
    center[i] = 0;
  }
  radius = 10;
}
CSphereElemParams::~CSphereElemParams()
{

}

CSphereElemParams &CSphereElemParams::operator = (CSphereElemParams &a)
{
  for (int i = 0; i < 3; i++)
  {
    center[i] = a.center[i];
  }
  radius = a.radius;
  return a;
}
