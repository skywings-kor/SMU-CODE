//#include <stdio.h>
//#include <stdlib.h>  //malloc함수를 위해 
//#include <string.h>  //strcmp와 strcpy
//#pragma warning (disable:4996)
//typedef struct node {
//	char name[15];
//	int age;
//	struct node* next;
//}NODE;
//
//NODE* loadData(NODE* _list, char* fname1, char* fname2, FILE* _fp1, FILE* _fp2);
//NODE* insertNode(NODE* _list, char* _n, int _a);
//void printList(NODE* walker);
//
//void main() {
//	FILE* fp1, * fp2;
//	NODE* list = NULL;
//	fp1 = NULL;
//	fp2 = NULL;
//	list = loadData(list, "datafile1.txt", "datafile2.txt", fp1, fp2);
//	printList(list);
//}
//
//void printList(NODE* walker) {
//	if (walker == NULL) printf("==End of Print====\n");
//	else {
//		printf("%s\t%d\n", walker->name, walker->age);
//		printList(walker->next);
//	}
//}
//
//
//NODE* loadData(NODE* _list, char* fname1, char* fname2, FILE* _fp1, FILE* _fp2) {
//	char nameData[15];
//	int ageData;
//	if ((_fp1 = fopen(fname1, "r")) == NULL) {
//		printf("File Open Error!!!");
//		return NULL;
//	}
//	if ((_fp2 = fopen(fname2, "r")) == NULL) {
//		printf("File Open Error!!!");
//		return NULL;
//	}
//	while (!feof(_fp1)) {
//		fscanf(_fp1, "%s\t%d", nameData, &ageData);
//		_list = insertNode(_list, nameData, ageData);
//	}
//	while (!feof(_fp2)) {
//		fscanf(_fp2, "%s\t%d", nameData, &ageData);
//		_list = insertNode(_list, nameData, ageData);
//	}
//
//	return _list;
//}
//
//NODE* insertNode(NODE* _list, char* _n, int _a) {
//	NODE* current = NULL, * follow = NULL, * newnode = NULL;
//	current = follow = _list;
//
//	if ((newnode = (NODE*)malloc(sizeof(NODE))) == NULL) {
//		printf("No Memory allocated...\n");
//		return NULL;
//	}
//	strcpy(newnode->name, _n);
//	newnode->age = _a;
//	while ((current != NULL) && strcmp(current->name, _n) < 0) {  //이름으로 오름차순
////	while((current != NULL) && (current->age < _a)){  //나이로 오름차순 
//		follow = current;
//		current = current->next;
//
//	}
//	newnode->next = current;
//	if (current == _list) _list = newnode;
//	else follow->next = newnode;
//	return _list;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
