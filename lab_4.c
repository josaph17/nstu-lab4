/*Преобразовать  строку, содержащую   выражение на Си с операциями(=, == , != , a+=, a -= ), в  строку, содержащую  эти же операции с синтаксисом 
языка Паскаль(:=, =, #, a = a + , a = a - )*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define N 30

int Length(char S[]);
int FindChar(char S[]);
void ShiftR(char S[], int pos, int n);


int main()
{
    char S[N] = "a=b";
    char C[] = "=!+-=====";
    int res = FindChar(S);
    return 0;
}

int Length(char S[])
{
    int i;

    for (i = 0; S[i] != '\0'; i++);

    return i;
}

int FindChar(char S[])
{
	int i;
	for (i = 0; S[i] != '\0'; i++)
	{
		if (S[i] == 61) //код символа =
		{
			ShiftR(S, i, 1);
			return printf("%s", S);
		}
	}

	return -1;
}

void ShiftR(char S[], int pos, int n)
{
	int i = Length(S);

	for (; i >= pos; i--)
	{
		S[i + n] = S[i];
	}
}