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
//	printf("지금부터 랜덤값을 넣습니다.");
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
////	/*srand(time(NULL));*/		//난수 초기화
////	//int num = rand() % 3+1;		// 3을 넣을경우->  0~2 사이에서 뽑게 됨			3+1을 넣을경우-> 1~3 사이에서 뽑게 됨
////
////
////	printf("난수 초기화 이전..\n");
////	for (int i = 0; i < 10; i++)
////	{
////		printf("%d ", rand() % 10);
////	}
////
////	printf("\n\n");
////
////
////	srand(time(NULL));				//중요성!
////	printf("난수 초기화 이후..\n");
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
