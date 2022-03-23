//2019243064 컴퓨터공학부-데이터공학-박규민
//2022-03-23 Test Debug End;

#include <stdio.h>
#include <stdlib.h>  //malloc함수를 위해 
#include <string.h>  //strcmp와 strcpy
#pragma warning (disable:4996)
typedef struct node
{
	char name[15];
	int age;
	struct node* next;
}NODE;

NODE* loadData(NODE* _list, char* fname1, char* fname2, FILE* _fp1, FILE* _fp2);
NODE* insertNode(NODE* _list, char* _n, int _a);
void printList(NODE* walker);

void usercheck(NODE* _checker);		//이것이 추가적으로 더 만든 것 입니당!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

void main()
{
	FILE* fp1, * fp2;
	NODE* list = NULL;
	fp1 = NULL;
	fp2 = NULL;
	list = loadData(list, "datafile1.txt", "datafile2.txt", fp1, fp2);
	printList(list);

	usercheck(list);	//해당 구문 실행하기 위한 줄

	free(list);

}

void printList(NODE* walker)
{
	if (walker == NULL) printf("==End of Print====\n");
	else
	{
		printf("%s\t%d\n", walker->name, walker->age);
		printList(walker->next);
	}
}


void usercheck(NODE* checker)		//자! 이것은 유저가 입력한 이름에서 해당 이름보다 나이가 적은 사람을 표시하는 함수입니다!
{
	char username[15] = "";		//먼저 유저가 입력할 공간을 할당해주고 초기화를 해줍니다!
	NODE* check_current = NULL;		//노드가 위치해있는 현재
	NODE* check_follow = NULL;		//current가 위치해있는 바로 전 위치
	check_current = check_follow = checker;		//가볍게 노드의 시작점 위치를 잡아주고!
	int countage = 0;		// 유저가 입력한 이름의 나이를 잠깐 넣어주는 변수를 하나 만들어줍니다


	for (int i = 0;; i++)		//무한 반복으로 하나 돌게하고
	{
		check_current = check_follow = checker;		//이것은 매 처음으로 돌아올때마다 초기화해주기 위한 선언
		countage = 0;		//이것도 동일
		printf("검색하실 이름을 입력해주세요(0입력시 종료됩니다)=> ");	//유저 입력하시오!!~
		scanf("%s", username);		//유저 string으로 입력해주고~

		if (strcmp(username, "0") == 0)		//자 먼저! 비교합니다 !! 유저가 입력한 것이 0일경우 종료될 수 있도록(반복문 탈출)
		{
			printf("프로그램을 종료합니다\n");
			break;
		}


		while (check_current->name != NULL)			//링크드 리스트의 끝인 NULL이 나올경우 탈출해버리게하고
		{
			if (strcmp(username, check_current) == 0)		//유저가 입력한 string 과 링크드리스트에 저장되어있는 string이 같을 경우 실행해주는 문장
			{
				countage = check_current->age;		//countage라는 변수를 만든 곳에 유저가 입력한 이름에 해당하는 나이를 넣어주고
				break;		//탈출~
			}

			check_follow = check_current;		//while문에서 계속 같은 링크드 돌면 안되니까 다음 칸으로 넘어가도록 해줍니다
			check_current = check_current->next;	//while문에서 계속 같은 링크드 돌면 안되니까 다음 칸으로 넘어가도록 해줍니다

		}
		if ((check_current == NULL) || (check_current == check_follow))		//널이 결국 끝까지와서 아무것도 못찾았을 경우 해당 문장을 실행!
		{	//OR 아니면 나이가 제일 적어서 표시할 사람이 없을 경우도 해당 문장을 실행하도록..!
			printf("해당자가 없습니다(나이가 제일 적을 수도 있습니다)..\n");
		}

		else				//그 외에는 표시할 것이 있다는 거니까 해당 라인을 실행해줍니다
		{
			check_current = checker;		//노드 시작점으로 다 이동해주고
			check_follow = checker;			//얘도 이동해줍니다
			printf("해당 인원보다 나이가 적은 사람은\n");
			while (check_current->age < countage)		//노드가 위치한 나이가 countage 보다 적을 경우 계속 뱅뱅 돕니다
			{

				printf("%s \t %d \n", check_current->name, check_current->age);		//자 해당하는 것이 있을 경우! 노드가 현재 위치해있는 name과 age를 표시해줍니다.

				check_follow = check_current;	//다음 노드로 이동하기 위한 명령입니다.
				check_current = check_current->next;		//다음 노드로 이동하기 위한 명령입니다.
			}
			printf("입니다\n");
		}


	}
}



NODE* loadData(NODE* _list, char* fname1, char* fname2, FILE* _fp1, FILE* _fp2)
{
	char nameData[15];
	int ageData;
	if ((_fp1 = fopen(fname1, "r")) == NULL)
	{
		printf("File Open Error!!!");
		return NULL;
	}
	if ((_fp2 = fopen(fname2, "r")) == NULL)
	{
		printf("File Open Error!!!");
		return NULL;
	}
	while (!feof(_fp1))
	{
		fscanf(_fp1, "%s\t%d", nameData, &ageData);
		_list = insertNode(_list, nameData, ageData);
	}
	while (!feof(_fp2))
	{
		fscanf(_fp2, "%s\t%d", nameData, &ageData);
		_list = insertNode(_list, nameData, ageData);
	}

	return _list;
}

NODE* insertNode(NODE* _list, char* _n, int _a)
{
	NODE* current = NULL, * follow = NULL, * newnode = NULL;
	current = follow = _list;

	if ((newnode = (NODE*)malloc(sizeof(NODE))) == NULL)
	{
		printf("No Memory allocated...\n");
		return NULL;
	}

	strcpy(newnode->name, _n);		//newnode에서 이름을 비교해서 1과 0과 -1로 나누는것

	newnode->age = _a;

	while ((current != NULL) && (current->age < _a))		//나이로 정렬
	{
		follow = current;
		current = current->next;

	}
	newnode->next = current;
	if (current == _list)
	{
		_list = newnode;
	}

	else
	{
		follow->next = newnode;
	}

	return _list;
}
