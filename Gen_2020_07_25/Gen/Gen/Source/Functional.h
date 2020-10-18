//---------------------------------------------------------------------------

#ifndef FunctionalH
#define FunctionalH
//---------------------------------------------------------------------------

// ������� ���������� ����� � ������� �������
double RoundUp(double value);

// ������� ���������� ����� � ������� �������
double RoundDoun(double value);

// ����� ���/������ � �������
int FindMinMax(double *buff, int length, double &min, double &max);

// ������������� ����� � ������
int CreateStr(char *strBuf, double value);

// ������� ���������� ���������� ������ ����� ������
int CalcOrder(double min, double max);

// ������� �������� ���������� ����� �� ��������� ������������ ��������
int CheckString(const char *buf, int len);

// ������� �������� ���������� ����� �� ������������
int CheckNumb(const char *buf, int len);

//---------------------------------------------------------------------------
#endif
