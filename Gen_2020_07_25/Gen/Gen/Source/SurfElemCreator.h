//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
// Название модуля: SurfElemCreator
//
// Описание: содержит реализацию класса создания элемента поверхность
//
// Автор: Никитин Вячеслав
//
// Дата создания: 23.07.2020
//
// Дата последнего изменения: 23.07.2020
//------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////

#ifndef SURFELEMCREATOR_H
#define SURFELEMCREATOR_H

#include "BaseElemCreator.h"

class CSurfElemCreator : public CBaseElemCreator
{
public:
  CSurfElemCreator();
  CSurfElemCreator(const bool flag);
  ~CSurfElemCreator();

private:
  static CSurfElemCreator *startPtr;

protected:
  virtual int CreateDialogPage(QWidget *w);
};

#endif