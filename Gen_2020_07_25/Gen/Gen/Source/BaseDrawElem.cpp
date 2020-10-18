//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
// Название модуля: BaseDrawElem
//
// Описание: содержит описание базового класса всех отображаемых элементов
//
// Автор: Никитин Вячеслав
//
// Дата создания: 10.05.2020
//
// Дата последнего изменения: 10.05.2020
//------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////

#include "BaseDrawElem.h"
#include <stdio.h>

static int IDIter = 0;

CBaseDrawElem::CBaseDrawElem()  : QObject()
{
  curParams = NULL;
}

CBaseDrawElem::~CBaseDrawElem()
{
}

int CBaseDrawElem::Draw()
{
  return 0;
}

void CBaseDrawElem::SetCurParams(CBaseElemParams *params)
{
  curParams = params;
}

int CBaseDrawElem::ChangeParams(CBaseElemParams &params)
{
  return 0;
}

void CBaseDrawElem::SetElemName(const char *str)
{
  elemName = QString(tr(str)) + ", " + QString::number(++IDIter);
}

QString &CBaseDrawElem::GetElemName()
{
  return elemName;
}

int CBaseDrawElem::ReadDataFromFile(QString path)
{
  return 0;
}

int CBaseDrawElem::WriteDataToFile(QString path)
{
  return 0;
}
