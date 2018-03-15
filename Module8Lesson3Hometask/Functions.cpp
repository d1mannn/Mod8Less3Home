#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include "Header.h"
#include <iostream>
using namespace std;
#define max 50


int TaskNumb()
{
	setlocale(LC_ALL, "Rus");
	int task;
	printf("Введите номер задания - ");
	scanf_s("%d", &task);
	return task;
}

int SpaceCounter(char * arr, int *length)
{
	int count = 0, code = 0;
	for (int i = 0; i < *length; i++)
	{	
		code = (int)arr[i];
		if (!((code >= 65 && code <= 90) || (code >= 97 && code <= 122)))
			count++;
	}
	return count;
}

int SpaceCounter2(char * arr, int *length)
{
	int count = 0;
	for (int i = 0; i < *length; i++)
	{
		if (arr[i] == ' ')
			count++;
	}
	return count;
}

void FirstAndLastLettersAreTheSame(char * arr, int *length)
{	
	int counter = 0;
	char word, word2;
	for (int i = 0; i <= *length; i++)
	{
		if (arr[i] != ' ' && arr[i] != '\0' && arr[i] != '-' && arr[i] != ',')
			counter++;
		if (arr[i] == ' ' || arr[i] == '\0' || (arr[i] == '-' && arr[i + 1] != ' ') || arr[i] == ',')
		{	
			word = arr[i - 1];
			word2 = arr[i - counter];
			word = (char)toupper(word);
			word2 = (char)toupper(word2);
			if (word == word2)
			{
				for (int j = i - counter; j < i; j++)
				{
					printf("%c", arr[j]);
				}
				printf("\n");
			}
			
			/*if (arr[i - 1] == arr[i - counter])
			{
				for (int j = i - counter; j < i; j++)
				{
					printf("%c", arr[j]);
				}
				printf("\n");
			}*/
			counter = 0;
		}
		/*if ((arr[i] == '-' && arr[i + 1] != ' '))
		{

		}*/
	}
}

void LetterK(char * arr, int *length)
{
	int counter = 0;
	for (int i = 0; i <= *length; i++)
	{
		if (arr[i] != ' ' && arr[i] != '\0')
			counter++;
		if (arr[i] == ' ' || arr[i] == '\0')
		{
			for (int j = i - counter; j < i; j++)
			{
				if (arr[j] == 'k' || arr[j] == 'K')
				{
					for (int j = i - counter; j < i; j++)
					{
						printf("%c", arr[j]);
					}
					printf("\n");
				}
			}
			counter = 0;
		}
			
	}
}

void CommaPutting(char *arr, int *length)
{
	int counter = 0;
	char temp[max];
	for (int i = 0; i < *length; i++)
	{
		if (arr[i] != ' ')
			counter++;
		if (arr[i] == ' ')
		{	
			temp[i + 1] = arr[i + 1];
			arr[i + 1] = ',';
			for (int j = i + 1; j < *length; j++)
			{
				arr[j + 1] = temp[j];
				temp[j + 1] = arr[j + 2];
			}
			*length++;
		}
	}
	puts(arr);
}

void SymbolReplace(char *arr, int * length, char * old, char * tonew)
{	
	int count = 0;
	int length1 = *length;
	for (int i = 0; i < *length; i++)
	{
		/*if(arr[i] == '<' && arr[i + 1] == 'i')
			arr = (char*)realloc(length, 1 * sizeof(char))*/

		//первое вхождение
		if (arr[i] == *old)
		{	
			count++;
			old++;
		}
		else
		{
			*old = *old - count;
			count = 0;
		}

		if (count == strlen(old))
		{	
			//нашли
			int different = strlen(tonew) - strlen(old);
			if (different > 0)
			{	
				printf("ДО \n %s\n", arr);
				arr = (char *)realloc(arr, different);
				if (arr == NULL)
					break;
				printf("ПОСЛЕ\n%s\n", arr);
				arr[strlen(arr) + 1] = '\0';
				/*for (int i = strlen(arr); i >= 0; i++)
				{
					
				}*/
			}
		}
	}
}

void Replacing(char * arr, int * length)
{	
	/*int count = 0;
	char *arr = (char *)calloc(*length, sizeof(char)), temp1, temp2;
	for (int i = 0; i < *length; i++)
	{	
		
		if (arr[i] == '<' && arr[i + 1] == 'i')
		{
			arr = (char *)realloc(arr, 1);
			if (arr == 0)
				break;
		}
	}*/
}

void DotInsteadOfDouble(char * arr, int *length)
{
	for (int i = 0; i < *length / 2; i++)
	{
		if (arr[i] == '.')
			arr[i] = ':';
	}
	for (int i = *length / 2; i < *length; i++)
	{
		if (arr[i] == '!')
			arr[i] = '.';
	}
}

void ThreeLetter(char * arr, int * length)
{
	int count = 0, code = 0;
	for (int i = 0; i < *length; i++)
	{	
		code = (int)arr[i];

		if (code >= 65 && code <= 90)
			count++;
		else if (code >= 97 && code <= 122)
			count++;
		else
		{
			if (count == 3)
			{
				for (int j = i - 3; j < i; j++)
				{
					printf("%c", arr[j]);
				}
				printf("\n");
			}
			/*if (!((code >= 65 && code <= 90) || (code >= 97 && code <= 122)))
			{
				for (int j = i - 3; j < i; j++)
				{
					printf("%c", arr[i]);
				}
				count = 0;
			}*/
			count = 0;
		}
		/*if ((int)arr[i] >= 65 && (int)arr[i] <= 90)
			count++;
		if ((int)arr[i] >= 97 && (int)arr[i] <= 122)
			count++;
		if (count == 3)
			if (!((int)arr[i + 1] >= 65 && (int)arr[i + 1] <= 90) || !((int)arr[i + 1] >= 97 && (int)arr[i + 1] <= 122))
			{
				for (int j = i - 3; j < i; j++)
				{
					printf("%c", arr[i]);
				}
			}*/
	}
}

void Repl(char *str, int length)
{
	int space = SpaceCounter2(str, &length);
	str = (char *)realloc(str, sizeof(char) * (strlen(str) + space));
	int n = 0, kon = 0, ws = 0;
	while (kon < strlen(str))
	{
		while (str[kon] != ' ')
		{
			if (kon != strlen(str))
				kon++;
			else break;
		}
		for (int i = strlen(str) + 1; i >= kon; i--)
		{
			*(str + i) = *(str + 1 - 1);
		}
		*(str + kon) = ',';
		kon = kon + 2;
	}
	printf("\n\n%s\n\n", str);
}

void Replacing(char * arr, int * space, int * length)
{
	arr = (char*)realloc(arr, sizeof(char) * (*length + *space));
	int end = 0;
	while (end < *length)
	{
		while (arr[end] != ' ')
		{
			if (end != *length)
				end++;
			else break;
		}
		for (int i = *length + 1; i >= end; i--)
		{
			*(arr + i) = *(arr + i - 1);
		}
		*(arr + end) = ',';
		end = end + 2;
	}
	printf("\n\n%s\n\n", arr);
}

char * createDunamicChar(int len)
{
	return (char *)malloc(len * sizeof(char));
}

char * reallocDunamicChar(char * str, int len)
{
	return (char*)realloc(str, len * sizeof(char));
}

void replacestr(char *str, char * old, char * tonew)
{
	int count = 0;
	int lenOld = strlen(old);
	int lenToNew = strlen(tonew);
	int strLen = strlen(str);
	int start = 0;

	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == *old)
		{
			count++;
			old++;
		}
		else
		{
			old = old - count;
			count = 0;
		}

		if (count == lenOld)
		{
			int different = strlen(tonew) - lenOld;
			if (different > 0)
			{
				str = reallocDunamicChar(str, (strLen + different + 1));
				if (str == NULL) break;
				//Доделать 
				for (int j = strlen(str) + 1; j > i; j--)
				{
					*(str + j) = *(str + j - 1);
				}
				*(str + strLen + different + 1) = '\0';
				tonew = tonew - lenToNew;
				for (int j = i - lenOld; j < i; j++)
				{
					*(str + j) = *(tonew);
					tonew++;
				}
				printf("\n\n%d\n%s\n\n", strlen(str), str);
			}
			else if (different == 0)
				for (int j = 0; j < lenOld; j++)
					*(str + j) = *(tonew + j);
		}
	}

}

void ArrFillingTwo(char * arr)
{	
	printf("enter only 0 or 1\n");
	int count = 0;
	do
	{
		arr[count] = getchar();
		cin.get();
		count++;
	} while ( arr[count - 1] == '0' || arr[count - 1] == '1');
	arr[count - 1] = '\0';
	puts(arr);
}

void FromTwotoTen(char * arr)
{
	//48 - 0 49 - 1
	int count = 0, *arr2, sum = 0;
	arr2 = (int*)calloc(strlen(arr), sizeof(int));
	for (int i = strlen(arr) - 1; i >= 0; i--)
	{
		if ((int)arr[i] == 48)
			arr2[i] = 0;
		if ((int)arr[i] == 49)
			arr2[i] = 1;
		sum += arr2[i] * pow(2, count);
		count++;
		printf("%d", arr2[i]);
	}
	printf("%s = %d\n", arr, sum);

}