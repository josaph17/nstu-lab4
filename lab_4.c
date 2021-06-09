/*Преобразовать  строку, содержащую   выражение на Си с операциями(=, == , != , a+=, a -= ), в  строку, содержащую  эти же операции с синтаксисом 
языка Паскаль(:=, =, #, a = a + , a = a - )*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define N 30

int Length(char S[]);
void ConvertToPascal(char S[]);
void ShiftR(char S[], int pos, int n);
void PlaceStr(char S1[], char ch, int pos);

int main()
{
    char S[N] = "a=b";
	printf("%s\n", S);
	ConvertToPascal(S);
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
	for (i = 0; S[i] != '\0'; i++)
	{
		if (S[i] == 61) //код символа =
		{
			ShiftR(S, i, 1);
			PlaceStr(S, 58, i);
			return ;
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

void PlaceStr(char S1[], char ch, int pos)
{
	int j;

	S1[pos] = ch;
}