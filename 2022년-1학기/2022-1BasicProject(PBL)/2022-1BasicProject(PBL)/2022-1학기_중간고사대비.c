////연결리스트? -> 동적 자료형의 한 종류이다
//
////malloc 함수를 이용한 메모리 할당
//
////포인터 변수가 무엇인가? -> 주소값을 저장하는 변수입니다
//
////int *y로 선언을 하면-> y를 그냥 쓰면 할당 메모리 공간 안을 의미합니다
////& 연산자는 변수의 주소 값을 반환하므로 상수가 아닌 변수가 피연산자이어야 한다.
////& 연산자의 반환 값은 포인터 변수에 저장을 한다.
////ex로 int num=10 하고 int *y=&num 이렇게 선언하면 y에는 num의 주소값이 들어가서 *y로 printf시 10이 나오게된다
//// 
////만일 주소를 보고 싶으면 그냥 y로 printf하고 &num을 printf하면 두개의 주소가 같음을 알 수 있다.(61626=61626 예시로 이런식)
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
///////////////////////////////////////////////////포인터 활용 예시-made by 박규민
////int main()
////{
////	int num = 10;
////	int* y=&num;
////	printf("정상적인 포인터 사용-> %d \n", *y);
////	printf("포인터y가 가리키는 주소-> %d\n", y);
////	printf("숫자10을 넣은 num의 주소-> %d", &num);
////
////	return 0;
////}
//
//////////////////////////////////////////////////연결리스트 활용
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
//		printf("하고싶은 항목을 택해주세요(1.추가 ㅣ 2.삭제	ㅣ 3.검색	ㅣ	4.종료");
//		scanf("%d", &user);
//
//		if (user == 1)
//		{
//			printf("사용자 id 입력: ");
//			scanf("%s", fid);
//
//			printf("비밀번호 입력: ");
//			scanf("%d", &fps);
//
//			list=insertnode(list, fid, fps);
//
//			printf("저장되었습니다\n");
//			viewnode(list);
//			system("pause");
//		}
//
//		else if (user == 2)
//		{
//			printf("지울 ID 입력: ");
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
//			printf("찾을 ID 입력: ");
//			scanf("%s", sid);
//			searchnode(list, sid);
//
//			system("pause");
//		}
//
//		else if (user == 4)
//		{
//			printf("시스템을 종료합니다");
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
//		printf("\n\n정상적으로 지워졌습니다");
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
//				printf("\n\n정상적으로 지워졌습니다");
//				return dellist;
//			}
//
//			follow->next = current->next;
//			free(current);
//
//			viewnode(dellist);
//
//			printf("\n\n정상적으로 지워졌습니다");
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
//	printf("잘못 입력하셨습니다");
//}
//
//NODE* searchnode(NODE* searchlist, char sid[20])
//{
//	if (searchlist == NULL)
//	{
//		printf("id를 찾을 수 없습니다");
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
		printf("선택해주세요1)삽입, 2)삭제, 3)검색, 4)종료");
		scanf("%d", &choiceuser);

		if (choiceuser == 1)
		{
			printf("이름를 입력해주세요");
			scanf("%s", name);
			printf("나이를 입력해주세요:");
			scanf("%d", &pass);
			list = insertnode(list, name, pass);

			viewnode(list);
			system("pause");
		}

		else if (choiceuser == 2)
		{
			printf("지울 이름입력:");
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
		printf("ㅡㅡㅡㅡㅡㅡendㅡㅡㅡㅡㅡㅡ");

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

	printf("지울 값이 없습니다..");

}