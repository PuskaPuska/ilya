#ifndef SCENE3D_H 
#define SCENE3D_H

#include <QGLWidget> // подключаем класс QGLWidget
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


class  CScene3D : public QGLWidget // класс Scene3D наследует встроенный класс QGLWidget
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
  GLfloat xRot; // переменная хранит угол поворота вокруг оси X
  GLfloat yRot; // переменная хранит угол поворота вокруг оси Y   
  GLfloat zRot; // переменная хранит угол поворота вокруг оси Z
  GLfloat zTra; // переменная хранит величину трансляции оси Z 
  GLfloat xTra; // переменная хранит величину трансляции оси X
  GLfloat yTra; // переменная хранит величину трансляции оси Y 
  GLfloat nSca; // переменная отвечает за масштабирование объекта
  QVector3D center;
  
  

  QPoint ptrMousePosition; // координата указателя мыши

  void scale_point();
  void scale_plus();     // приблизить сцену
  void scale_minus();    // удалиться от сцены  
  void rotate_up();      // повернуть сцену вверх
  void rotate_down();    // повернуть сцену вниз
  void rotate_left();    // повернуть сцену влево
  void rotate_right();   // повернуть сцену вправо
  void rotate_pull();    // повернуть сцену влево
  void rotate_push();   // повернуть сцену вправо
  void translate_down(); // транслировать сцену вниз
  void translate_up();   // транслировать сцену вверх      
  void translate_left(); // транслировать сцену влево
  void translate_right();   // транслировать сцену вправо
  void translate_pull(); // транслировать сцену на себя
  void translate_push();   // транслировать сцену от себя
  void defaultScene();   // наблюдение сцены по умолчанию
  void part();
 // void light(int i); //Выбор источника света

  void drawAxis( QVector3D center,GLfloat xRot,GLfloat yRot,GLfloat zRot);       // построить оси координат

  void getVertexArray(); // определить массив вершин
  void getColorArray();  // определить массив цветов вершин
  void getIndexArray();  // определить массив индексов вершин      
  void drawFigure();     // построить фигуру
  QVector3D screen2world(int x, int y);
  QVector2D world2screen(float x, float y,float z);

protected:
  // метод для проведения инициализаций, связанных с OpenGL 
  /*virtual*/ void initializeGL();         
  // метод вызывается при изменении размеров окна виджета            
  /*virtual*/ void resizeGL(int nWidth, int nHeight);  
  // метод, чтобы заново перерисовать содержимое виджета  
  /*virtual*/ void paintGL();                          

  // метод обработки события мыши при нажатии клавиши мыши
  /*virtual*/ void mousePressEvent(QMouseEvent* pe); 
  // метод обработки события мыши при перемещении мыши  
  /*virtual*/ void mouseMoveEvent(QMouseEvent* pe);  
  // метод обработки событий мыши при отжатии клавиши мыши  
  /*virtual*/ void mouseReleaseEvent(QMouseEvent* pe); 
  // метод обработки событий колесика мыши 
  /*virtual*/ void wheelEvent(QWheelEvent* pe);  
  // методы обработки события при нажатии определенной клавиши       
  /*virtual*/ void keyPressEvent(QKeyEvent* pe);       

//public: 
//  CScene3D(QWidget* parent = 0); // конструктор класса
//  ~CScene3D();
//
//public: 
  //CScene3D(QWidget* parent = 0); // конструктор класса
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