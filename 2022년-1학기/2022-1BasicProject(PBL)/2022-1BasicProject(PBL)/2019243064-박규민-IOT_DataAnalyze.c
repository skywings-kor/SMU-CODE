#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#pragma warning (disable:4996)

int loginsys(char userid[20], char userpw[30]);

int main()
{
	//로그인 시스템 변수
	int userchoice1;		//유저가 실행하기 위해 선택하는 것을 넣는 변수
	int logincheck;		//로그인 함수에서 반환값 받는 변수
	char userid[20], userpw[30];


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

		}

		else if (userchoice1 == 3)
		{

		}

		else if (userchoice1 == 0)
		{
			printf("                                     프로그램을 종료합니다...\n\n");
			exit(0);
		}

	}



	printf("로그인에 성공하여 메인페이지로 왔습니다");
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
		}

	}
	fclose(fp);		//파일 닫아줌
	return 0;		//로그인 실패


}