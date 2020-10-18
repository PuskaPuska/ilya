#ifndef SCENE3D_H 
#define SCENE3D_H

#include <QGLWidget> // ���������� ����� QGLWidget
#include <QVector3D>
#include <QVector2D>
#include "DrawSurfElem.h"


typedef struct lightingStruct{
    GLfloat ambient[4];
    GLfloat diffuse[4];
    GLfloat specular[4];
}lightingStruct;

typedef struct materialStruct{
    GLfloat ambient[4];
    GLfloat diffuse[4];
    GLfloat specular[4];
    GLfloat shininess;
}materialStruct;


class  CScene3D : public QGLWidget // ����� Scene3D ��������� ���������� ����� QGLWidget
{ 
	Q_OBJECT
public:
    explicit CScene3D(QWidget *parent = 0);

private: 
	CDrawSurfElem *model;

	QVector3D centerInOpenGlWid;
    QVector3D cameraInOpenGlWid;

    float *matrixForMouseRotate;
    QPointF lastPos;


	//int i;
  GLfloat xRot; // ���������� ������ ���� �������� ������ ��� X
  GLfloat yRot; // ���������� ������ ���� �������� ������ ��� Y   
  GLfloat zRot; // ���������� ������ ���� �������� ������ ��� Z
  GLfloat zTra; // ���������� ������ �������� ���������� ��� Z 
  GLfloat xTra; // ���������� ������ �������� ���������� ��� X
  GLfloat yTra; // ���������� ������ �������� ���������� ��� Y 
  GLfloat nSca; // ���������� �������� �� ��������������� �������
  QVector3D center;
  
  

  QPoint ptrMousePosition; // ���������� ��������� ����

  void scale_point();
  void scale_plus();     // ���������� �����
  void scale_minus();    // ��������� �� �����  
  void rotate_up();      // ��������� ����� �����
  void rotate_down();    // ��������� ����� ����
  void rotate_left();    // ��������� ����� �����
  void rotate_right();   // ��������� ����� ������
  void rotate_pull();    // ��������� ����� �����
  void rotate_push();   // ��������� ����� ������
  void translate_down(); // ������������� ����� ����
  void translate_up();   // ������������� ����� �����      
  void translate_left(); // ������������� ����� �����
  void translate_right();   // ������������� ����� ������
  void translate_pull(); // ������������� ����� �� ����
  void translate_push();   // ������������� ����� �� ����
  void defaultScene();   // ���������� ����� �� ���������
  void part();
 // void light(int i); //����� ��������� �����

  void drawAxis( QVector3D center,GLfloat xRot,GLfloat yRot,GLfloat zRot);       // ��������� ��� ���������

  void getVertexArray(); // ���������� ������ ������
  void getColorArray();  // ���������� ������ ������ ������
  void getIndexArray();  // ���������� ������ �������� ������      
  void drawFigure();     // ��������� ������
  QVector3D screen2world(int x, int y);
  QVector2D world2screen(float x, float y,float z);

protected:
  // ����� ��� ���������� �������������, ��������� � OpenGL 
  /*virtual*/ void initializeGL();         
  // ����� ���������� ��� ��������� �������� ���� �������            
  /*virtual*/ void resizeGL(int nWidth, int nHeight);  
  // �����, ����� ������ ������������ ���������� �������  
  /*virtual*/ void paintGL();                          

  // ����� ��������� ������� ���� ��� ������� ������� ����
  /*virtual*/ void mousePressEvent(QMouseEvent* pe); 
  // ����� ��������� ������� ���� ��� ����������� ����  
  /*virtual*/ void mouseMoveEvent(QMouseEvent* pe);  
  // ����� ��������� ������� ���� ��� ������� ������� ����  
  /*virtual*/ void mouseReleaseEvent(QMouseEvent* pe); 
  // ����� ��������� ������� �������� ���� 
  /*virtual*/ void wheelEvent(QWheelEvent* pe);  
  // ������ ��������� ������� ��� ������� ������������ �������       
  /*virtual*/ void keyPressEvent(QKeyEvent* pe);       

//public: 
//  CScene3D(QWidget* parent = 0); // ����������� ������
//  ~CScene3D();
//
//public: 
  //CScene3D(QWidget* parent = 0); // ����������� ������
 // void initialOpengl();
  
//signals:
    
//public slots:
//    void slot_recieveStl(QString path);
//    void slot_finishLoadStl();

    /*void slot_moveLeft();
    void slot_moveRight();
    void slot_moveUp();
    void slot_moveDown();*/

public:
	void initialOpengl();
    void setMaterial(materialStruct *material);
}; 
#endif 