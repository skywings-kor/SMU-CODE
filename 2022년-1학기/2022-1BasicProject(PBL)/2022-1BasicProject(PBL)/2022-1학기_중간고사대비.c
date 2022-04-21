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
//		printf("선택해주세요1)삽입, 2)삭제, 3)검색, 4)종료");
//		scanf("%d", &choiceuser);
//
//		if (choiceuser == 1)
//		{
//			printf("이름를 입력해주세요");
//			scanf("%s", name);
//			printf("나이를 입력해주세요:");
//			scanf("%d", &pass);
//			list = insertnode(list, name, pass);
//
//			viewnode(list);
//			system("pause");
//		}
//
//		else if (choiceuser == 2)
//		{
//			printf("지울 이름입력:");
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
//			printf("찾을 이름입력: ");
//			scanf("%s", name);
//			searchsys(list, name);
//			system("pause");
//		}
//
//		else if (choiceuser == 4)
//		{
//			printf("시스템을 종료합니다");
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
//		printf("ㅡㅡㅡㅡㅡㅡendㅡㅡㅡㅡㅡㅡ");
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
//	printf("지울 값이 없습니다..");
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
//	printf("이름을 찾지 못하였습니다.");
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
//	while (!feof(fp))	//파일의 끝일경우 반복문 종료
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
//			result = strtok(NULL, " =,T");		//시간만 가져오기 위해 한 번더 strtok
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
//		printf("이름:%s, 나이:%d \n", walker->name, walker->age);
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


//포인터 변수가 무엇인가?
//-> 포인터 변수는 주소값을 저장하는 변수입니다.
//%p를 하면 주소를 출력하는거고
//이떄 printf에선 &변수명 이리 합니다.

//&변수명 -> 주소값 표현
//포인터=&변수 => 주소값 전달


////문자열 다루는 함수
//strcmp(, )
//strcpy(, )
//atoi(???)
//strtok(~~~," =")
//
////연결리스트 문제
//노드 이용해서 각각 내가 원하는 연결리스트 생성
//자기 위치 찾아갈수 있도록
//연결리스트 검색
//특정노드 삭제
//void search()
//void delete()
//
//배열-> 배열명은 ? 주소이다.
//
//fgets()-> 문자 입력 받아오기 한줄 한줄 가져오는거
//
//연결리스트 자료part1, part2 보기
//
//datafile 1개 주고 읽어서 이름 순으로 연결리스트에 입력, 정렬된걸 출력
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
//		printf("선택 1)넣기, 2)삭제, 3)검색, 4)종료");
//		scanf("%d", &userse);
//
//		if (userse == 1)
//		{
//			printf("이름입력");
//			scanf("%s", inname);
//			printf("나이 입력");
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
//			printf("삭제 이름:");
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
//		printf("이름: %s, 나이:%d \n", walker->name, walker->age);
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
//		printf("이름:%s, 나이:%d\n", walker->name, walker->age);
//		return viewnode(walker->next);
//	}
//
//	else
//	{
//		return walker;
//	}
//}

////2019243064 컴퓨터공학부-데이터공학-박규민
////2022-04-05 Test Debug End;
//
//<개발 개요> 
//1.사용자로부터 입력받는 10진수 정수를 사용자가 지정한 진법(2진수~ 9진수)로 변환
//2.스택을 이용한 구현
//3.나머지 연산(%)과 나누기 연산(/)를 이용한 진법변환과정 구현  

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
//	printf("변환하기 전 숫자:");
//	scanf("%d", &user);
//
//	printf("진법변환할 숫자:");
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
//		printf("꽉찼습니다");
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
//		printf("비워졌습니다");
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
//		printf("입력");
//		scanf("%d", &user);
//
//		if (user == 1)
//		{
//			printf("이름:");
//			scanf("%s", name);
//			printf("나이:");
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
//			printf("지울이름:");
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
//			printf("찾을 이름: ");
//			scanf("%s", name);
//
//			searchnode(list, name);
//
//			system("pause");
//		}
//		else
//		{
//			printf("잘못입력");
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
//		printf("이름:%s, 나이:%d\n", walker->name, walker->age);
//		return viewnode(walker->next);
//	}
//
//	else
//	{
//		printf("마지막");
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
//		printf("지울 이름을 찾을 수 없습니다");
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
//			printf("이름%s, 나이%d", walker->name, walker->age);
//			return selist;
//		}
//		walker = walker->next;
//
//	}
//
//	printf("찾을 수 없습니다");
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
//		printf("이름%s, 나이%d\n", walker->str, walker->age);
//		return viewnode(walker->next);
//	}
//
//	else
//	{
//		printf("엔딩");
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
//	printf("값 입력:");
//	scanf("%d", &user);
//	printf("변환한 진수 입력:");
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
//		printf("스택이 비어있습니다");
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