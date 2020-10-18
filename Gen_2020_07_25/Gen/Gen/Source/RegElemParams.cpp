//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
// Название модуля: RegElemParams
//
// Описание: содержит описание класса хранения и передачи параметров регулярной оюласти
//
// Автор: Никитин Вячеслав
//
// Дата создания: 07.06.2020
//
// Дата последнего изменения: 07.06.2020
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
