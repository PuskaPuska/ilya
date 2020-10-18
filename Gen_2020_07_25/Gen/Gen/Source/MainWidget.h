//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
// Название модуля: MainWidget
//
// Описание: содержит описание главного диалога задания параметров расчета
//
// Автор: Никитин Вячеслав
//
// Дата создания: 17.04.2014
//
// Дата последнего изменения: 06.11.2014
//------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////

#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QDialog>
#include "WidgetTree.h"
#include "Scene3D.h"
#include <QtGui>

class QProgressBar;

class CMainWidget : public QWidget
{
  Q_OBJECT

public:

  CMainWidget(QWidget *parent = 0);

  int UpdateDialog();
  int SetByDefault();                                // установить настройки по умолчанию

signals:
  void runButtonClicked();
  void endButtonClicked();

public slots:
  void OnRunButton();
  void OnAddSourseButton();
  void OnDelSourseButton(int pos);
  void OnCopySourseButton(int pos);
  void OnAddMeteoButton();
  void OnDelMeteoButton(int pos);
  void OnCopyMeteoButton(int pos);

  void OnItemTreeChange(int numItem);
  void OnStopBuatton();
  void OnStopedCalc();
  void OnSetCurPos(int curPos);
  void OnUpdateMeteo();
  void OnUpdateNeme();
  void OnUpdateSource();

protected:

private:
  CWidgetTree *newViewTree;
  CScene3D *newSceneWidget;
  QPushButton *stopButton;
  QPushButton *runButton;
  QProgressBar *progressBar;

  ~CMainWidget();

  // функция проверки введенного числа на отсутсвие недопустимых символов
  int CheckStringIn(QString str, QString name);
};

#endif