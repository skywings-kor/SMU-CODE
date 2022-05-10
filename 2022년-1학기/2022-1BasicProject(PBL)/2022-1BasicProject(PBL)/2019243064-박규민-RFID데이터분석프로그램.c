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

TAGINFO* referenceRead(TAGINFO*tagreadlist, char referenceid[27]);

TAGINFO* referenceInlist(TAGINFO* taglist, char inid[27], double intime, float inrssi);

TAGINFO* referenceInview(TAGINFO* walker);

int main()
{
	TAGINFO* list = NULL;
	int interchoice;
	char targetID[27] = "0x35E0170044CF0D590000F5A5";

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

	for (int i = 0;; i++)
	{
		system("cls");
		printf("					Made by-2019243064 박규민\n\n\n\n");
		printf("				<실행하고 싶은 시스템 번호를 입력해주시면 됩니다>\n\n");
		printf("					1. Reference Tag Analysis\n\n");
		printf("					2. Target Tag Analysis\n\n");
		printf("					3. Estimation Tag Analysis\n\n");
		printf("					0. Quit\n\n");

		scanf("%d", &interchoice);

		if (interchoice = 1)		//참조 태그 분석 함수실행
		{
			for (int j = 0; j < 60; j++)
			{
				list=referenceRead(list,referenceIDs[j]);
				
			}

			referenceInview(list);
			
		}

		else if (interchoice = 2)
		{

		}

		else if (interchoice = 3)

		{

		}



		else if (interchoice = 0)
		{
			printf("시스템을 종료합니다\n");
			exit(0);
		}

		system("pause");
	}

	return 0;

}


TAGINFO* referenceRead(TAGINFO* tagreadlist, char referenceid[27])
{
	char str[200];
	char* res;

	FILE* fp;
	fp = fopen("RFID_Data.txt", "r");
	
	int count = 0;
	float sumrssi = 0, sumhour = 0, summinute = 0;
	float sumseconds = 0;

	float timesum = 0;
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
					sumhour = atoi(res)+sumhour;
					
					res = strtok(NULL, " =,T:");
					summinute = atoi(res)+summinute;

					res = strtok(NULL, " =,T:");
					sumseconds = atof(res)+sumseconds;

				}

				else
				{
					res = strtok(NULL, " =,T\n");
				}
			}

		}

		



	}

	if (sumrssi == 0)
	{
		printf("해당되는 데이터가 존재하지 않습니다\n");
		return tagreadlist;
	}

	else
	{
		sumrssi = sumrssi / count;	//rssi평균

		timesum = sumhour * 60;	//시를 분으로 변환 넣어두기
		summinute = (summinute + timesum) * 60;		//분을 초로 변환
		
		timesum = summinute + sumseconds;		//초로 변환한거를 기존 초와 합하기

		
		timesum = timesum / count;
		
		//시간으로 재전환 테스트
		//int test, test1;
		//float test2;

		//test = (timesum / 60) / 60;

		//timesum = timesum - test * 60 * 60;

		//test1 = timesum / 60;

		//timesum = timesum - test1 * 60;

		//printf("시간:%d 분:%d 초:%f \n", test, test1, timesum);

		tagreadlist = referenceInlist(tagreadlist, referenceid, timesum,sumrssi);

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


TAGINFO* referenceInview(TAGINFO* walker)
{
	if (walker != NULL)
	{
		printf("%s ", walker->id);
		printf("%f ", walker->rssi);
		printf("%f \n", walker->identifiedTime);
	}

	else
	{
		return walker;
	}
}