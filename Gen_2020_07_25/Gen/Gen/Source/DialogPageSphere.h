//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
// Название модуля: DialogPageSphere
//
// Описание: содержит описание диалогов задания параметров элемента Сфера
//
// Автор: Никитин Вячеслав
//
// Дата создания: 03.07.2020
//
// Дата последнего изменения: 03.07.2020
//------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////

#ifndef DIALOGPAGESPHERE_H
#define DIALOGPAGESPHERE_H

#include "DialogBasePage.h"
#include "MyLineEdit.h"

class QPushButton;

class CDialogPageSphere : public CDialogBasePage
{
  Q_OBJECT
public:
  CDialogPageSphere(QWidget *parent = 0);
  ~CDialogPageSphere();

  int CreateDialogElems();

private:
  CLineEdit *cenP[3];
  CLineEdit *rad;
  QPushButton *setParams;

  public slots:
    void OnSetParamsButton();
};

#endif