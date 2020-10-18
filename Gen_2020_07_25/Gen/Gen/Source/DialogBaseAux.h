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

#ifndef DIALOGBASEAUX_H
#define DIALOGBASEAUX_H

#include <QDialog>

class CDialogBaseAux : public QDialog
{
  Q_OBJECT
public:
  CDialogBaseAux(QWidget *parent = 0);
  ~CDialogBaseAux();

  virtual int SetParams(double *paramsIn);
  virtual int SetByDefault();

  // функция проверки введенного числа на отсутсвие недопустимых символов
  int CheckStringIn(QString str, QString name);

protected:
  double *params;

private:
  int CreateDialogElems();

  public slots:
    void OnOkButton();
};

#endif