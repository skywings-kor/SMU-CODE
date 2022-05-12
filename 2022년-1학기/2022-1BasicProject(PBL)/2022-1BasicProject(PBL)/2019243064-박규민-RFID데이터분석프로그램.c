#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

typedef struct taginfo
{
	char id[27];
	float rssi;
	double identifiedTime;
	struct taginfo* next;
} TAGINFO;

TAGINFO* referenceRead(TAGINFO*tagreadlist, char referenceid[27]);		//참조값의 데이터들을 파일에서 가져와 분석하는 함수
TAGINFO* referenceInlist(TAGINFO* taglist, char inid[27], double intime, float inrssi);		//referenceRead에서 분석을 마친 데이터들이 reference의 연결리스트에 저장되도록 하는 함수

TAGINFO* targetRead(TAGINFO* tagreadlist, char targetid[27]);		//타겟의 데이터를 파일에서 가져와 분석하는 함수
TAGINFO* targetInlist(TAGINFO* taglist, char inid[27], double intime, float inrssi);		//targetRead에서 분석을 마친 데이터가 target의 연결리스트에 저장되도록 하는 함수

TAGINFO* estimationRead(TAGINFO* estimationlist, TAGINFO* referencelist, float targetrssi);		//타겟 ID와 RSSI가 같은 참조데이터 순으로 estimation의 연결리스트에 저장되도록 하는 함수


void estimationCal(int inxres,int inyres, char finalid[27],int rescount);		//타겟의 최종 예측 좌표를 계산하고 출력하는 함수

TAGINFO* estimationview(TAGINFO* estimationlist);		//예측하기 위해 해당하는 데이터들을 저장한 연결리스트에 저장한 값들을 한 번 출력해주는 함수
TAGINFO* listInview(TAGINFO* walker);		//1번, 2번 기능에서 진행한 것을 출력하기 위한 연결리스트 출력 함수

int main()
{
	TAGINFO* referencelist = NULL,*targetlist=NULL,*estimationlist=NULL,*mainwalker=NULL;
	int interchoice;		//사용자가 사용자 메뉴 선택할 때 들어갈 변수
	
	char targetID[27] = "0x35E0170044CF0D590000F5A5";		//타겟 ID

	//참조 ID
	char referenceIDs[60][27] =
	{
		"0x35E0170044CF0D590000F544","0x35E0170044CF0D590000F543","0x35E0170044CF0D590000F542","0x35E0170044CF0D590000F551","0x35E0170044CF0D590000F550","0x35E0170044CF0D590000F54F",
		"0x35E0170044CF0D590000F61D","0x35E0170044CF0D590000F61C","0x35E0170044CF0D590000F61B","0x35E0170044CF0D590000F61A","0x35E0170044CF0D590000F629","0x35E0170044CF0D590000F628",
		"0x35E0170044CF0D590000F54E","0x35E0170044CF0D590000F55D","0x35E0170044CF0D590000F55C","0x35E0170044CF0D590000F55B","0x35E0170044CF0D590000F55A","0x35E0170044CF0D590000F569",
		"0x35E0170044CF0D590000F627","0x35E0170044CF0D590000F626","0x35E0170044CF0D590000F635","0x35E0170044CF0D590000F634","0x35E0170044CF0D590000F633","0x35E0170044CF0D590000F632",
		"0x35E0170044CF0D590000F568","0x35E0170044CF0D590000F567","0x35E0170044CF0D590000F566","0x35E0170044CF0D590000F575","0x35E0170044CF0D590000F574","0x35E0170044CF0D590000F573",
		"0x35E0170044CF0D590000F641","0x35E0170044CF0D590000F640","0x35E0170044CF0D590000F63F","0x35E0170044CF0D590000F63E","0x35E0170044CF0D590000F64D","0x35E0170044CF0D590000F64C",
		"0x35E0170044CF0D590000F572","0x35E0170044CF0D590000F581","0x35E0170044CF0D590000F580","0x35E0170044CF0D590000F57F","0x35E0170044CF0D590000F57E","0x35E0170044CF0D590000F58D",
		"0x35E0170044CF0D590000F64B","0x35E0170044CF0D590000F64A","0x35E0170044CF0D590000F659","0x35E0170044CF0D590000F658","0x35E0170044CF0D590000F657","0x35E0170044CF0D590000F656",
		"0x35E0170044CF0D590000F58C","0x35E0170044CF0D590000F58B","0x35E0170044CF0D590000F58A","0x35E0170044CF0D590000F599","0x35E0170044CF0D590000F598","0x35E0170044CF0D590000F597",
		"0x35E0170044CF0D590000F603","0x35E0170044CF0D590000F5F8","0x35E0170044CF0D590000F5F7","0x35E0170044CF0D590000F5F6","0x35E0170044CF0D590000F605","0x35E0170044CF0D590000F604"
	};
	
	//참조 좌표값
	int referecePoints[60][2] =
	{
		{ 7, 1 },{ 22, 1 },{ 37, 1 },{ 52, 1 },{ 67, 1 },{ 81, 1 },
		{ 101, 1 },{ 116, 1 },{ 131, 1 },{ 146, 1 },{ 161, 1 },{ 176, 1 },
		{ 7, 41 },{ 22, 41 },{ 37, 41 },{ 52, 41 },{ 67, 41 },{ 81, 41 },
		{ 101, 41 },{ 116, 41 },{ 131, 41 },{ 146, 41 },{ 161, 41 },{ 176, 41 },
		{ 7, 80 },{ 22, 80 },{ 37, 80 },{ 52, 80 },{ 67, 80 },{ 81, 80 },
		{ 101, 80 },{ 116, 80 },{ 131, 80 },{ 146, 80 },{ 161, 80 },{ 176, 80 },
		{ 7, 115 },{ 22, 115 },{ 37, 115 },{ 52, 115 },{ 67, 115 },{ 81, 115 },
		{ 101, 115 },{ 116, 115 },{ 131, 115 },{ 146, 115 },{ 161, 115 },{ 176, 115 },
		{ 7, 144 },{ 22, 144 },{ 37, 144 },{ 52, 144 },{ 67, 144 },{ 81, 144 },
		{ 101, 144 },{ 116, 144 },{ 131, 144 },{ 146, 144 },{ 161, 144 },{ 176, 144 }
	};


	//메인 인터페이스 시작
	for (int i = 0;; i++)
	{
		system("cls");		//화면 싹 깨끗해지게 해주는 기능

		printf("					Made by-2019243064 박규민\n\n\n\n");
		printf("				<실행하고 싶은 시스템 번호를 입력해주시면 됩니다>\n\n");
		printf("					1. Reference Tag Analysis\n\n");
		printf("					2. Target Tag Analysis\n\n");
		printf("					3. Estimation Tag Analysis\n\n");
		printf("					4. Target ID 변경하기\n\n");
		printf("					0. Quit\n\n");

		scanf("%d", &interchoice);



		if (interchoice == 1)		//참조 태그 분석 함수실행
		{
			printf("					<참조 태그 데이터가 존재하지 않는 ID목록>\n");
			referencelist = NULL, targetlist = NULL, estimationlist = NULL;		//연결리스트가 기존에 하던것과 같이 계속 쌓이면 안되니까 한 번 싹 비워줍니다.

			for (int j = 0; j < 60; j++)		//참조 데이터들이 60칸으로 정해져있으니 배열0번째부터 59번째까지 확인하도록 합니다.
			{
				referencelist = referenceRead(referencelist, referenceIDs[j]);		//j가 0일경우 참조 ID 들어있는 0번째 배열을 가져와 referenceRead 함수에 보냅니다.(연결리스트 또한 저장을 위해 보내줍니다)

			}

			printf("\n");
			printf("					<참조 태그 데이터 분석 목록>\n");
			listInview(referencelist);		//연결리스트에 넣은 참조 데이터들을 보기 위한 함수

		}

		else if (interchoice == 2)		//타겟 태그 분석 함수실행
		{
			printf("					<타겟 태그 데이터가 존재하지 않는 ID목록>\n");
			referencelist = NULL, targetlist = NULL, estimationlist = NULL;		//연결리스트가 기존에 하던것과 같이 계속 쌓이면 안되니까 한 번 싹 비워줍니다.

			targetlist = targetRead(targetlist, targetID);		//타겟 ID는 1개로 정해져있으므로 1번만 실행시켜줍니다.

			printf("\n");
			printf("					<타겟 태그 데이터 분석 목록>\n");
			listInview(targetlist);		//연결리스트에 넣은 타겟 데이터를 보기 위한 함수


		}


		else if (interchoice == 3)		//타겟 태그의 예측 좌표
		{
			int xres = 0;		//x좌표 총합 변수
			int yres = 0;		//y좌표 총합 변수

			int esticount = 0;		//참조 ID 배열의 몇번째인지 저장하고 이 횟수를 바탕으로 참조 좌표값을 가져오기 위한 변수
			int knnuser = 0;		//knn알고리즘을 하기 위해 사용자가 참조 범위를 지정하도록 하기 위한 변수

			referencelist = NULL, targetlist = NULL, estimationlist = NULL;		//기존 데이터에 쌓이면 안되니 한 번 싹 비워줍니다.

			printf("					<참조 태그 데이터가 존재하지 않는 ID목록>\n");

			//참조 태그 분석 함수 실행
			for (int j = 0; j < 60; j++)
			{
				referencelist = referenceRead(referencelist, referenceIDs[j]);		//1번 기능과 동일
			}
			
			printf("\n\n");

			//타겟 태그 분석 함수 실행
			targetlist = targetRead(targetlist, targetID);		//2번 기능과 동일

			printf("					<RSSI근접도 분석 목록>\n");

			estimationlist = estimationRead(estimationlist, referencelist, targetlist->rssi);		//
			estimationview(estimationlist);

			printf("참조할 데이터 개수를 입력해주세요: ");
			scanf("%d", &knnuser);

			if ((knnuser < 1) || (60 < knnuser))
			{
				printf("error..입력하신 개수가 참조 범위를 벗어납니다");
				printf("처음으로 돌아갑니다.");
			}

			else
			{
				mainwalker = estimationlist;
				int knncount = 0;

				for (int f = 0; f <= knnuser - 1; f++)
				{
					esticount = 0;
					knncount = knncount + 1;
					for (int e = 0; e < 60; e++)
					{
						if (strcmp(mainwalker->id, referenceIDs[e]) == 0)
						{
							break;
						}
						else
						{
							esticount = esticount + 1;
						}

					}

					xres = referecePoints[esticount][0] + xres;
					yres = referecePoints[esticount][1] + yres;


					mainwalker = mainwalker->next;

				}

				estimationCal(xres, yres, mainwalker->id, knncount);

			}


		}

		else if (interchoice == 4)
		{
			char temp[27] = "";
			printf("변경하실 Target의 ID를 입력(26개 정확히): ");
			scanf("%s", temp);

			if (strlen(temp) == 26)
			{
				strcpy(targetID, temp);
				printf("타겟 ID의 변경이 완료되었습니다\n\n");
			}
		
			else
			{
				printf("Error...잘못입력하셨습니다\n\n");
			}
		
			
		}

		else if (interchoice == 0)
		{
			printf("시스템을 종료합니다\n");
			exit(0);
		}

		system("pause");
	}

	return 0;

}

//1번 기능				1번 기능				1번 기능				1번 기능				1번 기능				1번 기능				
TAGINFO* referenceRead(TAGINFO* tagreadlist, char referenceid[27])
{
	char str[200];
	char* res;

	FILE* fp;
	fp = fopen("RFID_Data.txt", "r");
	
	int count = 0;
	float sumrssi = 0;
	float sumhour = 0, summinute = 0;
	float sumseconds = 0;

	float temp=0;


	double distance = 0;
	double timesum = 0;
	while (!feof(fp))
	{
		fgets(str, sizeof(str), fp);	//rfid_data.txt파일에서 한줄을 가져옴
		res = strtok(str, " =,T\n");
		res = strtok(NULL, " =,T\n");
		res = strtok(NULL, " =,T\n");
		
		if (strcmp(referenceid, res) == 0)
		{
			count = count + 1;

			while (res != NULL)
			{


				if (strcmp(res, "rssi") == 0)
				{
					res = strtok(NULL, " =,T\n");
					sumrssi = atoi(res) + sumrssi;
					
				}

				else if (strcmp(res, "time") == 0)
				{
					res = strtok(NULL, " =,T");
					
					res = strtok(NULL, " =,T:");
					sumhour = atoi(res);
					
					res = strtok(NULL, " =,T:");
					summinute = atoi(res);

					res = strtok(NULL, " =,T:");
					sumseconds = atof(res);


					timesum = sumhour * 60;	//시를 분으로 변환 넣어두기
					summinute = (summinute + timesum) * 60;		//분을 초로 변환

					timesum = summinute + sumseconds;		//초로 변환한거를 기존 초와 합하기
					
					if (count >= 2)
					{


						distance = timesum - temp + distance;
					}
					temp = timesum;


				}

				else
				{
					res = strtok(NULL, " =,T\n");
				}
			}

		}

		



	}

	fclose(fp);

	if (sumrssi == 0)
	{
		printf("ID: %s\n", referenceid);
		return tagreadlist;
	}

	else
	{
		sumrssi = sumrssi / count;	//rssi평균
		distance = distance/count;
		

		tagreadlist = referenceInlist(tagreadlist, referenceid, distance,sumrssi);

		return tagreadlist;
	}
	
}

TAGINFO* referenceInlist(TAGINFO* taglist,char inid[27],double intime,float inrssi)
{
	TAGINFO* newtaginfo,*current=NULL,*follow=NULL;
	current = taglist;
	newtaginfo = (TAGINFO*)malloc(sizeof(TAGINFO));

	strcpy(newtaginfo->id, inid);
	newtaginfo->rssi = inrssi;
	newtaginfo->identifiedTime = intime;


	while (current != NULL)
	{
		follow = current;
		current = current->next;
	}
	newtaginfo->next = current;
	if (current == taglist)
	{
		taglist = newtaginfo;
	}

	else
	{
		follow->next = newtaginfo;
	}

	return taglist;

}


//2번 기능			//2번 기능			//2번 기능			//2번 기능			//2번 기능			//2번 기능			
TAGINFO* targetRead(TAGINFO* tagreadlist, char targetid[27])
{
	char str[200];
	char* res;

	FILE* fp;
	fp = fopen("RFID_Data.txt", "r");

	int count = 0;
	float sumrssi = 0;
	float sumhour = 0, summinute = 0;
	float sumseconds = 0;

	float temp = 0;


	double distance = 0;
	double timesum = 0;
	while (!feof(fp))
	{
		fgets(str, sizeof(str), fp);	//rfid_data.txt파일에서 한줄을 가져옴
		res = strtok(str, " =,T\n");
		res = strtok(NULL, " =,T\n");
		res = strtok(NULL, " =,T\n");

		if (strcmp(targetid, res) == 0)
		{
			count = count + 1;

			while (res != NULL)
			{


				if (strcmp(res, "rssi") == 0)
				{
					res = strtok(NULL, " =,T\n");
					sumrssi = atoi(res) + sumrssi;

				}

				else if (strcmp(res, "time") == 0)
				{
					res = strtok(NULL, " =,T");

					res = strtok(NULL, " =,T:");
					sumhour = atoi(res);

					res = strtok(NULL, " =,T:");
					summinute = atoi(res);

					res = strtok(NULL, " =,T:");
					sumseconds = atof(res);


					timesum = sumhour * 60;	//시를 분으로 변환 넣어두기
					summinute = (summinute + timesum) * 60;		//분을 초로 변환

					timesum = summinute + sumseconds;		//초로 변환한거를 기존 초와 합하기

					if (count >= 2)
					{


						distance = timesum - temp + distance;
					}
					temp = timesum;


				}

				else
				{
					res = strtok(NULL, " =,T\n");
				}
			}

		}





	}

	fclose(fp);

	if (sumrssi == 0)
	{
		printf("ID: %s\n", targetid);
		return tagreadlist;
	}

	else
	{
		sumrssi = sumrssi / count;	//rssi평균
		distance = distance / count;


		tagreadlist = targetInlist(tagreadlist, targetid, distance, sumrssi);

		return tagreadlist;
	}


}



TAGINFO* targetInlist(TAGINFO* taglist, char inid[27], double intime, float inrssi)
{
	TAGINFO* newtaginfo, * current = NULL, * follow = NULL;
	current = taglist;
	newtaginfo = (TAGINFO*)malloc(sizeof(TAGINFO));

	strcpy(newtaginfo->id, inid);
	newtaginfo->rssi = inrssi;
	newtaginfo->identifiedTime = intime;


	while (current != NULL)
	{
		follow = current;
		current = current->next;
	}
	newtaginfo->next = current;
	if (current == taglist)
	{
		taglist = newtaginfo;
	}

	else
	{
		follow->next = newtaginfo;
	}

	return taglist;
}


//3번 기능			//3번 기능			//3번 기능			//3번 기능			//3번 기능			//3번 기능
TAGINFO* estimationRead(TAGINFO* estimationlist, TAGINFO* referencelist, float targetrssi)
{
	TAGINFO* current = NULL,*follow=NULL,*newinfo=NULL ,*referencewalker=NULL;
	referencewalker = referencelist;
	while (referencewalker != NULL)		//절대값으로 만들기 위한 코드 부분
	{
		
		referencewalker->rssi = referencewalker->rssi - targetrssi;

		if (0 > referencewalker->rssi)		//절대값 전환을 위한 코드
		{
			referencewalker->rssi = referencewalker->rssi * (-1);
		}
		
		referencewalker = referencewalker->next;
	}
	

	referencewalker = referencelist;
	while (referencewalker != NULL)
	{
		current = estimationlist;
		follow = estimationlist;

		newinfo = (TAGINFO*)malloc(sizeof(TAGINFO));

		strcpy(newinfo->id, referencewalker->id);
		newinfo->rssi = referencewalker->rssi;
		newinfo->identifiedTime = referencewalker->identifiedTime;
		
		

		while ((current != NULL)&& (current->rssi < newinfo->rssi))
		{
			follow = current;
			current = current->next;
		}
		newinfo->next = current;

		if (current == estimationlist)
		{
			estimationlist = newinfo;
		}
		else
		{
			follow->next = newinfo;
		}

		referencewalker = referencewalker->next;
		
	}
	


	return estimationlist;
}

TAGINFO* estimationview(TAGINFO* estimationlist)
{

	if (estimationlist != NULL)
	{
		printf("ID:%s\n", estimationlist->id);
		printf("rssi근접도:%.1f   \n\n", estimationlist->rssi);
		estimationview(estimationlist->next);
	}

	else
	{
		return estimationlist;
	}
}

void estimationCal(int inxres, int inyres, char finalid[27], int rescount)
{
	int fx=0;
	int fy=0;

	fx = inxres / rescount;
	fy = inyres / rescount;

	printf("				타겟ID의 최종 예측 좌표는 X: %d, Y: %d 입니다", fx, fy);


}






TAGINFO* listInview(TAGINFO* walker)
{
	if (walker != NULL)
	{
		printf("ID: %s\n", walker->id);
		printf("RSSI:%.1f   ", walker->rssi);
		printf("인터벌: %.3lf \n\n",walker->identifiedTime);

		listInview(walker->next);
	}

	else
	{
		return walker;
	}
}


