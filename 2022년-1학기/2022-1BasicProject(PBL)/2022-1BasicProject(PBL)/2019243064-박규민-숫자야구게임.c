#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#pragma warning (disable:4996)

typedef struct node 
{
	int correct;
	struct node* next;
}NODE;

NODE* randnumin(NODE* in_list);		//연결리스트에 랜덤값 넣어주는 함수
NODE* viewnode(NODE* walker);		//연결리스트 보여주는 함수(임시용)
NODE* strikecorrectcheck(NODE*list,int f1,int f2,int f3,int f4,int f5,int strikecount);		//노드와 유저가 입력한 값 5개 받아와서 정답 맞는지 확인하는 함수
NODE* ballcorrectcheck(NODE*list,int f1,int f2,int f3,int f4,int f5,int ballcount);		//노드와 유저가 입력한 값 5개 받아와서 정답 맞는지 확인하는 함수

int loginpage(char userinid[20], char userinpw[20]);		//로그인 기능 함수
int usercreate(char createid[20], char createpw[20]);

int main(void)
{
	printf("                                     <SMU-2019243064-컴퓨터공학부-박규민>\n\n");
	//로그인 구간ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
	int userlogin;		//유저 로그인할건지 회원가입할건지 비밀번호찾기할건지 프로그램 종료할건지 나누는 변수
	int success;		//로그인 성공시 반환값 받는거
	char userid[20];		//로그인->아이디 입력한거
	char userpw[20];		//로그인->비번입력한거

	char createid[20];
	char createpw[20];
	int createsuccess;

	for (int k = 0;; k++)		//로그인이나 회원가입이나 비밀번호 찾기 실패시 돌아오게 하기위한 for문
	{
		system("cls");
		success = 0;
		createsuccess = 0;
		userlogin = 0;

		printf("                       <1> 로그인           <2> 회원가입           <3> 비밀번호 찾기           <0> 프로그램 종료");
		scanf("%d", &userlogin);
	
		
		if (userlogin == 1)		//로그인
		{

			printf("아이디를 입력해주세요: ");
			scanf("%s", userid);

			printf("비밀번호를 입력해주세요: ");
			scanf("%s", userpw);

			success=loginpage(userid,userpw);

			if (success == 1)
			{
				printf("                       로그인 성공\n\n");
				break;
			}

			else
			{
				printf("                       ID또는 PW가 잘못되었습니다\n\n");
				system("pause");
			}
		}

		else if (userlogin == 2)		//회원가입
		{
			printf("만드실 ID입력: ");
			scanf("%s", createid);

			printf("만드실 PW입력: ");
			scanf("%s", createpw);

			createsuccess=usercreate(createid, createpw);
		}

		else if (userlogin == 3)
		{

		}

		else if (userlogin == 0)			//프로그램 종료
		{
			printf("프로그램을 종료합니다.");
			system("pause");
			exit(0);
		}

		else
		{
			printf("다시 입력해주세요");
		}

	}

	
	NODE* list;
	list= NULL;		//노드 리스트 초기화
	int userin;		//유저가 5자리 입력한 값
	int res5,res4, res3, res2, res1;		//사용자가 5자리 수 입력한거 나누기 위한 임시 변수
	int ballcount = 0;		//볼카운트
	int strikecount = 0;		//스트라이크 카운트

	list=randnumin(list);		//메인 연결리스트에 랜덤값 넣어주는 함수 실행된 리턴값 넣어주기
	

	for (int i = 1;; i++)		//무한루프
	{
		printf("\nㅡㅡㅡㅡ%d번째 기회ㅡㅡㅡㅡ",i);
		userin = 0;
		ballcount = 0;
		strikecount = 0;
		//유저가 다시 입력했을 때 기존 값이 남아있으면 안되니 초기화 해주기 위한 것
	

		printf("\n맞추실 숫자5자리를 입력(1~9, tip:0을 입력시 종료됩니다)->");

		scanf("%d", &userin);
		if (userin == 0)
		{
			printf("\n!!프로그램을 종료합니다!!");
			system("pause");
			exit(0);
		}

		else if ((10000>userin) || (99999 < userin))
		{
			printf("\n<error> 숫자가 잘못 입력되었습니다.\n");
			i = i - 1;
		}

		
		else
		{
			res5 = userin / 10000;
			userin = userin - res5 * 10000;

			res4 = userin / 1000;
			userin = userin - res4 * 1000;

			res3 = userin / 100;
			userin = userin - res3 * 100;

			res2 = userin / 10;
			userin = userin - res2 * 10;

			res1 = userin;
			printf("%d %d %d %d %d", res5, res4, res3, res2, res1);

			strikecount = strikecorrectcheck(list, res5, res4, res3, res2, res1, ballcount, strikecount);
			ballcount = ballcorrectcheck(list, res5, res4, res3, res2, res1, ballcount, strikecount);
			printf("\n%d스트라이크 %d볼입니다.\n", strikecount, ballcount);

			system("pause");
		}
		



	}

}

NODE* randnumin(NODE* in_list)
{
	int count=0;
	NODE* current = NULL, * follow = NULL,*checker=NULL;
	NODE* newnode;
	

	int temp = 0;

	srand(time(NULL));

	for (int i = 1; i<=5; i++)
	{
		checker = in_list;		//노드 돌아다니면 값 같을 경우 랜덤함수 다시 하도록 하는거

		follow = in_list;
		current = in_list;
		newnode = (NODE*)malloc(sizeof(NODE));

		temp = (rand() % 9) + 1;
		while (checker != NULL)
		{
			if (checker->correct == temp)
			{
				temp = (rand() % 9) + 1;
			}

			else
			{
				checker = checker->next;
			}
			
		}


		
		newnode->correct = temp;

		while (current != NULL)
		{
			
			follow = current;
			current = current->next;
		}
		newnode->next = current;
		if (current == in_list)
		{
			in_list = newnode;
		}

		else
		{
			follow->next = newnode;
		}
		
	}

	return in_list;

}

NODE* viewnode(NODE* walker)
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

NODE* strikecorrectcheck(NODE* list, int f1, int f2, int f3, int f4, int f5,int strikecount)	//노드와 유저가 입력한 값 5개 받아와서 정답 맞는지 확인하는 함수
{
	NODE* walker;
	walker = list;

	//첫번째자리
	if (walker->correct == f1)
	{
		strikecount = strikecount + 1;
	}

	walker = walker->next;

	//두번째자리
	if (walker->correct == f2)
	{
		strikecount = strikecount + 1;
	}

	walker = walker->next;

	//세번째자리
	if (walker->correct == f3)
	{
		strikecount = strikecount + 1;
	}

	walker = walker->next;

	//네번째자리
	if (walker->correct == f4)
	{
		strikecount = strikecount + 1;
	}

	walker = walker->next;

	//다섯번째자리
	if (walker->correct == f5)
	{
		strikecount = strikecount + 1;
	}


	return strikecount;
}

NODE* ballcorrectcheck(NODE* list, int f1, int f2, int f3, int f4, int f5, int ballcount)
{
	NODE* walker;
	walker = list;

	//첫번째자리
	if ((walker->correct == f2)||(walker->correct==f3) || (walker->correct == f4) || (walker->correct == f5))
	{
		ballcount = ballcount + 1;
	}

	walker = walker->next;

	//두번째자리
	if ((walker->correct == f1) || (walker->correct == f3) || (walker->correct == f4) || (walker->correct == f5))
	{
		ballcount = ballcount + 1;
	}

	walker = walker->next;

	//세번째자리
	if ((walker->correct == f2) || (walker->correct == f1) || (walker->correct == f4) || (walker->correct == f5))
	{
		ballcount = ballcount + 1;
	}

	walker = walker->next;

	//네번째자리
	if ((walker->correct == f2) || (walker->correct == f3) || (walker->correct == f1) || (walker->correct == f5))
	{
		ballcount = ballcount + 1;
	}

	walker = walker->next;

	//다섯번째자리
	if ((walker->correct == f2) || (walker->correct == f3) || (walker->correct == f4) || (walker->correct == f1))
	{
		ballcount = ballcount + 1;
	}


	return ballcount;
}

//로그인 함수			로그인 함수				로그인 함수			로그인 함수					로그인 함수					로그인 함수
int loginpage(char userinid[20], char userinpw[20])		
{
	FILE* fp;
	fp = fopen("user.txt", "r");

	char str[60];
	char* id;
	char* pw;
	while (!feof(fp))
	{
		fgets(str, sizeof(str), fp);
		id = strtok(str, " ");
		pw = strtok(NULL, " ");

		if ((strcmp(userinid, id) == 0) && (strcmp(userinpw, pw) == 0))
		{
			return 1;	//로그인에 성공할경우
			break;
		}


	}

	return 0;		//로그인에 실패할 경우

}

int usercreate(char createid[20], char createpw[20])
{
	FILE* fp;
	fp = fopen("user.txt", "r");

	char str[60];
	char* id;
	char* pw;
	while (!feof(fp))
	{
		fgets(str, sizeof(str), fp);
		id = strtok(str, " ");
		pw = strtok(NULL, " ");

		if (strcmp(createid, id) == 0)
		{
			return 1;		//같은 아이디가 이미 존재시
			break;
		}


	}
	//fp = fclose("user.txt");

	fp = fopen("user.txt", "a");
	//파일에 입력넣는거 구현해야함이어서
	
	

}