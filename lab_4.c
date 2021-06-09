/*Преобразовать  строку, содержащую   выражение на Си с операциями(=, == , != , a+=, a -= ), в  строку, содержащую  эти же операции с синтаксисом 
языка Паскаль(:=, =, #, a = a + , a = a - )*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define N 100

int Length(char S[]);
int Length2(char S[], char pos);
void ConvertToPascal(char S[]);
void ShiftL(char S[], int pos, int n);
void ShiftR(char S[], int pos, int n);
void ShiftR2(char S[], int pos, int n);
void ShiftR3(char S[], int pos, int n);
void ShiftR4(char S[], int pos, int n);
void PlaceStr(char S[], char ch, int pos);
void ChangeMarks(char S[], int pos1, int pos2);

int main()
{
    char S[N] = "vars+=54354";
	printf("Programm on C:\n");
	printf("%s\n", S);
	ConvertToPascal(S);
	//printf("Programm on Pascal:\n");
	//printf("%s\n", S);
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
	int len = Length(S);
	int i;

	for (i = 0; S[i] != '\0' && i< len; i++)
	{
		if (S[i] == 61 && S[i + 1] != 61) // =
		{
			ShiftR(S, i, 1);
			PlaceStr(S, 58, i); // :=
			i++;
		}

		else if (S[i] == 61 && S[i+1] == 61)  // ==
		{
			ShiftL(S, i+1, 1); //=
		}

		else if (S[i] == 33 && S[i + 1] == 61) // !=
		{
			ShiftL(S, i+1, 1);
			PlaceStr(S, 35, i); // #	
			i--;
		}

		else if (S[i] == 43 && S[i + 1] == 61) // +=
		{
			ChangeMarks(S, i, i + 1);
			printf("ChangeMarks %s\n", S);
		/*	ShiftR3(S, i+1, i);
			printf("ShiftR3 %s\n", S);*/
			ShiftR4(S, i+1, i);
			printf("ShiftR4 %s\n", S);
		}
		else if (S[i] == 45 && S[i + 1] == 61) // -=
		{
			ChangeMarks(S, i, i + 1);
			i + i;
		}
	}
	/*return -1;*/		//СПРОСИТЬ
}

void ShiftR(char S[], int pos, int n)
{
	int i = Length(S);

	for (; i >= pos; i--)
	{
		S[i + n] = S[i];
	}
}

void ShiftR2(char S[], int pos, int n)
{
	int p = pos - 1;

	for (; p >= 0; p--)
	{
		S[p + n] = S[p];
	}
}

void ShiftR3(char S[], int pos, int n) /*ShiftR3(S,i=5="+", i)*/
{
	int p = pos+n-1;

	for (p; p >=pos; p--)
	{
		S[p + n] = S[p];
	}
}

void ShiftR4(char S[], int pos, int n) /*ShiftR3(S,i=4="s", i=5)*/
{
	int len2 = Length2(S, pos); //6, 2-ой операнд и "+"
	int p = len2 + pos-1 ;
	int delta = p - len2;

	for (; p >= pos; p--)
	{
		S[p + delta] = S[p];
	}
}

int Length2(char S[], int pos)
{
	int i=pos;

	for (; S[i] != '\0' && S[i] != 32; i++);

	int p = i - pos;

	return p;
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
 
void ChangeMarks(char S[], int pos1, int pos2)
{
	int tmp;
	tmp = S[pos1];
	S[pos1] = S[pos2];
	S[pos2] = tmp;
}