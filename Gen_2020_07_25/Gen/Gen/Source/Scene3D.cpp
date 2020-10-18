#include "Scene3D.h"
#include <QtGui>      // ���������� ������ QtGui
//#include <QtCore>     // ���������� ������ QtCore
//#include <QtOpenGL>   // ���������� ������ QtOpenGL
#include <math.h>     // ���������� �������������� ����������
#include "scene3D.h"  // ���������� ������������ ���� scene3D.h
#include<qdebug.h>
#include<GL/GLU.h>
#include "Storage.h"
#include<QVector3D>
//#define  GLFW_INCLUDE_GLU
//#include <GLFW\glfw3.h>


bool ortho;
float rat;
int xPos;
int yPos;
float xDet,yDet,zDet;
int side;
bool xSide=true,ySide=true,zSide=true;
int light_sample=1;
int mapping=0;
QString str;
int xText;
int yText;
int nW,nH;

const static float pi=3.141593, k=pi/180; // ���������� ����������

GLfloat VertexArray[12][3]; // ����������� ������ ������
GLfloat ColorArray[12][3];  // ����������� ������ ������ ������
GLubyte IndexArray[20][3];  // ����������� ������ �������� ������

// ����������� ������ Scene3D
CScene3D::CScene3D(QWidget* parent/*= 0*/) : QGLWidget(parent) 
{ 
  // setFormat(QGLFormat(QGL::DepthBuffer)); // ������������ ����� �������
  // ����������� �� ��������� � ��������� 

  // ��������� �������� ������-������ ������
  xRot=-90; yRot=0; zRot=0; zTra=0;xTra=0;yTra=0; nSca=1; 
 
  setFocusPolicy(Qt::StrongFocus);
  //qDebug()<<"++++++++++++++";
    
  
    setMinimumHeight(50);
    setMinimumWidth(50);
    model = new CDrawSurfElem(this);
    initialOpengl();

  // �������� ������ ��������� �� ������ parent
} 

//
void CScene3D::initialOpengl()
{   
	qDebug()<<"INITIALOPENGL";
    centerInOpenGlWid = model->model_getCenter(model->model_getSize());

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //cam.setCamera(centerInOpenGlWid.x(),centerInOpenGlWid.y(),centerInOpenGlWid.z()*5,//+100,
    //              centerInOpenGlWid.x(),centerInOpenGlWid.y(),centerInOpenGlWid.z(),
    //              0.0,1.0,0.0
    //              );
    resizeGL(width(),height());

}
//
void CScene3D::initializeGL() // �������������
{
  // ���� ��� ������� ������ ����������� - ����� ������ ��� ����
  qglClearColor(Qt::white); 
  glEnable(GL_DEPTH_TEST);  // ������������� ����� �������� ������� ��������
  glShadeModel(GL_FLAT);    // ��������� ����� ����������� ������ 
  // ������������� �����, ����� �������� ������ ������� ����������� 
  glEnable(GL_CULL_FACE);  

  getVertexArray(); // ���������� ������ ������
  getColorArray();  // ���������� ������ ������ ������
  getIndexArray();  // ���������� ������ �������� ������

  glEnableClientState(GL_VERTEX_ARRAY); // ����������� ������� ������
  glEnableClientState(GL_COLOR_ARRAY);  // ����������� ������� ������ ������
  //qDebug()<<"-----------";
   glEnable(GL_LIGHTING);

    // ������������� ������ ���������

   glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);

    // �������������� ���������� �������� �

    // ��������� �����

    glEnable(GL_NORMALIZE);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_SMOOTH);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	//glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_BLEND);
}

void CScene3D::resizeGL(int nWidth, int nHeight) // ���� �������
{ 
	nW=nWidth;
	nH=nHeight;

	//height=nHeight;
  glMatrixMode(GL_PROJECTION); // ������������� ������� ������������ �������
  glLoadIdentity();            // ����������� ������������ ������� ��������� �������

  // ��������� ������ ���� ������� � ��� ������
  GLfloat ratio=(GLfloat)nHeight/(GLfloat)nWidth;
  rat=ratio;
  //qDebug()<<rat;

  // ������� ����
  if (nWidth>=nHeight)
	 { qDebug()<<nWidth<<nHeight;
    // ��������� ��������� ������������� ��������
    glOrtho(-1.0/ratio, 1.0/ratio, -1.0, 1.0, -10.0, 1.0); 
  ortho=true;}
	 else
    {glOrtho(-1.0, 1.0, -1.0*ratio, 1.0*ratio, -10.0, 1.0);      
  // ��������� ��������� (�����, ������, �������, ������, ��������, ������)
  ortho=false;}
 // qDebug()<<ortho;
  // ��������� ��������� ������������� ��������
  // glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 10.0);
  // ��������� ��������� (�����, ������, �������, ������, �������, �������)

  // ���� ���������
  glViewport(0, 0, (GLint)nWidth, (GLint)nHeight);
}

void CScene3D::paintGL() // ���������
{ 
  // glClear(GL_COLOR_BUFFER_BIT); // ���� ������� ��������� ������� ������ �������
  // ������� ������ ����������� � �������
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 

  //����� �����������
  if (mapping==0){
	  //����� ����������� � c���� GL_LINE
	  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);}
  else if (mapping==1){
	   //����� ����������� � c���� GL_FILL
	  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);}
  else if(mapping==2){
   //����� ����������� � c���� GL_POINT
	  glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
	 }

  // ������������� ��������� � ���������� ������� �������������
  glMatrixMode(GL_MODELVIEW); 
 
  // ��������� ��������� ������� �������������
  glLoadIdentity(); 
  //qDebug()<<screen2world(1.0,1.0);
  QVector3D ctr=screen2world(60,nH-60);
  qDebug()<<"CTRBKBKJBBKBJ"<<ctr.z();
 // float nS=0.95;
  glPushMatrix();
 /* glScalef(nS,nS, nS);
  glTranslatef(0.0,0.0,7.0);*/
  glDisable (GL_LIGHTING);
  drawAxis(ctr,xRot,yRot,zRot);   // ��������� ���� ���������
  
  glPopMatrix();

  glEnable (GL_LIGHTING);
  //����
  GLfloat material_diffuse[] = {0.5, 0.5, 0.5, 0.5};

	  glEnable(GL_COLOR_MATERIAL);
      glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, material_diffuse);

      // ��������� ���������� �����

      if (light_sample == 1)

      {

            // ������������ �������� �����

            GLfloat light0_diffuse[] = {1.0, 1.0, 1.0};

            GLfloat light0_direction[] = {0.0, 0.0, -1.0, 0.0};

            glEnable(GL_LIGHT0);

            glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);

            glLightfv(GL_LIGHT0, GL_POSITION, light0_direction);

      }

      if (light_sample == 2)

      {

            // �������� �������� �����

            // �������� ������������� � �����������

            // ��������� (�� ���������)

            GLfloat light1_diffuse[] = {0.4, 0.7, 0.2};

            GLfloat light1_position[] = {0.0, 0.0,-1.0, 1.0};

            glEnable(GL_LIGHT1);

            glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);

            glLightfv(GL_LIGHT1, GL_POSITION, light1_position);

      }

      if (light_sample == 3)

      {

            // �������� �������� �����

            // �������� ������������� � �����������

            // ������ �������� f(d) = 1.0 / (0.4 * d * d + 0.2 * d)

            GLfloat light2_diffuse[] = {0.4, 0.7, 0.2};

            GLfloat light2_position[] = {0.0, 0.0, -1.0, 1.0};

            glEnable(GL_LIGHT2);

            glLightfv(GL_LIGHT2, GL_DIFFUSE, light2_diffuse);

            glLightfv(GL_LIGHT2, GL_POSITION, light2_position);

            glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, 0.0);

            glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, 0.2);

            glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, 0.4);

      }

      if (light_sample == 4)

      {

            // ���������

            // �������� ������������� � �����������

            // ��������� (�� ���������)

            // �������� ���� ��� ������� 30 ��������

            // ����������� �� ����� ���������

            GLfloat light3_diffuse[] = {0.4, 0.7, 0.2};

            GLfloat light3_position[] = {0.0, 0.0, -1.0, 1.0};

            GLfloat light3_spot_direction[] = {0.0, 0.0, -1.0};

            glEnable(GL_LIGHT3);

            glLightfv(GL_LIGHT3, GL_DIFFUSE, light3_diffuse);

            glLightfv(GL_LIGHT3, GL_POSITION, light3_position);

            glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, 30);

            glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, light3_spot_direction);

      }

      if (light_sample == 5)

      {

            // ���������

            // �������� ������������� � �����������

            // ��������� (�� ���������)

            // �������� ���� ��� ������� 30 ��������

            // ����������� �� ����� ���������

            // ������� ������� �������� ������������� ��� ����������

            GLfloat light4_diffuse[] = {0.4, 0.7, 0.2};

            GLfloat light4_position[] = {0.0, 0.0, -1.0, 1.0};

            GLfloat light4_spot_direction[] = {0.0, 0.0, -1.0};

            glEnable(GL_LIGHT4);

            glLightfv(GL_LIGHT4, GL_DIFFUSE, light4_diffuse);

            glLightfv(GL_LIGHT4, GL_POSITION, light4_position);

            glLightf(GL_LIGHT4, GL_SPOT_CUTOFF, 30);

            glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, light4_spot_direction);

            glLightf(GL_LIGHT4, GL_SPOT_EXPONENT, 15.0);

      }

      if (light_sample == 6)

      {

            // ��������� ���������� �����

            GLfloat light5_diffuse[] = {1.0, 0.0, 0.0};

            GLfloat light5_position[] = {0.5 * cos(0.0), 0.5 * sin(0.0), -1.0, 1.0};

            glEnable(GL_LIGHT5);

            glLightfv(GL_LIGHT5, GL_DIFFUSE, light5_diffuse);

            glLightfv(GL_LIGHT5, GL_POSITION, light5_position);

            glLightf(GL_LIGHT5, GL_CONSTANT_ATTENUATION, 0.0);

            glLightf(GL_LIGHT5, GL_LINEAR_ATTENUATION, 0.4);

            glLightf(GL_LIGHT5, GL_QUADRATIC_ATTENUATION, 0.8);

           
      }

	   if (light_sample == 7)

	   {
		 GLfloat light6_diffuse[] = {0.0, 1.0, 0.0};

            GLfloat light6_position[] = {0.5 * cos(2 * pi / 3), 0.5 * sin(2 * pi / 3), 1.0, 1.0};

            glEnable(GL_LIGHT6);

            glLightfv(GL_LIGHT6, GL_DIFFUSE, light6_diffuse);

            glLightfv(GL_LIGHT6, GL_POSITION, light6_position); 

            glLightf(GL_LIGHT6, GL_CONSTANT_ATTENUATION, 0.0);

            glLightf(GL_LIGHT6, GL_LINEAR_ATTENUATION, 0.4);

            glLightf(GL_LIGHT6, GL_QUADRATIC_ATTENUATION, 0.8);

            GLfloat light7_diffuse[] = {0.0, 0.0, 1.0};

            GLfloat light7_position[] = {0.5 * cos(4 * pi / 3), 0.5 * sin(4 * pi / 3), 1.0, 1.0};

            glEnable(GL_LIGHT7);

            glLightfv(GL_LIGHT7, GL_DIFFUSE, light7_diffuse);

            glLightfv(GL_LIGHT7, GL_POSITION, light7_position); 

            glLightf(GL_LIGHT7, GL_CONSTANT_ATTENUATION, 0.0);

            glLightf(GL_LIGHT7, GL_LINEAR_ATTENUATION, 0.4);

            glLightf(GL_LIGHT7, GL_QUADRATIC_ATTENUATION, 0.8);
	   }
	   
	   if (light_sample == 0)
	   {glDisable(GL_LIGHTING);}
 
 

	   part();
//
	    glLoadIdentity();
 glScalef(nSca,nSca, nSca);        // ���������������
 glTranslatef(xDet,yDet,zDet);


 glTranslatef(xTra, -zTra, yTra);    // ����������     
  
 glRotatef(xRot, 1.0f, 0.0f, 0.0f); // ������� ������ ��� X         
 glRotatef(yRot, 0.0f, 1.0f, 0.0f); // ������� ������ ��� Y
 glRotatef(zRot, 0.0f, 0.0f, 1.0f); // ������� ������ ��� Z


 //�������� ������
 glPushMatrix();
 qDebug()<<"Loading_MODEL";
   // model->model_draw();
  glPopMatrix();
//



   qDebug()<<xRot<<zRot<<yRot;
  //drawAxis( );   // ��������� ���� ���������
   drawFigure(); // ���������� ������
   qDebug()<<screen2world(1.0,1.0);
   qDebug()<<world2screen(1.0,1.0,1.0);
   str="����� ����� ���� ���� �������";

   /*int xText=world2screen(0.0,0.0,0.75).x();
   int yText=world2screen(0.0,0.0,0.75).y();*/

   
   xText=world2screen(0.0,0.0,-0.75).x();
   yText=world2screen(0.0,0.0,-0.75).y();

   renderText(xText, yText, str, QFont("Times", 12, QFont::Normal));
  /* for (int i=0;i<11;i++){
	   int xText=world2screen(VertexArray[i][0],VertexArray[i][1],VertexArray[i][2]).x();
	   int yText=world2screen(VertexArray[i][0],VertexArray[i][1],VertexArray[i][2]).y();
	   renderText(xText, yText, str, QFont("Times", 12, QFont::Normal));
   }*/
   
   qDebug()<<mapping;

   CStorage *storage = &CStorage::instance();
  for (int i=0; i<storage->elemContainer.size(); i++)
  {
    storage->elemContainer[i]->Draw();
  }

    glDisable(GL_COLOR_MATERIAL);
	
	glDisable(GL_LIGHT0);

	glDisable(GL_LIGHT1);

	glDisable(GL_LIGHT2);

	glDisable(GL_LIGHT3);

	glDisable(GL_LIGHT4);

	glDisable(GL_LIGHT5);

	glDisable(GL_LIGHT6);

	glDisable(GL_LIGHT7);
}  



void CScene3D::mousePressEvent(QMouseEvent* pe) // ������� ������� ����
{
  // ��� ������� ������������� ������ ���� ���������� ptrMousePosition 
  // ����� ��������� ���������� ��������� ���� 
  ptrMousePosition = pe->pos();  

   //ptrMousePosition = (*pe).pos(); // ����� � ��� ��������         
   qDebug()<<ptrMousePosition;
  //qDebug()<<-ptrMousePosition.y()+height()/2;
} 

void CScene3D::mouseReleaseEvent(QMouseEvent* pe) // ������� ������� ����
{ 
  // ��������� �������, ������� ������ ����������� ��� ������� ������� ����            
} 

// ��������� ��������� ������� ����
void CScene3D::mouseMoveEvent(QMouseEvent* pe) 
{   
  // ���������� ����� ��������
  xRot += 180.0/nSca*nSca*(pe->y()-ptrMousePosition.y())/height();
  int alfa=15;
  int ip=180;
  int xR=int(xRot);
 /* if(pe->y()>=nH/2)
  xR-=((pe->y()-nH/2)/nH)*10;
  else xR+=((pe->y()-nH/2)/nH)*10;*/

  qDebug()<<"Y="<<pe->y()<<"xR"<<xR;
  if(xR>=ip+alfa && xR<=2*ip-alfa||xR>=-ip+alfa && xR<=-alfa)
	zRot += 180/nSca*nSca*(GLfloat)(pe->x()-ptrMousePosition.x())/width(); 
  else if(xR>=alfa && xR<=ip-alfa||xR>=-2*ip+alfa && xR<=-ip-alfa)
	zRot -= 180/nSca*nSca*(GLfloat)(pe->x()-ptrMousePosition.x())/width(); 
  else if(xR>-alfa && xR<alfa|| xR>2*ip-alfa || xR<-2*ip+alfa)
	yRot += 180/nSca*nSca*(GLfloat)(pe->x()-ptrMousePosition.x())/width(); 
  else if(xR>ip-alfa && xR<ip+alfa||xR>-ip-alfa && xR<-ip+alfa)
	yRot -= 180/nSca*nSca*(GLfloat)(pe->x()-ptrMousePosition.x())/width(); 


  
  ptrMousePosition = pe->pos();

  updateGL(); // ���������� �����������
}

// �������� ������� ����
void CScene3D::wheelEvent(QWheelEvent* pe) 
{ 
  if ((pe->delta())>0) scale_plus(); else if ((pe->delta())<0) scale_minus();   
  /* gluLookAt(0.5, 0.0, 1.0, // ��������� ����, ������ "��"
0.0, 0.0, 0.0, // ����, ������ "��"
0.0, 1.0, 0.0); // ���� ����������
*/
   float xCam,yCam,zCam;
   ptrMousePosition = pe->pos();
   xPos=ptrMousePosition.x()-width()/2;
   yPos=-ptrMousePosition.y()+height()/2;


   zCam=-cos(zRot*pi/180)*sin(xRot*pi/180);
   yCam=cos(xRot*pi/180);
   xCam=-sin(zRot*pi/180);

   xDet=-xPos*xCam/100*nSca;
   yDet=-yPos*yCam/100*nSca;
   zDet=0;
   
   qDebug()<<zRot;
   qDebug()<<xRot;

   qDebug()<<xCam;
   qDebug()<<yCam;
   qDebug()<<zCam;


   /*int PosX=xPos-width()/2;
	int  PosY=-yPos+height()/2;
   */
/*  qDebug()<<ptrMousePosition.x();
  qDebug()<<ptrMousePosition.y();*/
  //glTranslatef(ptrMousePosition.x()/500, ptrMousePosition.y()/600, 0.0f);  
  updateGL(); // ���������� �����������          
}

// ������� ������������ �������
void CScene3D::keyPressEvent(QKeyEvent* pe) 
{  
  switch (pe->key())
  {         
  case Qt::Key_Plus:  
    scale_plus();     // ���������� �����
    break;

  case Qt::Key_Equal:  
    scale_plus();     // ���������� �����   
    break;

  case Qt::Key_Minus: 
    scale_minus();    // ��������� �� �����
    break;

 // case Qt::Key_Up: 
	//  if(zSide==true)
 //   rotate_up();      // ��������� ����� �����
	// else
	//rotate_down();    // ��������� ����� ����
 //   break;

 // case Qt::Key_Down:  
 //    if(zSide==false)
 //   rotate_up();      // ��������� ����� �����
	// else
	//rotate_down();    // ��������� ����� ����
 //   break;         

 // case Qt::Key_Left:  
	//  if(xSide==true)
 //   rotate_left();     // ��������� ����� �����
	//  else
 //   rotate_right();
 //   break;

 // case Qt::Key_Right:  
	//  if(xSide==true)
 //   rotate_right();   // ��������� ����� ������
	// else
	//rotate_left();
 //   break; 

 // case Qt::Key_V:  
	//  if(ySide==true)
 //   rotate_pull();
	// else
	//rotate_push(); 	  
 //   break;

 // case Qt::Key_B:  
	// if(ySide==false)
 //   rotate_pull();
	// else
	//rotate_push(); 
 //   break; 

	case Qt::Key_Up: 
    rotate_up();      // ��������� ����� �����
    break;

  case Qt::Key_Down:  
	rotate_down();    // ��������� ����� ����
    break;         

  case Qt::Key_Left:  
    rotate_left();     // ��������� ����� �����
    break;

  case Qt::Key_Right:  
    rotate_right();   // ��������� ����� ������
    break; 

  case Qt::Key_V:  
    rotate_pull();
    break;

  case Qt::Key_B:  
	rotate_push(); 
    break; 

  case Qt::Key_S:
    translate_down(); // ������������� ����� ����
    break;  

  case Qt::Key_W:
    translate_up();   // ������������� ����� �����
    break; 

	case Qt::Key_A:
    translate_left(); // ������������� ����� �����
    break;  

  case Qt::Key_D:
    translate_right();   // ������������� ����� ������
    break; 
	
  case Qt::Key_Z:
    translate_pull(); // ������������� ����� �� ����
    break;  

  case Qt::Key_X:
    translate_push();   // ������������� ����� �� ����
    break; 


  case Qt::Key_Space:  // ������� �������
    defaultScene();   // ����������� �������� �� ���������
    break;

  case Qt::Key_1: // ������� "1"
    light_sample=1;    // �������� ����� �1
    break;

	case Qt::Key_2: // ������� "2"
    light_sample=2;    // �������� ����� �2
    break;

	case Qt::Key_3: // ������� "3"
    light_sample=3;    // �������� ����� �3
    break;  

	case Qt::Key_4: // ������� "4"
    light_sample=4;    // �������� ����� �4
    break;

	case Qt::Key_5: // ������� "5"
    light_sample=5;    // �������� ����� �5
    break;      

	case Qt::Key_6: // ������� "6"
    light_sample=6;    // �������� ����� �6
    break;   

	case Qt::Key_7: // ������� "7"
    light_sample=7;    // �������� ����� �7
    break;

	case Qt::Key_0: // ������� "7"
    light_sample=0;    // ���������� ���������� �����
    break;

	case Qt::Key_M: 
    mapping=mapping+1;
	mapping=mapping%3;   
    break; 
	
	case Qt::Key_Escape:
    this->close();  
    break;  
  }

  updateGL(); // ���������� �����������
}


void CScene3D::scale_plus() // ���������� �����
{
  nSca = nSca*1.1;
}

void CScene3D::scale_minus() // ��������� �� ����� 
{
  nSca = nSca/1.1;
}

void CScene3D::rotate_up() // ��������� ����� �����
{
  xRot -= 1.0;
}

void CScene3D::rotate_down() // ��������� ����� ����
{
  xRot += 1.0;
}

void CScene3D::rotate_left() // ��������� ����� �����
{
  zRot -= 1.0;
}

void CScene3D::rotate_right() // ��������� ����� ������
{
  zRot += 1.0;
}

void CScene3D::rotate_pull() // ��������� ����� �����
{
  yRot -= 1.0;
}

void CScene3D::rotate_push() // ��������� ����� ������
{
  yRot += 1.0;
}
void CScene3D::translate_down() // ������������� ����� ����
{
  zTra += 0.05;
}

void CScene3D::translate_up() // ������������� ����� �����
{
  zTra -= 0.05;
}

void CScene3D::translate_left() // ������������� ����� �����
{
  xTra -= 0.05;
}

void CScene3D::translate_right() // ������������� ����� ������
{
  xTra += 0.05;
}

void CScene3D::translate_pull() // ������������� ����� �� ����
{
  yTra += 0.05;
}

void CScene3D::translate_push() // ������������� ����� �� ����
{
  yTra -= 0.05;
}

void CScene3D::defaultScene() // ���������� ����� �� ���������
{
  xRot=-90; yRot=0; zRot=0; zTra=0;xTra=0;yTra=0; nSca=1;
}

void CScene3D::part() 
{

	 if(xRot>=360.0){
	  xRot-=360;}
  else if(xRot<=-360.0){
	  xRot+=360;}

  if(zRot>=360.0){
	  zRot-=360;}
  else if(zRot<=-360.0){
	  zRot+=360;}

   if(yRot>=360.0){
	  yRot-=360;}
  else if(yRot<=-360.0){
	  yRot+=360;}


 if((int)xRot%360>=-180 && (int)xRot%360<=0 || (int)xRot%360>=180) {
	 xSide=true;}
 else xSide=false;

 if((int)zRot%360>=-90 && (int)zRot%360<=90 || (int)zRot%360<=-270 || (int)zRot%360>=270) {
	 zSide=true;}
 else zSide=false;

 if((int)yRot%360>=-90 && (int)yRot%360<=90 || (int)yRot%360<=-270 || (int)yRot%360>=270 ) {
	 ySide=true;}
 else ySide=false;

}

void CScene3D::drawAxis(QVector3D center,GLfloat xRot,GLfloat yRot,GLfloat zRot) // ��������� ��� ���������
{
	glTranslatef((float)center.x(),(float)center.y(),(float)center.z());
	glRotatef(xRot, 1.0f, 0.0f, 0.0f); // ������� ������ ��� X         
	glRotatef(yRot, 0.0f, 1.0f, 0.0f); // ������� ������ ��� Y
	glRotatef(zRot, 0.0f, 0.0f, 1.0f); // ������� ������ ��� Z
	//qDebug()<<"fdhgshagvigdhiuhgdvcndviusdnvdsiun 0";
	glScalef(0.2,0.2,0.2);
	glPushMatrix();
	{
	  // ������������� ������ ����� ����������� � ��������
  glLineWidth(1.0f); 
  // �� ������ ������� ������ ����� 1 ������� �� ���������

  // ������������� ���� ����������� ����������
  glColor4f(1.00f, 0.00f, 0.00f, 1.0f); 
  // ��� x �������� �����
  glBegin(GL_LINES); // ���������� �����
  glVertex3f( 1.0f,  0.0f,  0.0f); // ������ �����
  glVertex3f(-1.0f,  0.0f,  0.0f); // ������ �����
  glEnd();  

  QColor halfGreen(0, 128, 0, 255);
  qglColor(halfGreen);
  glBegin(GL_LINES);
  // ��� y �������� �����
  glVertex3f( 0.0f,  1.0f,  0.0f);
  glVertex3f( 0.0f, -1.0f,  0.0f);

  glColor4f(0.00f, 0.00f, 1.00f, 1.0f);
  // ��� z ������ �����
  glVertex3f( 0.0f,  0.0f,  1.0f);
  glVertex3f( 0.0f,  0.0f, -1.0f);
 glEnd();

   GLUquadricObj *quadObj;
	quadObj= gluNewQuadric();
//	gluQuadricDrawStyle(quadObj,GLU_FILL);
	glClear(GL_COLOR_BUFFER_BIT|| GL_DEPTH_BUFFER_BIT);
	gluQuadricDrawStyle(quadObj,GLU_FILL);
	glPushMatrix();
	glColor3d(0,0,1);
	glTranslated(0,0,1);
	gluCylinder(quadObj,0.1,0,0.2,10,10);
	glPopMatrix();

	glPushMatrix();
	glColor3d(1,0,0);
	glTranslated(1,0,0);
	glRotated(90,0,1,0);
	gluCylinder(quadObj,0.1,0,0.2,10,10);
	glPopMatrix();

	glPushMatrix();
	glColor3d(0,1,0);
	glTranslated(0,-1,0);
	glRotated(90,1,0,0);
	gluCylinder(quadObj,0.1,0,0.2,10,10);
	glPopMatrix();
	}
 glPopMatrix();
}

void CScene3D::getVertexArray() // ���������� ������ ������
{
  GLfloat R=0.75; // ������ �����

  // ��������� �������� ��� ���������
  GLfloat a=4*R/sqrt(10+2*sqrt(double(5))); // ������� ���������
  GLfloat alpha=acos((1-a*a/2/R/R)); // ������ ���� �������� �� ���� 
  // cos(alpha)=(1-a*a/2/R/R)

  // ��������� ����� ���������
  //0 �����
  VertexArray[0][0]=0;   // x
  VertexArray[0][1]=0;   // y
  VertexArray[0][2]=R;   // z   

  //1 �����
  VertexArray[1][0]=R*sin(alpha)*sin(double(0));
  VertexArray[1][1]=R*sin(alpha)*cos(double(0)); 
  VertexArray[1][2]=R*cos(alpha);

  //2 �����
  VertexArray[2][0]=R*sin(alpha)*sin(72*k);
  VertexArray[2][1]=R*sin(alpha)*cos(72*k);
  VertexArray[2][2]=R*cos(alpha);

  //3 �����
  VertexArray[3][0]=R*sin(alpha)*sin(2*72*k);
  VertexArray[3][1]=R*sin(alpha)*cos(2*72*k);
  VertexArray[3][2]=R*cos(alpha); 

  //4 �����
  VertexArray[4][0]=R*sin(alpha)*sin(3*72*k);
  VertexArray[4][1]=R*sin(alpha)*cos(3*72*k);
  VertexArray[4][2]=R*cos(alpha);  

  //5 �����
  VertexArray[5][0]=R*sin(alpha)*sin(4*72*k);
  VertexArray[5][1]=R*sin(alpha)*cos(4*72*k);
  VertexArray[5][2]=R*cos(alpha);

  //6 �����
  VertexArray[6][0]=R*sin(pi-alpha)*sin(-36*k);
  VertexArray[6][1]=R*sin(pi-alpha)*cos(-36*k);
  VertexArray[6][2]=R*cos(pi-alpha);

  //7 �����
  VertexArray[7][0]=R*sin(pi-alpha)*sin(36*k);
  VertexArray[7][1]=R*sin(pi-alpha)*cos(36*k);
  VertexArray[7][2]=R*cos(pi-alpha);

  //8 �����
  VertexArray[8][0]=R*sin(pi-alpha)*sin((36+72)*k);
  VertexArray[8][1]=R*sin(pi-alpha)*cos((36+72)*k);
  VertexArray[8][2]=R*cos(pi-alpha);  

  //9 �����   
  VertexArray[9][0]=R*sin(pi-alpha)*sin((36+2*72)*k);
  VertexArray[9][1]=R*sin(pi-alpha)*cos((36+2*72)*k);
  VertexArray[9][2]=R*cos(pi-alpha);

  //10 �����
  VertexArray[10][0]=R*sin(pi-alpha)*sin((36+3*72)*k);
  VertexArray[10][1]=R*sin(pi-alpha)*cos((36+3*72)*k);
  VertexArray[10][2]=R*cos(pi-alpha); 

  //11 �����
  VertexArray[11][0]=0;
  VertexArray[11][1]=0;
  VertexArray[11][2]=-R;    
}

void CScene3D::getColorArray() // ���������� ������ ������ ������
{
  for (int i=0; i<12; i++)
  {      
    ColorArray[i][0]=0.1f*(qrand()%11); // R - ������� ������������
    ColorArray[i][1]=0.1f*(qrand()%11); // G - ������ ������������
    ColorArray[i][2]=0.1f*(qrand()%11); // B - ����� ������������
    // qrand()%11 - ��������������� ����� �� 0 �� 10 
  }
}

void CScene3D::getIndexArray()   // ���������� ������ ��������
{
  // 0 �����������
  IndexArray[0][0]=0; // ������ (�����) 1-�� �������
  IndexArray[0][1]=2; // ������ (�����) 2-�� �������
  IndexArray[0][2]=1; // ������ (�����) 3-�� �������

  // 1 �����������
  IndexArray[1][0]=0;
  IndexArray[1][1]=3;
  IndexArray[1][2]=2;

  // 2 �����������
  IndexArray[2][0]=0;
  IndexArray[2][1]=4;
  IndexArray[2][2]=3;

  // 3 �����������
  IndexArray[3][0]=0;
  IndexArray[3][1]=5;
  IndexArray[3][2]=4;

  // 4 �����������    
  IndexArray[4][0]=0;
  IndexArray[4][1]=1;
  IndexArray[4][2]=5;

  // 5 �����������
  IndexArray[5][0]=6;
  IndexArray[5][1]=1;
  IndexArray[5][2]=7;

  // 6 �����������
  IndexArray[6][0]=7;
  IndexArray[6][1]=1;
  IndexArray[6][2]=2;

  // 7 �����������
  IndexArray[7][0]=7;
  IndexArray[7][1]=2;
  IndexArray[7][2]=8;

  // 8 �����������
  IndexArray[8][0]=8;
  IndexArray[8][1]=2;
  IndexArray[8][2]=3;

  // 9 �����������
  IndexArray[9][0]=8;
  IndexArray[9][1]=3;
  IndexArray[9][2]=9;

  // 10 �����������
  IndexArray[10][0]=9;
  IndexArray[10][1]=3;
  IndexArray[10][2]=4;

  // 11 �����������
  IndexArray[11][0]=9;
  IndexArray[11][1]=4;
  IndexArray[11][2]=10;

  // 12 �����������
  IndexArray[12][0]=10;
  IndexArray[12][1]=4;
  IndexArray[12][2]=5;

  // 13 �����������
  IndexArray[13][0]=10;
  IndexArray[13][1]=5;
  IndexArray[13][2]=6;

  // 14 �����������
  IndexArray[14][0]=6;
  IndexArray[14][1]=5;
  IndexArray[14][2]=1;

  // 15 �����������
  IndexArray[15][0]=7;
  IndexArray[15][1]=11;
  IndexArray[15][2]=6;

  // 16 �����������
  IndexArray[16][0]=8;
  IndexArray[16][1]=11;
  IndexArray[16][2]=7;

  // 17 �����������
  IndexArray[17][0]=9;
  IndexArray[17][1]=11;
  IndexArray[17][2]=8;

  // 18 �����������
  IndexArray[18][0]=10;
  IndexArray[18][1]=11;
  IndexArray[18][2]=9;

  // 19 �����������
  IndexArray[19][0]=6;
  IndexArray[19][1]=11;
  IndexArray[19][2]=10; 
}

void CScene3D::drawFigure() // ��������� ������
{
  // ���������, ������ ����� ������� ������ � ������� ������
  glVertexPointer(3, GL_FLOAT, 0, VertexArray); 
  // ���������, ������ ����� ������� ������ � ������� ������ ������
  glColorPointer(3, GL_FLOAT, 0, ColorArray);  
  // ��������� ������� ������ � ��������, ������ �����������
 // glColor3f(0.0,0.0,0.0);
  glPointSize(5);
  glDrawElements(GL_TRIANGLES, 60, GL_UNSIGNED_BYTE, IndexArray);
}

QVector3D CScene3D:: screen2world(int x, int y)
{
	GLint viewport[4];
	GLdouble modelview[16];
	GLdouble projection[16];
	GLfloat winX, winY, winZ;
	GLdouble posX, posY, posZ;
	glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
	glGetDoublev(GL_PROJECTION_MATRIX, projection);
	glGetIntegerv(GL_VIEWPORT, viewport);
	winX = (float)x;
	winY = (float)viewport[3] - (float)y;
	glReadPixels(x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);
	gluUnProject(winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);
	QVector3D v(posX, posY, -posZ);
	return v;
}

QVector2D CScene3D:: world2screen(float x, float y,float z)
{
  GLint  viewport[4]; // ����� ��� ������ ���� ���������
  GLdouble mvmatrix[16], projmatrix[16]; // ����� ��� ������� �������������
  GLdouble winx, winy, winz; // ����� ��� ��������� ��������
 
  glGetIntegerv (GL_VIEWPORT, viewport); // ������� ������� ���� ���������
  glGetDoublev (GL_MODELVIEW_MATRIX, mvmatrix); // ������� ������� ������� ���������
  glGetDoublev (GL_PROJECTION_MATRIX, projmatrix); // ������� ������� ��������
  mvmatrix[13]=-mvmatrix[13];
  mvmatrix[1]=-mvmatrix[1];
  mvmatrix[2]=-mvmatrix[2];
  mvmatrix[9]=-mvmatrix[9];
	/*qDebug()<<"MODELVIEW";
  for (int i=0;i<16;i++)
  {qDebug()<<"VIEW"<<mvmatrix[i];}
  qDebug()<<"MODELVIEW";*/
  // ��������� 2D ������� 3D �����
  gluProject(x, y, -z, mvmatrix, projmatrix, viewport, &winx, &winy, &winz);
  QVector2D v(winx,winy);
  return v;
}