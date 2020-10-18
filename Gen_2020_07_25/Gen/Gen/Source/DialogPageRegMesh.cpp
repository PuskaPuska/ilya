//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
// Название модуля: DialogPageRegMesh
//
// Описание: содержит описание диалога задания параметров элемента 
// Регулярная область
//
// Автор: Никитин Вячеслав
//
// Дата создания: 10.05.2020
//
// Дата последнего изменения: 10.05.2020
//------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////


#include <QtGui>

#include "DialogPageRegMesh.h"
#include "RegElemParams.h"

CDialogPageRegMesh::CDialogPageRegMesh(QWidget *parent)
  : CDialogBasePage(parent)
{
  SetPageName("Не задано", "Не задано");

  CreateDialogElems();
}

CDialogPageRegMesh::~CDialogPageRegMesh()
{
}

int CDialogPageRegMesh::CreateDialogElems()
{
  QLabel *minLabel = new QLabel("Минимальная точка:");
  QHBoxLayout *minCoorHLayout = new QHBoxLayout;
  for (int i=0; i<3; i++)
  {
    minP[i] = new CLineEdit(tr("0"));
    minCoorHLayout->addWidget(minP[i]);
  }
  minP[0]->SetName(tr("x"));
  minP[1]->SetName(tr("y"));
  minP[2]->SetName(tr("z"));

  QLabel *maxLabel = new QLabel("Максимальня точка:");
  QHBoxLayout *maxCoorHLayout = new QHBoxLayout;
  for (int i=0; i<3; i++)
  {
    maxP[i] = new CLineEdit(tr("100"));
    maxCoorHLayout->addWidget(maxP[i]);
  }
  maxP[0]->SetName(tr("x"));
  maxP[1]->SetName(tr("y"));
  maxP[2]->SetName(tr("z"));

  QLabel *deltaLabel = new QLabel("Шаг сетки:");
  QHBoxLayout *deltaCoorHLayout = new QHBoxLayout;
  for (int i=0; i<3; i++)
  {
    delta[i] = new CLineEdit(tr("0.5"));
    deltaCoorHLayout->addWidget(delta[i]);
  }
  delta[0]->SetName(tr("Шаг по оси OX"));
  delta[1]->SetName(tr("Шаг по оси OY"));
  delta[2]->SetName(tr("Шаг по оси OZ"));


  setParams = new QPushButton(tr("Применить"));
  connect(setParams, SIGNAL(clicked()), this, SLOT(OnSetParamsButton()));

  QVBoxLayout *allVLayout = new QVBoxLayout;
  allVLayout->addWidget(minLabel);
  allVLayout->addLayout(minCoorHLayout);
  allVLayout->addWidget(maxLabel);
  allVLayout->addLayout(maxCoorHLayout);
  allVLayout->addWidget(deltaLabel);
  allVLayout->addLayout(deltaCoorHLayout);
  allVLayout->setAlignment(Qt::AlignCenter);
  allVLayout->addWidget(setParams);
  
  delete baseLayout;
  delete nullLabel;
  setLayout(allVLayout);
  return 0;
}

void CDialogPageRegMesh::OnSetParamsButton()
{
  CRegElemParams params;
  for (int i = 0; i < 3; i++)
  {
    if (!minP[i]->IsCorrect())
      return;
    params.minPoint[i] = minP[i]->text().toDouble();
    if (!maxP[i]->IsCorrect())
      return;
    params.maxPoint[i] = maxP[i]->text().toDouble();
    if (!delta[i]->IsCorrect())
      return;
    params.detla[i] = delta[i]->text().toDouble();
  }
  curElem->ChangeParams(params);
}