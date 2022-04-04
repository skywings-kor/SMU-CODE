////2019243064 컴퓨터공학부-데이터공학-박규민
////2022-03-30 Test Debug End;
//
//#include <stdio.h>
//#include <stdlib.h>  //malloc함수를 위해 
//#include <string.h>  //strcmp와 strcpy
//#include<windows.h>
//#pragma warning (disable:4996)
//
//typedef struct node
//{
//	char name[15];
//	int age;
//	struct node* next;
//}NODE;
//
//
//NODE* delData(NODE* del_list);		//지우는 함수
//NODE* loadData(NODE* _list);		//노드 생성 함수
//NODE* insertNode(NODE* _list, char* _n, int _a);		//노드 생성함수에서 사용되어지는 거
//void printList(NODE* walker);		//노드 출력함수
//
//void usercheck(NODE* _checker);		// search 부분
//
//void  main()
//{
//	NODE* list = NULL;
//	int inuser;
//	for (int i = 0;; i++)
//	{
//		
//		system("pause");	//아무키나 입력되면 진행하도록 하는것!
//		system("cls");		//한번 돌고나면 화면 싹 지우는거
//		printf("Enter [(1)Insert,(2)Delete,(3)Search,(4)Exit]: ");
//		scanf("%d", &inuser);
//
//		if (inuser == 1)		//값 넣는 부분
//		{
//			list=loadData(list);	//데이터 값 입력한걸 노드에 넣어주고
//			printList(list);		//넣고나면 제대로 넣어지고 정렬까지 되었는지 확인 스크린 띄어주고
//		}			//
//
//		else if (inuser == 2)		//노드 삭제부분
//		{
//			printf("지우기전 리스트를 보여드립니다.\n");
//			printList(list);
//			list=delData(list);		//헤헤... 교수님 죄송합니다... 이런 식도 안넣고 여쭤봐서... 당연한데...ㅠㅠㅠㅠ 더욱 분발하겠습니다..
//			
//		}
//
//		else if (inuser == 3)		//이름 넣으면 이름하고 나이 띄어주어서 찾아주는 부분
//		{
//			usercheck(list);
//			
//		}
//
//		else if (inuser == 4)		//종료부분
//		{
//			printf("시스템을 종료합니다");
//			exit(0);
//		}
//	}
//}
//
//void printList(NODE* walker)
//{
//	NODE* print_current=NULL;		//지금 이거 임시로 만든것임
//	
//	if (walker == NULL)
//	{
//		printf("==End of Print====\n");
//	}
//	else
//	{
//		printf("%s %d\n", walker->name, walker->age);
//		printList(walker->next);
//	}
//}
//
//void usercheck(NODE* checker)		//자! 이것은 유저가 입력한 이름에서 해당 이름보다 나이가 적은 사람을 표시하는 함수입니다!
//{
//	char username[15] = "";		//먼저 유저가 입력할 공간을 할당해주고 초기화를 해줍니다!
//	NODE* check_current = NULL;		//노드가 위치해있는 현재
//	NODE* check_follow = NULL;		//current가 위치해있는 바로 전 위치
//	check_current = check_follow = checker;		//가볍게 노드의 시작점 위치를 잡아주고!
//	int countage = 0;		// 유저가 입력한 이름의 나이를 잠깐 넣어주는 변수를 하나 만들어줍니다
//
//
//	for (int i = 0; ; i++)		//무한 반복으로 하나 돌게하고
//	{
//		check_current = check_follow = checker;		//이것은 매 처음으로 돌아올때마다 초기화해주기 위한 선언
//		countage = 0;		//이것도 동일
//		printf("찾으시려는 이름을 입력해주세요: ");
//		scanf("%s", username);		//유저 string으로 입력해주고~
//
//
//		while (check_current->name != NULL)			//링크드 리스트의 끝인 NULL이 나올경우 탈출해버리게하고
//		{
//			if (strcmp(username, check_current->name) == 0)		//유저가 입력한 string 과 링크드리스트에 저장되어있는 string이 같을 경우 실행해주는 문장
//			{
//				printf("해당 인원의 이름은 %s 이며, 나이는 %d세 입니다.\n", check_current->name, check_current->age);		//countage라는 변수를 만든 곳에 유저가 입력한 이름에 해당하는 나이를 넣어주고
//				return checker;
//			}
//
//			check_follow = check_current;		//while문에서 계속 같은 링크드 돌면 안되니까 다음 칸으로 넘어가도록 해줍니다
//			check_current = check_current->next;	//while문에서 계속 같은 링크드 돌면 안되니까 다음 칸으로 넘어가도록 해줍니다
//
//		}
//
//		if ((check_current == NULL) || (check_current == check_follow))		//널이 결국 끝까지와서 아무것도 못찾았을 경우 해당 문장을 실행!
//		{	//OR 아니면 나이가 제일 적어서 표시할 사람이 없을 경우도 해당 문장을 실행하도록..!
//			printf("해당자가 없습니다...\n");
//
//		}
//
//
//
//	}
//}
//
//NODE* loadData(NODE* _list)
//{
//	char nameData[15];
//	int ageData;
//
//	printf("이름과 나이를 입력해주세요: ");
//	scanf("%s %d", nameData, &ageData);
//
//	_list = insertNode(_list, nameData, ageData);
//
//	return _list;
//}
//
//NODE* insertNode(NODE* _list, char* _n, int _a)
//{
//	NODE* current = NULL, * follow = NULL, * newnode = NULL;
//	follow = _list;
//	current = _list;
//
//	if ((newnode = (NODE*)malloc(sizeof(NODE))) == NULL)
//	{
//		printf("No Memory allocated...\n");
//		return NULL;
//	}
//
//	strcpy(newnode->name, _n);		//newnode에서 이름을 비교해서 1과 0과 -1로 나누는것
//
//	newnode->age = _a;
//
//	while ((current != NULL) && (current->age < _a))		//나이로 정렬
//	{
//		follow = current;
//		current = current->next;
//
//	}
//	newnode->next = current;
//	if (current == _list)
//	{
//		_list = newnode;
//	}
//
//	else
//	{
//		follow->next = newnode;
//	}
//
//	return _list;
//}
//
//NODE* delData(NODE* del_list)
//{
//	NODE* current , * follow ;
//	current = follow = del_list;
//	char delname[15]="";
//
//
//	printf("삭제할 이름을 입력해주세요: ");
//	scanf("%s", delname);
//
//	if (strcmp(current->name, delname) == 0)	//지우려는 노드가 첫번째 노트일 경우 실행하는 것
//	{
//		
//		del_list= current->next;		//노드의 시작부분을 current->next로 하였는데 계속 시작부분 원점으로 돌아가서 출력함(free해도 free한 부분을 나타냄;;)
//		free(current);		//메모리 해방~
//		current = NULL;		//current 길 잃지 않게 잡아만 주는 역할
//		
//
//		return del_list;		
//	}
//
//	else
//	{
//		while (current != NULL)
//		{
//			follow = current;
//			current = current->next;
//
//			if ((strcmp(current->name, delname) == 0) && (current->next != NULL))		//중간 노드 부분 삭제
//			{
//				follow->next = current->next;		// 따라오는 노드를 다음 노드랑 연결시켜주고
//				
//				free(current);		//현재 current가 가리키고 있는 노드는 메모리 해방시키고
//
//				printList(del_list);		
//				return del_list;
//			}
//
//			else if ((strcmp(current->name, delname) == 0) && (current->next == NULL))		// 맨마지막 노드 부분 삭제
//			{
//				follow->next = NULL;
//				
//				free(current);
//
//				printList(del_list);
//				return del_list;
//			}
//
//			else if(current->next==NULL)		//만일 끝까지 갔는데 없을때 실행시키는 부분
//			{
//				printf("찾는 이름이 없습니다...");
//				return del_list;
//			}
//		}
//
//	}
//
//}
