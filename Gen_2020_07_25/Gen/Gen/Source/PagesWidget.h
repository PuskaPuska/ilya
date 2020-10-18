//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
// �������� ������: PagesWidget
//
// ��������: �������� �������� �������� ������� ������� ���������� �������
//
// �����: ������� ��������
//
// ���� ��������: 17.04.2014
//
// ���� ���������� ���������: 06.11.2014
//------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////

#ifndef SCENEWIDGET_H
#define SCENEWIDGET_H

#include <QStackedWidget>
#include "DialogBasePage.h"

class CPagesWidget : public QStackedWidget
{
  Q_OBJECT

public:

  CPagesWidget(QWidget *parent = 0);
  void SetCurWidget(const int &pos);

signals:

  public slots:

protected:

private:
  ~CPagesWidget();
};

#endif