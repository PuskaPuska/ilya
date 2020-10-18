//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
// Название модуля: DrawRegMeshElem
//
// Описание: содержит класса отображения элемента Регулярная сетка
//
// Автор: Никитин Вячеслав
//
// Дата создания: 10.05.2020
//
// Дата последнего изменения: 10.05.2020
//------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////

#include "DrawRegMeshElem.h"
#include "Storage.h"
#include <QtOpenGL>   // подключаем модуль QtOpenGL
//#include <QtCore>     // подключаем модуль QtCore

CDrawRegMeshElem::CDrawRegMeshElem() : CBaseDrawElem()
{
  myParams = new CRegElemParams();
  SetCurParams(myParams);
}

CDrawRegMeshElem::~CDrawRegMeshElem()
{
}

int CDrawRegMeshElem::Draw()
{
  if (curParams == NULL)
    return -1;
  CRegElemParams &tParams = *myParams;
  // устанавливаем ширину линии приближенно в пикселях
  glLineWidth(3.0f); 
  // до вызова команды ширина равна 1 пикселю по умолчанию

  // устанавливаем цвет последующих примитивов
  glColor4f(0.00f, 0.00f, 0.00f, 1.0f); 
  // ось x красного цвета
  glBegin(GL_LINES); // построение линии
  glVertex3f( tParams.minPoint[0],  tParams.minPoint[1],  tParams.minPoint[2]); // первая точка
  glVertex3f( tParams.maxPoint[0],  tParams.minPoint[1],  tParams.minPoint[2]); // вторая точка

  glVertex3f( tParams.maxPoint[0],  tParams.minPoint[1],  tParams.minPoint[2]); // первая точка
  glVertex3f( tParams.maxPoint[0],  tParams.maxPoint[1],  tParams.minPoint[2]); // вторая точка

  glVertex3f( tParams.maxPoint[0],  tParams.maxPoint[1],  tParams.minPoint[2]); // первая точка
  glVertex3f( tParams.minPoint[0],  tParams.maxPoint[1],  tParams.minPoint[2]); // вторая точка

  glVertex3f( tParams.minPoint[0],  tParams.maxPoint[1],  tParams.minPoint[2]); // первая точка
  glVertex3f( tParams.minPoint[0],  tParams.minPoint[1],  tParams.minPoint[2]); // вторая точка
  glEnd();  

  glBegin(GL_LINES); // построение линии
  glVertex3f( tParams.minPoint[0],  tParams.minPoint[1],  tParams.maxPoint[2]); // первая точка
  glVertex3f( tParams.maxPoint[0],  tParams.minPoint[1],  tParams.maxPoint[2]); // вторая точка

  glVertex3f( tParams.maxPoint[0],  tParams.minPoint[1],  tParams.maxPoint[2]); // первая точка
  glVertex3f( tParams.maxPoint[0],  tParams.maxPoint[1],  tParams.maxPoint[2]); // вторая точка

  glVertex3f( tParams.maxPoint[0],  tParams.maxPoint[1],  tParams.maxPoint[2]); // первая точка
  glVertex3f( tParams.minPoint[0],  tParams.maxPoint[1],  tParams.maxPoint[2]); // вторая точка

  glVertex3f( tParams.minPoint[0],  tParams.maxPoint[1],  tParams.maxPoint[2]); // первая точка
  glVertex3f( tParams.minPoint[0],  tParams.minPoint[1],  tParams.maxPoint[2]); // вторая точка
  glEnd();  

  glBegin(GL_LINES); // построение линии
  glVertex3f( tParams.minPoint[0],  tParams.minPoint[1],  tParams.minPoint[2]); // первая точка
  glVertex3f( tParams.minPoint[0],  tParams.minPoint[1],  tParams.maxPoint[2]); // вторая точка
  glEnd(); 

  glBegin(GL_LINES); // построение линии
  glVertex3f( tParams.maxPoint[0],  tParams.minPoint[1],  tParams.minPoint[2]); // первая точка
  glVertex3f( tParams.maxPoint[0],  tParams.minPoint[1],  tParams.maxPoint[2]); // вторая точка
  glEnd(); 

  glBegin(GL_LINES); // построение линии
  glVertex3f( tParams.minPoint[0],  tParams.maxPoint[1],  tParams.minPoint[2]); // первая точка
  glVertex3f( tParams.minPoint[0],  tParams.maxPoint[1],  tParams.maxPoint[2]); // вторая точка
  glEnd(); 

  glBegin(GL_LINES); // построение линии
  glVertex3f( tParams.maxPoint[0],  tParams.maxPoint[1],  tParams.minPoint[2]); // первая точка
  glVertex3f( tParams.maxPoint[0],  tParams.maxPoint[1],  tParams.maxPoint[2]); // вторая точка
  glEnd(); 

  //glBegin(GL_LINES); // построение линии
  //glVertex3f( tParams.minPoint[0],  tParams.minPoint[1],  tParams.minPoint[2]); // первая точка
  //glVertex3f( tParams.maxPoint[0],  tParams.maxPoint[1],  tParams.maxPoint[2]); // вторая точка
  //glEnd(); 

  return 0;
}

int CDrawRegMeshElem::ChangeParams(CBaseElemParams &params)
{
  if (curParams == NULL)
    curParams = new CBaseElemParams;
  CRegElemParams &tParams = (CRegElemParams&) params;
  *myParams = tParams;
  return 0;
}