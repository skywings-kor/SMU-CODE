﻿#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#pragma warning (disable:4996)

typedef struct timenode
{
	int ontime;
	int offtime;
	struct timenode* next;
}TN;

typedef struct node {

	char room[10];
	char households[10];
	char id[20];
	char pw[30];

}NODE;

int loginsys(char userid[20], char userpw[30]);		//로그인함수

int signup(char room[10], char households[10], char createid[20], char createpw[30]);		//회원가입함수

int findidsys(char findroom[10], char findholds[10]);

int findpwsys(char findid[20]);

//데이터 생성 함수
int	LightDataCreate();



int main()
{
	//로그인 시스템 변수
	int userchoice1;		//유저가 실행하기 위해 선택하는 것을 넣는 변수
	int logincheck;		//로그인 함수에서 반환값 받는 변수
	char userid[20], userpw[30];

	//회원가입 변수
	char room[10];	//호실
	char households[10];		//세대원수
	char createid[20];		//아이디
	char createpw[30];		//비번
	int createcheck;		//회원가입이 정상적으로 되었는지 확인

	//아이디 비밀번호 찾기 변수
	int idpwuser;
	char findroom[10];
	char findholds[10];
	char findid[20];

	
	for (int i = 0; ; i++)
	{
		system("cls");
		printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ안녕하세요 ㅁㅁㅁ아파트의 ㅁㅁ동 스마트홈 기능 시스템입니다.ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n\n");
		printf("                                     원하시는 기능을 입력해주세요\n\n");
		printf("                                     <1>. 로그인\n\n");
		printf("                                     <2>. 회원가입\n\n");
		printf("                                     <3>. 아이디,비밀번호 찾기\n\n");
		printf("                                     <0>. 시스템 종료\n\n\n");

		printf("입력: ");
		scanf("%d", &userchoice1);

		if (userchoice1 == 1)
		{
			printf("아이디 입력(20자 이내): ");
			scanf("%s", userid);

			printf("비밀번호 입력(30자 이내): ");
			scanf("%s", userpw);
			logincheck = loginsys(userid, userpw);

			if (logincheck == 1)
			{
				printf("로그인성공\n\n");
				system("pause");
				break;

			}

			else if (logincheck == 0)
			{
				printf("ID 또는 PW가 틀렸습니다\n\n");
				system("pause");
			}
		}

		else if (userchoice1 == 2)
		{
			printf("호수를 입력해주세요(ex_1203): ");
			scanf("%s", room);

			printf("\n세대원이 몇명인지 입력해주세요(ex_4): ");
			scanf("%s", households);

			printf("\n만드실 아이디를 입력해주세요(20자 이내): ");
			scanf("%s", createid);

			printf("\n만드실 비밀번호를 입력해주세요(20자 이내): ");
			scanf("%s", createpw);

			createcheck=signup(room, households, createid, createpw);
			
			if (createcheck == 0)
			{
				printf("\n\n 중복된 아이디가 존재합니다..\n");
				system("pause");
			}

			else if (createcheck == 1)
			{
				printf("\n\n 이미 만들어져있는 호수입니다..\n");
				system("pause");
			}

			else if(createcheck==2)
			{
				printf("\n\n 정상적으로 회원가입이 완료되었습니다..\n");
				system("pause");
			}
		}

		else if (userchoice1 == 3)		//아이디, 비번 찾기
		{

			system("cls");
			printf("                                     <1>. 아이디 찾기\n\n");
			printf("                                     <2>. 비밀번호 찾기\n\n");

			scanf("%d", &idpwuser);

			if (idpwuser == 1)
			{
				printf("거주하시는 호수를 입력해주세요: ");
				scanf("%s", findroom);

				printf("세대원이 몇명인지 입력해주세요: ");
				scanf("%s", findholds);

				findidsys(findroom, findholds);
				system("pause");
			}

			else if (idpwuser == 2)		//비밀번호 찾는 기능
			{
				printf("아이디를 적어주세요: ");

				scanf("%s", findid);

				findpwsys(findid);
				system("pause");
			}


		}

		else if (userchoice1 == 0)
		{
			printf("                                     프로그램을 종료합니다...\n\n");
			exit(0);
		}

	}

	system("cls");

	printf("로그인에 성공하여 메인페이지로 왔습니다");
	LightDataCreate();
	return 0;
}

int loginsys(char userid[20], char userpw[30])
{
	//문자열 가져오기 위한 변수
	char str[100];
	char* getid;
	char* getpw;
	char* temp;

	FILE* fp;
	fp = fopen("IOTuser.txt","r");

	while (!feof(fp))		//파일의 끝이 나올때까지 반복
	{
		fgets(str, sizeof(str), fp); //한 줄 가져오도록 함

		temp=strtok(str, " ");		//호수
		temp=strtok(NULL, " ");		//세대원수
		getid = strtok(NULL, " ");		//아이디
		getpw = strtok(NULL, " \n");		//비밀번호

		if ((strcmp(userid, getid) == 0) && (strcmp(userpw, getpw) == 0))		//아이디하고 비밀번호가 일치할 경우 실행
		{
			fclose(fp);		//파일 닫아줌
			return 1;		//로그인 성공
			break;
		}

		else
		{

		}

	}
	fclose(fp);		//파일 닫아줌
	return 0;		//로그인 실패


}

//회원가입함수		회원가입함수		회원가입함수		회원가입함수		회원가입함수		회원가입함수		회원가입함수		
int signup(char room[10], char households[10], char createid[20], char createpw[30])
{
	//회원가입을 위한 변수
	char str[60];
	char* alid;
	char* alpw;
	char* alroom;
	char* temp;

	FILE* fp;


	fp = fopen("IOTuser.txt", "r");



	while (!feof(fp))		//열은 파일에서 마지막 부분까지 나올때까지 반복
	{
		fgets(str, sizeof(str), fp);	
		alroom = strtok(str, " ");		//호수 넣어두기
		temp = strtok(NULL, " ");
		alid = strtok(NULL, " ");		
		alpw = strtok(NULL, " \n");		//위 로그인 코드와 동일한 역할


		if (strcmp(createid, alid) == 0)		//같은 아이디가 이미 존재시
		{
			return 0;		//같은 아이디 오류
			break;
		}

		else if (strcmp(room, alroom) == 0)
		{
			return 1;		//같은 호수 오류
			break;
		}
		


	}
	//파일을 다 돌았는데 해당되는 것이 없을 경우 회원가입 진행시켜주기
	fclose(fp);
	fp = fopen("IOTuser.txt", "a");		//파일 입력 중 추가하는 형식으로 열기
	
	fputs("\n", fp);
	fputs(room, fp);
	fputs(" ", fp);

	fputs(households, fp);
	fputs(" ", fp);

	fputs(createid, fp);
	fputs(" ", fp);

	fputs(createpw, fp);
	

	fclose(fp);

	return 2;








}


int findidsys(char findroom[10], char findholds[10])		//아이디 찾는 함수
{
	char* room;
	char* holds;
	char* id;
	char str[60];
	FILE* fp;

	fp = fopen("IOTuser.txt", "r");

	while (!feof(fp))		//열은 파일에서 마지막 부분까지 나올때까지 반복
	{
		fgets(str, sizeof(str), fp);
		room = strtok(str, " ");		//호수 넣어두기
		holds = strtok(NULL, " ");
		id = strtok(NULL, " ");

		if ((strcmp(findroom, room) == 0)&& (strcmp(findholds, holds) == 0))		//호수하고 세대원수가 같을 시
		{
			printf("고객님의 아이디는 < %s > 입니다", id);
			return 1;		//찾음
			fclose(fp);
			break;
		}






	}

	fclose(fp);
	printf("정보와 일치한 데이터가 없습니다..");
	return 0;

}


int findpwsys(char findid[20])
{
	char* readid;
	char* readpw;
	char* temp;
	char* str[60];
	FILE* fp;
	
	fp = fopen("IOTuser.txt", "r");

	while (!feof(fp))		//열은 파일에서 마지막 부분까지 나올때까지 반복
	{
		fgets(str, sizeof(str), fp);
		temp = strtok(str, " ");		//호수 넣어두기
		temp = strtok(NULL, " ");
		readid = strtok(NULL, " ");
		readpw = strtok(NULL, " \n");
		if (strcmp(findid, readid) == 0)		//호수하고 세대원수가 같을 시
		{
			printf("고객님의 비밀번호는 < %s > 입니다", readpw);
			return 1;		//찾음
			fclose(fp);
			break;
		}

	}
	fclose(fp);
	printf("아이디와 일치하는 정보가 없습니다..");
	return 0;

}

//전등 데이터 생섬 함수		전등 데이터 생섬 함수		전등 데이터 생섬 함수
int	LightDataCreate()
{
	TN* timelist;		//시간 담아둘 리스트 선언
	timelist = NULL;
	TN* newnode;
	TN* current = NULL, * follow = NULL, *checker=NULL;

	srand(time(NULL));		//랜덤함수 쓰기위한 선언
	FILE* fp;
	fp = fopen("IOTdata.txt", "a");
	
	int errorcount = 0;

	char room1_light;		//방1
	char room2_light;		//방2
	char room3_light;		//방3
	char kitchen_light;		//부엌
	char bigroom_light;		//거실

	int room1_hour=0;
	int room1_min = 0;
	int room1_sec = 0;
	int room1_hourlong = 0;
	int room1_1temp = 0;
	int room1_2temp = 0;

	int room1_time=0;


	int wakeup=0;

	

	wakeup = rand() % 3 + 6;		//6~8까지 랜덤 숫자

	room1_time = rand() % 11;

	if (room1_time == 0)
	{

	}

	else
	{
		for (int i = 1; i <= room1_time; i++ )
		{
			errorcount = 1;		//일단 오류가 있는걸로 초기화
			room1_hour = rand() % (24 - wakeup   + 1) + wakeup;	//일어난 시간부터 자기전까지의 시간 중 전등 시간 배분
			room1_min = rand() % 61;
			room1_sec = rand() % 61;

			room1_1temp = (room1_hour * 60 * 60) + (room1_min * 60) + (room1_sec);		//키기 시작한 시간

			room1_hourlong = rand() % 3;

			if (room1_hourlong == 2)		//최대 2시간이 걸렸을 경우 분 초는 0으로 세팅
			{
				room1_min = 0;
				room1_sec = 0;
			}

			else	//아닐경우엔 이렇게 분,초 생성;
			{
				room1_min = rand() % 61;
				room1_sec = rand() % 61;
			}

			room1_2temp = (room1_hour * 60 * 60) + (room1_min * 60) + (room1_sec);		//끈 시간
			
			//이렇게 시작과 끝은 생성을 했는데, 이런 생성한 시간이 겹치는지 검토를 하도록 해야함 그러기 위해 2번째 실행부터는 이것을 거치도록함

			if (i > 1)		//한번 반복하고나면 무조건 검토하도록 하는거
			{
				checker = timelist;//검토하러 돌아다니는 역할
				
				while (checker != NULL)
				{
					if (((room1_1temp < checker->ontime) && (room1_2temp < checker->ontime)) || ((room1_1temp > checker->ontime) && (room1_2temp > checker->ontime)))
					{
						errorcount = 0;		//이상없음을 넣어줌
						break;
					}
					else
					{
						checker = checker->next;
					}
					
				}

			}


			if (errorcount == 0)
			{
				newnode = (TN*)malloc(sizeof(TN));
				newnode->ontime = room1_1temp;
				newnode->offtime = room1_2temp;

				while (current != NULL)
				{

				}
			}

			else if (errorcount == 1)		//시간이 겹치는 문제가 있을 경우
			{
				i = i - 1;		//횟수 1회 차감하여 반복하도록함
			}
			
			

			printf("room1_hour: %d", room1_hour);
			printf("        room1_min: %d", room1_min);
			printf("        room1_sec: %d\n", room1_sec);
			
			

		}
	}


	

	return 0;
}