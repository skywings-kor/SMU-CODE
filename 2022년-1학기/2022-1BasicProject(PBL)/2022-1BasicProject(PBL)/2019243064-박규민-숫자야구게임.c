//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <time.h>
//#pragma warning (disable:4996)
//
//typedef struct node 
//{
//	int correct;
//	struct node* next;
//}NODE;
//
//void randnumin(NODE* in_list);
//
//
//
//int main(void)
//{
//	
//	NODE* list = NULL;
//	int userin;
//	int res5,res4, res3, res2, res1;
//
//	randnumin(list);
//
//	printf("%d %d %d %d %d", list->correct, list->next->correct, list->next->next->correct, list->next->next->next->correct, list->next->next->next->next->correct);
//
//	scanf("%d", &userin);
//
//	res5 = userin / 10000;
//	userin = userin - res5 *10000;
//
//	res4 = userin / 1000;
//	userin = userin - res4 *1000;
//
//	res3 = userin / 100;
//	userin = userin - res3 *100;
//
//	res2 = userin / 10;
//	userin = userin - res2 *10;
//	
//	res1 = userin;
//
//	printf("%d %d %d %d %d", res5, res4, res3, res2, res1);
//
//
//
//}
//
//void randnumin(NODE* in_list)
//{
//	int count=0;
//	NODE* current = NULL, * follow = NULL;
//	NODE* newnode= (NODE*)malloc(sizeof(NODE));
//
//	follow = in_list;
//	current = in_list;
//
//	printf("���ݺ��� �������� �ֽ��ϴ�.");
//	srand(time(NULL));
//	for (int i = 1; ; i++)
//	{
//		if (count <= 5)
//		{
//
//			newnode->correct = rand() % 9 + 1;
//			newnode->next = current;
//			count++;
//		}
//
//		else
//		{
//			break;
//		}
//		
//
//	}
//
//	return in_list;
//
//}
//
////#include <time.h>
////#include<stdio.h>
////#include<stdlib.h>
////
////int main(void)
////{
////	/*srand(time(NULL));*/		//���� �ʱ�ȭ
////	//int num = rand() % 3+1;		// 3�� �������->  0~2 ���̿��� �̰� ��			3+1�� �������-> 1~3 ���̿��� �̰� ��
////
////
////	printf("���� �ʱ�ȭ ����..\n");
////	for (int i = 0; i < 10; i++)
////	{
////		printf("%d ", rand() % 10);
////	}
////
////	printf("\n\n");
////
////
////	srand(time(NULL));				//�߿伺!
////	printf("���� �ʱ�ȭ ����..\n");
////	for (int i = 0; i < 10; i++)
////	{
////		printf("%d ", rand() % 10);
////	}
////
////	return 0;
//// 
//// 
//// 
////}
//
