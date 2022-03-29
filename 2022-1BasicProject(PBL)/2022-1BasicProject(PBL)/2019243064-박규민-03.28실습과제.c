//2019243064 ��ǻ�Ͱ��к�-�����Ͱ���-�ڱԹ�
//2022-03-23 Test Debug End;

#include <stdio.h>
#include <stdlib.h>  //malloc�Լ��� ���� 
#include <string.h>  //strcmp�� strcpy
#include<windows.h>
#pragma warning (disable:4996)

typedef struct node
{
	char name[15];
	int age;
	struct node* next;
}NODE;


NODE* delData(NODE* del_list);		//����� �Լ�
NODE* loadData(NODE* _list);		//��� ���� �Լ�
NODE* insertNode(NODE* _list, char* _n, int _a);		//��� �����Լ����� ���Ǿ����� ��
void printList(NODE* walker);		//��� ����Լ�

void usercheck(NODE* _checker);		// search �κ�

void  main()
{
	NODE* list = NULL;
	int inuser;
	for (int i = 0;; i++)
	{
		
		system("pause");
		system("cls");		//�ѹ� ������ ȭ�� �� ����°�
		printf("Enter [(1)Insert,(2)Delete,(3)Search,(4)Exit]: ");
		scanf("%d", &inuser);

		if (inuser == 1)		//�� �ִ� �κ�
		{
			list=loadData(list);	//������ �� �Է��Ѱ� ��忡 �־��ְ�
			printList(list);		//�ְ��� ����� �־����� ���ı��� �Ǿ����� Ȯ�� ��ũ�� ����ְ�
		}

		else if (inuser == 2)		//��� �����κ�
		{
			printf("������� ����Ʈ�� �����帳�ϴ�.\n");
			printList(list);
			delData(list);
		}

		else if (inuser == 3)		//�̸� ������ �̸��ϰ� ���� ����־ ã���ִ� �κ�
		{
			usercheck(list);
			
		}

		else if (inuser == 4)		//����κ�
		{
			printf("�ý����� �����մϴ�");
			exit(0);
		}
	}
}

void printList(NODE* walker)
{
	NODE* print_current=NULL;		//���� �̰� �ӽ÷� �������
	
	if (walker == NULL)
	{
		printf("==End of Print====\n");
	}
	else
	{
		printf("%s %d\n", walker->name, walker->age);
		printList(walker->next);
	}
}

void usercheck(NODE* checker)		//��! �̰��� ������ �Է��� �̸����� �ش� �̸����� ���̰� ���� ����� ǥ���ϴ� �Լ��Դϴ�!
{
	char username[15] = "";		//���� ������ �Է��� ������ �Ҵ����ְ� �ʱ�ȭ�� ���ݴϴ�!
	NODE* check_current = NULL;		//��尡 ��ġ���ִ� ����
	NODE* check_follow = NULL;		//current�� ��ġ���ִ� �ٷ� �� ��ġ
	check_current = check_follow = checker;		//������ ����� ������ ��ġ�� ����ְ�!
	int countage = 0;		// ������ �Է��� �̸��� ���̸� ��� �־��ִ� ������ �ϳ� ������ݴϴ�


	for (int i = 0; ; i++)		//���� �ݺ����� �ϳ� �����ϰ�
	{
		check_current = check_follow = checker;		//�̰��� �� ó������ ���ƿö����� �ʱ�ȭ���ֱ� ���� ����
		countage = 0;		//�̰͵� ����
		printf("ã���÷��� �̸��� �Է����ּ���: ");
		scanf("%s", username);		//���� string���� �Է����ְ�~


		while (check_current->name != NULL)			//��ũ�� ����Ʈ�� ���� NULL�� ���ð�� Ż���ع������ϰ�
		{
			if (strcmp(username, check_current->name) == 0)		//������ �Է��� string �� ��ũ�帮��Ʈ�� ����Ǿ��ִ� string�� ���� ��� �������ִ� ����
			{
				printf("�ش� �ο��� �̸��� %s �̸�, ���̴� %d�� �Դϴ�.\n", check_current->name, check_current->age);		//countage��� ������ ���� ���� ������ �Է��� �̸��� �ش��ϴ� ���̸� �־��ְ�
				return checker;
			}

			check_follow = check_current;		//while������ ��� ���� ��ũ�� ���� �ȵǴϱ� ���� ĭ���� �Ѿ���� ���ݴϴ�
			check_current = check_current->next;	//while������ ��� ���� ��ũ�� ���� �ȵǴϱ� ���� ĭ���� �Ѿ���� ���ݴϴ�

		}

		if ((check_current == NULL) || (check_current == check_follow))		//���� �ᱹ �������ͼ� �ƹ��͵� ��ã���� ��� �ش� ������ ����!
		{	//OR �ƴϸ� ���̰� ���� ��� ǥ���� ����� ���� ��쵵 �ش� ������ �����ϵ���..!
			printf("�ش��ڰ� �����ϴ�...\n");

		}



	}
}

NODE* loadData(NODE* _list)
{
	char nameData[15];
	int ageData;

	printf("�̸��� ���̸� �Է����ּ���: ");
	scanf("%s %d", nameData, &ageData);

	_list = insertNode(_list, nameData, ageData);

	return _list;
}

NODE* insertNode(NODE* _list, char* _n, int _a)
{
	NODE* current = NULL, * follow = NULL, * newnode = NULL;
	follow = _list;
	current = _list;

	if ((newnode = (NODE*)malloc(sizeof(NODE))) == NULL)
	{
		printf("No Memory allocated...\n");
		return NULL;
	}

	strcpy(newnode->name, _n);		//newnode���� �̸��� ���ؼ� 1�� 0�� -1�� �����°�

	newnode->age = _a;

	while ((current != NULL) && (current->age < _a))		//���̷� ����
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

NODE* delData(NODE* del_list)
{
	NODE* current , * follow ;
	current = follow = del_list;
	char delname[15]="";


	printf("������ �̸��� �Է����ּ���: ");
	scanf("%s", delname);

	if (strcmp(current->name, delname) == 0)	//������� ��尡 ù��° ��Ʈ�� ��� �����ϴ� ��
	{
		
		del_list= current->next;		//����� ���ۺκ��� current->next�� �Ͽ��µ� ��� ���ۺκ� �������� ���ư��� �����(free�ص� free�� �κ��� ��Ÿ��;;)
		free(current);
		
		printList(del_list);

		return ;
		/*free(current);
		
		printList(del_list);*/
	}

	else
	{
		while (current != NULL)
		{
			follow = current;
			current = current->next;

			if ((strcmp(current->name, delname) == 0) && (current->next != NULL))		//�߰��κ�
			{
				follow->next = current->next;
				
				free(current);

				printList(del_list);
				return del_list;
			}

			else if ((strcmp(current->name, delname) == 0) && (current->next == NULL))		// �Ǹ�����
			{
				follow->next = NULL;
				
				free(current);

				printList(del_list);
				return del_list;
			}

			else if(current->next==NULL)
			{
				printf("ã�� �̸��� �����ϴ�...");
				return del_list;
			}
		}

	}

}
