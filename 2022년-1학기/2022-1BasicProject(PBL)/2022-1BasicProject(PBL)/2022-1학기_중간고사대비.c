////���Ḯ��Ʈ? -> ���� �ڷ����� �� �����̴�
//
////malloc �Լ��� �̿��� �޸� �Ҵ�
//
////������ ������ �����ΰ�? -> �ּҰ��� �����ϴ� �����Դϴ�
//
////int *y�� ������ �ϸ�-> y�� �׳� ���� �Ҵ� �޸� ���� ���� �ǹ��մϴ�
////& �����ڴ� ������ �ּ� ���� ��ȯ�ϹǷ� ����� �ƴ� ������ �ǿ������̾�� �Ѵ�.
////& �������� ��ȯ ���� ������ ������ ������ �Ѵ�.
////ex�� int num=10 �ϰ� int *y=&num �̷��� �����ϸ� y���� num�� �ּҰ��� ���� *y�� printf�� 10�� �����Եȴ�
//// 
////���� �ּҸ� ���� ������ �׳� y�� printf�ϰ� &num�� printf�ϸ� �ΰ��� �ּҰ� ������ �� �� �ִ�.(61626=61626 ���÷� �̷���)
//
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<time.h>
//
//#pragma warning(disable:4996)
//
//
////
///////////////////////////////////////////////////������ Ȱ�� ����-made by �ڱԹ�
////int main()
////{
////	int num = 10;
////	int* y=&num;
////	printf("�������� ������ ���-> %d \n", *y);
////	printf("������y�� ����Ű�� �ּ�-> %d\n", y);
////	printf("����10�� ���� num�� �ּ�-> %d", &num);
////
////	return 0;
////}
//
//////////////////////////////////////////////////���Ḯ��Ʈ Ȱ��
//
//typedef struct node
//{
//	char id[20];
//	int password;
//	struct node* next;
//}NODE;
//
//NODE* insertnode(NODE* inlist,char uid[20], int ps);
//NODE* viewnode(NODE* showlist);
//NODE* delnode(NODE* dellist,char did[20]);
//NODE* searchnode(NODE* searchlist,char sid[20]);
//
//int main()
//{
//	NODE* list;
//	list = NULL;
//
//	int user;
//
//	char fid[20];
//	char sid[20];
//	int fps;
//	for (int i = 0; ; i++)
//	{
//		system("cls");
//		printf("�ϰ���� �׸��� �����ּ���(1.�߰� �� 2.����	�� 3.�˻�	��	4.����");
//		scanf("%d", &user);
//
//		if (user == 1)
//		{
//			printf("����� id �Է�: ");
//			scanf("%s", fid);
//
//			printf("��й�ȣ �Է�: ");
//			scanf("%d", &fps);
//
//			list=insertnode(list, fid, fps);
//
//			printf("����Ǿ����ϴ�\n");
//			viewnode(list);
//			system("pause");
//		}
//
//		else if (user == 2)
//		{
//			printf("���� ID �Է�: ");
//			scanf("%s", fid);
//
//			list = delnode(list, fid);
//
//			
//			system("pause");
//
//		}
//
//		else if (user == 3)
//		{
//			printf("ã�� ID �Է�: ");
//			scanf("%s", sid);
//			searchnode(list, sid);
//
//			system("pause");
//		}
//
//		else if (user == 4)
//		{
//			printf("�ý����� �����մϴ�");
//			exit(0);
//		}
//
//
//	}
//
//}
//NODE* viewnode(NODE* walker)
//{
//		if (walker == NULL)
//		{
//			printf("==End of Print====\n");
//		}
//		else
//		{
//			printf("%s %d\n", walker->id, walker->password);
//			viewnode(walker->next);
//		}
//
//}
//NODE* insertnode(NODE* inlist, char name[20], int age)
//{
//	
//	NODE* newnode,*current,*follow;
//	current = NULL;
//	follow = NULL;
//	newnode = (NODE*)malloc(sizeof(NODE));
//
//	current=inlist;
//	follow = inlist;
//
//
//	while(current!=NULL)
//	{
//		follow = current;
//		current = current->next;
//	}
//	strcpy(newnode->id, name);
//	newnode->password = age;
//	newnode->next = current;
//	if (current == inlist)
//	{
//		inlist = newnode;
//	}
//
//	else
//	{
//		follow->next = newnode;
//	}
//
//	
//
//
//	
//
//
//	return inlist;
//}
//
//NODE* delnode(NODE* dellist,char did[20])
//{
//	NODE* current, * follow;
//	current = NULL;
//	follow = NULL;
//	current = dellist;
//	follow = dellist;
//
//	if (strcmp(current->id, did) == 0)
//	{
//		dellist = current->next;
//		free(current);
//
//		viewnode(dellist);
//
//		printf("\n\n���������� ���������ϴ�");
//		return dellist;
//	}
//
//	while (current != NULL)
//	{
//		if (strcmp(current->id,did)==0)
//		{
//
//			if (current->next == NULL)
//			{
//				follow->next = NULL;
//				free(current);
//				viewnode(dellist);
//
//				printf("\n\n���������� ���������ϴ�");
//				return dellist;
//			}
//
//			follow->next = current->next;
//			free(current);
//
//			viewnode(dellist);
//
//			printf("\n\n���������� ���������ϴ�");
//			return dellist;
//
//		}
//
//		follow = current;
//		current = current->next;
//		
//		
//	}
//
//	printf("�߸� �Է��ϼ̽��ϴ�");
//}
//
//NODE* searchnode(NODE* searchlist, char sid[20])
//{
//	if (searchlist == NULL)
//	{
//		printf("id�� ã�� �� �����ϴ�");
//		return searchlist;
//	}
//	if (strcmp(searchlist->id,sid)==0)
//	{
//		printf("%s %d",searchlist->id,searchlist->password);
//	}
//
//	else
//	{
//		searchlist = searchlist->next;
//		searchnode(searchlist, sid);
//	}
//}

//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#pragma warning (disable:4996)
//
//typedef struct node {
//	char id[20];
//	int age;
//	struct node* next;
//}NODE;
//
//NODE* insertnode(NODE* inlist, char inid[20],int inage);
//NODE* viewnode(NODE* walker);
//NODE* delnode(NODE* delist, char delname[20]);
//NODE* searchsys(NODE* slist, char sname[20]);
//
//int main()
//{
//	NODE* list;
//	list = NULL;
//	int choiceuser;
//	char name[20];
//	int pass;
//	char delname[20];
//	
//	for (int i = 0;; i++)
//	{
//		system("cls");
//		printf("�������ּ���1)����, 2)����, 3)�˻�, 4)����");
//		scanf("%d", &choiceuser);
//
//		if (choiceuser == 1)
//		{
//			printf("�̸��� �Է����ּ���");
//			scanf("%s", name);
//			printf("���̸� �Է����ּ���:");
//			scanf("%d", &pass);
//			list = insertnode(list, name, pass);
//
//			viewnode(list);
//			system("pause");
//		}
//
//		else if (choiceuser == 2)
//		{
//			printf("���� �̸��Է�:");
//			scanf("%s", delname);
//
//			list=delnode(list, delname);
//
//			viewnode(list);
//			system("pause");
//
//		}
//
//		else if (choiceuser == 3)
//		{
//			printf("ã�� �̸��Է�: ");
//			scanf("%s", name);
//			searchsys(list, name);
//			system("pause");
//		}
//
//		else if (choiceuser == 4)
//		{
//			printf("�ý����� �����մϴ�");
//			exit(0);
//		}
//	}
//	
//
//}
//
//NODE* insertnode(NODE* inlist, char inid[20], int inage)
//{
//	NODE* newnode;
//	NODE* current=NULL,*follow=NULL;
//	
//	newnode = (NODE*)malloc(sizeof(NODE));
//	
//	strcpy(newnode->id, inid);
//	newnode->age = inage;
//
//	current = inlist;
//	follow = inlist;
//
//	while (current != NULL)
//	{
//		follow = current;
//		current = current->next;
//	}
//
//	newnode->next = current;
//	
//	if (current == inlist)
//	{
//		inlist = newnode;
//	}
//
//	else
//	{
//		follow->next = newnode;
//	}
//
//	return inlist;
//	
//	
//
//	
//}
//
//NODE* viewnode(NODE* walker)
//{
//	if (walker != NULL)
//	{
//		printf("%s %d \n", walker->id, walker->age);
//
//		return viewnode(walker->next);
//	}
//
//	else
//	{
//		printf("�ѤѤѤѤѤ�end�ѤѤѤѤѤ�");
//
//		return walker;
//	}
//
//}
//
//NODE* delnode(NODE* delist,char delname[20])
//{
//	NODE* current = NULL, * follow = NULL;
//
//	current = delist;
//	follow = delist;
//
//	while (current != NULL)
//	{
//
//		if (strcmp(current->id, delname) == 0)
//		{
//			if (current->next == NULL)
//			{
//				follow->next = NULL;
//				free(current);
//
//				return delist;
//			}
//
//			else if (follow == delist)
//			{
//				delist = current->next;
//				free(current);
//
//				return delist;
//			}
//
//			else
//			{
//				follow->next = current->next;
//				free(current);
//
//				return delist;
//			}
//
//		}
//
//		
//		follow = current;
//		current = current->next;
//	}
//
//	printf("���� ���� �����ϴ�..");
//	return delist;
//
//}
//
//NODE* searchsys(NODE* slist, char sname[20])
//{
//	NODE* walker=NULL;
//	walker = slist;
//	while (walker!=NULL)
//	{
//		if (strcmp(walker->id, sname) == 0)
//		{
//			printf("\n%s %d", walker->id, walker->age);
//
//			return slist;
//		}
//		
//		walker = walker->next;
//
//	}
//
//	printf("�̸��� ã�� ���Ͽ����ϴ�.");
//	return slist;
//}

//#include <stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#pragma warning(disable:4996)
//
//typedef struct taginfo
//{
//	char id[30];
//	int rssi;
//	char identifiedTime[15];
//	struct taginfo* next;
//}TAGINFO;
//
//TAGINFO* stringSplit(TAGINFO* head, char data[]);
//double avgRSSI(TAGINFO* head, char id[]);
//
//int main()
//{
//	char testID[30] = "";
//	char str[300];
//	FILE* fp;
//	fp = fopen("RFID_Data.txt", "r");
//	TAGINFO*list = NULL;
//
//	while (!feof(fp))	//������ ���ϰ�� �ݺ��� ����
//	{
//		fgets(str, 299, fp);
//
//		list = stringSplit(list, str);
//
//		printf("%s \n%d \n%s", list->id, list->rssi, list->identifiedTime);
//	}
//
//
//	return 0;
//}
//
//TAGINFO* stringSplit(TAGINFO* head, char data[])
//{
//	char* result;
//	TAGINFO* newnode;
//	newnode = (TAGINFO*)malloc(sizeof(TAGINFO));
//
//	result = strtok(data, " =,T");
//
//	while (result != NULL)
//	{
//		if (strcmp(result, "tag_id") == 0)
//		{
//			result = strtok(NULL, " =,T");
//			strcpy(newnode->id, result);
//		}
//
//		else if (strcmp(result, "rssi") == 0)
//		{
//			result = strtok(NULL, " =,T");
//			newnode->rssi = atoi(result);
//		}
//
//		else if (strcmp(result, "time") == 0)
//		{
//			result = strtok(NULL, " =,T");
//			result = strtok(NULL, " =,T");		//�ð��� �������� ���� �� ���� strtok
//			strcpy(newnode->identifiedTime, result);
//
//		}
//		else
//		{
//			result=strtok(NULL, " =,T");
//		}
//
//
//
//	}
//	newnode->next = head;
//	head = newnode;
//
//	return head;
//
//}


//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#pragma warning (disable:4996)
//
//typedef struct node
//{
//	char name[20];
//	int age;
//	struct node* next;
//}NODE;
//
//NODE* insertnode(NODE* inlist,char str[]);
//NODE* viewnode(NODE* viewlist);
//int main()
//{
//	NODE* list;
//	list = NULL;
//	char str[100];
//	FILE* fp;
//	fp = fopen("datafile1.txt", "r");
//	while (!feof(fp))
//	{
//		fgets(str, 99, fp);
//		list=insertnode(list, str);
//		
//	}
//
//	fp = fopen("datafile2.txt", "r");
//	while (!feof(fp))
//	{
//		fgets(str, 99, fp);
//		list = insertnode(list, str);
//
//	}
//	viewnode(list);
//
//
//	return 0;
//}
//
//NODE* insertnode(NODE* inlist, char str[])
//{
//	NODE* current,*follow, * newnode;
//	newnode = (NODE*)malloc(sizeof(NODE));
//
//	current = inlist;
//	follow = inlist;
//	char* result;
//	char resname;
//	int resage;
//
//	result = strtok(str, "\t");
//
//	strcpy(newnode->name, result);
//
//	result = strtok(NULL, "\t");
//	newnode->age = atoi(result);
//
//	while ((current != NULL)&&(current->age<newnode->age))
//	{
//		follow = current;
//		current = current->next;
//	}
//	newnode->next = current;
//
//	if (current == inlist)
//	{
//		inlist = newnode;
//	}
//
//	else
//	{
//		follow->next = newnode;
//	}
//
//	return inlist;
//	
//}
//
//NODE* viewnode(NODE* viewlist)
//{
//	NODE* walker;
//	walker = viewlist;
//	if (walker != NULL)
//	{
//		printf("�̸�:%s, ����:%d \n", walker->name, walker->age);
//		return viewnode(viewlist->next);
//	}
//
//	else
//	{
//		return viewlist;
//	}
//
//
//}


//������ ������ �����ΰ�?
//-> ������ ������ �ּҰ��� �����ϴ� �����Դϴ�.
//%p�� �ϸ� �ּҸ� ����ϴ°Ű�
//�̋� printf���� &������ �̸� �մϴ�.

//&������ -> �ּҰ� ǥ��
//������=&���� => �ּҰ� ����


////���ڿ� �ٷ�� �Լ�
//strcmp(, )
//strcpy(, )
//atoi(???)
//strtok(~~~," =")
//
////���Ḯ��Ʈ ����
//��� �̿��ؼ� ���� ���� ���ϴ� ���Ḯ��Ʈ ����
//�ڱ� ��ġ ã�ư��� �ֵ���
//���Ḯ��Ʈ �˻�
//Ư����� ����
//void search()
//void delete()
//
//�迭-> �迭���� ? �ּ��̴�.
//
//fgets()-> ���� �Է� �޾ƿ��� ���� ���� �������°�
//
//���Ḯ��Ʈ �ڷ�part1, part2 ����
//
//datafile 1�� �ְ� �о �̸� ������ ���Ḯ��Ʈ�� �Է�, ���ĵȰ� ���
//
//#include <stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#pragma warning (disable:4996)
//
//typedef struct node
//{
//	char name[20];
//	int age;
//	struct node* next;
//
//}NODE;
//
//NODE* inputnode(NODE* inlist, char inname[20], int inage);
//NODE* viewnode(NODE* walker);
//NODE* delnode(NODE* delist,char delname[20]);
//
//int main()
//{
//	NODE* list;
//	list = NULL;
//
//	int userse;
//	char inname[20];
//	int inage;
//
//	for (int i = 0;; i++)
//	{
//		system("cls");
//
//		printf("���� 1)�ֱ�, 2)����, 3)�˻�, 4)����");
//		scanf("%d", &userse);
//
//		if (userse == 1)
//		{
//			printf("�̸��Է�");
//			scanf("%s", inname);
//			printf("���� �Է�");
//			scanf("%d", &inage);
//			list = inputnode(list, inname,inage);
//
//			viewnode(list);
//
//			system("pause");
//		}
//
//		else if (userse == 2)
//		{
//			printf("���� �̸�:");
//			scanf("%s", inname);
//			list = delnode(list, inname);
//
//			viewnode(list);
//			system("pause");
//		}
//	}
//
//
//
//
//
//
//	return 0;
//}
//
//NODE* inputnode(NODE* inlist, char inname[20],int inage)
//{
//	NODE* current, * follow, * newnode;
//	newnode = (NODE*)malloc(sizeof(NODE));
//
//	current = inlist;
//	follow = inlist;
//
//	strcpy(newnode->name, inname);
//	newnode->age = inage;
//
//	while ((current != NULL) && (current->age < newnode->age))
//	{
//		follow = current;
//		current = current->next;
//	}
//	newnode->next = current;
//
//	if (current == inlist)
//	{
//		inlist = newnode;
//	}
//
//	else
//	{
//		follow->next = newnode;
//	}
//
//	return inlist;
//
//}
//
//NODE* viewnode(NODE* walker)
//{
//	if (walker != NULL)
//	{
//		printf("�̸�: %s, ����:%d \n", walker->name, walker->age);
//		return viewnode(walker->next);
//	}
//
//	else
//	{
//		return walker;
//	}
//
//}
//
//NODE* delnode(NODE* delist, char delname[20])
//{
//	NODE* current,*follow;
//	current = delist;
//	follow = delist;
//	
//	while (current != NULL)
//	{
//		if (strcmp(current->name, delname) == 0)
//		{
//			break;
//		}
//
//		follow = current;
//		current = current->next;
//	}
//
//	if (current == delist)
//	{
//		delist = current->next;
//		free(current);
//
//		return delist;
//	}
//
//	else
//	{
//		follow->next = current->next;
//		free(current);
//
//		return delist;
//	}
//
//
//
//
//}


//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#pragma warning (disable:4996)
//
//typedef struct node
//{
//	char name[20];
//	int age;
//	struct node* next;
//}NODE;
//
//NODE* insertnode(NODE* inlist, char str[100]);
//NODE* viewnode(NODE* walker);
//int main()
//{
//	NODE* list;
//	list = NULL;
//	FILE* fp;
//	fp = fopen("datafile1.txt", "r");
//
//	char str[100];
//
//	while (!feof(fp))
//	{
//		fgets(str, 99, fp);
//		list=insertnode(list, str);
//
//	}
//	viewnode(list);
//	return 0;
//}
//
//NODE* insertnode(NODE* inlist, char str[100])
//{
//	char *result;
//	NODE* current, * follow, * newnode;
//	newnode = (NODE*)malloc(sizeof(NODE));
//
//	current = inlist;
//	follow = inlist;
//
//	result=strtok(str, "\t");
//	strcpy(newnode->name, result);
//
//	result = strtok(NULL, "\t");
//	newnode->age = atoi(result);
//
//
//	while ((current != NULL)&&(current->age<newnode->age))
//	{
//		follow = current;
//		current = current->next;
//	}
//	newnode->next = current;
//
//	if (current == inlist)
//	{
//		inlist = newnode;
//		return inlist;
//	}
//	else
//	{
//		follow->next = newnode;
//	}
//
//	return inlist;
//
//	
//
//}
//
//NODE* viewnode(NODE* walker)
//{
//	if (walker != NULL)
//	{
//		printf("�̸�:%s, ����:%d\n", walker->name, walker->age);
//		return viewnode(walker->next);
//	}
//
//	else
//	{
//		return walker;
//	}
//}

////2019243064 ��ǻ�Ͱ��к�-�����Ͱ���-�ڱԹ�
////2022-04-05 Test Debug End;
//
//<���� ����> 
//1.����ڷκ��� �Է¹޴� 10���� ������ ����ڰ� ������ ����(2����~ 9����)�� ��ȯ
//2.������ �̿��� ����
//3.������ ����(%)�� ������ ����(/)�� �̿��� ������ȯ���� ����  

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)
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

void initation(STACK* stp);
int checkEmpty(STACK* stp);
int checkFull(STACK* stp);
void push(STACK* stp, int data);
int pop(STACK* stp);

void main()
{
	int user;
	int change;
	int temp=0;
	STACK st;
	initation(&st);

	printf("��ȯ�ϱ� �� ����:");
	scanf("%d", &user);

	printf("������ȯ�� ����:");
	scanf("%d", &change);

	if (user < change)
	{
		push(&st, user);
	}
	else
	{
		temp = user;

		while (change <= temp)
		{
			push(&st, temp % change);
			temp = temp / change;
		}
		if (temp != 0)
		{
			push(& st, temp);
		}
	}

	int popdata = 0;

	while (popdata != -1)
	{
		popdata = pop(&st);

		if (popdata != -1)
		{
			printf("%d ", popdata);
		}
	}

	system("pause");

}


void initation(STACK* stp)
{
	stp->counter = 0;
	stp->top = NULL;
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
int checkFull(STACK* stp)
{
	if (stp->counter > MAX)
	{
		return 1;
	}

	else
	{
		return 0;
	}
}
void push(STACK* stp, int data)
{
	if (checkFull(stp)==0)
	{
		STACKNODE* newnode;
		newnode = (STACKNODE*)malloc(sizeof(STACKNODE));
		newnode->data = data;
		newnode->next = stp->top;
		stp->top = newnode;
		stp->counter += 1;

		return stp;

	}
	else
	{
		printf("��á���ϴ�");
	}




}
int pop(STACK* stp)
{
	STACKNODE* current;
	int data;
	if (checkEmpty(stp) == 0)
	{
		data=stp->top->data;
		current = stp->top;
		stp->top = stp->top->next;

		free(current);

		return data;
	}

	else
	{
		printf("��������ϴ�");
		return -1;
	}
}

//
//#include <stdio.h>
//#include <stdlib.h>
//#include<string.h>
//#pragma warning (disable:4996)
//#define MAX 16		 //���� ������(����� �ִ� ����) ����
//
//typedef struct snode		//���Ḯ��Ʈ ���� ����ü 
//{
//	int data;			//<�ڱԹ�>: ���Ḯ��Ʈ�� ���� data ���� ���� 
//	struct snode* next;		//<�ڱԹ�>: ���Ḯ��Ʈ ���� �ּҸ� ����Ű�� ���� ����
//}STACKNODE;
//
//
//typedef struct stack		// ���ÿ� ���Ḯ��Ʈ ����� ����ü 
//{
//	int counter;		// ���Ḯ��Ʈ�� ����� ��� ���� 
//	STACKNODE* top;		 // ���Ḯ��Ʈ ������(�Ǵ� ������ �ֻ���) 
//}STACK;
//
//void initiation(STACK* stp);		//���� �ʱ�ȭ 
//int checkEmpty(STACK* stp);		// ������ ����ִ��� Ȯ�� (0 �Ǵ� 1��ȯ) 
//int checkFull(STACK* stp);		// ������ ���� ���ִ���  Ȯ�� (0 �Ǵ� 1��ȯ) 
//void push(STACK* stp, int data);		//���ÿ��� Ǫ�� ���� 
//int pop(STACK* stp);		//���ÿ��� �� ����
//
//void main()
//{
//	STACK st;
//
//	int poppedData;		//<�ڱԹ�>:POP��(��) ���ڸ� ��� �����صδ� ����
//	int typeOfCode = 0;		// ����ڰ� �Է��� ��ȯ ���� (2 ~ 9) 
//	int decimalValue = 0;		// ����ڰ� �Է��� 10����  
//	int remainder = 0;		//������
//	int quotient = 0;		// �� 
//
//	printf("Stduent Name: �ڱԹ� \n");
//
//	initiation(&st);		//<�ڱԹ�>: �ʱ�ȭ �� �� ���ִ� �Լ�
//
//	printf("Enter a Decimal Value: ");
//	scanf("%d", &decimalValue);		//<�ڱԹ�>: ����ڰ� �Է��� ���� ���ڸ� decimalValue�� �ֽ��ϴ�
//
//	printf("Enter a Type of Code(2~9): ");
//	scanf("%d", &typeOfCode);		//<�ڱԹ�>: ����ڰ� �Է��� ���� ��ȯ�� ���ڸ� typeOfCode�� �ֽ��ϴ�
//
//	if (decimalValue < typeOfCode)		// ������ȯ ������ ���⹰�� ���ÿ� Push
//	{
//		push(&st, decimalValue);
//	}
//
//	else
//	{//���� ��ȯ �κ�
//		quotient = decimalValue;		//<�ڱԹ�>: quotient�� ����ڰ� ���� ���ڸ� ���� ���� �ֽ��ϴ�.
//		while (quotient >= typeOfCode)		//<�ڱԹ�>:quotient�� ���� ���� ����ڰ� ���� ��ȯ�� ���ڸ� ���� �� ���� ũ�� ��� �ݺ��մϴ�.
//		{
//			push(&st, quotient % typeOfCode);		//<�ڱԹ�>: quotient�� ����ڰ� �Է��� ������ȯ�� ���ڷ� ���� �������� push�Լ��� �����ϴ�.
//			quotient = quotient / typeOfCode;		//<�ڱԹ�>: quotient�� ����ڰ� �Է��� ������ȯ�� ���ڷ� ������ ����� quotient�� �����մϴ�. 
//		}
//		if (quotient != 0)		 
//		{
//			push(&st, quotient);
//		}
//
//	}
//
//
//	//POP �ϴ� ����
//	poppedData = 0;
//	printf("Converted Value (Radix = %d): ", typeOfCode);
//	while (poppedData != -1)		//<�ڱԹ�>: pop���� return�� ���� -1�� �ƴϸ� ��� �ݺ��մϴ�.
//	{
//		poppedData = pop(&st);		//<�ڱԹ�>: ����κп����� pop���� return �� data�� poppedData�� ���ϴ�
//		if (poppedData != -1)		//<�ڱԹ�>: pop���� return �� ���� -1�� �ƴϸ� �ش� ���ǹ��� �����մϴ�
//		{
//			printf("%d ", poppedData);		//<�ڱԹ�>: ����ڿ��� � ���� pop �Ǿ����� �˷��ݴϴ�.
//			
//		}
//	}
//	printf("\n");		//<�ڱԹ�>: ���������� ǥ���� �� �ݺ����� Ż�������� �ش� �ý����� ���߰� ���ݴϴ�.(�Ʒ���)
//	system("pause");
//}
//
//
//void initiation(STACK* stp)
//{
//	stp->counter = 0;		//<�ڱԹ�>:��� ���� ī��Ʈ �ϱ� ���ؼ� 0���� �ʱ�ȭ ������ϴ�!
//	stp->top = NULL;		//<�ڱԹ�>:��� �κ��� NULL�� �� �� �ʱ�ȭ ������ϴ�.
//
//}
//
//int checkEmpty(STACK* stp)
//{
//
//	if (stp->top == NULL)		//<�ڱԹ�>: ���ÿ����� �ֻ�� ���� NULL�̸� ������ ����ִٴ� ���̴ϱ� 1�� ��ȯ���ְ� �ƴҰ�쿡�� 0�� ��ȯ�Ͽ� ������ �������� �˷��ݴϴ�.
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//int checkFull(STACK* stp)		//<�ڱԹ�>:���� ���� push���� ���Ǿ����� �Լ��� STACK�� �����ִ��� Ȯ���Ͽ� ��ȯ���� �־���մϴ�.
//{//<�ڱԹ�>:�̶� ��ȯ���� 0�̸� push�� �����ϰ� �ǰ� �ƴϸ��� ������ ��á�ٰ� �޽����� �����ϰ� �˴ϴ�.
//	if (stp->counter < MAX)		//<�ڱԹ�>: ���� �ִ� ������(MAX=16)�� ���س��ұ⿡ ���� ������ ī��Ʈ�� ���� MAX���� ���ų� Ŭ��� return 1�� ���ְ� �ƴҰ�쿣 0�� ���ݴϴ�.
//	{
//		
//		return 0;
//	}
//	else
//	{
//		return 1;
//	}
//
//
//}
//
//void push(STACK* stp, int data)
//{
//	if (checkFull(stp) == 0)		//<�ڱԹ�>: checkFull�̶�� �Լ��� ���Ͽ� ������ �����ִ��� �˻����ִµ� �̶� return�� 0�̸� �����մϴ�.
//	{
//		STACKNODE* newnode = (STACKNODE*)malloc(sizeof(STACKNODE));		//<�ڱԹ�>:���ο� ��带 ���� ���� ��ũ�� ����Ʈ�� ��������ֱ� ���� newnode��� ��带 �Ѱ� ����ϴ�.
//		newnode->data = data;		//<�ڱԹ�>: newnode->data�� �ش��ϴ� ������ ����ڰ� �Է��� ���ڿ��� �ش� �������� ������ ������ ������ ����(data) �ֽ��ϴ�.
//		newnode->next = stp->top;		//<�ڱԹ�>: �׸��� data�� �ִ� ���� �ƴ� next �������� ��ũ�� ����Ʈ�� ��������ݴϴ�.
//		stp->top = newnode; //<�ڱԹ�>: �ֻ�ܿ� ���� ���� ���� newnode�� ������ ���ݴϴ�.
//		stp->counter += 1;		//<�ڱԹ�>: ���� �׷��� ��尡 �Ѱ� ���������� �߰� �Ǿ����� ī��Ʈ�� �ϳ����ݴϴ�.
//		
//		return stp;		//<�ڱԹ�>: ���� main�� ���� push�� ����� �������ֱ� ���� return stp�� ���ݴϴ�
//	}
//
//	else               //<�ڱԹ�>:return 1�� ��ȯ�Ǹ� ����Ǵ� ��-��á�ٰ� �ȳ��մϴ�
//	{
//		printf("The stack is Full! \n");
//	}
//}
//
//int pop(STACK* stp)
//{
//	STACKNODE* current;
//	int data;
//	if (checkEmpty(stp) == 1)		//<�ڱԹ�>: ������ Ȥ�ö� ����ְų� ������ ������ �� ����� �ش� if���� �����ϰ� �մϴ�.
//	{
//		printf("The stack is empty! \n");
//		return -1;		//data�����δ� ������ ���ٴ� ����
//	}
//	else
//	{
//		data = stp->top->data;		//<�ڱԹ�>: ���Ḯ��Ʈ ���� data��� ������ �ִ� ���� pop�� ����� data�� �ӽ÷� �־�����ϴ�
//		current = stp->top;		//<�ڱԹ�>: ���Ḯ��Ʈ���� delete�� ��ó�� ���� current�� ���� top�� ����Ű�� �մϴ�
//		stp->top = stp->top->next;		//<�ڱԹ�>: �׸��� top�� top�� ���� �κ��� ����Ű�� �Ͽ� current�� ���� ������ �ִ� �޸𸮸� �ݳ��� �غ� �մϴ�.
//
//		free(current);		//<�ڱԹ�>: �޸� �ݳ�!
//
//		
//		return data;		//<�ڱԹ�>: �������� �ӽ÷� �־�� ���� ���ٴ� ���� �˷��ֱ� ���� pop�� data ������ �����ݴϴ�.
//	}
//}