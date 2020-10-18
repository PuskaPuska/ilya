//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
// Название модуля: MyLineEdit
//
// Описание: содержит описание перегруженного класса QLineEdit
//
// Автор: Никитин Вячеслав
//
// Дата создания: 20.04.2015
//
// Дата последнего изменения: 30.04.2015
//------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////

#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QLineEdit>
#include <QKeyEvent>

class CLineEdit : public QLineEdit
{
  Q_OBJECT
public:

  CLineEdit(QWidget *parent = 0);
  CLineEdit(const QString & contents, QWidget * parent = 0);

  virtual void keyPressEvent( QKeyEvent * event );
  virtual void focusOutEvent(QFocusEvent * event);
  virtual void focusInEvent(QFocusEvent * event);
  int IsCorrect();
  int SetName(QString str);

private:
  int isCor;
  QString namePar;
};

#endif