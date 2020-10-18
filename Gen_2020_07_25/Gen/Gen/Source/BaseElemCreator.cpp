//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
// Название модуля: BaseElemCreator
//
// Описание: содержит реализацию класса создания элементов
//
// Автор: Никитин Вячеслав
//
// Дата создания: 18.05.2020
//
// Дата последнего изменения: 18.05.2020
//------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////

#include "BaseElemCreator.h"

CBaseElemCreator::CBaseElemCreator()
{
  drawElem = NULL;
  dialogPage = NULL;
}

CBaseElemCreator::~CBaseElemCreator()
{
  sprintf(elemName, "empty element");
}

CBaseDrawElem *CBaseElemCreator::GetElem()
{
  return drawElem;
}

CDialogBasePage *CBaseElemCreator::GetDialog(QWidget *w)
{
  if (dialogPage == NULL)
    CreateDialogPage(w);
  return dialogPage;
}

int CBaseElemCreator::CreateDialogPage(QWidget *w)
{
  return 0;
}