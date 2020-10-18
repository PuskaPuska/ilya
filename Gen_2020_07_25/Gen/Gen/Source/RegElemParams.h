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