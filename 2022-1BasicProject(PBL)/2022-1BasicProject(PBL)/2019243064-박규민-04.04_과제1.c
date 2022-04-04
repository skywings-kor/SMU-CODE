#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#pragma warning (disable:4996)
#define MAX 16

typedef struct snode
{
	int data;
	struct snode* next;
}STACKNODE;


typedef struct stack
{
	int counter;
	STACKNODE* top;
}STACK;

void initiation(STACK* stp);
int checkEmpty(STACK* stp);
int checkFull(STACK* stp);
void push(STACK* stp, int data);
int pop(STACK* stp);
STACKNODE* newnode = NULL, * current = NULL, * follow = NULL;
void main()
{
	STACK st;

	int poppedData;
	int typeOfCode = 0;
	int decimalValue = 0;
	int remainder = 0;
	int quotient = 0;

	printf("Stduent Name: �ڱԹ� \n");

	initiation(&st);

	printf("Enter a Decimal Value: ");
	scanf("%d", &decimalValue);

	printf("Enter a Type of Code(2~9): ");
	scanf("%d", &typeOfCode);

	if (decimalValue < typeOfCode)
	{
		push(&st, decimalValue);

		
	}
	else
	{
		quotient = decimalValue;
		while (quotient >= typeOfCode)
		{
			push(&st, quotient % typeOfCode);
			quotient = quotient / typeOfCode;
		}
		if (quotient != 0)
		{
			push(&st, quotient);
		}

	}
	//POP
	poppedData = 0;
	printf("Converted Value (Radix = %d): ", typeOfCode);
	while (poppedData != -1)
	{
		poppedData = pop(&st);
		if (poppedData != -1)
		{
			printf("%d", poppedData);
		}
	}
	printf("\n");
	system("pause");
}


void initiation(STACK* stp)
{
	stp->top = (STACKNODE*)malloc(sizeof(STACKNODE));

}

int checkEmpty(STACK* stp)
{
	
	if (stp->top == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int checkFull(STACK* stp)		//<�ڱԹ�>:���� ���� push���� ���Ǿ����� �Լ��� STACK�� �����ִ��� Ȯ���Ͽ� ��ȯ���� �־���մϴ�.
{//<�ڱԹ�>:�̶� ��ȯ���� 0�̸� push�� �����ϰ� �ǰ� �ƴϸ��� ������ ��á�ٰ� �޽����� �����ϰ� �˴ϴ�.

	if (stp->top->next != NULL)
	{//<�ڱԹ�>: STACK���� ���� ������ �������� �� ���� ������ NULL(��)�� �ƴ� ��� 0�� �༭ ���ڸ� �ְ� ���ְ�
		return 0;
	}
	else//<�ڱԹ�>: �ƴϰ� ��á�� ��쿡�� 1�� �༭ ������ ��á�ٴ� push������ else���� �����ϰ� �մϴ�
	{
		return 1;
	}
}

void push(STACK* stp, int data)
{
	if (checkFull(stp) == 0)
	{
		STACKNODE* newnode = (STACKNODE*)malloc(sizeof(STACKNODE));
		newnode->data = data;
		newnode->next = stp->top;
		stp->top = newnode;

		printf("push: %d\n", data);
		return stp;
	}
	else
	{
		printf("The stack is Full! \n");
	}
}

int pop(STACK* stp)
{
	STACKNODE* current;
	int data;
	if (checkEmpty(stp) == 1)
	{
		printf("The stack is empty! \n");
		return -1;
	}
	else
	{
		stp->top->next = stp->top->next->next;
		data = stp->top->data;
		free(stp->top->data);
		return data;
	}
}