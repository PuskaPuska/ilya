//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
// Название модуля: DialogPageSurf
//
// Описание: содержит описание диалогов задания параметров элемента Поверхность
//
// Автор: Никитин Вячеслав
//
// Дата создания: 23.07.2020
//
// Дата последнего изменения: 23.07.2020
//------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////


#include <QtGui>

#include "DialogPageSurf.h"
#include "SurfElemParams.h"

CDialogPageSurf::CDialogPageSurf(QWidget *parent)
  : CDialogBasePage(parent)
{
  SetPageName("Не задано", "Не задано");

  CreateDialogElems();
}

CDialogPageSurf::~CDialogPageSurf()
{
}

int CDialogPageSurf::CreateDialogElems()
{
  setParams = new QPushButton(tr("Применить"));
  connect(setParams, SIGNAL(clicked()), this, SLOT(OnSetParamsButton()));

  QVBoxLayout *allVLayout = new QVBoxLayout;
  allVLayout->setAlignment(Qt::AlignCenter);
  allVLayout->addWidget(setParams);

  delete baseLayout;
  delete nullLabel;
  setLayout(allVLayout);
  return 0;
}

void CDialogPageSurf::OnSetParamsButton()
{
  CSurfElemParams params;
  curElem->ChangeParams(params);
}