//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
// Название модуля: DrawSurfElem
//
// Описание: содержит класса отображения элемента Поверхность
//
// Автор: Никитин Вячеслав
//
// Дата создания: 23.07.2020
//
// Дата последнего изменения: 23.07.2020
//------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////

#ifndef DRAWSURFELEM_H
#define DRAWSURFELEM_H

//#include "BaseDrawElem.h"
//#include "SurfElemParams.h"
#include <QObject>
#include <face.h>
#include <QList>
#include <QFile>
#include <QMessageBox>
#include <QtOpenGL>
#include <GL/glu.h>

typedef struct modelSize{
   
    float smallX;
    float largeX;
    float smallY;
    float largeY;
    float smallZ;
    float largeZ;
} modelSize;

class CDrawSurfElem : public QObject
{
	 Q_OBJECT
public:
    explicit CDrawSurfElem(QObject *parent = 0);

public:
  /*CDrawSurfElem();
  ~CDrawSurfElem();

  CSurfElemParams *myParams;*/

  //virtual int Draw();
  //virtual int ChangeParams(CBaseElemParams &params);
  void ReadDataFromFile(QString path);
  virtual int WriteDataToFile(QString path);
   
  void model_readText(QString path);
  void model_readBinary(QString path);
  void model_clear();
  void model_draw();
  void model_test();
  modelSize model_getSize();
  void model_getSizeWhileReadPoint(QVector3D point);
  QVector3D model_getCenter(modelSize size);

  int model_getFacesCount();

private:
    QVector3D getCoordinateFromString(QString line);

private:
    QList<face*> faceList;
    modelSize size;
    QVector3D center;
};

#endif