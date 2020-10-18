//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
// �������� ������: DialogBaseAux
//
// ��������: �������� �������� �������� ������ ��������������� ��������
//
// �����: ������� ��������
//
// ���� ��������: 31.08.2014
//
// ���� ���������� ���������: 31.08.2014
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

  // ������� �������� ���������� ����� �� ��������� ������������ ��������
  int CheckStringIn(QString str, QString name);

protected:
  double *params;

private:
  int CreateDialogElems();

  public slots:
    void OnOkButton();
};

#endif