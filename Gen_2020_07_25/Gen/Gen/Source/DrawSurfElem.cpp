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

#include "DrawSurfElem.h"
#include "Storage.h"
#include <QtOpenGL>   // подключаем модуль QtOpenGL
//#include <QtCore>     // подключаем модуль QtCore
#include <QTextStream>
#include <QDebug>
#include <QDateTime>




CDrawSurfElem::CDrawSurfElem(QObject *parent) :
    QObject(parent)
{   
    model_clear();
}

//CDrawSurfElem::CDrawSurfElem() : CBaseDrawElem()
//{
//  myParams = new CSurfElemParams();
//  SetCurParams(myParams);
//}
//
//CDrawSurfElem::~CDrawSurfElem()
//{
//}

/*int CDrawSurfElem::Draw()
{
  if (curParams == NULL)
    return -1;
  CSurfElemParams &tParams = *myParams;

  //glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  //glPushMatrix();       // сохраняем текущие координаты
  //glTranslated(tParams.center[0],tParams.center[1],tParams.center[2]);  // сдвигаемся по оси Х на единицу 
  //glColor3d(0,1,0);
  //gluSphere(0.5); // рисуем сферу в (1,0,0)  в абсолютных координатах
  //glPopMatrix();  // возвращаемся к старой системе координат
  //auxSwapBuffers();

  return 0;
}*/

//int CDrawSurfElem::ChangeParams(CBaseElemParams &params)
//{
//  if (curParams == NULL)
//    curParams = new CBaseElemParams;
//  CSurfElemParams &tParams = (CSurfElemParams&) params;
//  *myParams = tParams;
//  return 0;
//}

void CDrawSurfElem::ReadDataFromFile(QString path)
{
  qDebug()<<"Push mash";
  QFile file(path);
    if(file.open(QIODevice::ReadOnly))
    {
        QByteArray header = file.read(80);
        file.close();

        if (header.trimmed().startsWith("solid") && header.contains("\n"))
        {
            qDebug("start to read text");
            model_readText(path);
        }
        else
        {
            qDebug("huaile");
            model_readBinary(path);
        }
    }
    else
    {
        QMessageBox::information(0,tr("v kdv "),tr("vjdsvjjs"));
    }

//  return 0;
}

int CDrawSurfElem::WriteDataToFile(QString path)
{
  return 0;
}


void CDrawSurfElem::model_readText(QString path)
{
    model_clear();
	qDebug()<<"PATH__TEXT"<<path;
    QDateTime time = QDateTime::currentDateTime();

//    qDebug()<< time.toString("yyyy-MM-dd hh:mm:ss ddd"); //设置显示格式

    QFile file(path);
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QVector3D vn;
    QVector3D point1;
    QVector3D point2;
    QVector3D point3;
    QVector<QVector3D> triAngel;
    face *tempFace ;


    int count=0;

    QString line;
    QTextStream in(&file);
    line = in.readLine();                   // solid

    while(true)
    {
        line = in.readLine().trimmed();     //facet or endsolid
        if(line.trimmed().startsWith("endsolid"))
        {
            break;
        }
        vn = getCoordinateFromString(line);
        line = in.readLine();               //outer loop
        line = in.readLine().trimmed();     //vertex 1
        point1 = getCoordinateFromString(line);
        line = in.readLine().trimmed();     //vertex 2
        point2 = getCoordinateFromString(line);
        line = in.readLine().trimmed();     //vertex 3
        point3 = getCoordinateFromString(line);
        line = in.readLine();               //endloop
        line = in.readLine();               //endfacet

        triAngel.clear();
        triAngel.append(point1);
        triAngel.append(point2);
        triAngel.append(point3);
       
        model_getSizeWhileReadPoint(point1);
        model_getSizeWhileReadPoint(point2);
        model_getSizeWhileReadPoint(point3);

        tempFace = new face;
        tempFace->setNormalVector(vn);
        tempFace->setTriAngle(triAngel);

        faceList.append(tempFace);
        count++;
    }


    time = QDateTime::currentDateTime();
//    qDebug()<< time.toString("yyyy-MM-dd hh:mm:ss ddd");
    file.close();
}


void CDrawSurfElem::model_readBinary(QString path)
{
    model_clear();
    //
	qDebug()<<"PATH__BIN"<<path;
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
        return;
    QVector3D vn;
    QVector3D point1;
    QVector3D point2;
    QVector3D point3;
    QVector<QVector3D> triAngel;
    face *tempFace;

    file.seek(0);
    QDataStream in(&file);
    in.setByteOrder(QDataStream::LittleEndian);
    in.setFloatingPointPrecision(QDataStream::SinglePrecision);

    quint32 n;
    quint16 control_bytes;
    quint32 count = 0;

    file.seek(80);
    in >> n;
    qDebug() << n << "triangles in the model.";

    float nx, ny, nz, x1, x2, x3, y1, y2, y3, z1, z2, z3;

    while (count < n)
    {
        file.seek(84+count*50+0+0);
        in >> nx;
        file.seek(84+count*50+0+4);
        in >> ny;
        file.seek(84+count*50+0+8);
        in >> nz;
        file.seek(84+count*50+12+0);
        in >> x1;
        file.seek(84+count*50+12+4);
        in >> y1;
        file.seek(84+count*50+12+8);
        in >> z1;
        file.seek(84+count*50+24+0);
        in >> x2;
        file.seek(84+count*50+24+4);
        in >> y2;
        file.seek(84+count*50+24+8);
        in >> z2;
        file.seek(84+count*50+36+0);
        in >> x3;
        file.seek(84+count*50+36+4);
        in >> y3;
        file.seek(84+count*50+36+8);
        in >> z3;
        file.seek(84+count*50+48);
        in >> control_bytes;

        if (control_bytes == 0 && in.status() == QDataStream::Ok)
        {
            vn = QVector3D(nx,ny,nz);
            point1= QVector3D(x1,y1,z1);
            point2= QVector3D(x2,y2,z2);
            point3= QVector3D(x3,y3,z3);

            triAngel.clear();
            triAngel.append(point1);
            triAngel.append(point2);
            triAngel.append(point3);

            
            model_getSizeWhileReadPoint(point1);
            model_getSizeWhileReadPoint(point2);
            model_getSizeWhileReadPoint(point3);

            tempFace = new face;
            tempFace->setNormalVector(vn);
            tempFace->setTriAngle(triAngel);

            faceList.append(tempFace);

            count++;
        }
        else
        {
            qDebug() << "File read error when readStlBinaryFormat"
                     << (int) in.status();

        }
    }
    file.close();
    qDebug()<<tr("finish load");
    qDebug()<<faceList.size();
}

void CDrawSurfElem::model_clear()
{
    faceList.clear();
    size.smallX = 0;
    size.largeX = 0;
    size.smallY = 0;
    size.largeY = 0;
    size.smallZ = 0;
    size.largeZ = 0;
}

void CDrawSurfElem::model_draw()
{

	qDebug()<<"MODEL DRAW";
    QVector<QVector3D> triAngle;
    QVector3D normal;
    GLfloat normalVector[3];
    for(int i=0; i<faceList.size(); i++)
    {
        normal = faceList.at(i)->getNormalVector();
        normal.normalize();
        normalVector[0] = normal.x();
        normalVector[1] = normal.y();
        normalVector[2] = normal.z();
        triAngle = faceList.at(i)->getTriAngle();
      glBegin(GL_TRIANGLES);
        glNormal3fv(normalVector);
        glVertex3f(triAngle.at(0).x(),triAngle.at(0).y(),triAngle.at(0).z() );
        glVertex3f(triAngle.at(1).x(),triAngle.at(1).y(),triAngle.at(1).z() );
        glVertex3f(triAngle.at(2).x(),triAngle.at(2).y(),triAngle.at(2).z() );
      glEnd();
    }

//        glBegin(GL_TRIANGLES);								// Drawing Using Triangles
//            glVertex3f( 0.0f, 1.0f, 0.0f);					// Top
//            glVertex3f(-1.0f,-1.0f, 0.0f);					// Bottom Left
//            glVertex3f( 1.0f,-1.0f, 0.0f);					// Bottom Right
//        glEnd();
}

void CDrawSurfElem::model_test()
{
    QVector<QVector3D> test;
    if(faceList.isEmpty())
        return;
    for(int i=0;i<10;i++)
    {
        test = faceList.at(i)->getTriAngle();
    }
}

modelSize CDrawSurfElem::model_getSize()
{
    return size;
}

void CDrawSurfElem::model_getSizeWhileReadPoint(QVector3D point)
{
	qDebug()<<"GET_SIZE_MODEL";
    float pointX = point.x();
    float pointY = point.y();
    float pointZ = point.z();
   //
   if(pointX < size.smallX)
       size.smallX = pointX;
   else if(pointX > size.largeX)
       size.largeX = pointX;
   //
   if(pointY < size.smallY)
       size.smallY = pointY;
   else if(pointY > size.largeY)
       size.largeY = pointY;
   //
   if(pointZ < size.smallZ)
       size.smallZ = pointZ;
   else if(pointZ > size.largeZ)
       size.largeZ = pointZ;
}

QVector3D CDrawSurfElem::model_getCenter(modelSize size)
{
	qDebug()<<"GET_CENTER";
    QVector3D center;
    center.setX( (size.largeX + size.smallX)/2 );
    center.setY( (size.largeY + size.smallY)/2 );
    center.setZ( (size.largeZ + size.smallZ)/2 );
    return center;
}

int CDrawSurfElem::model_getFacesCount()
{
    return faceList.size();
}

QVector3D CDrawSurfElem::getCoordinateFromString(QString line)
{
	qDebug()<<"GET_COORD";
     QVector3D coordinate;
     QVector<float> point;

     QStringList strList = line.split(" ");

    int count = strList.size();
    for(int i=count-3;i<count;i++)
    {
        point.append(strList[i].toDouble());

    }
    coordinate.setX(point[0]);
    coordinate.setY(point[1]);
    coordinate.setZ(point[2]);
    return coordinate;
}
