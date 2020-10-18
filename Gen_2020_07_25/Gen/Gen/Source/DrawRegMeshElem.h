//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
// Название модуля: DrawRegMeshElem
//
// Описание: содержит класса отображения элемента Регулярная сетка
//
// Автор: Никитин Вячеслав
//
// Дата создания: 10.05.2020
//
// Дата последнего изменения: 10.05.2020
//------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////

#ifndef DRAWREGMESHELEM_H
#define DRAWREGMESHELEM_H

#include "BaseDrawElem.h"
#include "RegElemParams.h"

class CDrawRegMeshElem : public CBaseDrawElem
{
public:
  CDrawRegMeshElem();
  ~CDrawRegMeshElem();

  CRegElemParams *myParams;

  virtual int Draw();
  virtual int ChangeParams(CBaseElemParams &params);
};

#endif