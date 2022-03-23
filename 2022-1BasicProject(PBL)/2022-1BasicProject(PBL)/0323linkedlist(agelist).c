//2019243064 ��ǻ�Ͱ��к�-�����Ͱ���-�ڱԹ�
//2022-03-23 Test Debug End;

#include <stdio.h>
#include <stdlib.h>  //malloc�Լ��� ���� 
#include <string.h>  //strcmp�� strcpy
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

void usercheck(NODE*_checker);		//�̰��� �߰������� �� ���� �� �Դϴ�!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

void main() 
{
	FILE* fp1, * fp2;
	NODE* list = NULL;
	fp1 = NULL;
	fp2 = NULL;
	list = loadData(list, "datafile1.txt", "datafile2.txt", fp1, fp2);
	printList(list);
	
	usercheck(list);	//�ش� ���� �����ϱ� ���� ��

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


void usercheck(NODE* checker)		//��! �̰��� ������ �Է��� �̸����� �ش� �̸����� ���̰� ���� ����� ǥ���ϴ� �Լ��Դϴ�!
{
	char username[15]="";		//���� ������ �Է��� ������ �Ҵ����ְ� �ʱ�ȭ�� ���ݴϴ�!
	NODE* check_current = NULL;		//��尡 ��ġ���ִ� ����
	NODE* check_follow = NULL;		//current�� ��ġ���ִ� �ٷ� �� ��ġ
	check_current = check_follow = checker;		//������ ����� ������ ��ġ�� ����ְ�!
	int countage = 0;		// ������ �Է��� �̸��� ���̸� ��� �־��ִ� ������ �ϳ� ������ݴϴ�


	for (int i = 0;; i++)		//���� �ݺ����� �ϳ� �����ϰ�
	{
		check_current = check_follow = checker;		//�̰��� �� ó������ ���ƿö����� �ʱ�ȭ���ֱ� ���� ����
		countage = 0;		//�̰͵� ����
		printf("�˻��Ͻ� �̸��� �Է����ּ���(0�Է½� ����˴ϴ�)=> ");	//���� �Է��Ͻÿ�!!~
		scanf("%s", username);		//���� string���� �Է����ְ�~
		
		if (strcmp(username,"0") == 0)		//�� ����! ���մϴ� !! ������ �Է��� ���� 0�ϰ�� ����� �� �ֵ���(�ݺ��� Ż��)
		{
			printf("���α׷��� �����մϴ�\n");
			break;
		}

	
		while (check_current->name != NULL)			//��ũ�� ����Ʈ�� ���� NULL�� ���ð�� Ż���ع������ϰ�
		{
			if (strcmp(username,check_current)==0)		//������ �Է��� string �� ��ũ�帮��Ʈ�� ����Ǿ��ִ� string�� ���� ��� �������ִ� ����
			{
				countage = check_current->age;		//countage��� ������ ���� ���� ������ �Է��� �̸��� �ش��ϴ� ���̸� �־��ְ�
				break;		//Ż��~
			}

			check_follow = check_current;		//while������ ��� ���� ��ũ�� ���� �ȵǴϱ� ���� ĭ���� �Ѿ���� ���ݴϴ�
			check_current = check_current->next;	//while������ ��� ���� ��ũ�� ���� �ȵǴϱ� ���� ĭ���� �Ѿ���� ���ݴϴ�

		}
		if ((check_current==NULL)||(check_current==check_follow))		//���� �ᱹ �������ͼ� �ƹ��͵� ��ã���� ��� �ش� ������ ����!
		{	//OR �ƴϸ� ���̰� ���� ��� ǥ���� ����� ���� ��쵵 �ش� ������ �����ϵ���..!
			printf("�ش��ڰ� �����ϴ�(���̰� ���� ���� ���� �ֽ��ϴ�)..\n");
		}
		
		else				//�� �ܿ��� ǥ���� ���� �ִٴ� �Ŵϱ� �ش� ������ �������ݴϴ�
		{
			check_current = checker;		//��� ���������� �� �̵����ְ�
			check_follow = checker;			//�굵 �̵����ݴϴ�
			printf("�ش� �ο����� ���̰� ���� �����\n");
			while (check_current->age < countage)		//��尡 ��ġ�� ���̰� countage ���� ���� ��� ��� ��� ���ϴ�
			{

				printf("%s \t %d \n", check_current->name, check_current->age);		//�� �ش��ϴ� ���� ���� ���! ��尡 ���� ��ġ���ִ� name�� age�� ǥ�����ݴϴ�.

				check_follow = check_current;	//���� ���� �̵��ϱ� ���� ����Դϴ�.
				check_current = check_current->next;		//���� ���� �̵��ϱ� ���� ����Դϴ�.
			}
			printf("�Դϴ�\n");
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

	strcpy(newnode->name, _n);		//newnode���� �̸��� ���ؼ� 1�� 0�� -1�� �����°�

	newnode->age = _a;

	while((current != NULL) && (current->age < _a))		//���̷� ����
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
