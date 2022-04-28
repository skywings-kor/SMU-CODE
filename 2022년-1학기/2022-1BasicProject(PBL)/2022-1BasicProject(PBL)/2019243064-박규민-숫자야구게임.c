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

NODE* randnumin(NODE* in_list);		//���Ḯ��Ʈ�� ������ �־��ִ� �Լ�
NODE* viewnode(NODE* walker);		//���Ḯ��Ʈ �����ִ� �Լ�(�ӽÿ�)
NODE* strikecorrectcheck(NODE*list,int f1,int f2,int f3,int f4,int f5,int strikecount);		//���� ������ �Է��� �� 5�� �޾ƿͼ� ���� �´��� Ȯ���ϴ� �Լ�
NODE* ballcorrectcheck(NODE*list,int f1,int f2,int f3,int f4,int f5,int ballcount);		//���� ������ �Է��� �� 5�� �޾ƿͼ� ���� �´��� Ȯ���ϴ� �Լ�

int loginpage(char userinid[20], char userinpw[20]);		//�α��� ��� �Լ�
int usercreate(char createid[20], char createpw[20]);

int main(void)
{
	printf("                                     <SMU-2019243064-��ǻ�Ͱ��к�-�ڱԹ�>\n\n");
	//�α��� �����ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�
	int userlogin;		//���� �α����Ұ��� ȸ�������Ұ��� ��й�ȣã���Ұ��� ���α׷� �����Ұ��� ������ ����
	int success;		//�α��� ������ ��ȯ�� �޴°�
	char userid[20];		//�α���->���̵� �Է��Ѱ�
	char userpw[20];		//�α���->����Է��Ѱ�

	char createid[20];
	char createpw[20];
	int createsuccess;

	for (int k = 0;; k++)		//�α����̳� ȸ�������̳� ��й�ȣ ã�� ���н� ���ƿ��� �ϱ����� for��
	{
		system("cls");
		success = 0;
		createsuccess = 0;
		userlogin = 0;

		printf("                       <1> �α���           <2> ȸ������           <3> ��й�ȣ ã��           <0> ���α׷� ����");
		scanf("%d", &userlogin);
	
		
		if (userlogin == 1)		//�α���
		{

			printf("���̵� �Է����ּ���: ");
			scanf("%s", userid);

			printf("��й�ȣ�� �Է����ּ���: ");
			scanf("%s", userpw);

			success=loginpage(userid,userpw);

			if (success == 1)
			{
				printf("                       �α��� ����\n\n");
				break;
			}

			else
			{
				printf("                       ID�Ǵ� PW�� �߸��Ǿ����ϴ�\n\n");
				system("pause");
			}
		}

		else if (userlogin == 2)		//ȸ������
		{
			printf("����� ID�Է�: ");
			scanf("%s", createid);

			printf("����� PW�Է�: ");
			scanf("%s", createpw);

			createsuccess=usercreate(createid, createpw);
		}

		else if (userlogin == 3)
		{

		}

		else if (userlogin == 0)			//���α׷� ����
		{
			printf("���α׷��� �����մϴ�.");
			system("pause");
			exit(0);
		}

		else
		{
			printf("�ٽ� �Է����ּ���");
		}

	}

	
	NODE* list;
	list= NULL;		//��� ����Ʈ �ʱ�ȭ
	int userin;		//������ 5�ڸ� �Է��� ��
	int res5,res4, res3, res2, res1;		//����ڰ� 5�ڸ� �� �Է��Ѱ� ������ ���� �ӽ� ����
	int ballcount = 0;		//��ī��Ʈ
	int strikecount = 0;		//��Ʈ����ũ ī��Ʈ

	list=randnumin(list);		//���� ���Ḯ��Ʈ�� ������ �־��ִ� �Լ� ����� ���ϰ� �־��ֱ�
	

	for (int i = 1;; i++)		//���ѷ���
	{
		printf("\n�ѤѤѤ�%d��° ��ȸ�ѤѤѤ�",i);
		userin = 0;
		ballcount = 0;
		strikecount = 0;
		//������ �ٽ� �Է����� �� ���� ���� ���������� �ȵǴ� �ʱ�ȭ ���ֱ� ���� ��
	

		printf("\n���߽� ����5�ڸ��� �Է�(1~9, tip:0�� �Է½� ����˴ϴ�)->");

		scanf("%d", &userin);
		if (userin == 0)
		{
			printf("\n!!���α׷��� �����մϴ�!!");
			system("pause");
			exit(0);
		}

		else if ((10000>userin) || (99999 < userin))
		{
			printf("\n<error> ���ڰ� �߸� �ԷµǾ����ϴ�.\n");
			i = i - 1;
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
			printf("\n%d��Ʈ����ũ %d���Դϴ�.\n", strikecount, ballcount);

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

			else
			{
				checker = checker->next;
			}
			
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

//�α��� �Լ�			�α��� �Լ�				�α��� �Լ�			�α��� �Լ�					�α��� �Լ�					�α��� �Լ�
int loginpage(char userinid[20], char userinpw[20])		
{
	FILE* fp;
	fp = fopen("user.txt", "r");

	char str[60];
	char* id;
	char* pw;
	while (!feof(fp))
	{
		fgets(str, sizeof(str), fp);
		id = strtok(str, " ");
		pw = strtok(NULL, " ");

		if ((strcmp(userinid, id) == 0) && (strcmp(userinpw, pw) == 0))
		{
			return 1;	//�α��ο� �����Ұ��
			break;
		}


	}

	return 0;		//�α��ο� ������ ���

}

int usercreate(char createid[20], char createpw[20])
{
	FILE* fp;
	fp = fopen("user.txt", "r");

	char str[60];
	char* id;
	char* pw;
	while (!feof(fp))
	{
		fgets(str, sizeof(str), fp);
		id = strtok(str, " ");
		pw = strtok(NULL, " ");

		if (strcmp(createid, id) == 0)
		{
			return 1;		//���� ���̵� �̹� �����
			break;
		}


	}
	//fp = fclose("user.txt");

	fp = fopen("user.txt", "a");
	//���Ͽ� �Է³ִ°� �����ؾ����̾
	
	

}