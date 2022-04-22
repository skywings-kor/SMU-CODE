#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#pragma warning (disable:4996)

typedef struct node 
{
	int correct;
	struct node* next;
}NODE;

NODE* randnumin(NODE* in_list);
NODE* viewnode(NODE* walker);
NODE* strikecorrectcheck(NODE*list,int f1,int f2,int f3,int f4,int f5,int strikecount);		//���� ������ �Է��� �� 5�� �޾ƿͼ� ���� �´��� Ȯ���ϴ� �Լ�
NODE* ballcorrectcheck(NODE*list,int f1,int f2,int f3,int f4,int f5,int ballcount);		//���� ������ �Է��� �� 5�� �޾ƿͼ� ���� �´��� Ȯ���ϴ� �Լ�

int main(void)
{
	
	NODE* list;
	list= NULL;		//��� ����Ʈ �ʱ�ȭ
	int userin;		//������ 5�ڸ� �Է��� ��
	int res5,res4, res3, res2, res1;		//����ڰ� 5�ڸ� �� �Է��Ѱ� ������ ���� �ӽ� ����
	int ballcount = 0;		//��ī��Ʈ
	int strikecount = 0;		//��Ʈ����ũ ī��Ʈ
	list=randnumin(list);
	
	viewnode(list);

	for (int i = 0;; i++)
	{
		ballcount = 0;
		strikecount = 0;
		//������ �ٽ� �Է����� �� ���� ���� ���������� �ȵǴ� �ʱ�ȭ ���ֱ� ���� ��
	

		printf("\n\n ���߽� ����5�ڸ��� �Է�(1~9)->");
		scanf("%d", &userin);
		if (99999 < userin)
		{
			printf("<error> ���ڰ� �߸� �ԷµǾ����ϴ�.");
		}

		else if (userin == 0)
		{
			printf("���α׷��� �����մϴ�");
			exit(0);
		}
		else
		{
			res5 = userin / 10000;
			userin = userin - res5 * 10000;

			res4 = userin / 1000;
			userin = userin - res4 * 1000;

			res3 = userin / 100;
			userin = userin - res3 * 100;

			res2 = userin / 10;
			userin = userin - res2 * 10;

			res1 = userin;
			printf("%d %d %d %d %d", res5, res4, res3, res2, res1);

			strikecount = strikecorrectcheck(list, res5, res4, res3, res2, res1, ballcount, strikecount);
			ballcount = ballcorrectcheck(list, res5, res4, res3, res2, res1, ballcount, strikecount);
			printf("\n\n%d��Ʈ����ũ %d���Դϴ�.", strikecount, ballcount);

			system("pause");
		}
		


	}


}

NODE* randnumin(NODE* in_list)
{
	int count=0;
	NODE* current = NULL, * follow = NULL,*checker=NULL;
	NODE* newnode;
	

	int temp = 0;

	srand(time(NULL));
	printf("���ݺ��� �������� �ֽ��ϴ�.");

	for (int i = 1; i<=5; i++)
	{
		checker = in_list;		//��� ���ƴٴϸ� �� ���� ��� �����Լ� �ٽ� �ϵ��� �ϴ°�

		follow = in_list;
		current = in_list;
		newnode = (NODE*)malloc(sizeof(NODE));

		temp = (rand() % 9) + 1;
		while (checker != NULL)
		{
			if (checker->correct == temp)
			{
				temp = (rand() % 9) + 1;
			}

			checker = checker->next;
		}


		
		newnode->correct = temp;

		while (current != NULL)
		{
			
			follow = current;
			current = current->next;
		}
		newnode->next = current;
		if (current == in_list)
		{
			in_list = newnode;
		}

		else
		{
			follow->next = newnode;
		}
		
	}

	return in_list;

}

NODE* viewnode(NODE* walker)
{
	if (walker != NULL)
	{
		printf("%d ", walker->correct);
		viewnode(walker->next);
	}

	else
	{
		return walker;
	}
}

NODE* strikecorrectcheck(NODE* list, int f1, int f2, int f3, int f4, int f5,int strikecount)	//���� ������ �Է��� �� 5�� �޾ƿͼ� ���� �´��� Ȯ���ϴ� �Լ�
{
	NODE* walker;
	walker = list;

	//ù��°�ڸ�
	if (walker->correct == f1)
	{
		strikecount = strikecount + 1;
	}

	walker = walker->next;

	//�ι�°�ڸ�
	if (walker->correct == f2)
	{
		strikecount = strikecount + 1;
	}

	walker = walker->next;

	//����°�ڸ�
	if (walker->correct == f3)
	{
		strikecount = strikecount + 1;
	}

	walker = walker->next;

	//�׹�°�ڸ�
	if (walker->correct == f4)
	{
		strikecount = strikecount + 1;
	}

	walker = walker->next;

	//�ټ���°�ڸ�
	if (walker->correct == f5)
	{
		strikecount = strikecount + 1;
	}


	return strikecount;
}

NODE* ballcorrectcheck(NODE* list, int f1, int f2, int f3, int f4, int f5, int ballcount)
{
	NODE* walker;
	walker = list;

	//ù��°�ڸ�
	if ((walker->correct == f2)||(walker->correct==f3) || (walker->correct == f4) || (walker->correct == f5))
	{
		ballcount = ballcount + 1;
	}

	walker = walker->next;

	//�ι�°�ڸ�
	if ((walker->correct == f1) || (walker->correct == f3) || (walker->correct == f4) || (walker->correct == f5))
	{
		ballcount = ballcount + 1;
	}

	walker = walker->next;

	//����°�ڸ�
	if ((walker->correct == f2) || (walker->correct == f1) || (walker->correct == f4) || (walker->correct == f5))
	{
		ballcount = ballcount + 1;
	}

	walker = walker->next;

	//�׹�°�ڸ�
	if ((walker->correct == f2) || (walker->correct == f3) || (walker->correct == f1) || (walker->correct == f5))
	{
		ballcount = ballcount + 1;
	}

	walker = walker->next;

	//�ټ���°�ڸ�
	if ((walker->correct == f2) || (walker->correct == f3) || (walker->correct == f4) || (walker->correct == f1))
	{
		ballcount = ballcount + 1;
	}


	return ballcount;
}