#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include "Header.h"
#include <iostream>
using namespace std;
#define max 50


// ============ 
// ��� �������� ���������� �������
// ============

//char * p;
//pt = (char*)calloc(50, sizeof(char));
//strcpy(, pt, p);
//pt = (char*)realloc(pt, (strlen(p) + 5) * sizeof(char));


void main()
{
	int task;
	do
	{
		task = TaskNumb();
		cin.get();
		switch (task)
		{
			case 1:
			{
				/*1.	���� ������ �� ���������� ����.����� ���������� ���� �� ����� ��������� ��� ��������.
					������� �����, ������������ � ��������������� ����� � ��� �� ������.*/
				char arr[] = "���������� ������ - ����-���, ��� � �� ��� ����";//"dad doesn't have an eye";
				int length = strlen(arr);
				FirstAndLastLettersAreTheSame(arr, &length);
			} break;

			case 2:
			{
				/*2.	��� ������ ��������, � ������� ����������� ��������� <i> � < / i>.
					�������� ������ ��������� <i> �� < / i>, � ������ ��������� < / i> �� <#>.
					���������: � ��������� ������� ������, ��� ����� i ����� ����, ��� ��������, ��� � ���������.*/
				char a[] = "<i>", b[] = "</#>", c[] = "<i><body><hr><ul><i>���������</i><i>�������� ����</i><i>��������</i><i>����� ������</i></ul><hr></body>";
				char * m = createDunamicChar(150);
				for (int i = 0; i < strlen(c); i++)
				{
					m[i] = c[i];
				}
				//strcpy_s(m,strlen(c),c);

				printf("\n Before replace : %s \n", m);

				replacestr(m, a, b);

				printf("\n After replace : %s \n", m);


				//char arr[] = "<i>Hello my friend</i> <p> JJJ <i> JJ </i>J</p>";
				//int length = strlen(arr);
				//printf("����� arr = %d\n", length);
				//char *arr2;
				//arr2 = (char*)calloc(length, sizeof(char));
				//printf("����� arr2 = %d\n", strlen(arr2));
				////strcpy(arr, arr2);
				//for (int i = 0; i < length; i++)
				//{
				//	arr2[i] = arr[i];
				//}
				////char tonew = '<i>', old = '</i>';
				////arr2 = (char*)realloc(arr, 1);
				//length = strlen(arr2);
				//printf("����� arr2 = %d\n", length);
				//SymbolReplace(arr, &length, &old, &tonew);
			}break;

			case 3:
			{
				/*3.	��� ������ ��������, ���������� ����� � �������� ������� ���������.
					��������� ������������ ����� ����� �����(� ��� ������ ������ ���� ������ ������� 0 � 1).
					���� ����� ������� �������, ��������� ����.��� ���������� ����� ��������� ����� � ���������� ������� ���������*/
				char arr[100];
				ArrFillingTwo(arr);
				FromTwotoTen(arr);
			} break;

			case 4:
			{
				/*4.	��� ������ ��������, ���������� �����.
					���������� ����� ������������ � ��� ������������ ����� ��������, �������� �� ����.*/
				char mas[] = "��� ������ 1 1 ��������, ���������� �����.111 ���������� 111111 ����� ������������ 1111 � ��� ������������ ";
				int count = 0, MAX = 0;
				for (int i = 0; i < strlen(mas); i++)
				{
					//printf("%d - %c\n", (int)mas[i], mas[i]);
					if ((int)mas[i] >= 48 && (int)mas[i] <= 57)
						count++;
					else
					{
						if (MAX < count)
							MAX = count;
						count = 0;
					}
				}
				printf("%s \n", mas);
				printf("Max = %d \n", MAX);
			} break;

			case 5:
			{
				/*5.	��� ������ ��������.������������� ���, ������� ������� ��� ���������(:), 
					������������� ����� ������ �������� ��������, � ������� ������� ��� 
					��������������� �����, ������������� ����� ��������, ������� �� ������ �������� ��������� �������*/
				char arr[] = "&.#*.@(.&#>@_.;:@*!+-;:.!,!.,;:^";
				int length = strlen(arr);
				puts(arr);
				DotInsteadOfDouble(arr, &length);
				puts(arr);
			} break;

			case 6:
			{
				//6.	��� ������ ��������.������� �� �����, ������� �������� ���� �� ���� ����� k.
				char arr[] = "Key hey blocking";
				puts(arr);
				int length = strlen(arr);
				LetterK(arr, &length);
			} break;

			case 7:
			{
				//7.	��� ������ ��������, ���������� �����.� ������ ����� ������� �������� ������ ������� ������� � ������

#pragma region OLDCODE

				//char arr1[] = "hello my friend", *arr;

				//arr = (char*)calloc(strlen(arr1), sizeof(char));

				//int length = strlen(arr);

				////strcpy_s(arr, length, arr1);
				//cin.get();
				//fgets(arr, length + 1, stdin);
				//printf("Before - %d\n", strlen(arr));
				//int space = SpaceCounter2(arr, &length);
				//arr = (char*)realloc(arr, (length + space) * sizeof(char));
				//if (arr == NULL)
				//{
				//	printf("\nERROR\n");
				//	EXIT_FAILURE;
				//}
				//printf("After - %d\n", strlen(arr));

				////CommaPutting(arr, &length);

#pragma endregion

				char * arr = (char*)calloc(16, sizeof(char));
				strcpy_s(arr, 16,"hello my friend");
				int length = strlen(arr);
				int space = SpaceCounter2(arr, &length);
				Replacing(arr, &space, &length);

			} break;

			case 8:
			{
				//8.	��� ������ ��������, ���������� �����, ��������������� ������.
				//������� �� ����� �����, ���������� ��� �����.
				char arr[] = "Hello, my dear son! I hope you are fine.";
				int length = strlen(arr);
				ThreeLetter(arr, &length);
			} break;

			case 9:
			{
				int input;
				int counter = 0;                                     // ������� ��������� �����
				int * values = NULL;
				int * many_numbers;

				do {
					std::cout << "������� ����� �������� (0 - �����): ";
					std::cin >> input;
					counter++;

					many_numbers = (int*)realloc(values, counter * sizeof(int)); // ��� ���������� ������ �����, ����������� ������ �� 1

					if (many_numbers != NULL)
					{
						values = many_numbers;
						values[counter - 1] = input;                      // �������� � ������� ������ ��� �������� �����
					}
					else
					{
						free(values);                                   // ������� ������
						std::cout << "������ ������������� ������!";
						exit(1);                                          // ��������� ������ ���������
					}
				} while (input != 0);                                   // ���� �� ����� 0

				std::cout << "��������� �����: ";
				for (int i = 0; i < counter; i++) std::cout << values[i] << " ";
				free(values);                                         // ������� ������

			} break;

			case 10:
			{
				for (int i = 0; i < 255; i++)
				{
					printf("%d == %c\n", i, i);
				}
			} break;
		}
	} while (task > 0);
}