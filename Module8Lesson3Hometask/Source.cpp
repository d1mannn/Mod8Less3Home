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
// Так работает расширение массива
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
				/*1.	Дана строка из нескольких слов.Слова отделяются друг от друга пробелами или запятыми.
					Вывести слова, начинающиеся и заканчивающиеся одной и той же буквой.*/
				char arr[] = "Автотрасса москва - Алма-ата, Как я по ней ехал";//"dad doesn't have an eye";
				int length = strlen(arr);
				FirstAndLastLettersAreTheSame(arr, &length);
			} break;

			case 2:
			{
				/*2.	Дан массив символов, в котором встречаются структуры <i> и < / i>.
					Заменить каждое вхождение <i> на < / i>, а каждое вхождение < / i> на <#>.
					Замечание: в программе следует учесть, что буква i может быть, как строчной, так и прописной.*/
				char a[] = "<i>", b[] = "</#>", c[] = "<i><body><hr><ul><i>Чебурашка</i><i>Крокодил Гена</i><i>Шапокляк</i><i>Крыса Лариса</i></ul><hr></body>";
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
				//printf("Длина arr = %d\n", length);
				//char *arr2;
				//arr2 = (char*)calloc(length, sizeof(char));
				//printf("Длина arr2 = %d\n", strlen(arr2));
				////strcpy(arr, arr2);
				//for (int i = 0; i < length; i++)
				//{
				//	arr2[i] = arr[i];
				//}
				////char tonew = '<i>', old = '</i>';
				////arr2 = (char*)realloc(arr, 1);
				//length = strlen(arr2);
				//printf("Длина arr2 = %d\n", length);
				//SymbolReplace(arr, &length, &old, &tonew);
			}break;

			case 3:
			{
				/*3.	Дан массив символов, содержащий число в двоичной системе счисления.
					Проверить правильность ввода этого числа(в его записи должны быть только символы 0 и 1).
					Если число введено неверно, повторить ввод.При правильном вводе перевести число в десятичную систему счисления*/
				char arr[100];
				ArrFillingTwo(arr);
				FromTwotoTen(arr);
			} break;

			case 4:
			{
				/*4.	Дан массив символов, содержащий текст.
					Определить длину содержащейся в нем максимальной серии символов, отличных от букв.*/
				char mas[] = "Дан массив 1 1 символов, содержащий текст.111 Определить 111111 длину содержащейся 1111 в нем максимальной ";
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
				/*5.	Дан массив символов.Преобразовать его, заменив точками все двоеточия(:), 
					встречающиеся среди первой половины символов, и заменив точками все 
					восклицательные знаки, встречающиеся среди символов, стоящих во второй половине исходного массива*/
				char arr[] = "&.#*.@(.&#>@_.;:@*!+-;:.!,!.,;:^";
				int length = strlen(arr);
				puts(arr);
				DotInsteadOfDouble(arr, &length);
				puts(arr);
			} break;

			case 6:
			{
				//6.	Дан массив символов.Указать те слова, которые содержат хотя бы одну букву k.
				char arr[] = "Key hey blocking";
				puts(arr);
				int length = strlen(arr);
				LetterK(arr, &length);
			} break;

			case 7:
			{
				//7.	Дан массив символов, содержащий текст.В строке между словами вставить вместо пробела запятую и пробел

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
				//8.	Дан массив символов, содержащий текст, заканчивающийся точкой.
				//Вывести на экран слова, содержащие три буквы.
				char arr[] = "Hello, my dear son! I hope you are fine.";
				int length = strlen(arr);
				ThreeLetter(arr, &length);
			} break;

			case 9:
			{
				int input;
				int counter = 0;                                     // счетчик введенных чисел
				int * values = NULL;
				int * many_numbers;

				do {
					std::cout << "Введите целое значение (0 - выход): ";
					std::cin >> input;
					counter++;

					many_numbers = (int*)realloc(values, counter * sizeof(int)); // при добавлении нового числа, увеличиваем массив на 1

					if (many_numbers != NULL)
					{
						values = many_numbers;
						values[counter - 1] = input;                      // добавить к массиву только что введённое число
					}
					else
					{
						free(values);                                   // удалить массив
						std::cout << "Ошибка перевыделения памяти!";
						exit(1);                                          // завершить работу программы
					}
				} while (input != 0);                                   // пока не введён 0

				std::cout << "Введенные числа: ";
				for (int i = 0; i < counter; i++) std::cout << values[i] << " ";
				free(values);                                         // удалить массив

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