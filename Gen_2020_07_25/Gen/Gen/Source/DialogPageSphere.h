//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
// �������� ������: DialogPageSphere
//
// ��������: �������� �������� �������� ������� ���������� �������� �����
//
// �����: ������� ��������
//
// ���� ��������: 03.07.2020
//
// ���� ���������� ���������: 03.07.2020
//------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////

#ifndef DIALOGPAGESPHERE_H
#define DIALOGPAGESPHERE_H

#include "DialogBasePage.h"
#include "MyLineEdit.h"

class QPushButton;

class CDialogPageSphere : public CDialogBasePage
{
  Q_OBJECT
public:
  CDialogPageSphere(QWidget *parent = 0);
  ~CDialogPageSphere();

  int CreateDialogElems();

private:
  CLineEdit *cenP[3];
  CLineEdit *rad;
  QPushButton *setParams;

  public slots:
    void OnSetParamsButton();
};

#endif