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

//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#pragma warning(disable:4996)
//#define MAX 16
//
//typedef struct snode
//{
//	int data;
//	struct snode* next;
//}STACKNODE;
//
//typedef struct stack
//{
//	int counter;
//	STACKNODE* top;
//}STACK;
//
//void initation(STACK* stp);
//int checkEmpty(STACK* stp);
//int checkFull(STACK* stp);
//void push(STACK* stp, int data);
//int pop(STACK* stp);
//
//void main()
//{
//	int user;
//	int change;
//	int temp=0;
//	STACK st;
//	initation(&st);
//
//	printf("��ȯ�ϱ� �� ����:");
//	scanf("%d", &user);
//
//	printf("������ȯ�� ����:");
//	scanf("%d", &change);
//
//	if (user < change)
//	{
//		push(&st, user);
//	}
//	else
//	{
//		temp = user;
//
//		while (change <= temp)
//		{
//			push(&st, temp % change);
//			temp = temp / change;
//		}
//		if (temp != 0)
//		{
//			push(& st, temp);
//		}
//	}
//
//	int popdata = 0;
//
//	while (popdata != -1)
//	{
//		popdata = pop(&st);
//
//		if (popdata != -1)
//		{
//			printf("%d ", popdata);
//		}
//	}
//
//	system("pause");
//
//}
//
//
//void initation(STACK* stp)
//{
//	stp->counter = 0;
//	stp->top = NULL;
//}
//int checkEmpty(STACK* stp)
//{
//	if (stp->top == NULL)
//	{
//		return 1;
//	}
//
//	else
//	{
//		return 0;
//	}
//}
//int checkFull(STACK* stp)
//{
//	if (stp->counter > MAX)
//	{
//		return 1;
//	}
//
//	else
//	{
//		return 0;
//	}
//}
//void push(STACK* stp, int data)
//{
//	if (checkFull(stp)==0)
//	{
//		STACKNODE* newnode;
//		newnode = (STACKNODE*)malloc(sizeof(STACKNODE));
//		newnode->data = data;
//		newnode->next = stp->top;
//		stp->top = newnode;
//		stp->counter += 1;
//
//		return stp;
//
//	}
//	else
//	{
//		printf("��á���ϴ�");
//	}
//
//
//
//
//}
//int pop(STACK* stp)
//{
//	STACKNODE* current;
//	int data;
//	if (checkEmpty(stp) == 0)
//	{
//		data=stp->top->data;
//		current = stp->top;
//		stp->top = stp->top->next;
//
//		free(current);
//
//		return data;
//	}
//
//	else
//	{
//		printf("��������ϴ�");
//		return -1;
//	}
//}
//
//#include <stdio.h>
//#include <stdlib.h>
//#include<string.h>
//#pragma warning(disable:4996)
//
//typedef struct node
//{
//	char name[20];
//	int age;
//	struct node* next;
//
//}NODE;
//NODE* viewnode(NODE* walker);
//NODE* inputnode(NODE* inlist, char name[20], int age);
//NODE* delnode(NODE* delist, char name[20]);
//NODE* searchnode(NODE* selist, char name[20]);
//int main()
//{
//	NODE* list;
//	list = NULL;
//
//	int user;
//	char name[20];
//	int age;
//	for (int i = 0;; i++)
//	{
//		system("cls");
//		int user;
//		printf("�Է�");
//		scanf("%d", &user);
//
//		if (user == 1)
//		{
//			printf("�̸�:");
//			scanf("%s", name);
//			printf("����:");
//			scanf("%d", &age);
//
//			list = inputnode(list, name, age);
//
//			viewnode(list);
//
//			system("pause");
//		}
//		else if (user == 2)
//		{
//			printf("�����̸�:");
//			scanf("%s", name);
//
//			list = delnode(list, name);
//
//			viewnode(list);
//
//			system("pause");
//		}
//		else if (user == 3)
//		{
//			printf("ã�� �̸�: ");
//			scanf("%s", name);
//
//			searchnode(list, name);
//
//			system("pause");
//		}
//		else
//		{
//			printf("�߸��Է�");
//		}
//	}
//
//
//}
//
//NODE* inputnode(NODE* inlist, char name[20], int age)
//{
//	NODE* current, * follow, * newnode;
//	newnode = (NODE*)malloc(sizeof(NODE));
//	current = inlist;
//	follow = inlist;
//
//	strcpy(newnode->name, name);
//	newnode->age = age;
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
//		printf("������");
//		return walker;
//	}
//}
//
//NODE* delnode(NODE* delist, char name[20])
//{
//	NODE* current, * follow;
//	current = delist;
//	follow = delist;
//
//	while (current != NULL)
//	{
//		if (strcmp(current->name, name) == 0)
//		{
//			break;
//		}
//
//		follow = current;
//		current = current->next;
//
//	}
//	if (current == NULL)
//	{
//		printf("���� �̸��� ã�� �� �����ϴ�");
//		return delist;
//	}
//
//	if (current == delist)
//	{
//		delist = current->next;
//		free(current);
//		return delist;
//	}
//	else if (current->next == NULL)
//	{
//		follow->next = NULL;
//		free(current);
//
//		return delist;
//	}
//	else
//	{
//		follow->next = current->next;
//		free(current);
//		return delist;
//	}
//
//
//}
//
//NODE* searchnode(NODE* selist, char name[20])
//{
//	NODE* walker;
//	walker = selist;
//
//	while (walker!= NULL)
//	{
//		if (strcmp(walker->name, name) == 0)
//		{
//			printf("�̸�%s, ����%d", walker->name, walker->age);
//			return selist;
//		}
//		walker = walker->next;
//
//	}
//
//	printf("ã�� �� �����ϴ�");
//	return selist;
//
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include<string.h>
//#pragma warning(disable:4996)
//
//typedef struct node
//{
//	char str[100];
//	int age;
//	struct node* next;
//}NODE;
//
//NODE* innode(NODE* inlist, char str[100]);
//NODE* viewnode(NODE* walker);
//void main()
//{
//	char str[100];
//	char str2[100];
//	NODE* list;
//	list = NULL;
//
//	FILE* fp;
//	FILE* fp2;
//	fp = fopen("datafile1.txt", "r");
//	fp2 = fopen("datafile2.txt", "r");
//	while (!feof(fp))
//	{
//		fgets(str, 99, fp);
//		list = innode(list, str);
//		fgets(str2, 99, fp2);
//		list = innode(list, str2);
//
//	}
//	viewnode(list);
//
//}
//
//NODE* innode(NODE* inlist, char str[100])
//{
//	char* result;
//	NODE* newnode, * current, * follow;
//	
//	newnode = (NODE*)malloc(sizeof(NODE));
//	current = inlist;
//	follow = inlist;
//
//	result = strtok(str, "\t");
//	strcpy(newnode->str, result);
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
//NODE* viewnode(NODE* walker)
//{
//	if (walker != NULL)
//	{
//		printf("�̸�%s, ����%d\n", walker->str, walker->age);
//		return viewnode(walker->next);
//	}
//
//	else
//	{
//		printf("����");
//		return walker;
//	}
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include<string.h>
//#pragma warning(disable:4996)
//#define MAX 16
//
//typedef struct snode
//{
//	int data;
//	struct node* next;
//}STACKNODE;
//
//typedef struct stack
//{
//	int counter;
//	STACKNODE* top;
//}STACK;
//
//void initation(STACK* stp);
//int checkEmpty(STACK* stp);
//int checkFull(STACK* stp);
//void push(STACK* stp, int data);
//int pop(STACK* stp);
//
//void main()
//{
//	STACK st;
//	int user;
//	int change;
//	int temp;
//
//	initation(&st);
//
//	printf("�� �Է�:");
//	scanf("%d", &user);
//	printf("��ȯ�� ���� �Է�:");
//	scanf("%d", &change);
//
//	if (user < change)
//	{
//		push(&st, user);
//	}
//
//	else
//	{
//		temp = user;
//		while (change <= temp)
//		{
//			push(&st, temp % change);
//			temp = temp / change;
//		}
//
//		if (temp != 0)
//		{
//			push(&st, temp);
//		}
//	}
//
//	int popdata=0;
//	while (popdata != -1)
//	{
//		popdata = pop(&st);
//		if (popdata != -1)
//		{
//			printf("%d", popdata);
//		}
//	}
//
//	printf("\n");
//	system("pause");
//
//
//
//
//
//}
//
//void initation(STACK* stp)
//{
//	stp->counter = 0;
//	stp->top = NULL;
//}
//
//int checkEmpty(STACK* stp)
//{
//	if (stp->top == NULL)
//	{
//		return 1;
//	}
//
//	else
//	{
//		return 0;
//	}
//}
//
//int checkFull(STACK* stp)
//{
//	if (stp->counter <= MAX)
//	{
//		return 0;
//	}
//
//	else
//	{
//		return 1;
//	}
//}
//
//void push(STACK* stp, int data)
//{
//	if (checkFull(stp) == 0)
//	{
//		STACKNODE* newnode,*current;
//		current = stp;
//		newnode = (STACKNODE*)malloc(sizeof(STACKNODE));
//
//		newnode->data = data;
//		newnode->next = stp->top;
//		stp->top = newnode;
//		stp->counter += 1;
//		return stp;
//
//	}
//
//	else
//	{
//		printf("\nthe stack is FULL");
//	}
//}
//
//int pop(STACK* stp)
//{
//	STACKNODE* current;
//	current = stp;
//	int data;
//
//	if (checkEmpty(stp) == 1)
//	{
//		printf("������ ����ֽ��ϴ�");
//		return -1;
//	}
//
//	else
//	{
//
//		data = stp->top->data;
//		current = stp->top;
//		stp->top = stp->top->next;
//
//		free(current);
//		
//		return data;
//	}
//}


//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#pragma warning(disable:4996)
//
//typedef struct taginfo
//{
//	char id[30];
//	int rssi;
//	char idetified[20];
//	struct taginfo* next;
//}TAGINFO;
//
//TAGINFO* stringsplit(TAGINFO* head, char data[]);
//
//void main()
//{
//	TAGINFO* list;
//	list = NULL;
//	char str[300];
//	FILE* fp;
//	fp = fopen("RFID_Data.txt", "r");
//
//	while (!feof(fp))
//	{
//		fgets(str, 299, fp);
//		list = stringsplit(list, str);
//
//		printf("%s", list->idetified);
//	}
//}
//
//
//TAGINFO* stringsplit(TAGINFO* head, char data[])
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
//			result = strtok(NULL, " =,T");
//			strcpy(newnode->idetified, result);
//
//		}
//
//		else
//		{
//			result = strtok(NULL, " =,T");
//		}
//
//		
//	}
//	newnode->next = head;
//	head = newnode;
//
//	return head;
//}