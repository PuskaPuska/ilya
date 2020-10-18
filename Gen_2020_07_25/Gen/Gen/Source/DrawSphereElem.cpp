//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
// Название модуля: DrawSphereElem
//
// Описание: содержит класса отображения элемента Сфера
//
// Автор: Никитин Вячеслав
//
// Дата создания: 03.07.2020
//
// Дата последнего изменения: 03.07.2020
//------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////

#include "DrawSphereElem.h"
#include "Storage.h"
#include <QtOpenGL>   // подключаем модуль QtOpenGL
//#include <QtCore>     // подключаем модуль QtCore

CDrawSphereElem::CDrawSphereElem() : CBaseDrawElem()
{
  myParams = new CSphereElemParams();
  SetCurParams(myParams);
}

CDrawSphereElem::~CDrawSphereElem()
{
}

int CDrawSphereElem::Draw()
{
  if (curParams == NULL)
    return -1;
  CSphereElemParams &tParams = *myParams;

  //glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  //glPushMatrix();       // сохраняем текущие координаты
  //glTranslated(tParams.center[0],tParams.center[1],tParams.center[2]);  // сдвигаемся по оси Х на единицу 
  //glColor3d(0,1,0);
  //gluSphere(0.5); // рисуем сферу в (1,0,0)  в абсолютных координатах
  //glPopMatrix();  // возвращаемся к старой системе координат
  //auxSwapBuffers();

  return 0;
}

int CDrawSphereElem::ChangeParams(CBaseElemParams &params)
{
  if (curParams == NULL)
    curParams = new CBaseElemParams;
  CSphereElemParams &tParams = (CSphereElemParams&) params;
  *myParams = tParams;
  return 0;
}