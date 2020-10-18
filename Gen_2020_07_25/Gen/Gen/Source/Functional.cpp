//---------------------------------------------------------------------------


#pragma hdrstop

#include <stdio.h>
#include <math.h>
#include <string.h>

#include "Functional.h"
//#include "Main.h"

//---------------------------------------------------------------------------

// функция округления числа в большую сторону
double RoundUp(double value)
{
  if (value == 0)
    return 0;

  double tempDoub = log10(fabs(value));

  if (value > 0)
  {
    tempDoub = ceil(tempDoub);
    return (floor(value/pow(float(10), int(tempDoub)-2)) + 1)*pow(float(10), int(tempDoub)-2);
  }
  else
  {
    tempDoub = fabs(floor(tempDoub));
    return (ceil(value*pow(float(10), int(tempDoub))) + 0.1)/pow(float(10), int(tempDoub));
  }

  return value;
}

// функция округления числа в меньшую сторону
double RoundDoun(double value)
{
  if (value == 0)
    return 0;

  double tempDoub = log10(fabs(value));

  if (value > 0)
  {
    tempDoub = ceil(tempDoub);
    return (ceil(value/pow(float(10), int(tempDoub)-2)) - 1)*pow(float(10), int(tempDoub)-2);
  }
  else
  {
    tempDoub = fabs(floor(tempDoub));
    return (floor(value*pow(float(10), int(tempDoub)+1)) - 1)/pow(float(10), int(tempDoub)+1);
  }

  return value;
}

int FindMinMax(double *buff, int length, double &min, double &max)
{
  int i;

  for (i=0; i<length; i++)
  {
    if (i == 0)
    {
      min = max = buff[i];
    }
    else
    {
      if (min > buff[i])
        min = buff[i];

      if (max < buff[i])
        max = buff[i];
    }
  }

  return 0;
}

// преобразовать число в строку
int CreateStr(char *strBuf, double value)
{
  if (value == 0)
    return -1;

  double tempDoub = log10(value);
  //int order = log10(value);
  int order = tempDoub;

  if (abs(order) > 6)
    sprintf(strBuf, "%.2e", value);
  else
  {
    char s1[2];
    char s[10];

    // если число кратно 10
    tempDoub = pow(float(10), order);
    if (value == tempDoub)
    {
      if (order < 0)
        sprintf(s1, "%d", abs(order));
      else
        sprintf(s1, "%d", 0);
        
      //sprintf(s, "%.");
      sprintf(s, "");
      strncat(s, "%", 1);
      strncat(s, ".", 1);
      strncat(s, s1, strlen(s1));
      strncat(s, "f", 1);

      sprintf(strBuf, s, value);
      return 0;
    }

    if (order > 0)
    {
      if (order > 3)
        sprintf(s1, "%d", 0);
      else
        sprintf(s1, "%d", 3 - order);
    }
    else
    {
      int temp = abs(order) + 2;
      if (temp > 6)
        temp = 6;

      sprintf(s1, "%d", temp);
    }

    //sprintf(s, "%.");
    sprintf(s, "");
    strncat(s, "%", 1);
    strncat(s, ".", 1);
    strncat(s, s1, strlen(s1));
    strncat(s, "f", 1);

    sprintf(strBuf, s, value);
  }
  return 0;
}

// функция вычисления количества знаков после апятой
int CalcOrder(double min, double max)
{
  if (max - min <= 0)
    return 0;

  int order = abs(log10(max - min));
  double length = max - min;

  if (length> 1)
  {
    if (order > 3)
      order = 0;
    else
      order = 3 - order;
  }
  else
    order = 3 + order;

  if (order > 6)
    order = 6;

  return order;
}

// функция проверки введенного числа на отсутсвие недопустимых символов
int CheckString(const char *buf, int len)
{
  int i;
  int res = 1;
  for (i=0; i<len; i++)
  {
    if (buf[i] == '.')
      continue;
    //if (buf[i] == ',')
    //{
    //  //buf[i] = '.';
    //  continue;
    //}

    if (buf[i] == 'e')
      continue;

    if (buf[i] == 'E')
      continue;

    if (i == 0 || i > 1)
    {
      if (buf[i] == '-')
        continue;

      if (buf[i] == '+')
        continue;
    }
    /*if (i>1 && buf[i] == '-')
      continue;

    if (i>1 && buf[i] == '+')
      continue;*/

    if (buf[i] < '0')
    {
      res = 0;
      break;
    }
    if (buf[i] > '9')
    {
      res = 0;
      break;
    }
  }

  /*if (!res)
  {
    char buf[512];
    sprintf(buf, "Параметр '%s' введен не правильно!", caption);
    //MessageDlg(buf, mtError, TMsgDlgButtons() << mbOK, 0);
  }*/

  return res;
}

// функция проверки введенного числа на правильность
int CheckNumb(const char *buf, int len)
{
  if (buf[0] == 'e' || buf[0] == 'E')
    return 0;

  int i, k=0;
  int posE = -1, posP = -1;
  for (i=0; i<len; i++)
  {
    if (buf[i] == '.')
    {
      posP = i;
      k++;
    }
  }
  if (k>1)
    return 0;

  k=0;
  for (i=0; i<len; i++)
  {
    if (buf[i] == 'e')
    {
      posE = i;
      k++;
    }
  }

  if (k == 0)
  {
    for (i=0; i<len; i++)
    {
      if (buf[i] == 'E')
      {
        posE = i;
        k++;
      }
    }
  }
  if (k>1)
    return 0;
  if (k==1)
  {
    if (posE+1 >= len)
      return 0;

    if (buf[posE+1] != '-' && buf[posE+1] != '+')
      return 0;
  }

  if (posE>=0)
    if (posP > posE)
      return 0;

  posP = -1;
  posE = -1;
  k = 0;
  for (i=0; i<len; i++)
  {
    if (buf[i] == '-')
    {
      if (posP == -1)
        posP = i;
      else
        posE = i;
      k++;
    }
  }
  if (k>2)
    return 0;

  if (k == 2)
  {
    if (posP != 0 || posE < 2)
      return 0;
    if (posE+1 >= len)
      return 0;
    if (buf[posE+1] < '0' && buf[posE+1] > '9')
      return 0;
    if (buf[posP+1] < '0' && buf[posP+1] > '9')
      return 0;
    if (buf[posE-1] != 'e' && buf[posE-1] != 'E')
      return 0;
  }
  if (k == 1)
  {
    if (posP > 0 && buf[posP-1] != 'E' && buf[posP-1] != 'e')
      return 0;

    if (posP+1 >= len)
      return 0;

    if (buf[posP+1] < '0' && buf[posP+1] > '9')
      return 0;
  }

  posP = -1;
  posE = -1;
  k = 0;
  for (i=0; i<len; i++)
  {
    if (buf[i] == '+')
    {
      if (posP == -1)
        posP = i;
      else
        posE = i;
      k++;
    }
  }
  if (k>2)
    return 0;

  if (k == 2)
  {
    if (posP != 0 || posE < 2)
      return 0;
    if (posE+1 >= len)
      return 0;
    if (buf[posE+1] < '0' && buf[posE+1] > '9')
      return 0;
    if (buf[posP+1] < '0' && buf[posP+1] > '9')
      return 0;
    if (buf[posE-1] != 'e' && buf[posE-1] != 'E')
      return 0;
  }
  if (k == 1)
  {
    if (posP > 0 && buf[posP-1] != 'e' && buf[posP-1] != 'E')
      return 0;

    if (posP+1 >= len)
      return 0;

    if (buf[posP+1] < '0' && buf[posP+1] > '9')
      return 0;
  }

  return 1;
}

#pragma package(smart_init)
