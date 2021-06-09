/*Преобразовать  строку, содержащую   выражение на Си с операциями(=, == , != , a+=, a -= ), в  строку, содержащую  эти же операции с синтаксисом 
языка Паскаль(:=, =, #, a = a + , a = a - )*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define N 30

int Length(char S[]);
void ConvertToPascal(char S[]);
void ShiftL(char S[], int pos, int n);
void ShiftR(char S[], int pos, int n);
void ShiftR2(char S[], int pos, int n);
void PlaceStr(char S[], char ch, int pos);
void ChangeMarks(char S[], int pos1, int pos2);

int main()
{
    char S[N] = "myvar-=25 c";
	printf("Programm on C: %s\n", S);
	ConvertToPascal(S);
	printf("Programm on Pascal: %s\n", S);
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

	for (i = 0; S[i] != '\0'; i++)
	{
		if (S[i] == 61 && S[i + 1] != 61) // =
		{
			ShiftR(S, i, 1);
			PlaceStr(S, 58, i); // :
			return ;
		}

		else if (S[i] == 61 && S[i+1] == 61)  // ==
		{
			ShiftL(S, i+1, 1);
			return;
		}

		else if (S[i] == 33 && S[i + 1] == 61) // !=
		{
			ShiftL(S, i+1, 1);
			PlaceStr(S, 35, i); // #
			return;
		}

		else if (S[i] == 43 && S[i + 1] == 61) // +=
		{
			ChangeMarks(S, i, i + 1);
			ShiftR(S, i, i);
			ShiftR2(S, i, i+1);
			return;
		}
		else if (S[i] == 45 && S[i + 1] == 61) // -=
		{
			ChangeMarks(S, i, i + 1);
			ShiftR(S, i, i);
			ShiftR2(S, i, i + 1);
			return;
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
	int p = pos-1;

	for (; p >= 0; p--)
	{
		S[p + n] = S[p];
	}
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