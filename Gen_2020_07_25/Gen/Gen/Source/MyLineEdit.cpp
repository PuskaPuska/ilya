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

#include <QtGui>
#include "MyLineEdit.h"
#include "Functional.h"

CLineEdit::CLineEdit(QWidget *parent)
  : QLineEdit(parent)
{
  isCor = 1;
  namePar = "";
}

CLineEdit::CLineEdit(const QString & contents, QWidget * parent)
  : QLineEdit(contents, parent)
{
  isCor = 1;
  namePar = "";
}

int CLineEdit::SetName(QString str)
{
  namePar = str;
  return 0;
}

int CLineEdit::IsCorrect()
{
  if (namePar != "" && isCor == 0)
  {
    char messag[512] = "Ошибка";
    sprintf(messag, "Параметр '%s' введен не правильно!", namePar.toStdString().c_str());

    QMessageBox* pmbx =
      new QMessageBox(tr("Ошибка ввода данных"),
      tr(messag),
      QMessageBox::Critical,
      NULL,
      NULL,
      QMessageBox::Cancel | QMessageBox::Escape);
    int n = pmbx->exec(); 
    delete pmbx; 
  }
  return isCor;
}

void CLineEdit::keyPressEvent( QKeyEvent * event )
{
  if (event->key() != Qt::Key_Backspace &&
      event->key() != Qt::Key_Tab &&
      event->key() != Qt::Key_Delete)
  {
    QString str = event->text();
    //char sim = event->text();

    if (CheckString(str.toStdString().c_str(), str.length()) == 0)
      return;
  }

  QLineEdit::keyPressEvent(event);
}

void CLineEdit::focusInEvent(QFocusEvent * event)
{
  QLineEdit::focusInEvent(event);

  setStyleSheet("background-color: white");
}

void CLineEdit::focusOutEvent(QFocusEvent * event)
{
  QLineEdit::focusOutEvent(event);

  //isCor = 0;

  QString str = text();

  isCor = CheckNumb(str.toStdString().c_str(), str.length());
  if (isCor == 0)
    setStyleSheet("background-color: red");
  return;

  //if (str[0] != '-' || str[0] != '+' || (str[0] >= '0' && str[0] <= '9') || str[0] != '.')
  if (str[0] == 'e' || str[0] == 'E')
  {
    setStyleSheet("background-color: red");
    return;
  }

  int i, k=0;
  int posE = -1, posP = -1;
  for (i=0; i<str.length(); i++)
  {
    if (str[i] == '.')
    {
      posP = i;
      k++;
    }
  }
  if (k>1)
  {
    setStyleSheet("background-color: red");
    return;
  }

  k=0;
  for (i=0; i<str.length(); i++)
  {
    if (str[i] == 'e')
    {
      posE = i;
      k++;
    }
  }
  
  if (k == 0)
  {
    for (i=0; i<str.length(); i++)
    {
      if (str[i] == 'E')
      {
        posE = i;
        k++;
      }
    }
  }
  if (k>1)
  {
    setStyleSheet("background-color: red");
    return;
  }
  if (k==1)
  {
    if (posE+1 >= str.length())
    {
      setStyleSheet("background-color: red");
      return;
    }

    if (str[posE+1] != '-' && str[posE+1] != '+')
    {
      setStyleSheet("background-color: red");
      return;
    }
  }

  if (posE>=0)
    if (posP > posE)
    {
      setStyleSheet("background-color: red");
      return;
    }

  posP = -1;
  posE = -1;
  k = 0;
  for (i=0; i<str.length(); i++)
  {
    if (str[i] == '-')
    {
      if (posP == -1)
        posP = i;
      else
        posE = i;
      k++;
    }
  }
  if (k>2)
  {
    setStyleSheet("background-color: red");
    return;
  }

  if (k == 2)
  {
    if (posP != 0 || posE < 2)
    {
      setStyleSheet("background-color: red");
      return;
    }
    if (posE+1 >= str.length())
    {
      setStyleSheet("background-color: red");
      return;
    }
    if (str[posE+1] < '0' && str[posE+1] > '9')
    {
      setStyleSheet("background-color: red");
      return;
    }
    if (str[posP+1] < '0' && str[posP+1] > '9')
    {
      setStyleSheet("background-color: red");
      return;
    }
    if (str[posE-1] != 'e' && str[posE-1] != 'E')
    {
      setStyleSheet("background-color: red");
      return;
    }
    //if (str[posE-1] != 'E')
    //{
    //  setStyleSheet("background-color: red");
    //  return;
    //}
  }
  if (k == 1)
  {
    //if (posP > 0 && str[posP-1] != 'e')
    //{
    //  setStyleSheet("background-color: red");
    //  return;
    //}

    if (posP > 0 && str[posP-1] != 'E' && str[posP-1] != 'e')
    {
      setStyleSheet("background-color: red");
      return;
    }

    if (posP+1 >= str.length())
    {
      setStyleSheet("background-color: red");
      return;
    }

    if (str[posP+1] < '0' && str[posP+1] > '9')
    {
      setStyleSheet("background-color: red");
      return;
    }
  }

  posP = -1;
  posE = -1;
  k = 0;
  for (i=0; i<str.length(); i++)
  {
    if (str[i] == '+')
    {
      if (posP == -1)
        posP = i;
      else
        posE = i;
      k++;
    }
  }
  if (k>2)
  {
    setStyleSheet("background-color: red");
    return;
  }

  if (k == 2)
  {
    if (posP != 0 || posE < 2)
    {
      setStyleSheet("background-color: red");
      return;
    }
    if (posE+1 >= str.length())
    {
      setStyleSheet("background-color: red");
      return;
    }
    if (str[posE+1] < '0' && str[posE+1] > '9')
    {
      setStyleSheet("background-color: red");
      return;
    }
    if (str[posP+1] < '0' && str[posP+1] > '9')
    {
      setStyleSheet("background-color: red");
      return;
    }
    if (str[posE-1] != 'e' && str[posE-1] != 'E')
    {
      setStyleSheet("background-color: red");
      return;
    }
    //if (str[posE-1] != 'E')
    //{
    //  setStyleSheet("background-color: red");
    //  return;
    //}
  }
  if (k == 1)
  {
    if (posP > 0 && str[posP-1] != 'e' && str[posP-1] != 'E')
    {
      setStyleSheet("background-color: red");
      return;
    }

    //if (posP > 0 && str[posP-1] != 'E')
    //{
    //  setStyleSheet("background-color: red");
    //  return;
    //}

    if (posP+1 >= str.length())
    {
      setStyleSheet("background-color: red");
      return;
    }

    if (str[posP+1] < '0' && str[posP+1] > '9')
    {
      setStyleSheet("background-color: red");
      return;
    }
  }

  isCor = 1;
}