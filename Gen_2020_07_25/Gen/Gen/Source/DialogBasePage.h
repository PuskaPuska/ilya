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

#ifndef DIALOGBASEPAGE_H
#define DIALOGBASEPAGE_H

#include <QWidget>
#include "BaseDrawElem.h"

class QLabel;
class QGridLayout;

class CDialogBasePage : public QWidget
{
  Q_OBJECT
public:
  CDialogBasePage(QWidget *parent = 0);
  ~CDialogBasePage();

  QLabel *nullLabel;
  QGridLayout *baseLayout;

  int CreateDialogElems();
  virtual int SetPageName(QString name, QString shortName);
  virtual int CheckStringIn(QString str, QString name);
  QString GetPageName();
  QString GetPageShortName();
  void SetCurElem(CBaseDrawElem *elem);

private:
  QString pageName;
  QString shortPageName;

protected:
  CBaseDrawElem *curElem;
};

#endif