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
//
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
//
//
//int main()
//{
//	NODE* list;
//	list = NULL;
//
//	int user;
//
//	char fid[20];
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
//			list=insertnode(list,fid,fps);
//
//			printf("����Ǿ����ϴ�");
//			viewnode(list);
//			system("pause");
//		}
//
//		else if (user == 2)
//		{
//
//		}
//
//		else if (user == 3)
//		{
//
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
//NODE* viewnode(NODE* showlist)
//{
//	NODE* walker;
//	walker = showlist;
//	while (walker->next != NULL)
//	{
//		printf("id=>%s    password=>%d \n", walker->id, walker->password);
//		walker = walker->next;
//	}
//
//	return showlist;
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