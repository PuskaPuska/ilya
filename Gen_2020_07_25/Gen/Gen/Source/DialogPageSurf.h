//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
// �������� ������: DialogPageSurf
//
// ��������: �������� �������� �������� ������� ���������� �������� �����������
//
// �����: ������� ��������
//
// ���� ��������: 23.07.2020
//
// ���� ���������� ���������: 23.07.2020
//------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////

#ifndef DIALOGPAGESURF_H
#define DIALOGPAGESURF_H

#include "DialogBasePage.h"
#include "MyLineEdit.h"

class QPushButton;

class CDialogPageSurf : public CDialogBasePage
{
  Q_OBJECT
public:
  CDialogPageSurf(QWidget *parent = 0);
  ~CDialogPageSurf();

  int CreateDialogElems();

private:
  QPushButton *setParams;

  public slots:
    void OnSetParamsButton();
};

#endif