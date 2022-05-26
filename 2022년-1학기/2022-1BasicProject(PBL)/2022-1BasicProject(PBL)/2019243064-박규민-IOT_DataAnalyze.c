#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#pragma warning (disable:4996)

void loginsys(char userid[20], char userpw[30]);

int main()
{
	//로그인 시스템 변수
	int userchoice1;
	char userid[20], userpw[30];
	printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ안녕하세요 ㅁㅁㅁ아파트의 스마트홈 기능 시스템입니다.ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n\n");
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
		loginsys(userid, userpw);


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




	return 0;
}

void loginsys(char userid[20], char userpw[30])
{
	FILE* fp;
	fp = fopen("IOTuser.txt","r");



}