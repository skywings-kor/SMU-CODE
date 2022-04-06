////2019243064 ��ǻ�Ͱ��к�-�����Ͱ���-�ڱԹ�
////2022-04-05 Test Debug End;
//
//<���� ����> 
//1.����ڷκ��� �Է¹޴� 10���� ������ ����ڰ� ������ ����(2����~ 9����)�� ��ȯ
//2.������ �̿��� ����
//3.������ ����(%)�� ������ ����(/)�� �̿��� ������ȯ���� ����  


#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#pragma warning (disable:4996)
#define MAX 16		 //���� ������(����� �ִ� ����) ����

typedef struct snode		//���Ḯ��Ʈ ���� ����ü 
{
	int data;			//<�ڱԹ�>: ���Ḯ��Ʈ�� ���� data ���� ���� 
	struct snode* next;		//<�ڱԹ�>: ���Ḯ��Ʈ ���� �ּҸ� ����Ű�� ���� ����
}STACKNODE;


typedef struct stack		// ���ÿ� ���Ḯ��Ʈ ����� ����ü 
{
	int counter;		// ���Ḯ��Ʈ�� ����� ��� ���� 
	STACKNODE* top;		 // ���Ḯ��Ʈ ������(�Ǵ� ������ �ֻ���) 
}STACK;

void initiation(STACK* stp);		//���� �ʱ�ȭ 
int checkEmpty(STACK* stp);		// ������ ����ִ��� Ȯ�� (0 �Ǵ� 1��ȯ) 
int checkFull(STACK* stp);		// ������ ���� ���ִ���  Ȯ�� (0 �Ǵ� 1��ȯ) 
void push(STACK* stp, int data);		//���ÿ��� Ǫ�� ���� 
int pop(STACK* stp);		//���ÿ��� �� ����

void main()
{
	STACK st;

	int poppedData;		//<�ڱԹ�>:POP��(��) ���ڸ� ��� �����صδ� ����
	int typeOfCode = 0;		// ����ڰ� �Է��� ��ȯ ���� (2 ~ 9) 
	int decimalValue = 0;		// ����ڰ� �Է��� 10����  
	int remainder = 0;		//������
	int quotient = 0;		// �� 

	printf("Stduent Name: �ڱԹ� \n");

	initiation(&st);		//<�ڱԹ�>: �ʱ�ȭ �� �� ���ִ� �Լ�

	printf("Enter a Decimal Value: ");
	scanf("%d", &decimalValue);		//<�ڱԹ�>: ����ڰ� �Է��� ���� ���ڸ� decimalValue�� �ֽ��ϴ�

	printf("Enter a Type of Code(2~9): ");
	scanf("%d", &typeOfCode);		//<�ڱԹ�>: ����ڰ� �Է��� ���� ��ȯ�� ���ڸ� typeOfCode�� �ֽ��ϴ�

	if (decimalValue < typeOfCode)		// ������ȯ ������ ���⹰�� ���ÿ� Push
	{
		push(&st, decimalValue);
	}

	else
	{//���� ��ȯ �κ�
		quotient = decimalValue;		//<�ڱԹ�>: quotient�� ����ڰ� ���� ���ڸ� ���� ���� �ֽ��ϴ�.
		while (quotient >= typeOfCode)		//<�ڱԹ�>:quotient�� ���� ���� ����ڰ� ���� ��ȯ�� ���ڸ� ���� �� ���� ũ�� ��� �ݺ��մϴ�.
		{
			push(&st, quotient % typeOfCode);		//<�ڱԹ�>: quotient�� ����ڰ� �Է��� ������ȯ�� ���ڷ� ���� �������� push�Լ��� �����ϴ�.
			quotient = quotient / typeOfCode;		//<�ڱԹ�>: quotient�� ����ڰ� �Է��� ������ȯ�� ���ڷ� ������ ����� quotient�� �����մϴ�. 
		}
		if (quotient != 0)		 
		{
			push(&st, quotient);
		}

	}


	//POP �ϴ� ����
	poppedData = 0;
	printf("Converted Value (Radix = %d): ", typeOfCode);
	while (poppedData != -1)		//<�ڱԹ�>: pop���� return�� ���� -1�� �ƴϸ� ��� �ݺ��մϴ�.
	{
		poppedData = pop(&st);		//<�ڱԹ�>: ����κп����� pop���� return �� data�� poppedData�� ���ϴ�
		if (poppedData != -1)		//<�ڱԹ�>: pop���� return �� ���� -1�� �ƴϸ� �ش� ���ǹ��� �����մϴ�
		{
			printf("%d ", poppedData);		//<�ڱԹ�>: ����ڿ��� � ���� pop �Ǿ����� �˷��ݴϴ�.
			
		}
	}
	printf("\n");		//<�ڱԹ�>: ���������� ǥ���� �� �ݺ����� Ż�������� �ش� �ý����� ���߰� ���ݴϴ�.(�Ʒ���)
	system("pause");
}


void initiation(STACK* stp)
{
	stp->counter = 0;		//<�ڱԹ�>:��� ���� ī��Ʈ �ϱ� ���ؼ� 0���� �ʱ�ȭ ������ϴ�!
	stp->top = NULL;		//<�ڱԹ�>:��� �κ��� NULL�� �� �� �ʱ�ȭ ������ϴ�.

}

int checkEmpty(STACK* stp)
{

	if (stp->top == NULL)		//<�ڱԹ�>: ���ÿ����� �ֻ�� ���� NULL�̸� ������ ����ִٴ� ���̴ϱ� 1�� ��ȯ���ְ� �ƴҰ�쿡�� 0�� ��ȯ�Ͽ� ������ �������� �˷��ݴϴ�.
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
	if (stp->counter < MAX)		//<�ڱԹ�>: ���� �ִ� ������(MAX=16)�� ���س��ұ⿡ ���� ������ ī��Ʈ�� ���� MAX���� ���ų� Ŭ��� return 1�� ���ְ� �ƴҰ�쿣 0�� ���ݴϴ�.
	{
		
		return 0;
	}
	else
	{
		return 1;
	}


}

void push(STACK* stp, int data)
{
	if (checkFull(stp) == 0)		//<�ڱԹ�>: checkFull�̶�� �Լ��� ���Ͽ� ������ �����ִ��� �˻����ִµ� �̶� return�� 0�̸� �����մϴ�.
	{
		STACKNODE* newnode = (STACKNODE*)malloc(sizeof(STACKNODE));		//<�ڱԹ�>:���ο� ��带 ���� ���� ��ũ�� ����Ʈ�� ��������ֱ� ���� newnode��� ��带 �Ѱ� ����ϴ�.
		newnode->data = data;		//<�ڱԹ�>: newnode->data�� �ش��ϴ� ������ ����ڰ� �Է��� ���ڿ��� �ش� �������� ������ ������ ������ ����(data) �ֽ��ϴ�.
		newnode->next = stp->top;		//<�ڱԹ�>: �׸��� data�� �ִ� ���� �ƴ� next �������� ��ũ�� ����Ʈ�� ��������ݴϴ�.
		stp->top = newnode; //<�ڱԹ�>: �ֻ�ܿ� ���� ���� ���� newnode�� ������ ���ݴϴ�.
		stp->counter += 1;		//<�ڱԹ�>: ���� �׷��� ��尡 �Ѱ� ���������� �߰� �Ǿ����� ī��Ʈ�� �ϳ����ݴϴ�.
		
		return stp;		//<�ڱԹ�>: ���� main�� ���� push�� ����� �������ֱ� ���� return stp�� ���ݴϴ�
	}

	else               //<�ڱԹ�>:return 1�� ��ȯ�Ǹ� ����Ǵ� ��-��á�ٰ� �ȳ��մϴ�
	{
		printf("The stack is Full! \n");
	}
}

int pop(STACK* stp)
{
	STACKNODE* current;
	int data;
	if (checkEmpty(stp) == 1)		//<�ڱԹ�>: ������ Ȥ�ö� ����ְų� ������ ������ �� ����� �ش� if���� �����ϰ� �մϴ�.
	{
		printf("The stack is empty! \n");
		return -1;		//data�����δ� ������ ���ٴ� ����
	}
	else
	{
		data = stp->top->data;		//<�ڱԹ�>: ���Ḯ��Ʈ ���� data��� ������ �ִ� ���� pop�� ����� data�� �ӽ÷� �־�����ϴ�
		current = stp->top;		//<�ڱԹ�>: ���Ḯ��Ʈ���� delete�� ��ó�� ���� current�� ���� top�� ����Ű�� �մϴ�
		stp->top = stp->top->next;		//<�ڱԹ�>: �׸��� top�� top�� ���� �κ��� ����Ű�� �Ͽ� current�� ���� ������ �ִ� �޸𸮸� �ݳ��� �غ� �մϴ�.

		free(current);		//<�ڱԹ�>: �޸� �ݳ�!

		
		return data;		//<�ڱԹ�>: �������� �ӽ÷� �־�� ���� ���ٴ� ���� �˷��ֱ� ���� pop�� data ������ �����ݴϴ�.
	}
}