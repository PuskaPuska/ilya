//////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
// Название модуля: Storage
//
// Описание: хранилище настроек и результатов
//
// Автор: Никитин Вячеслав
//
// Дата создания: 10.05.2020
//
// Дата последнего изменения: 10.05.2020
//------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////

//---------------------------------------------------------------------------

#include <stdio.h>
#include <list>
#include <windows.h>

#include "Storage.h"
#include "Functional.h"

using namespace std;

CStorage *CStorage::curStorData = NULL;

//---------------------------------------------------------------------------
CStorage::CStorage()
{

  applicationPath = NULL;
  applicationName = NULL;
}

CStorage::~CStorage()
{
  Free();
  CStorage::curStorData = NULL;

  if (applicationPath)
    delete [] applicationPath;
  applicationPath = NULL;

  if (applicationName)
    delete [] applicationName;
  applicationName = NULL;
}

CStorage &CStorage::instance()
{
    if (curStorData == NULL)
        curStorData = new CStorage;

    return *curStorData;
}

//---------------------------------------------------------------------------
// функция-деструктор
void CStorage::Free()
{
}

// функция записи данных в файл
int CStorage::SaveDataFCI(const char *fileName, double *arrayX, double *arrayY, double *values, int countX, int countY, const char *sourceName)
{
  int iFileHandle;

  try
  {
    if (arrayX == NULL)
      return -1;

    if (arrayY == NULL)
      return -2;

    if (values == NULL)
      return -3;

    // временный массив для преобразованя строки в число
    char temp[256] ;
    int j = 0;
    int i = 0;
    int n = 0;

    FILE *file;

    // создаем файл
    //iFileHandle = FileCreate(fileName);

    file = fopen( fileName, "w" ); 

    if (file == NULL)
      return -1;

    // записываем название данных
    sprintf(temp,"%s\r\n", sourceName);

    fputs( temp, file );
    for (i=0; i<countX; i++)
    {
      if (i == countX-1)
      {
        if (fabs(arrayX[i]) < 0.0000001 ||
            fabs(arrayX[i]) > 1000000)
          sprintf(temp, "%.6e\r\n", arrayX[i]);
        else
          sprintf(temp, "%.6f\r\n", arrayX[i]);
      }
      else
      {
        if (fabs(arrayX[i]) < 0.0000001 ||
            fabs(arrayX[i]) > 1000000)
          sprintf(temp, "%.6e\t", arrayX[i]);
        else
          sprintf(temp, "%.6f\t", arrayX[i]);
      }
      //FileWrite(iFileHandle, temp, sizeof(char)*strlen(temp));
      fputs( temp, file );
    }

    for (i=countY-1; i>=0; i--)
    {
      if (fabs(arrayY[i]) < 0.0000001 ||
          fabs(arrayY[i]) > 1000000)
        sprintf(temp, "%.6e\t", arrayY[i]);
      else
        sprintf(temp, "%.6f\t", arrayY[i]);

      //FileWrite(iFileHandle, temp, sizeof(char)*strlen(temp));
      fputs( temp, file );

      for (j=0; j<countX; j++)
      {
        if (j == countX-1)
        {
          if (fabs(values[n]) < 0.0000001 ||
              fabs(values[n]) > 1000000)
            sprintf(temp, "%.6e\r\n", values[n]);
          else
          sprintf(temp, "%.6f\r\n", values[n]);
        }
        else
        {
          if (fabs(values[n]) < 0.0000001 ||
              fabs(values[n]) > 1000000)
            sprintf(temp, "%.6e\t", values[n]);
          else
          sprintf(temp, "%.6f\t", values[n]);
        }
        //FileWrite(iFileHandle, temp, sizeof(char)*strlen(temp));
        fputs( temp, file );

        n++;
      }
    }

    // закрываем файл
    //FileClose(iFileHandle);
    fclose( file );
  }
  catch(...)
  {
      //Application->MessageBox("Can't perform one of the following file operations: Open, Seek, Read, Close.", "File Error", IDOK);
      return -1;
  }
  return 0;
}

int CStorage::SaveArrayIn2Col(const char *fileName, char *dataName, double *array, int count)
{
  int iFileHandle;

  try
  {
    // временный массив для преобразованя строки в число
    char temp[256] ;
    int i = 0;
    int n = count/2;

    // создаем файл
    //iFileHandle = FileCreate(fileName);
    FILE *file;
    file = fopen( fileName, "w" ); 

    // записываем название данных
    sprintf(temp,"%s\n", dataName);

    //FileWrite(iFileHandle, temp, sizeof(char)*strlen(temp));
    fputs( temp, file );

    for (i=0; i<n; i++)
    {
      if (fabs(array[i]) < 0.0000001 ||
          fabs(array[i]) > 1000000)
        sprintf(temp, "%.6e\t", array[i]);
      else
        sprintf(temp, "%.6f\t", array[i]);

      //FileWrite(iFileHandle, temp, sizeof(char)*strlen(temp));
      fputs( temp, file );

      if (fabs(array[i+n]) < 0.0000001 ||
          fabs(array[i+n]) > 1000000)
        sprintf(temp, "%.6e\n", array[i+n]);
      else
        sprintf(temp, "%.6f\n", array[i+n]);

      //FileWrite(iFileHandle, temp, sizeof(char)*strlen(temp));
      fputs( temp, file );
    }

    // закрываем файл
    //FileClose(iFileHandle);
    fclose( file );
  }
  catch(...)
  {
      //Application->MessageBox("Can't perform one of the following file operations: Open, Seek, Read, Close.", "File Error", IDOK);
      return -1;
  }
  return 0;
}

// функция записи данных в файл в три столбца из массива
int CStorage::SaveArrayIn3Col(const char *fileName, char *dataName, double *array, int count)
{
  int iFileHandle;

  try
  {
    // временный массив для преобразованя строки в число
    char temp[256] ;
    int i = 0;
    int n = count/3;

    // создаем файл
    //iFileHandle = FileCreate(fileName);
    FILE *file;
    file = fopen( fileName, "w" ); 

    // записываем название данных
    sprintf(temp,"%s\n", dataName);

    //FileWrite(iFileHandle, temp, sizeof(char)*strlen(temp));
    fputs( temp, file );

    for (i=0; i<n; i++)
    {
      if (fabs(array[i]) < 0.0000001 ||
          fabs(array[i]) > 1000000)
        sprintf(temp, "%.6e\t", array[i]);
      else
        sprintf(temp, "%.6f\t", array[i]);

      //FileWrite(iFileHandle, temp, sizeof(char)*strlen(temp));
      fputs( temp, file );

      if (fabs(array[i+n]) < 0.0000001 ||
          fabs(array[i+n]) > 1000000)
        sprintf(temp, "%.6e\t", array[i+n]);
      else
        sprintf(temp, "%.6f\t", array[i+n]);

      //FileWrite(iFileHandle, temp, sizeof(char)*strlen(temp));
      fputs( temp, file );

      if (fabs(array[i+n+n]) < 0.0000001 ||
          fabs(array[i+n+n]) > 1000000)
        sprintf(temp, "%.6e\n", array[i+n+n]);
      else
        sprintf(temp, "%.6f\n", array[i+n+n]);

      //FileWrite(iFileHandle, temp, sizeof(char)*strlen(temp));
      fputs( temp, file );
    }

    // закрываем файл
    //FileClose(iFileHandle);
    fclose( file );
  }
  catch(...)
  {
      //Application->MessageBox("Can't perform one of the following file operations: Open, Seek, Read, Close.", "File Error", IDOK);
      return -1;
  }
  return 0;
}

// функция загрузки данных из файла
int CStorage::LoadDataFCI(const char *fileName)
{
  int iFileHandle;
  int iFileLength;
  int iBytesRead;
  char *pszBuffer;

  try
  {
    // открываем файл
    //iFileHandle = FileOpen(fileName, fmOpenRead);
    FILE *file;
    file = fopen( fileName, "rb" ); 
    // определяем длину
    //iFileLength = FileSeek(iFileHandle,0,2);
    if (file)
    {
      fseek (file, 0, SEEK_END);
      iFileLength = ftell(file);
      //fclose (file);
    }
    else
      return -1;

    // идем в начало файла
    //FileSeek(iFileHandle,0,0);
    fseek (file, 0, SEEK_SET);
    // выделяем буфер
    pszBuffer = new char[iFileLength+1];
    // читаем данные
    //iBytesRead = FileRead(iFileHandle, pszBuffer, iFileLength);
    iBytesRead = fread(pszBuffer, sizeof(char), iFileLength, file);
    // закрываем файл
    //FileClose(iFileHandle);
    fclose( file );

    // временный массив для преобразованя строки в число
    char temp[256] ;
    int j = 0;
    int i = 0;
    int n;

    temp[0] = '\0';

    // вычисляем количестово изолиний
    while (pszBuffer[i] != '\r')
    {
      temp[i] = pszBuffer[i];
      i++;
    }

  }
  catch(...)
  {
    //Application->MessageBox("Can't perform one of the following file operations: Open, Seek, Read, Close.", "File Error", IDOK);
  }

  return 0;
}

int CStorage::SetApplicationPath(const char* strIn)
{
  if (applicationPath)
    delete [] applicationPath;
  if (applicationName)
    delete [] applicationName;

  int strInlength = strlen(strIn);
  applicationName = new char[strInlength];
  strcpy(applicationName, strIn);

  applicationPath = new char[strInlength];
  int i, j;
  for (i=strInlength-1; i!=0; i--)
  {
    if (strIn[i] == '\\')
    {
      j = i;
      break;
    }
  }

  for (i=0; i < strInlength; i++)
  {
    if (i == j+1)
      break;
    applicationPath[i] = strIn[i];
  }

  applicationPath[i] = '\0';

  return 0;
}

int CStorage::SetMainElemName(const char *elemName, const char *nameID)
{
  mainNamesID.push_back(nameID);
  mainElemNames.push_back(elemName);
  return 0;
}

int CStorage::SetDopElemName(const char *elemName, const char *nameID)
{
  dopNamesID.push_back(nameID);
  dopElemNames.push_back(elemName);
  return 0;
}

CBaseElemCreator *CStorage::CreateNewMainElem(const int &id)
{
  CBaseElemCreator *bCreator = factory.create(mainNamesID[id]);
  elemContainer.push_back(bCreator->GetElem());
  elemContainer[elemContainer.size() - 1]->SetElemName(mainElemNames[id].c_str());
  return bCreator;
}

CBaseElemCreator *CStorage::CreateNewDopElem(const int &id)
{
  CBaseElemCreator *bCreator = factory.create(dopNamesID[id]);
  elemContainer.push_back(bCreator->GetElem());
  elemContainer[elemContainer.size() - 1]->SetElemName(dopElemNames[id].c_str());
  return bCreator;
}

CBaseElemCreator *CStorage::CreateNewMainElem(const std::string &id)
{
  CBaseElemCreator *bCreator = factory.create(id);
  elemContainer.push_back(bCreator->GetElem());
  int i = 0;
  for (i=0; i<mainElemNames.size(); i++)
    if (id == mainNamesID[i])
      break;
  if (i == mainElemNames.size())
    return NULL;
  elemContainer[elemContainer.size() - 1]->SetElemName(mainElemNames[i].c_str());
  return bCreator;
}

CBaseElemCreator *CStorage::CreateNewDopElem(const std::string &id)
{
  CBaseElemCreator *bCreator = factory.create(id);
  elemContainer.push_back(bCreator->GetElem());
  int i = 0;
  for (i=0; i<dopElemNames.size(); i++)
    if (id == dopNamesID[i])
      break;
  if (i == dopElemNames.size())
    return NULL;
  elemContainer[elemContainer.size() - 1]->SetElemName(dopElemNames[i].c_str());
  return bCreator;
}