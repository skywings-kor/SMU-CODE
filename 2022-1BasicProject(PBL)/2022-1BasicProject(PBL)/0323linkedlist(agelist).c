#include <stdio.h>
#include <stdlib.h>  //malloc함수를 위해 
#include <string.h>  //strcmp와 strcpy
#pragma warning (disable:4996)
typedef struct node {
	char name[15];
	int age;
	struct node* next;
}NODE;

NODE* loadData(NODE* _list, char* fname1, char* fname2, FILE* _fp1, FILE* _fp2);
NODE* insertNode(NODE* _list, char* _n, int _a);
void printList(NODE* walker);
void usercheck(NODE*_checker);

void main() {

	

	FILE* fp1, * fp2;
	NODE* list = NULL;
	fp1 = NULL;
	fp2 = NULL;
	list = loadData(list, "datafile1.txt", "datafile2.txt", fp1, fp2);
	printList(list);
	
	usercheck(list);



}

void printList(NODE* walker) {
	if (walker == NULL) printf("==End of Print====\n");
	else {
		printf("%s\t%d\n", walker->name, walker->age);
		printList(walker->next);
	}
}
void usercheck(NODE* checker)
{
	char username[15];
	NODE* check_current=NULL;
	NODE* check_follow=NULL;
	check_current = check_follow = checker;
	int countage = 0;
	for (int i = 0;; i++)
	{
		printf("검색하실 이름을 입력해주세요(0입력시 종료됩니다)=> ");
		scanf("%s", &username);
		if (username == "0")
		{
			printf("프로그램을 종료합니다\n");
			break;
			exit(0);
		}
		
		while (check_current != NULL)			//널이 나오기전까지 반복합니다.
		{
			if (username == check_current->name)
			{
				countage = check_current->age;
			}
			check_follow = check_current;
			check_current = check_current->next;

		}

		check_current = checker;
		check_follow = checker;
		while (check_current->age < countage)
		{
			printf("해당 인원보다 나이가 적은 사람은 %s \t %d 인 사람입니다.", checker->name, checker->age);
			check_follow = check_current;
			check_current = check_current->next;
		}


	}
}


NODE* loadData(NODE* _list, char* fname1, char* fname2, FILE* _fp1, FILE* _fp2) {
	char nameData[15];
	int ageData;
	if ((_fp1 = fopen(fname1, "r")) == NULL) {
		printf("File Open Error!!!");
		return NULL;
	}
	if ((_fp2 = fopen(fname2, "r")) == NULL) {
		printf("File Open Error!!!");
		return NULL;
	}
	while (!feof(_fp1)) {
		fscanf(_fp1, "%s\t%d", nameData, &ageData);
		_list = insertNode(_list, nameData, ageData);
	}
	while (!feof(_fp2)) {
		fscanf(_fp2, "%s\t%d", nameData, &ageData);
		_list = insertNode(_list, nameData, ageData);
	}

	return _list;
}

NODE* insertNode(NODE* _list, char* _n, int _a) {
	NODE* current = NULL, * follow = NULL, * newnode = NULL;
	current = follow = _list;

	if ((newnode = (NODE*)malloc(sizeof(NODE))) == NULL) {
		printf("No Memory allocated...\n");
		return NULL;
	}

	strcpy(newnode->name, _n);		//newnode에서 이름을 비교해서 1과 0과 -1로 나누는것

	newnode->age = _a;

	while((current != NULL) && (current->age < _a))		//나이로 정렬
	{
		follow = current;
		current = current->next;

	}
	newnode->next = current;
	if (current == _list) _list = newnode;
	else follow->next = newnode;
	return _list;
}













