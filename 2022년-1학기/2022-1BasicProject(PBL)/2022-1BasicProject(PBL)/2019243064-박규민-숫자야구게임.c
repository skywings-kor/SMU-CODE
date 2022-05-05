////2019243064 ��ǻ�Ͱ��к�-�����Ͱ���-�ڱԹ�
////2022-05-04 Test Debug End;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#pragma warning (disable:4996)

typedef struct node 
{
	int correct;		//������ ���� �����ϱ� ���� int�� ����
	struct node* next;		//��� ���� ���� ����Ű�� ���� ����
}NODE;

NODE* randnumin(NODE* in_list);		//���Ḯ��Ʈ�� ������ �־��ִ� �Լ�
NODE* viewnode(NODE* walker);		//���Ḯ��Ʈ �����ִ� �Լ�(�ӽÿ�)
NODE* strikecorrectcheck(NODE*list,int f1,int f2,int f3,int f4,int f5,int strikecount);		//���� ������ �Է��� �� 5�� �޾ƿͼ� ���� �´��� Ȯ���ϴ� �Լ�
NODE* ballcorrectcheck(NODE*list,int f1,int f2,int f3,int f4,int f5,int ballcount);		//���� ������ �Է��� �� 5�� �޾ƿͼ� ���� �´��� Ȯ���ϴ� �Լ�

int loginpage(char userinid[20], char userinpw[20]);		//�α��� ��� �Լ�
int usercreate(char createid[20], char createpw[20]);		//ȸ������ ��� �Լ�
int userfind(char findid[20]);		//��й�ȣ ã�� ��� �Լ�
int highscore(char loginid[20]);		//���� �� ���� ���� ǥ�����ִ� �Լ�
int scoresave(char loginid[20], char inscore);		//���� ���߰��� ���� �������ִ� �Լ�

int main(void)
{
	
	//�α��� �����ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�
	int userlogin;		//���� �α����Ұ��� ȸ�������Ұ��� ��й�ȣã���Ұ��� ���α׷� �����Ұ��� ������ ����

	int success;		//�α��� ������ ��ȯ�� �޴°�
	char userid[20];		//�α���->���̵� �Է��Ѱ�
	char userpw[20];		//�α���->����Է��Ѱ�

	char createid[20];		//ȸ������->���̵� �Է� ������
	char createpw[20];		//ȸ������->��й�ȣ �Է� ������
	int createsuccess;		//ȸ������ ������ ��ȯ�޴� ����

	char findid[20];		//��й�ȣã��->���̵� �Է� ������


	for (int k = 0;; k++)		//�α����̳� ȸ�������̳� ��й�ȣ ã�� ���н� ���ƿ��� �ϱ����� for��
	{
		system("cls");
		printf("                                     <SMU-2019243064-��ǻ�Ͱ��к�-�ڱԹ�>\n\n");
		success = 0;
		createsuccess = 0;
		userlogin = 0;

		printf("                       <1> �α���           <2> ȸ������           <3> ��й�ȣ ã��           <0> ���α׷� ���� \n");
		scanf("%d", &userlogin);
	
		
		if (userlogin == 1)		//�α���
		{

			printf("���̵� �Է����ּ���: ");
			scanf("%s", userid);

			printf("��й�ȣ�� �Է����ּ���: ");
			scanf("%s", userpw);

			success=loginpage(userid,userpw);		//�α��α���� ����ϴ� �Լ����� �α��� ������ ��ȯ�޴� �κ��Դϴ�.

			if (success == 1)		
			{
				printf("                       �α��� ����\n\n");
				break;
			}

			else
			{
				printf("                       ID�Ǵ� PW�� �߸��Ǿ����ϴ�\n\n");
				system("pause");
			}
		}

		else if (userlogin == 2)		//ȸ������
		{
			printf("����� ID�Է�: ");
			scanf("%s", createid);

			printf("����� PW�Է�: ");
			scanf("%s", createpw);

			createsuccess=usercreate(createid, createpw);		//ȸ�������� ����ϴ� �Լ����� ȸ������ ������ ��ȯ�޴� �κ��Դϴ�.

			if (createsuccess == 1)
			{
				printf("������ ���̵� �־� ȸ�����Կ� �����Ͽ����ϴ�");
				system("pause");
			}

			else
			{
				printf("ȸ������ ����!");
				system("pause");
			}

		}

		else if (userlogin == 3)		//��й�ȣ ã��
		{
			printf("ã���� ID�Է�: ");
			scanf("%s", findid);

			userfind(findid);		//����ڰ� ��й�ȣ ã�� ���� �Լ� �κ� �����մϴ�.

			system("pause");
		}

		else if (userlogin == 0)			//���α׷� ����
		{
			printf("���α׷��� �����մϴ�.");
			system("pause");
			exit(0);
		}

		else
		{
		
		}

	}

	int highnum;		//�ִ� Ƚ�� ���� ����
	system("cls");		//�ѹ� �� �����ϰ� ���ݴϴ�(�ܼ�â)
	printf("                                     <SMU-2019243064-��ǻ�Ͱ��к�-�ڱԹ�>\n\n");
	highnum=highscore(userid);		//����ڰ� �α����� ID�� ����Ǿ��ִ� ������ ã�� �ִ� Ƚ���� ǥ�õ˴ϴ�(���� �Ǿ��ִ� ������ ���� ��� 0�� ���)
	printf("                                                                               <�ִ�Ƚ�� : %d��>\n\n",highnum);
	NODE* list;		//���Ḯ��Ʈ ����~!
	list= NULL;		//��� ����Ʈ �ʱ�ȭ
	int userin;		//������ 5�ڸ� �Է��� ��
	int res5,res4, res3, res2, res1;		//����ڰ� 5�ڸ� �� �Է��Ѱ� ������ ���� �ӽ� ����
	int ballcount = 0;		//��ī��Ʈ
	int strikecount = 0;		//��Ʈ����ũ ī��Ʈ

	list=randnumin(list);		//���� ���Ḯ��Ʈ�� ������ �־��ִ� �Լ� ����� ���ϰ� �־��ֱ�
	viewnode(list);

	for (int i = 1;; i++)		//���ѷ���
	{
		printf("\n�ѤѤѤ�%d��° ��ȸ�ѤѤѤ�",i);
		userin = 0;
		ballcount = 0;
		strikecount = 0;
		//������ �ٽ� �Է����� �� ���� ���� ���������� �ȵǴ� �ʱ�ȭ ���ֱ� ���� ��
	

		printf("\n���߽� �ߺ����� �ʴ� ����5�ڸ��� �Է�(1~9, tip:0�� �Է½� ����˴ϴ�)->");

		scanf("%d", &userin);
		if (userin == 0)	//���� �� ����ڰ� ���� �����ϰ� ������ 0 �Է��ϸ� ����ǰ� �� ��
		{
			printf("\n!!���α׷��� �����մϴ�!!");
			system("pause");
			exit(0);		//����
		}

		else if ((10000>userin) || (99999 < userin))		//����ڰ� �Է��� ���� 5�ڸ����� �Ѱų� ������� �����ϴ� �κ�
		{
			printf("\n<error> ���ڰ� �߸� �ԷµǾ����ϴ�.\n");
			i = i - 1;
		}

		
		else
		{
			res5 = userin / 10000;		//ù ��° �ڸ�
			userin = userin - res5 * 10000;
				
			res4 = userin / 1000;		//�� ��° �ڸ�
			userin = userin - res4 * 1000;

			res3 = userin / 100;		//�� ��° �ڸ�
			userin = userin - res3 * 100;

			res2 = userin / 10;		//�� ��° �ڸ�
			userin = userin - res2 * 10;

			res1 = userin;		//�ټ� ��° �ڸ�
			

			if ((res5 == res4) || (res5 == res3) || (res5 == res2) || (res5 == res1) || (res4 == res3) || (res4 == res2) || (res4 == res1) || (res3 == res2) || (res3 == res1) || (res2 == res1))
			{//����ڰ� �ߺ��� ���ڸ� �Է��� ���� ������� ���� ��Ÿ���ִ°�
				printf("�ߺ��� ���ڰ� �ԷµǾ����ϴ�.\n");
				i = i - 1;
			}

			else
			{
				printf("%d %d %d %d %d", res5, res4, res3, res2, res1);		//����ڰ� � ���ڸ� �Է��Ͽ����� ������

				strikecount = strikecorrectcheck(list, res5, res4, res3, res2, res1, ballcount, strikecount);		//��Ʈ����ũ ���� ���� �Լ� ����
				ballcount = ballcorrectcheck(list, res5, res4, res3, res2, res1, ballcount, strikecount);		//�� ���� ���� �Լ� ����
				printf("\n%d��Ʈ����ũ %d���Դϴ�.\n", strikecount, ballcount);

				if (strikecount == 5)//����ڰ� ������ ������(��Ʈ����ũ 5��)
				{
					printf("���ϵ帳�ϴ�! %d��° ���� �����ϼ̽��ϴ�! \n\n", i);		
					char changescore = i + '0';		//i�� int���̴ٺ��� ����� 0�� ���ؼ� char������ �ٲ��ݴϴ�
					scoresave(userid, changescore);		//���� �����ϴ� �Լ��� ����id, char������ ������ ������ �����ݴϴ�.
					printf("!������ ����Ǿ����ϴ�! \n");
					break;
				}

				system("pause");
			}
			
			

		}
		



	}
	
	//�ݺ��� Ż��� �����ϴ� �κ�
	printf("������ �����մϴ�...\n");		
	system("pause");
	exit(0);

}

//���� ���� ���Ḯ��Ʈ ���� �Լ�			���� ���� ���Ḯ��Ʈ ���� �Լ�			���� ���� ���Ḯ��Ʈ ���� �Լ�			���� ���� ���Ḯ��Ʈ ���� �Լ�
NODE* randnumin(NODE* in_list)
{
	int count=0;
	int errorcount = 0;		//�ߺ� ���� ī��Ʈ
	NODE* current = NULL, * follow = NULL,*checker=NULL,*walker=NULL;
	NODE* newnode;
	

	int temp = 0;		//�ӽ����忪���� int�� ����

	srand(time(NULL));		//�����Լ� �������� ����

	for (int i = 1; i<=5; i++)
	{
		checker = in_list;		//��� ���ƴٴϸ� �� ���� ��� �����Լ� �ٽ� �ϵ��� �ϴ°�
		
		follow = in_list;
		current = in_list;
		newnode = (NODE*)malloc(sizeof(NODE));		//���ο� ���Ḯ��Ʈ �޸� �Ҵ�

		temp = rand() % 9 + 1;		//�ӽ� ������ ������ 1�� ����

		while (checker != NULL)		//��ø�Ǵ� ���� �˻��ϱ� ���� ���Ḯ��Ʈ ���ƴٴϴ� �κ�
		{
			
			walker = in_list;
			errorcount = 0;		//0���� �ʱ�ȭ
			while (walker != NULL)		//���Ḯ��Ʈ���� �ߺ� ���� �˻��ϴ� �κ� ������(���� �ߺ� ���� ��ġ�°� ������ �ش� �κ��� �ƹ��� ���� ������)
			{
				if (walker->correct == temp)		//���Ḯ��Ʈ�� ������ִ� ������ �ӽ� �־�� ���̶� ������� errorcount 1�� �༭ �ٽ� ���� �Ѵ�.
				{
					errorcount = 1;		//�ߺ� �����ΰ��� �˷��ִ°�
					break;
				}

				else  //�ƴҰ�� ���Ḯ��Ʈ ����ĭ�� ����Ű�� �Ͽ� ���Ḯ��Ʈ �ߺ� ���� Ȯ���� �̾� ������.
				{
					walker = walker->next;
				}
			}

			if (errorcount==1)	//�ߺ� ���ڰ� ������� temp�� �ٽ� �������� �ش�
			{
				temp = rand() % 9 + 1;
			}

			else
			{
				checker = checker->next;
			}
			
		}


		
		newnode->correct = temp;	//�� �˻��ϰ� Ż������ ��� �̻��� ������ �� ��忡 temp�� ����ִ� ������ �ִ´�.

		while (current != NULL)		//���Ḯ��Ʈ�� �������� ���ö����� �ݺ�
		{
			
			follow = current;
			current = current->next;
		}
		newnode->next = current;
		if (current == in_list)
		{
			in_list = newnode;		//Ȥ�ö� ���Ḯ��Ʈ�� �ƹ��͵� ��� ó�� �κ��� ��� ����� ���� newnode�� ����Ű�� �ϴ� ��
		}

		else
		{
			follow->next = newnode;		//�ƴ� ���� follow�� ������ newnode�� ������� ���Ḯ��Ʈ �ϼ��ǰ���
		}
		
	}

	return in_list;		//�� �ϼ����� ��� ���Ḯ��Ʈ�� ���������ν� ���� ������ ����ִ� ���Ḯ��Ʈ �ϼ�~!

}

//���� ������ �� ���� �����ִ� �Լ�			���� ������ �� ���� �����ִ� �Լ�			���� ������ �� ���� �����ִ� �Լ�

NODE* viewnode(NODE* walker)		//�ʹ� ���� �����缭 ������ ���� ���� �׽�Ʈ �Ϸ��� ���� ������ ������ �ڵ��Դϴ�...(�Ф�...)
{
	if (walker != NULL)
	{
		printf("%d ", walker->correct);
		viewnode(walker->next);
	}

	else
	{
		return walker;
	}
}

//��Ʈ����ũ ���� Ȯ���ϴ� �Լ�			��Ʈ����ũ ���� Ȯ���ϴ� �Լ�			��Ʈ����ũ ���� Ȯ���ϴ� �Լ�			��Ʈ����ũ ���� Ȯ���ϴ� �Լ�
NODE* strikecorrectcheck(NODE* list, int f1, int f2, int f3, int f4, int f5,int strikecount)	//���� ������ �Է��� �� 5�� �޾ƿͼ� ���� �´��� Ȯ���ϴ� �Լ�
{
	NODE* walker;
	walker = list;

	//ù��°�ڸ�
	if (walker->correct == f1)
	{
		strikecount = strikecount + 1;
	}

	walker = walker->next;

	//�ι�°�ڸ�
	if (walker->correct == f2)
	{
		strikecount = strikecount + 1;
	}

	walker = walker->next;

	//����°�ڸ�
	if (walker->correct == f3)
	{
		strikecount = strikecount + 1;
	}

	walker = walker->next;

	//�׹�°�ڸ�
	if (walker->correct == f4)
	{
		strikecount = strikecount + 1;
	}

	walker = walker->next;

	//�ټ���°�ڸ�
	if (walker->correct == f5)
	{
		strikecount = strikecount + 1;
	}


	return strikecount;		//��Ʈ����ũ ���� ���� �Լ��� ����
}

//������ Ȯ���ϴ� �Լ�			������ Ȯ���ϴ� �Լ�			������ Ȯ���ϴ� �Լ�			������ Ȯ���ϴ� �Լ�
NODE* ballcorrectcheck(NODE* list, int f1, int f2, int f3, int f4, int f5, int ballcount)
{
	NODE* walker;
	walker = list;

	//ù��°�ڸ�
	if ((walker->correct == f2)||(walker->correct==f3) || (walker->correct == f4) || (walker->correct == f5))
	{
		ballcount = ballcount + 1;
	}

	walker = walker->next;

	//�ι�°�ڸ�
	if ((walker->correct == f1) || (walker->correct == f3) || (walker->correct == f4) || (walker->correct == f5))
	{
		ballcount = ballcount + 1;
	}

	walker = walker->next;

	//����°�ڸ�
	if ((walker->correct == f2) || (walker->correct == f1) || (walker->correct == f4) || (walker->correct == f5))
	{
		ballcount = ballcount + 1;
	}

	walker = walker->next;

	//�׹�°�ڸ�
	if ((walker->correct == f2) || (walker->correct == f3) || (walker->correct == f1) || (walker->correct == f5))
	{
		ballcount = ballcount + 1;
	}

	walker = walker->next;

	//�ټ���°�ڸ�
	if ((walker->correct == f2) || (walker->correct == f3) || (walker->correct == f4) || (walker->correct == f1))
	{
		ballcount = ballcount + 1;
	}


	return ballcount;		//�� ���� ���� �Լ��� ����
}

//�α��� �Լ�			�α��� �Լ�				�α��� �Լ�			�α��� �Լ�					�α��� �Լ�					�α��� �Լ�
int loginpage(char userinid[20], char userinpw[20])		
{
	FILE* fp;
	fp = fopen("user.txt", "r");		//user.txt������ �д� �������� ����

	char str[60];
	char* id;
	char* pw;
	while (!feof(fp))		//���� ���Ͽ��� ������ �κб��� ���ö����� �ݺ�
	{
		fgets(str, sizeof(str), fp);		//�� �� ������
		id = strtok(str, " ");		//�����̽��� �ϳ��� ���ڿ��� ������ id�� ����
		pw = strtok(NULL, " \n");		//���� ���� �̾� �޾� �ٹٲ� ������ ������ �� ������ pw�� ����

		if ((strcmp(userinid, id) == 0) && (strcmp(userinpw, pw) == 0))		//������ �Է��� ���̵��ϰ� ��й�ȣ�� user.txt�� �����ִ� �Ͱ� ������ ��� ����
		{
			fclose(fp);		//���� �������� �ݾ���
			return 1;	//�α��ο� �����Ұ��
			break;
		}


	}
	fclose(fp);		//�����ص� �ݾ���!
	return 0;		//�α��ο� ������ ���

}

//ȸ������ �Լ�		ȸ������ �Լ�		ȸ������ �Լ�		ȸ������ �Լ�		ȸ������ �Լ�		ȸ������ �Լ�		ȸ������ �Լ�
int usercreate(char createid[20], char createpw[20])
{
	FILE* fp;
	fp = fopen("user.txt", "r");		//user.txt������ �д� �������� ����

	char str[60];
	char* id;
	char* pw;
	while (!feof(fp))		//���� ���Ͽ��� ������ �κб��� ���ö����� �ݺ�
	{
		fgets(str, sizeof(str), fp);	
		id = strtok(str, " ");		
		pw = strtok(NULL, " ");		//�� �α��� �ڵ�� ������ ����

		if (strcmp(createid, id) == 0)		//���� ���̵� �̹� �����
		{
			return 1;		
			break;
		}


	}


	//���� ���̵� ���� ���ο� ���̵��϶� ����
	fclose(fp);		//���� r�������� �������� �ݾ��ְ�


	fp = fopen("user.txt", "a");		//user.txt���Ͽ� �߰� �ۼ����� �ϵ��� ����
	
	fputs(createid, fp);		//user.txt���Ͽ� ������ �Է��� id �ְ�
	fputs(" ", fp);		//��ĭ ����ְ�
	fputs(createpw, fp);		//user.txt���Ͽ� ������ �Է��� pw�ְ�

	fputs("\n", fp);		//enter�ϳ� ���ְ�(��ĭ ������)


	fclose(fp);		//�� �ۼ������� �ݾ��ְ�

	return 0;

	

}

//��й�ȣ ã�� �Լ�		��й�ȣ ã�� �Լ�				��й�ȣ ã�� �Լ�				��й�ȣ ã�� �Լ�				��й�ȣ ã�� �Լ�
int userfind(char findid[20])
{
	FILE* fp;
	fp = fopen("user.txt", "r");		//���� �б� �������� ����
	char str[60];
	char* resid;
	char* respw;
	

	while (!feof(fp))		//���� ������ ���� ���ö����� �ݺ���
	{
		fgets(str, sizeof(str), fp);		//�� �پ� �����ͼ� str ������ �ְ�

		resid = strtok(str, " ");
		respw = strtok(NULL, " \n");

		if (strcmp(resid, findid) == 0)		//ã������ ID�� ����Ǿ��ִ� ID �� ������� �ش� ��� ǥ��
		{
			printf("�ش� ID�� ����� < %s > �Դϴ�.", respw);

			return 1;
		}


	}
	fclose(fp);
	printf("�ش� ID�� �������� �ʽ��ϴ�");
	return 0;
}

//�α����� ID�� ���� �ܽð��� ������ Ƚ�� ǥ��				�α����� ID�� ���� �ܽð��� ������ Ƚ�� ǥ��				�α����� ID�� ���� �ܽð��� ������ Ƚ�� ǥ��
int highscore(char loginid[20])		//�ش� ID�� �ְ�����(Ƚ��) �ҷ����°�
{
	FILE* fp;
	fp = fopen("score.txt", "r");

	char str[60];
	char* resid;		//�α����� ����� id
	int highnum = 1000;		//������ 1000��(�־�����)	
	while (!feof(fp))
	{
		char* resscore;		//score.txt���Ͽ� �����ִ� ���� �����ϴ� ��
		int changescore;		//resscore�� atoi�� int�� ��ȯ�ؼ� �־�α� ���� int�� ����
		fgets(str, sizeof(str), fp); 
		resid = strtok(str, " ");
		resscore = strtok(NULL, " \n");
		
		changescore = atoi(resscore);		//atoi�� char�� int�� ��ȯ�ؼ� changescore�� �־���
		if ((strcmp(resid, loginid) == 0)&&(changescore<highnum))		//���̵� ���� ���� ������ �������� �ִ�Ƚ���� �� ������ ��Ÿ����� ����
		{
			highnum = changescore;
		}
		
	}
	
	fclose(fp);
	
	if (highnum == 1000)		//score.txt ���Ͽ� �α����� id�� ��ġ�ϴ� ������ �������� ���� ���
	{
		return 0;		//���� 0�� �����༭ ���ٴ� ���� �˷���
	}

	else
	{
		return highnum;		//�ִ� Ƚ�� ����Ȱ� main�� ������
	}
	
}

//���� ���� �Լ�			���� ���� �Լ�			���� ���� �Լ�			���� ���� �Լ�				���� ���� �Լ�			���� ���� �Լ�
int scoresave(char loginid[20], char inscore)		//�������κ��� �α����� id�ϰ� ���� �޼��� ������ ����
{
	FILE* fp;
	fp = fopen("score.txt","a");	//���� �߰��ۼ� �������� ����
	fputs("\n", fp);
	fputs(loginid, fp);		//score.txt���Ͽ� id �ۼ�
	fputs(" ", fp);

	fputc(inscore, fp);		//score.txt���Ͽ� pw �ۼ�

	


	fclose(fp);		//���� �������� �ݾ���

	return 0;
}