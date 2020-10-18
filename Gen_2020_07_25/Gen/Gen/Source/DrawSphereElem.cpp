//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
// �������� ������: DrawSphereElem
//
// ��������: �������� ������ ����������� �������� �����
//
// �����: ������� ��������
//
// ���� ��������: 03.07.2020
//
// ���� ���������� ���������: 03.07.2020
//------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////

#include "DrawSphereElem.h"
#include "Storage.h"
#include <QtOpenGL>   // ���������� ������ QtOpenGL
//#include <QtCore>     // ���������� ������ QtCore

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
  //glPushMatrix();       // ��������� ������� ����������
  //glTranslated(tParams.center[0],tParams.center[1],tParams.center[2]);  // ���������� �� ��� � �� ������� 
  //glColor3d(0,1,0);
  //gluSphere(0.5); // ������ ����� � (1,0,0)  � ���������� �����������
  //glPopMatrix();  // ������������ � ������ ������� ���������
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