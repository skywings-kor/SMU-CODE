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


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

typedef struct node {
	char id[20];
	int age;
	struct node* next;
}NODE;

NODE* insertnode(NODE* inlist, char inid[20],int inage);
NODE* viewnode(NODE* walker);
NODE* delnode(NODE* delist, char delname[20]);

int main()
{
	NODE* list;
	list = NULL;
	int choiceuser;
	char name[20];
	int pass;
	char delname[20];
	
	for (int i = 0;; i++)
	{
		system("cls");
		printf("�������ּ���1)����, 2)����, 3)�˻�, 4)����");
		scanf("%d", &choiceuser);

		if (choiceuser == 1)
		{
			printf("�̸��� �Է����ּ���");
			scanf("%s", name);
			printf("���̸� �Է����ּ���:");
			scanf("%d", &pass);
			list = insertnode(list, name, pass);

			viewnode(list);
			system("pause");
		}

		else if (choiceuser == 2)
		{
			printf("���� �̸��Է�:");
			scanf("%s", delname);

			list=delnode(list, delname);

			viewnode(list);
			system("pause");

		}
	}
	

}

NODE* insertnode(NODE* inlist, char inid[20], int inage)
{
	NODE* newnode;
	NODE* current=NULL,*follow=NULL;
	
	newnode = (NODE*)malloc(sizeof(NODE));
	
	strcpy(newnode->id, inid);
	newnode->age = inage;

	current = inlist;
	follow = inlist;

	while (current != NULL)
	{
		follow = current;
		current = current->next;
	}

	newnode->next = current;
	
	if (current == inlist)
	{
		inlist = newnode;
	}

	else
	{
		follow->next = newnode;
	}

	return inlist;
	
	

	
}

NODE* viewnode(NODE* walker)
{
	if (walker != NULL)
	{
		printf("%s %d \n", walker->id, walker->age);

		return viewnode(walker->next);
	}

	else
	{
		printf("�ѤѤѤѤѤ�end�ѤѤѤѤѤ�");

		return walker;
	}

}

NODE* delnode(NODE* delist,char delname[20])
{
	NODE* current = NULL, * follow = NULL;

	current = delist;
	follow = delist;

	while (current != NULL)
	{

		if (strcmp(current->id, delname) == 0)
		{
			if (current->next == NULL)
			{
				follow->next = NULL;
				free(current);

				return delist;
			}

			else if (follow == delist)
			{
				delist = current->next;
				free(current);

				return delist;
			}

			else
			{
				follow->next = current->next;
				free(current);

				return delist;
			}

		}

		
		follow = current;
		current = current->next;
	}

	printf("���� ���� �����ϴ�..");

}