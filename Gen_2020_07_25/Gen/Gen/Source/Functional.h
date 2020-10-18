//---------------------------------------------------------------------------

#ifndef FunctionalH
#define FunctionalH
//---------------------------------------------------------------------------

// функция округления числа в большую сторону
double RoundUp(double value);

// функция округления числа в большую сторону
double RoundDoun(double value);

// поиск мин/максов в массиве
int FindMinMax(double *buff, int length, double &min, double &max);

// преобразовать число в строку
int CreateStr(char *strBuf, double value);

// функция вычисления количества знаков после апятой
int CalcOrder(double min, double max);

// функция проверки введенного числа на отсутсвие недопустимых символов
int CheckString(const char *buf, int len);

// функция проверки введенного числа на правильность
int CheckNumb(const char *buf, int len);

//---------------------------------------------------------------------------
#endif
