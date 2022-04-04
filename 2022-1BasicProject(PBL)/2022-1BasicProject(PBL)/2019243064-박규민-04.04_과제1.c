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

	printf("Stduent Name: 박규민 \n");

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

int checkFull(STACK* stp)		//<박규민>:가장 먼저 push에서 사용되어지는 함수로 STACK이 꽉차있는지 확인하여 반환값을 주어야합니다.
{//<박규민>:이때 반환값이 0이면 push를 실행하게 되고 아니면은 스택이 꽉찼다고 메시지를 전달하게 됩니다.

	if (stp->top->next != NULL)
	{//<박규민>: STACK에서 제일 마지막 공간에서 그 다음 공간이 NULL(끝)이 아닐 경우 0을 줘서 숫자를 넣게 해주고
		return 0;
	}
	else//<박규민>: 아니고 꽉찼을 경우에는 1을 줘서 스택이 꽉찼다는 push에서의 else문을 실행하게 합니다
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