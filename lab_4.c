/*Преобразовать  строку, содержащую   выражение на Си с операциями(=, == , != , a+=, a -= ), в  строку, содержащую  эти же операции с синтаксисом 
языка Паскаль(:=, =, #, a = a + , a = a - )*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define N 100

char Letters[52] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
char Temp[N];

int Length(char S[]);
void ConvertToPascal(char S[]);
void ShiftL(char S[], int pos, int n);
void ShiftR(char S[], int pos, int n);
int FindIndex1(char S[], int pos); //найти индекс конца 1 операнда
int FindIndex2(char S[], int pos); //найти индекс конца 1 операнда
void CreateTemp(char S[], int pos1, int pos2);
void PlaceStr(char S[], char ch, int pos); /*для 1 символа*/
void PlaceStr2(char S1[], char S2[], int pos); /*для строки*/
void ChangeMarks(char S[], int pos1, int pos2);

int main()
{
    char S[N] = "b+=4 t==e s=d";
	printf("Programm on C:\n");
	printf("%s\n", S);
	ConvertToPascal(S);
	printf("Programm on Pascal:\n");
	printf("%s\n", S);
    return 0;
}

int Length(char S[])
{
    int i;

    for (i = 0; S[i] != '\0'; i++);

    return i;
}

void ConvertToPascal(char S[])
{
	int i;
	int len = Length(S);

	for (i = 0; S[i] != '\0' && i< len; i++)
	{
		if (S[i] == '=' && S[i + 1] != '=') 
		{
			ShiftR(S, i, 1);
			PlaceStr(S, ':', i); 
			i++;
			len += 1;
			//printf("%s\n", S);
		}

		else if (S[i] == '=' && S[i+1] == '=')   
		{
			ShiftL(S, i+1, 1); //=
			//printf("%s\n", S);
			len -= 1;
		}

		else if (S[i] == '!' && S[i + 1] == '=')
		{
			ShiftL(S, i+1, 1);
			PlaceStr(S, '#', i); 	
			i++;
			//printf("%s\n", S);
			len -= 1;
		}

		else if (S[i] == '+' && S[i + 1] == '=') 
		{
			int index2 = FindIndex2(S, i); 
			int index1 = FindIndex1(S, index2);
			CreateTemp(S, index1, index2); //сформируем Temp
			ChangeMarks(S, i, i + 1);
			int LengthTemp = Length(Temp);
			ShiftR(S, i+1, LengthTemp);
			PlaceStr2(S, Temp, i+1);
			i += Length(Temp);
			len += Length(Temp);
			//printf("%s\n", S);
		}
		else if (S[i] == '-' && S[i + 1] == '=') 
		{
			int index2 = FindIndex2(S, i);
			int index1 = FindIndex1(S, index2);
			CreateTemp(S, index1, index2); //сформируем Temp
			ChangeMarks(S, i, i + 1);
			int LengthTemp = Length(Temp);
			ShiftR(S, i + 1, LengthTemp);
			PlaceStr2(S, Temp, i + 1);
			i += Length(Temp);
			len += Length(Temp);
		}
	}
}

void ShiftR(char S[], int pos, int n)
{
	int i = Length(S);

	for (; i >= pos; i--)
	{
		S[i + n] = S[i];
	}
}

int FindIndex2(char S[], int pos)	//найти индекс 1-й буквы слева от "+"
{	
	for (int i = pos; i >= 0; i--)
	{
		for (int j = 0; j < 54; j++)
		{
			if (S[i] == Letters[j])
				return i;
		}
	}
}

int FindIndex1(char S[], int pos) // Найти индекс с которого начинается слово,  левого операнда +=
{
	for (int i = pos; i > 0; i--)
	{
		if (S[i] == 32 || S[i] == ';' || S[i] == ',')
			return i + 1;
	}
}

void CreateTemp(char S[], int pos1, int pos2)
{
	int i=0, j = pos1, limit = pos2;
	for (i, j; (i < N && j <= limit); i++, j++) //бежит по TEMP
			Temp[i] = S[j];
	Temp[i] = '\0';
	return Temp;
}

void ShiftL(char S[], int pos, int n)
{
	int i;

	for (i = pos; S[i] != '\0'; i++)
	{
		S[i - n] = S[i];
	}
	S[i - n] = S[i];
}

void PlaceStr(char S[], char ch, int pos)
{
	int j;

	S[pos] = ch;
}

void PlaceStr2(char S1[], char S2[], int pos)
{
	int j;

	for (j = 0; S2[j] != '\0'; j++)
	{
		S1[pos + j] = S2[j];
	}
}
 
void ChangeMarks(char S[], int pos1, int pos2)
{
	int tmp;
	tmp = S[pos1];
	S[pos1] = S[pos2];
	S[pos2] = tmp;
}