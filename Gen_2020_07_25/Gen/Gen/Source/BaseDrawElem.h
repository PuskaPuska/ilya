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

#ifndef BASEDRAWELEM_H
#define BASEDRAWELEM_H

#include "BaseElemParams.h"
#include "qobject.h"
#include <QString>

class CBaseDrawElem : public QObject
{
  Q_OBJECT
public:
  CBaseDrawElem();
  ~CBaseDrawElem();

  virtual int Draw();
  virtual int ChangeParams(CBaseElemParams &params);
  virtual int ReadDataFromFile(QString path);
  virtual int WriteDataToFile(QString path);
  void SetElemName(const char *str);
  QString &GetElemName();
protected:
  CBaseElemParams *curParams;
  QString elemName;

  void SetCurParams(CBaseElemParams *params);
};

#endif