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
//			list=insertnode(list,fid,fps);
//
//			printf("저장되었습니다");
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
//			printf("시스템을 종료합니다");
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