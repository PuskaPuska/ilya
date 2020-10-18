//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
// Название модуля: DialogBasePage
//
// Описание: содержит описание базового класса всех диалогов задания 
// параметров
//
// Автор: Никитин Вячеслав
//
// Дата создания: 19.05.2014
//
// Дата последнего изменения: 22.09.2014
//------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////

#include <QtGui>

#include "DialogBasePage.h"
#include "Functional.h"

CDialogBasePage::CDialogBasePage(QWidget *parent)
  : QWidget(parent)
{
  SetPageName("Не задано", "Не задано");

  CreateDialogElems();

  curElem = NULL;
}

CDialogBasePage::~CDialogBasePage()
{
}

int CDialogBasePage::CreateDialogElems()
{
  nullLabel = new QLabel(tr("Выберите необходимый пункт настроек."));

  baseLayout = new QGridLayout;
  baseLayout->addWidget(nullLabel);
  baseLayout->setAlignment(Qt::AlignCenter);
  setLayout(baseLayout);
  return 0;
}

// функция проверки введенного числа на отсутсвие недопустимых символов
int CDialogBasePage::CheckStringIn(QString str, QString name)
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

int CDialogBasePage::SetPageName(QString name, QString shortName)
{
  pageName = name;
  shortPageName = shortName;

  return 0;
}

QString CDialogBasePage::GetPageName()
{
  return pageName;
}

QString CDialogBasePage::GetPageShortName()
{
  return shortPageName;
}

void CDialogBasePage::SetCurElem(CBaseDrawElem *elem)
{
  curElem = elem;
}