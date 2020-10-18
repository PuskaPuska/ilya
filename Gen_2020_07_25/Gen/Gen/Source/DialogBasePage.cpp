//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
// �������� ������: DialogBasePage
//
// ��������: �������� �������� �������� ������ ���� �������� ������� 
// ����������
//
// �����: ������� ��������
//
// ���� ��������: 19.05.2014
//
// ���� ���������� ���������: 22.09.2014
//------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////

#include <QtGui>

#include "DialogBasePage.h"
#include "Functional.h"

CDialogBasePage::CDialogBasePage(QWidget *parent)
  : QWidget(parent)
{
  SetPageName("�� ������", "�� ������");

  CreateDialogElems();

  curElem = NULL;
}

CDialogBasePage::~CDialogBasePage()
{
}

int CDialogBasePage::CreateDialogElems()
{
  nullLabel = new QLabel(tr("�������� ����������� ����� ��������."));

  baseLayout = new QGridLayout;
  baseLayout->addWidget(nullLabel);
  baseLayout->setAlignment(Qt::AlignCenter);
  setLayout(baseLayout);
  return 0;
}

// ������� �������� ���������� ����� �� ��������� ������������ ��������
int CDialogBasePage::CheckStringIn(QString str, QString name)
{
  if (!CheckString(str.toStdString().c_str(), str.count()))
  {
    char messag[512] = "������";
    sprintf(messag, "�������� '%s' ������ �� ���������!", name.toStdString().c_str());

    QMessageBox* pmbx =
      new QMessageBox(tr("������ ����� ������"),
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