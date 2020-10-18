//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
// Название модуля: DialogBaseAux
//
// Описание: содержит описание базового класса вспомогательных диалогов
//
// Автор: Никитин Вячеслав
//
// Дата создания: 31.08.2014
//
// Дата последнего изменения: 31.08.2014
//------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////

#include <QtGui>
#include "DialogBaseAux.h"
#include "Functional.h"

CDialogBaseAux::CDialogBaseAux(QWidget *parent)
  : QDialog(parent)
{
  setAttribute(Qt::WA_DeleteOnClose);
  CreateDialogElems();
  params = NULL;
}

CDialogBaseAux::~CDialogBaseAux()
{
  
}

int CDialogBaseAux::CreateDialogElems()
{
  return 0;
}

int CDialogBaseAux::SetParams(double *paramsIn)
{
  if (paramsIn == NULL)
    return -1;

  params = paramsIn;

  return 0;
}

void CDialogBaseAux::OnOkButton()
{
  if (params == NULL)
    return;

  accept();
}

int CDialogBaseAux::SetByDefault()
{
  return 0;
}

// функция проверки введенного числа на отсутсвие недопустимых символов
int CDialogBaseAux::CheckStringIn(QString str, QString name)
{
  if (!CheckString(str.toStdString().c_str(), str.count()))
  {
    char messag[512] = "Ошибка";
    sprintf(messag, "Параметр '%s' введен не правильно!", name.toStdString().c_str());

    QMessageBox* pmbx =
      new QMessageBox(tr("Ошибка ввода данных"),
      tr(messag),
      QMessageBox::Critical,
      NULL,
      NULL,
      QMessageBox::Cancel | QMessageBox::Escape);
    int n = pmbx->exec(); 
    delete pmbx; 

    return -1;
  }

  return 0;
}