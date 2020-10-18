//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
// �������� ������: DrawRegMeshElem
//
// ��������: �������� ������ ����������� �������� ���������� �����
//
// �����: ������� ��������
//
// ���� ��������: 10.05.2020
//
// ���� ���������� ���������: 10.05.2020
//------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////

#include "DrawRegMeshElem.h"
#include "Storage.h"
#include <QtOpenGL>   // ���������� ������ QtOpenGL
//#include <QtCore>     // ���������� ������ QtCore

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
  // ������������� ������ ����� ����������� � ��������
  glLineWidth(3.0f); 
  // �� ������ ������� ������ ����� 1 ������� �� ���������

  // ������������� ���� ����������� ����������
  glColor4f(0.00f, 0.00f, 0.00f, 1.0f); 
  // ��� x �������� �����
  glBegin(GL_LINES); // ���������� �����
  glVertex3f( tParams.minPoint[0],  tParams.minPoint[1],  tParams.minPoint[2]); // ������ �����
  glVertex3f( tParams.maxPoint[0],  tParams.minPoint[1],  tParams.minPoint[2]); // ������ �����

  glVertex3f( tParams.maxPoint[0],  tParams.minPoint[1],  tParams.minPoint[2]); // ������ �����
  glVertex3f( tParams.maxPoint[0],  tParams.maxPoint[1],  tParams.minPoint[2]); // ������ �����

  glVertex3f( tParams.maxPoint[0],  tParams.maxPoint[1],  tParams.minPoint[2]); // ������ �����
  glVertex3f( tParams.minPoint[0],  tParams.maxPoint[1],  tParams.minPoint[2]); // ������ �����

  glVertex3f( tParams.minPoint[0],  tParams.maxPoint[1],  tParams.minPoint[2]); // ������ �����
  glVertex3f( tParams.minPoint[0],  tParams.minPoint[1],  tParams.minPoint[2]); // ������ �����
  glEnd();  

  glBegin(GL_LINES); // ���������� �����
  glVertex3f( tParams.minPoint[0],  tParams.minPoint[1],  tParams.maxPoint[2]); // ������ �����
  glVertex3f( tParams.maxPoint[0],  tParams.minPoint[1],  tParams.maxPoint[2]); // ������ �����

  glVertex3f( tParams.maxPoint[0],  tParams.minPoint[1],  tParams.maxPoint[2]); // ������ �����
  glVertex3f( tParams.maxPoint[0],  tParams.maxPoint[1],  tParams.maxPoint[2]); // ������ �����

  glVertex3f( tParams.maxPoint[0],  tParams.maxPoint[1],  tParams.maxPoint[2]); // ������ �����
  glVertex3f( tParams.minPoint[0],  tParams.maxPoint[1],  tParams.maxPoint[2]); // ������ �����

  glVertex3f( tParams.minPoint[0],  tParams.maxPoint[1],  tParams.maxPoint[2]); // ������ �����
  glVertex3f( tParams.minPoint[0],  tParams.minPoint[1],  tParams.maxPoint[2]); // ������ �����
  glEnd();  

  glBegin(GL_LINES); // ���������� �����
  glVertex3f( tParams.minPoint[0],  tParams.minPoint[1],  tParams.minPoint[2]); // ������ �����
  glVertex3f( tParams.minPoint[0],  tParams.minPoint[1],  tParams.maxPoint[2]); // ������ �����
  glEnd(); 

  glBegin(GL_LINES); // ���������� �����
  glVertex3f( tParams.maxPoint[0],  tParams.minPoint[1],  tParams.minPoint[2]); // ������ �����
  glVertex3f( tParams.maxPoint[0],  tParams.minPoint[1],  tParams.maxPoint[2]); // ������ �����
  glEnd(); 

  glBegin(GL_LINES); // ���������� �����
  glVertex3f( tParams.minPoint[0],  tParams.maxPoint[1],  tParams.minPoint[2]); // ������ �����
  glVertex3f( tParams.minPoint[0],  tParams.maxPoint[1],  tParams.maxPoint[2]); // ������ �����
  glEnd(); 

  glBegin(GL_LINES); // ���������� �����
  glVertex3f( tParams.maxPoint[0],  tParams.maxPoint[1],  tParams.minPoint[2]); // ������ �����
  glVertex3f( tParams.maxPoint[0],  tParams.maxPoint[1],  tParams.maxPoint[2]); // ������ �����
  glEnd(); 

  //glBegin(GL_LINES); // ���������� �����
  //glVertex3f( tParams.minPoint[0],  tParams.minPoint[1],  tParams.minPoint[2]); // ������ �����
  //glVertex3f( tParams.maxPoint[0],  tParams.maxPoint[1],  tParams.maxPoint[2]); // ������ �����
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