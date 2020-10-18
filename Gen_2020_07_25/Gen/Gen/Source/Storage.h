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

#ifndef STORAGE_H
#define STORAGE_H

#include "BaseDrawElem.h"
#include <vector>
#include "ObjectFactory.h"
#include "BaseElemCreator.h"

typedef grs::ObjectFactory<CBaseElemCreator, std::string> TypeFactory;

//---------------------------------------------------------------------------
class CStorage
{
private:
  static CStorage *curStorData;
public:
  char *applicationPath;
  char *applicationName;

  CStorage();
  ~CStorage();

  TypeFactory factory;

  std::vector<CBaseDrawElem *> elemContainer;
  std::vector<CBaseElemCreator*> staticPtrs;
  std::vector<std::string> mainElemNames;
  std::vector<std::string> dopElemNames;
  std::vector<std::string> mainNamesID;
  std::vector<std::string> dopNamesID;

  static CStorage &instance();

  // функция-деструктор
  void Free();

  // функция записи данных в файл
  int SaveDataFCI(const char *fileName, double *arrayX, double *arrayY, double *values, int countX, int countY, const char *sourceName);

  // функция загрузки данных из файла
  int LoadDataFCI(const char *fileName);

  // функция записи данных в файл в два столбца из массива
  int SaveArrayIn2Col(const char *fileName, char *dataName, double *array, int count);

  // функция записи данных в файл в три столбца из массива
  int SaveArrayIn3Col(const char *fileName, char *dataName, double *array, int count);

  int SetApplicationPath(const char* strIn);

  int SetMainElemName(const char *elemName, const char *nameID);
  int SetDopElemName(const char *elemName, const char *nameID);

  CBaseElemCreator *CreateNewMainElem(const int &id);
  CBaseElemCreator *CreateNewDopElem(const int &id);
  CBaseElemCreator *CreateNewMainElem(const std::string &id);
  CBaseElemCreator *CreateNewDopElem(const std::string &id);

};

//---------------------------------------------------------------------------
#endif
