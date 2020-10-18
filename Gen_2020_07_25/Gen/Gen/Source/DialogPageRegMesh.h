//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
// Название модуля: DialogPageRegMesh
//
// Описание: содержит описание диалога задания параметров элемента 
// Регулярная область
//
// Автор: Никитин Вячеслав
//
// Дата создания: 10.05.2020
//
// Дата последнего изменения: 10.05.2020
//------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////

#ifndef DIALOGPAGEREGMESH_H
#define DIALOGPAGEREGMESH_H

#include "DialogBasePage.h"
#include "MyLineEdit.h"

class QPushButton;

class CDialogPageRegMesh : public CDialogBasePage
{
  Q_OBJECT
public:
  CDialogPageRegMesh(QWidget *parent = 0);
  ~CDialogPageRegMesh();
  
  int CreateDialogElems();

private:
  CLineEdit *minP[3];
  CLineEdit *maxP[3];
  CLineEdit *delta[3];
  QPushButton *setParams;

public slots:
  void OnSetParamsButton();
};

#endif