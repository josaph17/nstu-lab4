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
void PlaceStr2(char S1[], char S2[], int pos);
//void ShiftR3(char S[], int pos, int n);
//void ShiftR4(char S[], int pos, int n);
void PlaceStr(char S[], char ch, int pos);
void ChangeMarks(char S[], int pos1, int pos2);

int main()
{
    char S[N] = " i=4; column!= 4, vars += 54354";
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
	int len = Length(S);
	int i;

	for (i = 0; S[i] != '\0' && i< len; i++)
	{
		if (S[i] == '=' && S[i + 1] != '=') 
		{
			ShiftR(S, i, 1);
			PlaceStr(S, ':', i); 
			i++;
		}

		else if (S[i] == '=' && S[i+1] == '=')   
		{
			ShiftL(S, i+1, 1); //=
		}

		else if (S[i] == '!' && S[i + 1] == '=')
		{
			ShiftL(S, i+1, 1);
			PlaceStr(S, '#', i); 	
			i--;
		}

		else if (S[i] == '+' && S[i + 1] == '=') 
		{
			int index2 = FindIndex2(S, i); /*найти индекс конца 1 операнда*/
			//printf("Firs letter left from \"+\" is \"%c\", index2 number %d\n",  S[index2], index2);
			int index1 = FindIndex1(S, index2);
			//printf("Firs letter left from \"%c\" is \"%c\", index1 number %d\n", S[index2], S[index1], index1);
			CreateTemp(S, index1, index2); //сформируем Temp
			//printf("This is creating Temp \"%s\" \n", Temp);
			ChangeMarks(S, i, i + 1);
			int LengthTemp = Length(Temp);
			ShiftR(S, i+1, LengthTemp);
			//printf("String after ShiftR \"%s\" \n", S);
			PlaceStr2(S, Temp, i+1);
			//printf("String after PlaceStr2 \"%s\"\n", S);
		}
		else if (S[i] == '-' && S[i + 1] == '=') 
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

int FindIndex1(char S[], int pos) // Найти индекс с которого начинается слово  левого операнда +=
{
	for (int i = pos; i >= 0; i--)
	{
		if (S[i] == 32 || S[i] == ';' || S[i] == ',')
			return i+1;
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
//void ShiftR3(char S[], int pos, int n) /*Идет после ShiftR4, на входе 3 и 5*/
//{
//	//int p = pos;
//
//	int len2 = Length2(S, pos+1); //6, 2-ой операнд и "+"
//	int p = len2 + pos;
//	int delta = p - len2;
//	p = pos;
//	for (p; p >=pos-delta; p--)
//	{
//		S[p + n] = S[p];
//	}
//}

//void ShiftR4(char S[], int pos, int n) /*ShiftR3(S,i=4="s", i=5)*/
//{
//	int len2 = Length2(S, pos); //6, 2-ой операнд и "+"
//	int p = len2 + pos-1 ;
//	int delta = p - len2;
//
//	for (; p >= pos; p--)
//	{
//		S[p + delta] = S[p];
//	}
//}


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