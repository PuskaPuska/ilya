//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
// Название модуля: DialogAddNewMesh
//
// Описание: содержит описание вспомогательного диалога добавления нового источника
//
// Автор: Никитин Вячеслав
//
// Дата создания: 17.05.2014
//
// Дата последнего изменения: 31.08.2014
//------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////

#ifndef DIALOGADDNEWMESH_H
#define DIALOGADDNEWMESH_H

#include <QDialog>
#include "DialogBaseAux.h"

class QComboBox;

class CDialogAddNewMesh : public CDialogBaseAux
{
  Q_OBJECT
public:
  CDialogAddNewMesh(QWidget *parent = 0);
  ~CDialogAddNewMesh();

  int SetParams(double *paramsIn);

private:
  QComboBox *typeSourserCombo;

  int CreateDialogElems();

  public slots:
    void OnOkButton();
};

#endif