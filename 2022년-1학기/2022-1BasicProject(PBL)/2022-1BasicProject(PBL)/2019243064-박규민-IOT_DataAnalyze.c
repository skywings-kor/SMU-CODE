#include <stdio.h>
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
int	Room1LightDataCreate(char apartroom[6]);

int	Room2LightDataCreate(char apartroom[6]);

int	Room3LightDataCreate(char apartroom[6]);

int KitchenLightDataCreate(char apartroom[6]);

int	LivingloomLightDataCreate(char apartroom[6]);

int InductionDataCreate(char apartroom[6]);

int WahserDataCreate(char apartroom[6]);

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

	//아파트 호수 배열 저장
	char ApartRoom[36][10] = {
		"101","102","201","202","301","302","401","402","501","502",
		"601","602","701","702","801","802","901","902","1001","1002",
		"1101","1102","1201","1202","1301","1302","1401","1402","1501","1502",
		"1601","1602","1701","1702","1801","1802"
	};

	system("cls");

	printf("데이터 생성을 시작합니다...\n\n");
	for (int i = 0; i < 36; i++)		//모든 호수를 생성하기위해 반복문 사용
	{
		printf("%s 데이터 생성 완료..\n", ApartRoom[i]);
		Room1LightDataCreate(ApartRoom[i]);		//방1 전등
		Room2LightDataCreate(ApartRoom[i]);		//방2 전등
		Room3LightDataCreate(ApartRoom[i]);		//방3 전등
		KitchenLightDataCreate(ApartRoom[i]);	//주방 전등
		LivingloomLightDataCreate(ApartRoom[i]);	//거실 전등
		InductionDataCreate(ApartRoom[i]);		//주방 인덕션


	}
	

	
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
int	Room1LightDataCreate(char apartroom[6])
{
	TN* timelist;		//시간 담아둘 리스트 선언
	timelist = NULL;
	TN* newnode;
	TN* current = NULL, * follow = NULL, *checker=NULL,*testcheck=NULL;
	srand(time(NULL));		//랜덤함수 쓰기위한 선언
	
	FILE* fp;

	int errorcount = 0;

	int room1_hour=0;
	int room1_min = 0;
	int room1_sec = 0;
	int room1_hourlong = 0;
	int room1_1temp = 0;
	int room1_2temp = 0;
	int room1_time=0;

	int wakeup=0;

	fp = fopen("IOTdata.txt", "a");
	for (int day = 1; day <= 30; day++)
	{
		timelist = NULL;		//값을 넣기위해서 만든 연결리스트는 계속 초기화해줍니다. 아니면 겹쳐서 계속 시간이 쌓이게 됩니다.
		
		wakeup = rand() % 3 + 6;		//6~8까지 랜덤 숫자
		room1_time = rand() % 11;

			if (room1_time == 0)
			{
				//room1_time이 킨 적이 하루에 한 번도 없을 때 pass 하도록 하는 것
			}

			else
			{
				for (int i = 1; i <= room1_time; i++)
				{
					errorcount = 0;		//일단 오류가 없는걸로 초기화
					current = timelist;
					follow = timelist;
					checker = timelist;
					testcheck = timelist;

					if (checker == NULL)		//처음 넣게되면 연결리스트에 아무것도 없어서 무한루프에 빠져서 추가해주기
					{
						errorcount = 0;
					}

					room1_hour = rand() % (24 - wakeup + 1) + wakeup;	//일어난 시간부터 자기전까지의 시간 중 전등 시간 배분
					room1_min = rand() % 61;	//키는 분 생성
					room1_sec = rand() % 61;	//키는 초 생성

					room1_1temp = (room1_hour * 60 * 60) + (room1_min * 60) + (room1_sec);		//킨 시간을 초로 변환

					room1_hourlong = rand() % 3 + 1;		//시간 지속시간
					room1_min = rand() % 61;	//끄는 분 생성
					room1_sec = rand() % 61;	//끄는 초 생성
					room1_hour = room1_hour + room1_hourlong;//시간 늘어난거 더해주기

					room1_2temp = (room1_hour * 60 * 60) + (room1_min * 60) + (room1_sec);		//끈 시간을 초로 변환

					//이렇게 시작과 끝은 생성을 했는데, 이런 생성한 시간이 겹치는지 검토를 하도록 해야함 그러기 위해 2번째 실행부터는 이것을 거치도록함

					if (i > 1)		//한번 반복하고나면 무조건 검토하도록 하는거
					{
						while (checker != NULL)
						{
							if (((room1_1temp < checker->ontime) && (room1_2temp < checker->ontime)) || ((room1_1temp > checker->offtime) && (room1_2temp > checker->offtime)))
							{
								checker = checker->next;
							}

							else
							{
								errorcount = 0;
								checker = checker->next;
							}
						}
					}

					if (errorcount == 0)
					{
						newnode = (TN*)malloc(sizeof(TN));
						newnode->ontime = room1_1temp;		//킨시간
						newnode->offtime = room1_2temp;		//끈시간

						while ((current != NULL) && (current->ontime < newnode->ontime))
						{
							if (room1_1temp < newnode->ontime)
							{
								break;
							}

							else
							{
								follow = current;
								current = current->next;
							}
						}
						newnode->next = current;
						if (current == timelist)		//아무것도 없을 경우 첫번째 칸에 넣기
						{
							timelist = newnode;
						}

						else
						{
							follow->next = newnode;
						}
					}
					else if (errorcount == 1)		//시간이 겹치는 문제가 있을 경우
					{
						i = i - 1;		//횟수 1회 차감하여 반복하도록함
					}
					
				}


				
				//파일 넣을 준비
				int starttime;
				int endtime;

				int changeday=0;

				int starthour = 0;
				int startmin = 0;
				int startsec = 0;

				int endhour = 0;
				int endmin = 0;
				int endsec = 0;

				char hourval[10];
				char minval[10];
				char secval[10];
				char dayval[10];
				
				current = timelist;
				follow = timelist;
				checker = timelist;
				testcheck = timelist;
				
				while (current != NULL)
				{

					starttime = current->ontime;
					endtime = current->offtime;

					//시작하는 시간
					starthour = starttime / 60 / 60;
					startmin = (starttime - (starthour * 60 * 60)) / 60;
					startsec = (starttime - (starthour * 60 * 60) - (startmin * 60));

					//끝나는 시간
					endhour = endtime / 60 / 60;
					endmin = (endtime - (endhour * 60 * 60)) / 60;
					endsec = (endtime - (endhour * 60 * 60) - (endmin * 60));

					sprintf(hourval, "%d", starthour);
					sprintf(minval, "%d", startmin);
					sprintf(secval, "%d", startsec);

					fputs("호수:", fp);
					fputs(apartroom, fp);

					fputs(" Room1:전등", fp);

					fputs(" 사용일:",fp);
					changeday = day;		//일단 현재 일자가 들어가도록 함
					

					sprintf(dayval, "%d", changeday);
					fputs(dayval, fp);

					fputs(" 사용시간:", fp);
					fputs(hourval, fp);
					fputs(":", fp);
					fputs(minval, fp);
					fputs(":", fp);
					fputs(secval, fp);

					fputs("~", fp);


					sprintf(hourval, "%d", endhour);
					sprintf(minval, "%d", endmin);
					sprintf(secval, "%d", endsec);

					fputs(hourval, fp);
					fputs(":", fp);
					fputs(minval, fp);
					fputs(":", fp);
					fputs(secval, fp);

					fputs("\n", fp);


					current = current->next;
				}

				

			}


		}

	//테스트 출력 리스트 안에 잘 들어갔는지위한 확인
	/*testcheck = timelist;
	while (testcheck != NULL)
	{
		printf("\n 시작시간 %d, 끝난시간 %d", testcheck->ontime, testcheck->offtime);
		testcheck = testcheck->next;
	}*/
		fclose(fp);



	return 0;
}

int	Room2LightDataCreate(char apartroom[6])
{
	TN* timelist;		//시간 담아둘 리스트 선언
	timelist = NULL;
	TN* newnode;
	TN* current = NULL, * follow = NULL, * checker = NULL, * testcheck = NULL;
	srand(time(NULL));		//랜덤함수 쓰기위한 선언

	FILE* fp;

	int errorcount = 0;

	int room1_hour = 0;
	int room1_min = 0;
	int room1_sec = 0;
	int room1_hourlong = 0;
	int room1_1temp = 0;
	int room1_2temp = 0;
	int room1_time = 0;

	int wakeup = 0;

	fp = fopen("IOTdata.txt", "a");
	for (int day = 1; day <= 30; day++)
	{
		timelist = NULL;		//값을 넣기위해서 만든 연결리스트는 계속 초기화해줍니다. 아니면 겹쳐서 계속 시간이 쌓이게 됩니다.

		wakeup = rand() % 3 + 6;		//6~8까지 랜덤 숫자
		room1_time = rand() % 11;

		if (room1_time == 0)
		{
			//room1_time이 킨 적이 하루에 한 번도 없을 때 pass 하도록 하는 것
		}

		else
		{
			for (int i = 1; i <= room1_time; i++)
			{
				errorcount = 0;		//일단 오류가 없는걸로 초기화
				current = timelist;
				follow = timelist;
				checker = timelist;
				testcheck = timelist;

				if (checker == NULL)		//처음 넣게되면 연결리스트에 아무것도 없어서 무한루프에 빠져서 추가해주기
				{
					errorcount = 0;
				}

				room1_hour = rand() % (24 - wakeup + 1) + wakeup;	//일어난 시간부터 자기전까지의 시간 중 전등 시간 배분
				room1_min = rand() % 61;	//키는 분 생성
				room1_sec = rand() % 61;	//키는 초 생성

				room1_1temp = (room1_hour * 60 * 60) + (room1_min * 60) + (room1_sec);		//킨 시간을 초로 변환

				room1_hourlong = rand() % 3 + 1;		//시간 지속시간
				room1_min = rand() % 61;	//끄는 분 생성
				room1_sec = rand() % 61;	//끄는 초 생성
				room1_hour = room1_hour + room1_hourlong;//시간 늘어난거 더해주기

				room1_2temp = (room1_hour * 60 * 60) + (room1_min * 60) + (room1_sec);		//끈 시간을 초로 변환

				//이렇게 시작과 끝은 생성을 했는데, 이런 생성한 시간이 겹치는지 검토를 하도록 해야함 그러기 위해 2번째 실행부터는 이것을 거치도록함

				if (i > 1)		//한번 반복하고나면 무조건 검토하도록 하는거
				{
					while (checker != NULL)
					{
						if (((room1_1temp < checker->ontime) && (room1_2temp < checker->ontime)) || ((room1_1temp > checker->offtime) && (room1_2temp > checker->offtime)))
						{
							checker = checker->next;
						}

						else
						{
							errorcount = 0;
							checker = checker->next;
						}
					}
				}

				if (errorcount == 0)
				{
					newnode = (TN*)malloc(sizeof(TN));
					newnode->ontime = room1_1temp;		//킨시간
					newnode->offtime = room1_2temp;		//끈시간

					while ((current != NULL) && (current->ontime < newnode->ontime))
					{
						if (room1_1temp < newnode->ontime)
						{
							break;
						}

						else
						{
							follow = current;
							current = current->next;
						}
					}
					newnode->next = current;
					if (current == timelist)		//아무것도 없을 경우 첫번째 칸에 넣기
					{
						timelist = newnode;
					}

					else
					{
						follow->next = newnode;
					}
				}
				else if (errorcount == 1)		//시간이 겹치는 문제가 있을 경우
				{
					i = i - 1;		//횟수 1회 차감하여 반복하도록함
				}

			}



			//파일 넣을 준비
			int starttime;
			int endtime;

			int changeday = 0;

			int starthour = 0;
			int startmin = 0;
			int startsec = 0;

			int endhour = 0;
			int endmin = 0;
			int endsec = 0;

			char hourval[10];
			char minval[10];
			char secval[10];
			char dayval[10];

			current = timelist;
			follow = timelist;
			checker = timelist;
			testcheck = timelist;

			while (current != NULL)
			{

				starttime = current->ontime;
				endtime = current->offtime;

				//시작하는 시간
				starthour = starttime / 60 / 60;
				startmin = (starttime - (starthour * 60 * 60)) / 60;
				startsec = (starttime - (starthour * 60 * 60) - (startmin * 60));

				//끝나는 시간
				endhour = endtime / 60 / 60;
				endmin = (endtime - (endhour * 60 * 60)) / 60;
				endsec = (endtime - (endhour * 60 * 60) - (endmin * 60));

				sprintf(hourval, "%d", starthour);
				sprintf(minval, "%d", startmin);
				sprintf(secval, "%d", startsec);

				fputs("호수:", fp);
				fputs(apartroom, fp);

				fputs(" Room2:전등", fp);

				fputs(" 사용일:", fp);
				changeday = day;		//일단 현재 일자가 들어가도록 함


				sprintf(dayval, "%d", changeday);
				fputs(dayval, fp);

				fputs(" 사용시간:", fp);
				fputs(hourval, fp);
				fputs(":", fp);
				fputs(minval, fp);
				fputs(":", fp);
				fputs(secval, fp);

				fputs("~", fp);


				sprintf(hourval, "%d", endhour);
				sprintf(minval, "%d", endmin);
				sprintf(secval, "%d", endsec);

				fputs(hourval, fp);
				fputs(":", fp);
				fputs(minval, fp);
				fputs(":", fp);
				fputs(secval, fp);

				fputs("\n", fp);


				current = current->next;
			}



		}


	}

	fclose(fp);



	return 0;
}



int	Room3LightDataCreate(char apartroom[6])
{
	TN* timelist;		//시간 담아둘 리스트 선언
	timelist = NULL;
	TN* newnode;
	TN* current = NULL, * follow = NULL, * checker = NULL, * testcheck = NULL;
	srand(time(NULL));		//랜덤함수 쓰기위한 선언

	FILE* fp;

	int errorcount = 0;

	int room1_hour = 0;
	int room1_min = 0;
	int room1_sec = 0;
	int room1_hourlong = 0;
	int room1_1temp = 0;
	int room1_2temp = 0;
	int room1_time = 0;

	int wakeup = 0;

	fp = fopen("IOTdata.txt", "a");
	for (int day = 1; day <= 30; day++)
	{
		timelist = NULL;		//값을 넣기위해서 만든 연결리스트는 계속 초기화해줍니다. 아니면 겹쳐서 계속 시간이 쌓이게 됩니다.

		wakeup = rand() % 3 + 6;		//6~8까지 랜덤 숫자
		room1_time = rand() % 11;

		if (room1_time == 0)
		{
			//room1_time이 킨 적이 하루에 한 번도 없을 때 pass 하도록 하는 것
		}

		else
		{
			for (int i = 1; i <= room1_time; i++)
			{
				errorcount = 0;		//일단 오류가 없는걸로 초기화
				current = timelist;
				follow = timelist;
				checker = timelist;
				testcheck = timelist;

				if (checker == NULL)		//처음 넣게되면 연결리스트에 아무것도 없어서 무한루프에 빠져서 추가해주기
				{
					errorcount = 0;
				}

				room1_hour = rand() % (24 - wakeup + 1) + wakeup;	//일어난 시간부터 자기전까지의 시간 중 전등 시간 배분
				room1_min = rand() % 61;	//키는 분 생성
				room1_sec = rand() % 61;	//키는 초 생성

				room1_1temp = (room1_hour * 60 * 60) + (room1_min * 60) + (room1_sec);		//킨 시간을 초로 변환

				room1_hourlong = rand() % 3 + 1;		//시간 지속시간
				room1_min = rand() % 61;	//끄는 분 생성
				room1_sec = rand() % 61;	//끄는 초 생성
				room1_hour = room1_hour + room1_hourlong;//시간 늘어난거 더해주기

				room1_2temp = (room1_hour * 60 * 60) + (room1_min * 60) + (room1_sec);		//끈 시간을 초로 변환

				//이렇게 시작과 끝은 생성을 했는데, 이런 생성한 시간이 겹치는지 검토를 하도록 해야함 그러기 위해 2번째 실행부터는 이것을 거치도록함

				if (i > 1)		//한번 반복하고나면 무조건 검토하도록 하는거
				{
					while (checker != NULL)
					{
						if (((room1_1temp < checker->ontime) && (room1_2temp < checker->ontime)) || ((room1_1temp > checker->offtime) && (room1_2temp > checker->offtime)))
						{
							checker = checker->next;
						}

						else
						{
							errorcount = 0;
							checker = checker->next;
						}
					}
				}

				if (errorcount == 0)
				{
					newnode = (TN*)malloc(sizeof(TN));
					newnode->ontime = room1_1temp;		//킨시간
					newnode->offtime = room1_2temp;		//끈시간

					while ((current != NULL) && (current->ontime < newnode->ontime))
					{
						if (room1_1temp < newnode->ontime)
						{
							break;
						}

						else
						{
							follow = current;
							current = current->next;
						}
					}
					newnode->next = current;
					if (current == timelist)		//아무것도 없을 경우 첫번째 칸에 넣기
					{
						timelist = newnode;
					}

					else
					{
						follow->next = newnode;
					}
				}
				else if (errorcount == 1)		//시간이 겹치는 문제가 있을 경우
				{
					i = i - 1;		//횟수 1회 차감하여 반복하도록함
				}

			}



			//파일 넣을 준비
			int starttime;
			int endtime;

			int changeday = 0;

			int starthour = 0;
			int startmin = 0;
			int startsec = 0;

			int endhour = 0;
			int endmin = 0;
			int endsec = 0;

			char hourval[10];
			char minval[10];
			char secval[10];
			char dayval[10];

			current = timelist;
			follow = timelist;
			checker = timelist;
			testcheck = timelist;

			while (current != NULL)
			{

				starttime = current->ontime;
				endtime = current->offtime;

				//시작하는 시간
				starthour = starttime / 60 / 60;
				startmin = (starttime - (starthour * 60 * 60)) / 60;
				startsec = (starttime - (starthour * 60 * 60) - (startmin * 60));

				//끝나는 시간
				endhour = endtime / 60 / 60;
				endmin = (endtime - (endhour * 60 * 60)) / 60;
				endsec = (endtime - (endhour * 60 * 60) - (endmin * 60));

				sprintf(hourval, "%d", starthour);
				sprintf(minval, "%d", startmin);
				sprintf(secval, "%d", startsec);

				fputs("호수:", fp);
				fputs(apartroom, fp);

				fputs(" Room3:전등", fp);

				fputs(" 사용일:", fp);
				changeday = day;		//일단 현재 일자가 들어가도록 함


				sprintf(dayval, "%d", changeday);
				fputs(dayval, fp);

				fputs(" 사용시간:", fp);
				fputs(hourval, fp);
				fputs(":", fp);
				fputs(minval, fp);
				fputs(":", fp);
				fputs(secval, fp);

				fputs("~", fp);


				sprintf(hourval, "%d", endhour);
				sprintf(minval, "%d", endmin);
				sprintf(secval, "%d", endsec);

				fputs(hourval, fp);
				fputs(":", fp);
				fputs(minval, fp);
				fputs(":", fp);
				fputs(secval, fp);

				fputs("\n", fp);


				current = current->next;
			}



		}


	}

	fclose(fp);

	return 0;
}



int	KitchenLightDataCreate(char apartroom[6])
{
	TN* timelist;		//시간 담아둘 리스트 선언
	timelist = NULL;
	TN* newnode;
	TN* current = NULL, * follow = NULL, * checker = NULL, * testcheck = NULL;
	srand(time(NULL));		//랜덤함수 쓰기위한 선언

	FILE* fp;

	int errorcount = 0;

	int room1_hour = 0;
	int room1_min = 0;
	int room1_sec = 0;
	int room1_hourlong = 0;
	int room1_1temp = 0;
	int room1_2temp = 0;
	int room1_time = 0;

	int wakeup = 0;

	fp = fopen("IOTdata.txt", "a");
	for (int day = 1; day <= 30; day++)
	{
		timelist = NULL;		//값을 넣기위해서 만든 연결리스트는 계속 초기화해줍니다. 아니면 겹쳐서 계속 시간이 쌓이게 됩니다.

		wakeup = rand() % 3 + 6;		//6~8까지 랜덤 숫자
		room1_time = rand() % 11;

		if (room1_time == 0)
		{
			//room1_time이 킨 적이 하루에 한 번도 없을 때 pass 하도록 하는 것
		}

		else
		{
			for (int i = 1; i <= room1_time; i++)
			{
				errorcount = 0;		//일단 오류가 없는걸로 초기화
				current = timelist;
				follow = timelist;
				checker = timelist;
				testcheck = timelist;

				if (checker == NULL)		//처음 넣게되면 연결리스트에 아무것도 없어서 무한루프에 빠져서 추가해주기
				{
					errorcount = 0;
				}

				room1_hour = rand() % (24 - wakeup + 1) + wakeup;	//일어난 시간부터 자기전까지의 시간 중 전등 시간 배분
				room1_min = rand() % 61;	//키는 분 생성
				room1_sec = rand() % 61;	//키는 초 생성

				room1_1temp = (room1_hour * 60 * 60) + (room1_min * 60) + (room1_sec);		//킨 시간을 초로 변환

				room1_hourlong = rand() % 3 + 1;		//시간 지속시간
				room1_min = rand() % 61;	//끄는 분 생성
				room1_sec = rand() % 61;	//끄는 초 생성
				room1_hour = room1_hour + room1_hourlong;//시간 늘어난거 더해주기

				room1_2temp = (room1_hour * 60 * 60) + (room1_min * 60) + (room1_sec);		//끈 시간을 초로 변환

				//이렇게 시작과 끝은 생성을 했는데, 이런 생성한 시간이 겹치는지 검토를 하도록 해야함 그러기 위해 2번째 실행부터는 이것을 거치도록함

				if (i > 1)		//한번 반복하고나면 무조건 검토하도록 하는거
				{
					while (checker != NULL)
					{
						if (((room1_1temp < checker->ontime) && (room1_2temp < checker->ontime)) || ((room1_1temp > checker->offtime) && (room1_2temp > checker->offtime)))
						{
							checker = checker->next;
						}

						else
						{
							errorcount = 0;
							checker = checker->next;
						}
					}
				}

				if (errorcount == 0)
				{
					newnode = (TN*)malloc(sizeof(TN));
					newnode->ontime = room1_1temp;		//킨시간
					newnode->offtime = room1_2temp;		//끈시간

					while ((current != NULL) && (current->ontime < newnode->ontime))
					{
						if (room1_1temp < newnode->ontime)
						{
							break;
						}

						else
						{
							follow = current;
							current = current->next;
						}
					}
					newnode->next = current;
					if (current == timelist)		//아무것도 없을 경우 첫번째 칸에 넣기
					{
						timelist = newnode;
					}

					else
					{
						follow->next = newnode;
					}
				}
				else if (errorcount == 1)		//시간이 겹치는 문제가 있을 경우
				{
					i = i - 1;		//횟수 1회 차감하여 반복하도록함
				}

			}



			//파일 넣을 준비
			int starttime;
			int endtime;

			int changeday = 0;

			int starthour = 0;
			int startmin = 0;
			int startsec = 0;

			int endhour = 0;
			int endmin = 0;
			int endsec = 0;

			char hourval[10];
			char minval[10];
			char secval[10];
			char dayval[10];

			current = timelist;
			follow = timelist;
			checker = timelist;
			testcheck = timelist;

			while (current != NULL)
			{

				starttime = current->ontime;
				endtime = current->offtime;

				//시작하는 시간
				starthour = starttime / 60 / 60;
				startmin = (starttime - (starthour * 60 * 60)) / 60;
				startsec = (starttime - (starthour * 60 * 60) - (startmin * 60));

				//끝나는 시간
				endhour = endtime / 60 / 60;
				endmin = (endtime - (endhour * 60 * 60)) / 60;
				endsec = (endtime - (endhour * 60 * 60) - (endmin * 60));

				sprintf(hourval, "%d", starthour);
				sprintf(minval, "%d", startmin);
				sprintf(secval, "%d", startsec);

				fputs("호수:", fp);
				fputs(apartroom, fp);

				fputs(" Kitchen:전등", fp);

				fputs(" 사용일:", fp);
				changeday = day;		//일단 현재 일자가 들어가도록 함


				sprintf(dayval, "%d", changeday);
				fputs(dayval, fp);

				fputs(" 사용시간:", fp);
				fputs(hourval, fp);
				fputs(":", fp);
				fputs(minval, fp);
				fputs(":", fp);
				fputs(secval, fp);

				fputs("~", fp);


				sprintf(hourval, "%d", endhour);
				sprintf(minval, "%d", endmin);
				sprintf(secval, "%d", endsec);

				fputs(hourval, fp);
				fputs(":", fp);
				fputs(minval, fp);
				fputs(":", fp);
				fputs(secval, fp);

				fputs("\n", fp);


				current = current->next;
			}



		}


	}

	fclose(fp);



	return 0;
}

int	LivingloomLightDataCreate(char apartroom[6])
{
	TN* timelist;		//시간 담아둘 리스트 선언
	timelist = NULL;
	TN* newnode;
	TN* current = NULL, * follow = NULL, * checker = NULL, * testcheck = NULL;
	srand(time(NULL));		//랜덤함수 쓰기위한 선언

	FILE* fp;

	int errorcount = 0;

	int room1_hour = 0;
	int room1_min = 0;
	int room1_sec = 0;
	int room1_hourlong = 0;
	int room1_1temp = 0;
	int room1_2temp = 0;
	int room1_time = 0;

	int wakeup = 0;

	fp = fopen("IOTdata.txt", "a");
	for (int day = 1; day <= 30; day++)
	{
		timelist = NULL;		//값을 넣기위해서 만든 연결리스트는 계속 초기화해줍니다. 아니면 겹쳐서 계속 시간이 쌓이게 됩니다.

		wakeup = rand() % 3 + 6;		//6~8까지 랜덤 숫자
		room1_time = rand() % 11;

		if (room1_time == 0)
		{
			//room1_time이 킨 적이 하루에 한 번도 없을 때 pass 하도록 하는 것
		}

		else
		{
			for (int i = 1; i <= room1_time; i++)
			{
				errorcount = 0;		//일단 오류가 없는걸로 초기화
				current = timelist;
				follow = timelist;
				checker = timelist;
				testcheck = timelist;

				if (checker == NULL)		//처음 넣게되면 연결리스트에 아무것도 없어서 무한루프에 빠져서 추가해주기
				{
					errorcount = 0;
				}

				room1_hour = rand() % (24 - wakeup + 1) + wakeup;	//일어난 시간부터 자기전까지의 시간 중 전등 시간 배분
				room1_min = rand() % 61;	//키는 분 생성
				room1_sec = rand() % 61;	//키는 초 생성

				room1_1temp = (room1_hour * 60 * 60) + (room1_min * 60) + (room1_sec);		//킨 시간을 초로 변환

				room1_hourlong = rand() % 3 + 1;		//시간 지속시간
				room1_min = rand() % 61;	//끄는 분 생성
				room1_sec = rand() % 61;	//끄는 초 생성
				room1_hour = room1_hour + room1_hourlong;//시간 늘어난거 더해주기

				room1_2temp = (room1_hour * 60 * 60) + (room1_min * 60) + (room1_sec);		//끈 시간을 초로 변환

				//이렇게 시작과 끝은 생성을 했는데, 이런 생성한 시간이 겹치는지 검토를 하도록 해야함 그러기 위해 2번째 실행부터는 이것을 거치도록함

				if (i > 1)		//한번 반복하고나면 무조건 검토하도록 하는거
				{
					while (checker != NULL)
					{
						if (((room1_1temp < checker->ontime) && (room1_2temp < checker->ontime)) || ((room1_1temp > checker->offtime) && (room1_2temp > checker->offtime)))
						{
							checker = checker->next;
						}

						else
						{
							errorcount = 0;
							checker = checker->next;
						}
					}
				}

				if (errorcount == 0)
				{
					newnode = (TN*)malloc(sizeof(TN));
					newnode->ontime = room1_1temp;		//킨시간
					newnode->offtime = room1_2temp;		//끈시간

					while ((current != NULL) && (current->ontime < newnode->ontime))
					{
						if (room1_1temp < newnode->ontime)
						{
							break;
						}

						else
						{
							follow = current;
							current = current->next;
						}
					}
					newnode->next = current;
					if (current == timelist)		//아무것도 없을 경우 첫번째 칸에 넣기
					{
						timelist = newnode;
					}

					else
					{
						follow->next = newnode;
					}
				}
				else if (errorcount == 1)		//시간이 겹치는 문제가 있을 경우
				{
					i = i - 1;		//횟수 1회 차감하여 반복하도록함
				}

			}



			//파일 넣을 준비
			int starttime;
			int endtime;

			int changeday = 0;

			int starthour = 0;
			int startmin = 0;
			int startsec = 0;

			int endhour = 0;
			int endmin = 0;
			int endsec = 0;

			char hourval[10];
			char minval[10];
			char secval[10];
			char dayval[10];

			current = timelist;
			follow = timelist;
			checker = timelist;
			testcheck = timelist;

			while (current != NULL)
			{

				starttime = current->ontime;
				endtime = current->offtime;

				//시작하는 시간
				starthour = starttime / 60 / 60;
				startmin = (starttime - (starthour * 60 * 60)) / 60;
				startsec = (starttime - (starthour * 60 * 60) - (startmin * 60));

				//끝나는 시간
				endhour = endtime / 60 / 60;
				endmin = (endtime - (endhour * 60 * 60)) / 60;
				endsec = (endtime - (endhour * 60 * 60) - (endmin * 60));

				sprintf(hourval, "%d", starthour);
				sprintf(minval, "%d", startmin);
				sprintf(secval, "%d", startsec);

				fputs("호수:", fp);
				fputs(apartroom, fp);

				fputs(" Livingroom:전등", fp);

				fputs(" 사용일:", fp);
				changeday = day;		//일단 현재 일자가 들어가도록 함


				sprintf(dayval, "%d", changeday);
				fputs(dayval, fp);

				fputs(" 사용시간:", fp);
				fputs(hourval, fp);
				fputs(":", fp);
				fputs(minval, fp);
				fputs(":", fp);
				fputs(secval, fp);

				fputs("~", fp);


				sprintf(hourval, "%d", endhour);
				sprintf(minval, "%d", endmin);
				sprintf(secval, "%d", endsec);

				fputs(hourval, fp);
				fputs(":", fp);
				fputs(minval, fp);
				fputs(":", fp);
				fputs(secval, fp);

				fputs("\n", fp);


				current = current->next;
			}



		}


	}

	fclose(fp);



	return 0;
}

//인덕션 데이터 생성		//인덕션 데이터 생성		//인덕션 데이터 생성		//인덕션 데이터 생성		//인덕션 데이터 생성		//인덕션 데이터 생성		
int InductionDataCreate(char apartroom[6])
{
	TN* timelist;		//시간 담아둘 리스트 선언
	timelist = NULL;
	TN* newnode;
	TN* current = NULL, * follow = NULL, * checker = NULL, * testcheck = NULL;
	srand(time(NULL));		//랜덤함수 쓰기위한 선언

	FILE* fp;

	int errorcount = 0;

	int room1_hour = 0;
	int room1_min = 0;
	int room1_sec = 0;

	int kit_endhour = 0;
	int kit_endmin = 0;
	int kit_endsec = 0;

	int mintemp = 0;
	int sectemp = 0;

	int room1_hourlong = 0;
	int room1_1temp = 0;
	int room1_2temp = 0;
	int induction_time = 0;



	int wakeup = 0;

	fp = fopen("IOTdata.txt", "a");
	for (int day = 1; day <= 30; day++)
	{
		timelist = NULL;		//값을 넣기위해서 만든 연결리스트는 계속 초기화해줍니다. 아니면 겹쳐서 계속 시간이 쌓이게 됩니다.

		wakeup = rand() % 3 + 6;		//6~8까지 랜덤 숫자
		induction_time = rand() % 5;		//인덕션 하루에 몇 번 켰는지 정하는 거

		if (induction_time == 0)
		{
			//room1_time이 킨 적이 하루에 한 번도 없을 때 pass 하도록 하는 것
		}

		else
		{
			for (int i = 1; i <= induction_time; i++)
			{
				errorcount = 0;		//일단 오류가 없는걸로 초기화
				current = timelist;
				follow = timelist;
				checker = timelist;
				testcheck = timelist;

				if (checker == NULL)		//처음 넣게되면 연결리스트에 아무것도 없어서 무한루프에 빠져서 추가해주기
				{
					errorcount = 0;
				}

				room1_hour = rand() % (24 - wakeup + 1) + wakeup;	//일어난 시간부터 자기전까지의 시간 중 전등 시간 배분
				room1_min = rand() % 61;	//키는 분 생성
				room1_sec = rand() % 61;	//키는 초 생성

				room1_1temp = (room1_hour * 60 * 60) + (room1_min * 60) + (room1_sec);		//킨 시간을 초로 변환

				room1_hourlong = 0;		//시간 지속시간 0시간으로 고정
				kit_endmin = rand() % 61;	//끄는 분 생성
				kit_endsec = rand() % 61;	//끄는 초 생성

				room1_hour = room1_hour + room1_hourlong;//시간 늘어난거 더해주기

				//인덕션을 위해 만들어준 추가 코드(00이 되기 위해 만든 코드부분)
				sectemp = room1_sec + kit_endsec;
				if (60 <= sectemp)
				{
					room1_min = room1_min + 1;
					sectemp = sectemp - 60;
				}

				mintemp = room1_min + kit_endmin;
				if (60 <= mintemp)
				{
					room1_hour = room1_hour + 1;
					mintemp = mintemp - 60;
				}



				room1_2temp = (room1_hour * 60 * 60) + (mintemp * 60) + (sectemp);		//끈 시간을 초로 변환

				//이렇게 시작과 끝은 생성을 했는데, 이런 생성한 시간이 겹치는지 검토를 하도록 해야함 그러기 위해 2번째 실행부터는 이것을 거치도록함

				if (i > 1)		//한번 반복하고나면 무조건 검토하도록 하는거
				{
					while (checker != NULL)
					{
						if (((room1_1temp < checker->ontime) && (room1_2temp < checker->ontime)) || ((room1_1temp > checker->offtime) && (room1_2temp > checker->offtime)))
						{
							checker = checker->next;
						}

						else
						{
							errorcount = 0;
							checker = checker->next;
						}
					}
				}

				if (errorcount == 0)
				{
					newnode = (TN*)malloc(sizeof(TN));
					newnode->ontime = room1_1temp;		//킨시간
					newnode->offtime = room1_2temp;		//끈시간

					while ((current != NULL) && (current->ontime < newnode->ontime))
					{
						if (room1_1temp < newnode->ontime)
						{
							break;
						}

						else
						{
							follow = current;
							current = current->next;
						}
					}
					newnode->next = current;
					if (current == timelist)		//아무것도 없을 경우 첫번째 칸에 넣기
					{
						timelist = newnode;
					}

					else
					{
						follow->next = newnode;
					}
				}
				else if (errorcount == 1)		//시간이 겹치는 문제가 있을 경우
				{
					i = i - 1;		//횟수 1회 차감하여 반복하도록함
				}

			}



			//파일 넣을 준비
			int starttime;
			int endtime;

			int changeday = 0;

			int starthour = 0;
			int startmin = 0;
			int startsec = 0;

			int endhour = 0;
			int endmin = 0;
			int endsec = 0;

			char hourval[10];
			char minval[10];
			char secval[10];
			char dayval[10];

			current = timelist;
			follow = timelist;
			checker = timelist;
			testcheck = timelist;

			while (current != NULL)
			{

				starttime = current->ontime;
				endtime = current->offtime;

				//시작하는 시간
				starthour = starttime / 60 / 60;
				startmin = (starttime - (starthour * 60 * 60)) / 60;
				startsec = (starttime - (starthour * 60 * 60) - (startmin * 60));

				//끝나는 시간
				endhour = endtime / 60 / 60;
				endmin = (endtime - (endhour * 60 * 60)) / 60;
				endsec = (endtime - (endhour * 60 * 60) - (endmin * 60));

				sprintf(hourval, "%d", starthour);
				sprintf(minval, "%d", startmin);
				sprintf(secval, "%d", startsec);

				fputs("호수:", fp);
				fputs(apartroom, fp);

				fputs(" Kitchen:인덕션", fp);

				fputs(" 사용일:", fp);
				changeday = day;		//일단 현재 일자가 들어가도록 함


				sprintf(dayval, "%d", changeday);
				fputs(dayval, fp);

				fputs(" 사용시간:", fp);
				fputs(hourval, fp);
				fputs(":", fp);
				fputs(minval, fp);
				fputs(":", fp);
				fputs(secval, fp);

				fputs("~", fp);


				sprintf(hourval, "%d", endhour);
				sprintf(minval, "%d", endmin);
				sprintf(secval, "%d", endsec);

				fputs(hourval, fp);
				fputs(":", fp);
				fputs(minval, fp);
				fputs(":", fp);
				fputs(secval, fp);

				fputs("\n", fp);


				current = current->next;
			}



		}


	}

	fclose(fp);



	return 0;
}




//세탁기 데이터 생성		//세탁기 데이터 생성		//세탁기 데이터 생성		//세탁기 데이터 생성		//세탁기 데이터 생성		//세탁기 데이터 생성		
int WahserDataCreate(char apartroom[6])
{
	TN* timelist;		//시간 담아둘 리스트 선언
	timelist = NULL;
	TN* newnode;
	TN* current = NULL, * follow = NULL, * checker = NULL, * testcheck = NULL;
	srand(time(NULL));		//랜덤함수 쓰기위한 선언

	FILE* fp;

	int errorcount = 0;

	int room1_hour = 0;
	int room1_min = 0;
	int room1_sec = 0;

	int kit_endhour = 0;
	int kit_endmin = 0;
	int kit_endsec = 0;

	int mintemp = 0;
	int sectemp = 0;

	int room1_hourlong = 0;
	int room1_1temp = 0;
	int room1_2temp = 0;
	int wahser_time = 0;



	int wakeup = 0;

	fp = fopen("IOTdata.txt", "a");
	for (int day = 1; day <= 30; day++)
	{
		timelist = NULL;		//값을 넣기위해서 만든 연결리스트는 계속 초기화해줍니다. 아니면 겹쳐서 계속 시간이 쌓이게 됩니다.

		wakeup = rand() % 3 + 6;		//6~8까지 랜덤 숫자
		wahser_time = rand() % 5;		//세탁기 하루에 몇 번 켰는지 정하는 거

		if (wahser_time == 0)
		{
			//room1_time이 킨 적이 하루에 한 번도 없을 때 pass 하도록 하는 것
		}

		else
		{
			for (int i = 1; i <= wahser_time; i++)
			{
				errorcount = 0;		//일단 오류가 없는걸로 초기화
				current = timelist;
				follow = timelist;
				checker = timelist;
				testcheck = timelist;

				if (checker == NULL)		//처음 넣게되면 연결리스트에 아무것도 없어서 무한루프에 빠져서 추가해주기
				{
					errorcount = 0;
				}

				room1_hour = rand() % (24 - wakeup + 1) + wakeup;	//일어난 시간부터 자기전까지의 시간 중 전등 시간 배분
				room1_min = rand() % 61;	//키는 분 생성
				room1_sec = rand() % 61;	//키는 초 생성

				room1_1temp = (room1_hour * 60 * 60) + (room1_min * 60) + (room1_sec);		//킨 시간을 초로 변환

				room1_hourlong = 0;		//시간 지속시간 0시간으로 고정
				kit_endmin = rand() % 61;	//끄는 분 생성
				kit_endsec = rand() % 61;	//끄는 초 생성

				room1_hour = room1_hour + room1_hourlong;//시간 늘어난거 더해주기

				//인덕션을 위해 만들어준 추가 코드(00이 되기 위해 만든 코드부분)
				sectemp = room1_sec + kit_endsec;
				if (60 <= sectemp)
				{
					room1_min = room1_min + 1;
					sectemp = sectemp - 60;
				}

				mintemp = room1_min + kit_endmin;
				if (60 <= mintemp)
				{
					room1_hour = room1_hour + 1;
					mintemp = mintemp - 60;
				}



				room1_2temp = (room1_hour * 60 * 60) + (mintemp * 60) + (sectemp);		//끈 시간을 초로 변환

				//이렇게 시작과 끝은 생성을 했는데, 이런 생성한 시간이 겹치는지 검토를 하도록 해야함 그러기 위해 2번째 실행부터는 이것을 거치도록함

				if (i > 1)		//한번 반복하고나면 무조건 검토하도록 하는거
				{
					while (checker != NULL)
					{
						if (((room1_1temp < checker->ontime) && (room1_2temp < checker->ontime)) || ((room1_1temp > checker->offtime) && (room1_2temp > checker->offtime)))
						{
							checker = checker->next;
						}

						else
						{
							errorcount = 0;
							checker = checker->next;
						}
					}
				}

				if (errorcount == 0)
				{
					newnode = (TN*)malloc(sizeof(TN));
					newnode->ontime = room1_1temp;		//킨시간
					newnode->offtime = room1_2temp;		//끈시간

					while ((current != NULL) && (current->ontime < newnode->ontime))
					{
						if (room1_1temp < newnode->ontime)
						{
							break;
						}

						else
						{
							follow = current;
							current = current->next;
						}
					}
					newnode->next = current;
					if (current == timelist)		//아무것도 없을 경우 첫번째 칸에 넣기
					{
						timelist = newnode;
					}

					else
					{
						follow->next = newnode;
					}
				}
				else if (errorcount == 1)		//시간이 겹치는 문제가 있을 경우
				{
					i = i - 1;		//횟수 1회 차감하여 반복하도록함
				}

			}



			//파일 넣을 준비
			int starttime;
			int endtime;

			int changeday = 0;

			int starthour = 0;
			int startmin = 0;
			int startsec = 0;

			int endhour = 0;
			int endmin = 0;
			int endsec = 0;

			char hourval[10];
			char minval[10];
			char secval[10];
			char dayval[10];

			current = timelist;
			follow = timelist;
			checker = timelist;
			testcheck = timelist;

			while (current != NULL)
			{

				starttime = current->ontime;
				endtime = current->offtime;

				//시작하는 시간
				starthour = starttime / 60 / 60;
				startmin = (starttime - (starthour * 60 * 60)) / 60;
				startsec = (starttime - (starthour * 60 * 60) - (startmin * 60));

				//끝나는 시간
				endhour = endtime / 60 / 60;
				endmin = (endtime - (endhour * 60 * 60)) / 60;
				endsec = (endtime - (endhour * 60 * 60) - (endmin * 60));

				sprintf(hourval, "%d", starthour);
				sprintf(minval, "%d", startmin);
				sprintf(secval, "%d", startsec);

				fputs("호수:", fp);
				fputs(apartroom, fp);

				fputs(" Kitchen:세탁기", fp);

				fputs(" 사용일:", fp);
				changeday = day;		//일단 현재 일자가 들어가도록 함


				sprintf(dayval, "%d", changeday);
				fputs(dayval, fp);

				fputs(" 사용시간:", fp);
				fputs(hourval, fp);
				fputs(":", fp);
				fputs(minval, fp);
				fputs(":", fp);
				fputs(secval, fp);

				fputs("~", fp);


				sprintf(hourval, "%d", endhour);
				sprintf(minval, "%d", endmin);
				sprintf(secval, "%d", endsec);

				fputs(hourval, fp);
				fputs(":", fp);
				fputs(minval, fp);
				fputs(":", fp);
				fputs(secval, fp);

				fputs("\n", fp);


				current = current->next;
			}



		}


	}

	fclose(fp);



	return 0;
}