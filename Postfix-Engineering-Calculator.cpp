#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#include <math.h>

struct Node
{
	char data[20];
	struct Node *next;
}*top1 = NULL, *top2 = NULL, *top3 = NULL;
typedef struct Node NODE;
void push1(char value[20]);
char* pop1();
void display1();
void push2(char value[20]);
char* pop2();
void display2();
void push3(char value[20]);
char* pop3();
void display3();
int priorityOperator(char* input);
int intpowerint(int a, int b);
double stringtodoublecast(char* a);
int parFactoriel(int n);
double parExp(double x);
double parSin(double x);
double parCos(double x);
double parTan(double x);
double parCot(double x);
double parSec(double x);
double parCsc(double x);
double parSinh(double x);
double parCosh(double x);
double parTanh(double x);
double parCoth(double x);

void main()
{
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	NODE *tempNode;
	int i = 0, op = -1, lenght = 0;
	double d1 = 0, d2 = 0, d3 = 0;
	char value[20], temp[20], tempd1[20], tempd2[20], tempd[20];
	system("cls");
	for (i = 0; i < 20; i++)
	{
		value[i] = 0;
		temp[i] = 0;
	}
	do
	{
		for (i = 0; i < 20; i++)
			value[i] = 0;
		i = 0;
		//getting string!-------------------------------------------------
		do
		{
			value[i] = getche();
			i++;
		} while (value[i - 1] != ' ');
		value[i - 1] = 0;
		push1(value);
		//checking for the end of statement------------------------------------
		if (strcmp(value, "=") != 0)
		{
			//finding out priority of operator: 0->number | 1-4->operator | 5->( | 6->) ---------------
			op = priorityOperator(value);
			if (op == 0)
			{
				push3(value);
			}
			else
			{
				strcpy(temp, pop2());
				if (strcmp(temp, "Error") == 0)
				{
					push2(value);
					//printf("\n%s\n", value);
				}
				else
				{
					//checking for ')'------------------------------------------
					if (strcmp(value, ")") == 0)
					{
						while ((strcmp(temp, "(") != 0) && (strcmp(temp, "Error") != 0))
						{
							push3(temp);
							strcpy(temp, pop2());
						}
						//pop2();
					}
					else
					{
						if ((op>priorityOperator(temp)) || (priorityOperator(temp) == 5))
						{
							push2(temp);
							push2(value);
						}
						else
						{
							while ((op <= priorityOperator(temp)) && (priorityOperator(temp) != 5))
							{
								push3(temp);
								strcpy(temp, pop2());
							}
							push2(temp);
							push2(value);
						}
					}
				}
			}
		}
	} while (strcmp(value, "=") != 0);
	strcpy(temp, pop2());
	while (strcmp(temp, "Error") != 0)
	{
		push3(temp);
		strcpy(temp, pop2());
	}
	for (i = 0; i < 20; i++)
		temp[i] = 0;
	strcpy(temp, pop3());
	while (strcmp(temp, "Error") != 0)
	{
		push2(temp);
		strcpy(temp, pop3());
	}
	//printf("\n");
	//display2();
	//printf("\n--------\n");
	//display2();
	//printf("\n--------\n");
	//Sleep(5000);
	//-------------------------------
	tempNode = top2;
	while (true)
	{
		//Sleep(3000);
		for (i = 0; i < 20; i++)
			temp[i] = 0;
		op = -1;
		if (tempNode->data == NULL)
		{
			//printf("\n+++++++\n");
			SetConsoleTextAttribute(hstdout, FOREGROUND_GREEN);
			printf(top3->data);
			//printf("\n+++++++\n");
			Sleep(5000);
			exit(0);
		}
		strcpy(temp, tempNode->data);
		tempNode = tempNode->next;
		if (strcmp(temp, "Error") == 0)
		{
			SetConsoleTextAttribute(hstdout, FOREGROUND_RED);
			printf("Error!");
			break;
		}
		op = priorityOperator(temp);
		if (op == 0)
		{
			push3(temp);
		}
		else
		{
			if (op < 5)
			{
				if (strcmp(temp, "+") == 0)
				{
					strcpy(tempd1, pop3());
					d1 = stringtodoublecast(tempd1);
					strcpy(tempd2, pop3());
					d2 = stringtodoublecast(tempd2);
					sprintf(tempd, "%lf", d2 + d1);
					push3(tempd);
				}
				if (strcmp(temp, "-") == 0)
				{
					strcpy(tempd1, pop3());
					d1 = stringtodoublecast(tempd1);
					strcpy(tempd2, pop3());
					d2 = stringtodoublecast(tempd2);
					sprintf(tempd, "%lf", d2 - d1);
					push3(tempd);
				}
				if (strcmp(temp, "*") == 0)
				{
					strcpy(tempd1, pop3());
					d1 = stringtodoublecast(tempd1);
					strcpy(tempd2, pop3());
					d2 = stringtodoublecast(tempd2);
					sprintf(tempd, "%lf", d2 * d1);
					push3(tempd);
				}
				if (strcmp(temp, "/") == 0)
				{
					strcpy(tempd1, pop3());
					d1 = stringtodoublecast(tempd1);
					strcpy(tempd2, pop3());
					d2 = stringtodoublecast(tempd2);
					if (d1 == 0)
					{
						printf("Error: Divided by zero!\n");
						Sleep(3000);
						exit(0);
					}
					sprintf(tempd, "%lf", d2 / d1);
					push3(tempd);
				}
				if (strcmp(temp, "^") == 0)
				{
					strcpy(tempd1, pop3());
					d1 = stringtodoublecast(tempd1);
					strcpy(tempd2, pop3());
					d2 = stringtodoublecast(tempd2);
					sprintf(tempd, "%lf", pow(d2, d1));
					push3(tempd);
				}
				if (strcmpi(temp, "exp") == 0)
				{
					strcpy(tempd1, pop3());
					d1 = stringtodoublecast(tempd1);
					sprintf(tempd, "%lf", parExp(d1));
					push3(tempd);
				}
				if (strcmpi(temp, "sin") == 0)
				{
					strcpy(tempd1, pop3());
					d1 = stringtodoublecast(tempd1);
					sprintf(tempd, "%lf", parSin(d1));
					push3(tempd);
				}
				if (strcmpi(temp, "cos") == 0)
				{
					strcpy(tempd1, pop3());
					d1 = stringtodoublecast(tempd1);
					sprintf(tempd, "%lf", parCos(d1));
					push3(tempd);
				}
				if (strcmpi(temp, "tan") == 0)
				{
					strcpy(tempd1, pop3());
					d1 = stringtodoublecast(tempd1);
					sprintf(tempd, "%lf", parTan(d1));
					push3(tempd);
				}
				if (strcmpi(temp, "cot") == 0)
				{
					strcpy(tempd1, pop3());
					d1 = stringtodoublecast(tempd1);
					sprintf(tempd, "%lf", parCot(d1));
					push3(tempd);
				}
				if (strcmpi(temp, "sec") == 0)
				{
					strcpy(tempd1, pop3());
					d1 = stringtodoublecast(tempd1);
					sprintf(tempd, "%lf", parSec(d1));
					push3(tempd);
				}
				if (strcmpi(temp, "csc") == 0)
				{
					strcpy(tempd1, pop3());
					d1 = stringtodoublecast(tempd1);
					sprintf(tempd, "%lf", parCsc(d1));
					push3(tempd);
				}
				if (strcmpi(temp, "sinh") == 0)
				{
					strcpy(tempd1, pop3());
					d1 = stringtodoublecast(tempd1);
					sprintf(tempd, "%lf", parSinh(d1));
					push3(tempd);
				}
				if (strcmpi(temp, "cosh") == 0)
				{
					strcpy(tempd1, pop3());
					d1 = stringtodoublecast(tempd1);
					sprintf(tempd, "%lf", parCosh(d1));
					push3(tempd);
				}
				if (strcmpi(temp, "tanh") == 0)
				{
					strcpy(tempd1, pop3());
					d1 = stringtodoublecast(tempd1);
					sprintf(tempd, "%lf", parTanh(d1));
					push3(tempd);
				}
				if (strcmpi(temp, "coth") == 0)
				{
					strcpy(tempd1, pop3());
					d1 = stringtodoublecast(tempd1);
					sprintf(tempd, "%lf", parCoth(d1));
					push3(tempd);
				}
				if (strcmpi(temp, "ln") == 0)
				{
					strcpy(tempd1, pop3());
					d1 = stringtodoublecast(tempd1);
					sprintf(tempd, "%lf", log(d1));
					push3(tempd);
				}
			}
		}
	}
	//------------------------------
}
void push1(char value[20])
{
	NODE *newNode;
	newNode = (NODE*)malloc(sizeof(NODE));
	strcpy(newNode->data, value);
	if (top1 == NULL)
		newNode->next = NULL;
	else
		newNode->next = top1;
	top1 = newNode;
}
char* pop1()
{
	char c[20];
	if (top1 == NULL)
		return "Error";
	else
	{
		NODE *temp = top1;
		strcpy(c, temp->data);
		top1 = temp->next;
		free(temp);
		return c;
	}
}
void display1()
{
	if (top1 == NULL)
		printf("\nStack is Empty!!!\n");
	else
	{
		NODE *temp = top1;
		while (temp != NULL)
		{
			printf("%s--->", temp->data);
			temp = temp->next;
		}
		printf("NULL");
	}
}
void push2(char value[20])
{
	NODE *newNode;
	newNode = (NODE*)malloc(sizeof(NODE));
	strcpy(newNode->data, value);
	if (top2 == NULL)
		newNode->next = NULL;
	else
		newNode->next = top2;
	top2 = newNode;
}
char* pop2()
{
	char c[20];
	if (top2 == NULL)
		return "Error";
	else
	{
		NODE *temp = top2;
		strcpy(c, temp->data);
		top2 = temp->next;
		free(temp);
		return c;
	}
}
void display2()
{
	if (top2 == NULL)
		printf("\nStack is Empty!!!\n");
	else
	{
		NODE *temp = top2;
		while (temp != NULL)
		{
			printf("%s--->", temp->data);
			temp = temp->next;
		}
		printf("NULL");
	}
}
void push3(char value[20])
{
	NODE *newNode;
	newNode = (NODE*)malloc(sizeof(NODE));
	strcpy(newNode->data, value);
	if (top3 == NULL)
		newNode->next = NULL;
	else
		newNode->next = top3;
	top3 = newNode;
}
char* pop3()
{
	char c[20];
	if (top3 == NULL)
		return "Error";
	else
	{
		NODE *temp = top3;
		strcpy(c, temp->data);
		top3 = temp->next;
		free(temp);
		return c;
	}
}
void display3()
{
	if (top3 == NULL)
		printf("\nStack is Empty!!!\n");
	else
	{
		NODE *temp = top3;
		while (temp != NULL)
		{
			printf("%s--->", temp->data);
			temp = temp->next;
		}
		printf("NULL");
	}
}
int priorityOperator(char* input)
{
	if ((strcmp(input, "+") == 0) || (strcmp(input, "-") == 0))
		return 1;
	if ((strcmp(input, "*") == 0) || (strcmp(input, "/") == 0))
		return 2;
	if (strcmp(input, "^") == 0)
		return 3;
	if ((strcmpi(input, "sin") == 0) || (strcmpi(input, "cos") == 0) || (strcmpi(input, "tan") == 0) || (strcmpi(input, "cot") == 0) || (strcmpi(input, "sec") == 0) || (strcmpi(input, "csc") == 0) || (strcmpi(input, "ln") == 0) || (strcmpi(input, "sinh") == 0) || (strcmpi(input, "cosh") == 0) || (strcmpi(input, "tanh") == 0) || (strcmpi(input, "coth") == 0) || (strcmpi(input, "exp") == 0))
		return 4;
	if (strcmp(input, "(") == 0)
		return 5;
	if (strcmp(input, ")") == 0)
		return 6;
	return 0;
}
int intpowerint(int a, int b)
{
	int i, result = a;
	for (i = 0; i < b; i++)
		result *= a;
	result /= a;
	return result;
}
double stringtodoublecast(char* a)
{
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	char b[20];
	int lenght, i, j, sign=1;
	double sum = 0, sum2 = 0;
	for (j = 0; j < 20; j++)
		b[j] = 0;
	strcpy(b, a);
	if (strcmp(b, "Error") == 0)
	{
		SetConsoleTextAttribute(hstdout, FOREGROUND_RED);
		printf("Error");
		Sleep(3000);
		exit(0);
	}
	lenght = strlen(b);
	if (strcmpi(b, "pi") == 0)
		return 3.14159265;
	if (strcmpi(b, "-pi") == 0)
		return -3.14159265;
	if (strcmpi(b, "e") == 0)
		return 2.718281828;
	if (strcmpi(b, "-e") == 0)
		return -2.718281828;
	if (b[0] == '-')
	{
		sign = -1;
		b[0] = 48;
	}
	if ((b[0] < 48) || (b[0] > 57))
	{
		if ((b[0]!='-') && (b[i] != '.'))
		{
			SetConsoleTextAttribute(hstdout, FOREGROUND_RED);
			printf("Error!\n");
			Sleep(3000);
			exit(0);
		}
	}
	for (i = 1; i < lenght; i++)
	{
		if ((b[i] < 48) || (b[i] > 57))
		{
			if (b[i] != '.')
			{
				SetConsoleTextAttribute(hstdout, FOREGROUND_RED);
				printf("Error!\n");
				Sleep(3000);
				exit(0);
			}
		}
	}
	for (i = 0; i < lenght; i++)
		if (b[i] == '.')
			break;
	if (i == lenght - 1)
	{
		for (j = 0; j < lenght; j++)
		{
			sum += (b[j] - 48) * intpowerint(10, i - j);
		}
	}
	else
	{
		for (j = 0; j < i; j++)
		{
			sum += (b[j] - 48) * intpowerint(10, i - (j + 1));
		}
		for (j = i + 1; j < lenght; j++)
		{
			sum2 += (b[j] - 48) * intpowerint(10, lenght - (j + 1));
		}
		sum2 = sum2 / intpowerint(10, lenght - (i + 1));
		sum = sum + sum2;
	}
	return (sum * sign);
}
int parFactoriel(int n)
{
	int i, sum = 1;
	for (i = 0; i < n; i++)
	{
		sum *= (i + 1);
	}
	return sum;
}
double parExp(double x)
{
	int i, Z = floor(x);
	double sum = 0, cross = 1, R = x - floor(x);
	if (R != 0)
	{
		for (i = 0; i < 30; i++)
		{
			sum += pow(R, i) / parFactoriel(i);
			//printf("%lf + ", sum);
		}
	}
	else
		sum = 1;
	for (i = 0; i < Z; i++)
	{
		cross *= 2.718281828;
	}
	return cross*sum;
}
double parSin(double x)
{
	int i;
	double result = 0;
	while (x >= 2 * 3.14159265)
		x -= 2 * 3.14159265;
	while (x < 0)
		x += 2 * 3.14159265;
	if ((x < 0.0001) && (x > -0.0001))
		return 0;
	if ((x < 3.1417 / 2) && (x > 3.1415 / 2))
		return 1;
	if ((x < 3.1417) && (x > 3.1415))
		return 0;
	if ((x < 3 * 3.1417 / 2) && (x > 3 * 3.1415 / 2))
		return -1;
	if ((x > 3.14159265 / 2) && (x < 3 * 3.14159265 / 2))
		x = 3.14159265 - x;
	for (i = 0; i < 10; i++)
	{
		result += pow(-1, i)*pow(x, 2 * i + 1) / parFactoriel(2 * i + 1);
		//printf("%lf + ", sum);
	}
	return result;
}
double parCos(double x)
{
	int i;
	double result = 0;
	while (x >= 2 * 3.14159265)
		x -= 2 * 3.14159265;
	while (x < 0)
		x += 2 * 3.14159265;
	if ((x < 0.0001) && (x > -0.0001))
		return 1;
	if ((x < 3.1417 / 2) && (x > 3.1415 / 2))
		return 0;
	if ((x < 3.1417) && (x > 3.1415))
		return -1;
	if ((x < 3 * 3.1417 / 2) && (x > 3 * 3.1415 / 2))
		return 0;
	if ((x > 3.14159265 / 2) && (x < 3 * 3.14159265 / 2))
		x = 3.14159265 - x;
	for (i = 0; i < 10; i++)
	{
		result += pow(-1, i)*pow(x, 2 * i) / parFactoriel(2 * i);
		//printf("%lf + ", sum);
	}
	return result;
}
double parTan(double x)
{
	double result = 0;
	if ((parCos(x) < 0.001) && (parCos(x) > -0.001))
	{
		printf("Error: Invalid Argument(out of Tan function domain)");
		Sleep(3000);
		exit(0);
	}
	result = parSin(x) / parCos(x);
	return result;
}
double parCot(double x)
{
	double result = 0;
	if ((parSin(x) < 0.001) && (parSin(x) > -0.001))
	{
		printf("Error: Invalid Argument(out of Cot function domain)");
		Sleep(3000);
		exit(0);
	}
	result = parCos(x) / parSin(x);
	return result;
}
double parSec(double x)
{
	double result = 0;
	if ((parCos(x) < 0.001) && (parCos(x) > -0.001))
	{
		printf("Error: Invalid Argument(out of Sec function domain)");
		Sleep(3000);
		exit(0);
	}
	result = 1 / parCos(x);
	return result;
}
double parCsc(double x)
{
	double result = 0;
	if ((parSin(x) < 0.001) && (parSin(x) > -0.001))
	{
		printf("Error: Invalid Argument(out of Csc function domain)");
		Sleep(3000);
		exit(0);
	}
	result = 1 / parSin(x);
	return result;
}
double parSinh(double x)
{
	double result = 0;
	result = (pow(2.718281828, x) - pow(2.718281828, -x)) / 2;
	return result;
}
double parCosh(double x)
{
	double result = 0;
	result = (pow(2.718281828, x) + pow(2.718281828, -x)) / 2;
	return result;
}
double parTanh(double x)
{
	double result = 0;
	result = (pow(2.718281828, x) - pow(2.718281828, -x)) / (pow(2.718281828, x) + pow(2.718281828, -x));
	return result;
}
double parCoth(double x)
{
	double result = 0;
	result = (pow(2.718281828, x) + pow(2.718281828, -x)) / (pow(2.718281828, x) - pow(2.718281828, -x));
	return result;
}