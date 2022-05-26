//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#pragma warning (disable:4996)
//
//typedef struct taginfo
//{
//	char id[27];
//	float rssi;
//	double identifiedTime;
//	struct taginfo* next;
//} TAGINFO;
//
//TAGINFO* referenceRead(TAGINFO*tagreadlist, char referenceid[27]);		//참조값의 데이터들을 파일에서 가져와 분석하는 함수
//TAGINFO* referenceInlist(TAGINFO* taglist, char inid[27], double intime, float inrssi);		//referenceRead에서 분석을 마친 데이터들이 reference의 연결리스트에 저장되도록 하는 함수
//
//TAGINFO* targetRead(TAGINFO* tagreadlist, char targetid[27]);		//타겟의 데이터를 파일에서 가져와 분석하는 함수
//TAGINFO* targetInlist(TAGINFO* taglist, char inid[27], double intime, float inrssi);		//targetRead에서 분석을 마친 데이터가 target의 연결리스트에 저장되도록 하는 함수
//
//TAGINFO* estimationRead(TAGINFO* estimationlist, TAGINFO* referencelist, float targetrssi);		//타겟 ID와 RSSI가 같은 참조데이터 순으로 estimation의 연결리스트에 저장되도록 하는 함수
//
//
//void estimationCal(int inxres,int inyres, char finalid[27],int rescount);		//타겟의 최종 예측 좌표를 계산하고 출력하는 함수
//
//TAGINFO* estimationview(TAGINFO* estimationlist);		//예측하기 위해 해당하는 데이터들을 저장한 연결리스트에 저장한 값들을 한 번 출력해주는 함수
//TAGINFO* listInview(TAGINFO* walker);		//1번, 2번 기능에서 진행한 것을 출력하기 위한 연결리스트 출력 함수
//
//int main()
//{
//	TAGINFO* referencelist = NULL,*targetlist=NULL,*estimationlist=NULL,*mainwalker=NULL;
//	//referencelist-> 참조데이터 연결리스트
//	//targetlist-> 타겟데이터 연결리스트
//	//estimationlist->타겟 ID의 RSSI근접도 연결리스트
//	//mainwalker-> 각 연결리스트 추출을 위한 용도
//	int interchoice;		//사용자가 사용자 메뉴 선택할 때 들어갈 변수
//	
//	char targetID[27] = "0x35E0170044CF0D590000F5A5";		//타겟 ID
//
//	//참조 ID
//	char referenceIDs[60][27] =
//	{
//		"0x35E0170044CF0D590000F544","0x35E0170044CF0D590000F543","0x35E0170044CF0D590000F542","0x35E0170044CF0D590000F551","0x35E0170044CF0D590000F550","0x35E0170044CF0D590000F54F",
//		"0x35E0170044CF0D590000F61D","0x35E0170044CF0D590000F61C","0x35E0170044CF0D590000F61B","0x35E0170044CF0D590000F61A","0x35E0170044CF0D590000F629","0x35E0170044CF0D590000F628",
//		"0x35E0170044CF0D590000F54E","0x35E0170044CF0D590000F55D","0x35E0170044CF0D590000F55C","0x35E0170044CF0D590000F55B","0x35E0170044CF0D590000F55A","0x35E0170044CF0D590000F569",
//		"0x35E0170044CF0D590000F627","0x35E0170044CF0D590000F626","0x35E0170044CF0D590000F635","0x35E0170044CF0D590000F634","0x35E0170044CF0D590000F633","0x35E0170044CF0D590000F632",
//		"0x35E0170044CF0D590000F568","0x35E0170044CF0D590000F567","0x35E0170044CF0D590000F566","0x35E0170044CF0D590000F575","0x35E0170044CF0D590000F574","0x35E0170044CF0D590000F573",
//		"0x35E0170044CF0D590000F641","0x35E0170044CF0D590000F640","0x35E0170044CF0D590000F63F","0x35E0170044CF0D590000F63E","0x35E0170044CF0D590000F64D","0x35E0170044CF0D590000F64C",
//		"0x35E0170044CF0D590000F572","0x35E0170044CF0D590000F581","0x35E0170044CF0D590000F580","0x35E0170044CF0D590000F57F","0x35E0170044CF0D590000F57E","0x35E0170044CF0D590000F58D",
//		"0x35E0170044CF0D590000F64B","0x35E0170044CF0D590000F64A","0x35E0170044CF0D590000F659","0x35E0170044CF0D590000F658","0x35E0170044CF0D590000F657","0x35E0170044CF0D590000F656",
//		"0x35E0170044CF0D590000F58C","0x35E0170044CF0D590000F58B","0x35E0170044CF0D590000F58A","0x35E0170044CF0D590000F599","0x35E0170044CF0D590000F598","0x35E0170044CF0D590000F597",
//		"0x35E0170044CF0D590000F603","0x35E0170044CF0D590000F5F8","0x35E0170044CF0D590000F5F7","0x35E0170044CF0D590000F5F6","0x35E0170044CF0D590000F605","0x35E0170044CF0D590000F604"
//	};
//	
//	//참조 좌표값
//	int referecePoints[60][2] =
//	{
//		{ 7, 1 },{ 22, 1 },{ 37, 1 },{ 52, 1 },{ 67, 1 },{ 81, 1 },
//		{ 101, 1 },{ 116, 1 },{ 131, 1 },{ 146, 1 },{ 161, 1 },{ 176, 1 },
//		{ 7, 41 },{ 22, 41 },{ 37, 41 },{ 52, 41 },{ 67, 41 },{ 81, 41 },
//		{ 101, 41 },{ 116, 41 },{ 131, 41 },{ 146, 41 },{ 161, 41 },{ 176, 41 },
//		{ 7, 80 },{ 22, 80 },{ 37, 80 },{ 52, 80 },{ 67, 80 },{ 81, 80 },
//		{ 101, 80 },{ 116, 80 },{ 131, 80 },{ 146, 80 },{ 161, 80 },{ 176, 80 },
//		{ 7, 115 },{ 22, 115 },{ 37, 115 },{ 52, 115 },{ 67, 115 },{ 81, 115 },
//		{ 101, 115 },{ 116, 115 },{ 131, 115 },{ 146, 115 },{ 161, 115 },{ 176, 115 },
//		{ 7, 144 },{ 22, 144 },{ 37, 144 },{ 52, 144 },{ 67, 144 },{ 81, 144 },
//		{ 101, 144 },{ 116, 144 },{ 131, 144 },{ 146, 144 },{ 161, 144 },{ 176, 144 }
//	};
//
//
//	//메인 인터페이스 시작
//	for (int i = 0;; i++)
//	{
//		system("cls");		//화면 싹 깨끗해지게 해주는 기능
//
//		printf("					Made by-2019243064 박규민\n\n\n");
//		printf("			<실행하고 싶은 시스템 번호를 입력해주시면 됩니다>)\n");
//		printf("									(현재 타겟ID: %s)\n\n", targetID);
//		printf("					1. Reference Tag Analysis\n\n");
//		printf("					2. Target Tag Analysis\n\n");
//		printf("					3. Estimation Tag Analysis\n\n");
//		printf("					4. Target ID 변경하기\n\n");
//		printf("					0. Quit\n\n");
//
//		scanf("%d", &interchoice);
//
//
//
//		if (interchoice == 1)		//참조 태그 분석 함수실행
//		{
//			printf("					<참조 태그 데이터가 존재하지 않는 ID목록>\n");
//			referencelist = NULL, targetlist = NULL, estimationlist = NULL;		//연결리스트가 기존에 하던것과 같이 계속 쌓이면 안되니까 한 번 싹 비워줍니다.
//
//			for (int j = 0; j < 60; j++)		//참조 데이터들이 60칸으로 정해져있으니 배열0번째부터 59번째까지 확인하도록 합니다.
//			{
//				referencelist = referenceRead(referencelist, referenceIDs[j]);		//j가 0일경우 참조 ID 들어있는 0번째 배열을 가져와 referenceRead 함수에 보냅니다.(연결리스트 또한 저장을 위해 보내줍니다)
//
//			}
//
//			printf("\n");
//			printf("					<참조 태그 데이터 분석 목록>\n");
//			listInview(referencelist);		//연결리스트에 넣은 참조 데이터들을 보기 위한 함수
//
//		}
//
//		else if (interchoice == 2)		//타겟 태그 분석 함수실행
//		{
//			printf("					<타겟 태그 데이터가 존재하지 않는 ID목록>\n");
//			referencelist = NULL, targetlist = NULL, estimationlist = NULL;		//연결리스트가 기존에 하던것과 같이 계속 쌓이면 안되니까 한 번 싹 비워줍니다.
//
//			targetlist = targetRead(targetlist, targetID);		//타겟 ID는 1개로 정해져있으므로 1번만 실행시켜줍니다.
//
//			printf("\n");
//			printf("					<타겟 태그 데이터 분석 목록>\n");
//			listInview(targetlist);		//연결리스트에 넣은 타겟 데이터를 보기 위한 함수
//
//
//		}
//
//
//		else if (interchoice == 3)		//타겟 태그의 예측 좌표
//		{
//			int xres = 0;		//x좌표 총합 변수
//			int yres = 0;		//y좌표 총합 변수
//
//			int esticount = 0;		//참조 ID 배열의 몇번째인지 저장하고 이 횟수를 바탕으로 참조 좌표값을 가져오기 위한 변수
//			int knnuser = 0;		//knn알고리즘을 하기 위해 사용자가 참조 범위를 지정하도록 하기 위한 변수
//
//			referencelist = NULL, targetlist = NULL, estimationlist = NULL;		//기존 데이터에 쌓이면 안되니 한 번 싹 비워줍니다.
//
//			printf("					<참조 태그 데이터가 존재하지 않는 ID목록>\n");
//
//			//참조 태그 분석 함수 실행
//			for (int j = 0; j < 60; j++)
//			{
//				referencelist = referenceRead(referencelist, referenceIDs[j]);		//참조 ID 분석하는 함수를 실행하여 참조 데이터 연결리스트에 저장하도록함
//			}
//			
//			printf("\n\n");
//
//			//타겟 태그 분석 함수 실행
//			targetlist = targetRead(targetlist, targetID);		//타겟 ID 분석하는 함수를 실행하여 타겟 데이터 연결리스트에 저장하도록 함
//
//			printf("					<RSSI근접도 분석 목록>\n");
//
//			estimationlist = estimationRead(estimationlist, referencelist, targetlist->rssi);		//타겟 ID와 RSSI가 가장 비슷한 순으로 연결리스트에 저장하는 함수를 실행하여 예측 연결리스트에 저장되도록 함
//			estimationview(estimationlist);		//사용자에게 RSSI 근접도로 저장된 예측 연결리스트를 보여줌으로써 제대로 분석이 되었는지 확인할 수 있도록 합니다.
//
//			printf("참조할 데이터 개수를 입력해주세요: ");		//KNN알고리즘을 위해 사용자가 직접 데이터 신뢰성을 정하도록 합니다
//			scanf("%d", &knnuser);
//
//			if ((knnuser < 1) || (60 < knnuser))		//사용자가 1~60까지의 숫자가 아닌 그 외의 수를 넣었을 경우 에러를 표출해줍니다.
//			{
//				printf("error..입력하신 개수가 참조 범위를 벗어납니다");
//				printf("처음으로 돌아갑니다.");
//			}
//
//			else
//			{
//				mainwalker = estimationlist;	//mainwalker가 RSSI근접도로 저장된 연결리스트 헤더부분을 가리키게 합니다.	
//				int knncount = 0;	//knn을 몇번 실행하는지 알기위한 변수
//
//				for (int f = 0; f <= knnuser - 1; f++)		//반복이 0부터 시작(배열값 참조를 위해)이므로 기존 유저가 입력한 수에서 1을 빼야 딱 맞습니다 
//				{
//					esticount = 0;		//esticount는 x좌표 y좌표의 배열을 가리키게 하기 위해 해당하는 수를 저장하기 위한 역할입니다
//					knncount = knncount + 1;		//x좌표의 평균과 y좌표의 평균을 구하기 위해 해당 데이터가 몇 번 더해졌는지 카운트하도록 합니다
//					for (int e = 0; e < 60; e++)
//					{
//						if (strcmp(mainwalker->id, referenceIDs[e]) == 0)	//RSSI근접도로 저장된 연결리스트의 ID와 참조ID의 배열에 있는 ID가 같을 경우 해당 반복문을 탈출하게 합니다.
//						{
//							break;
//						}
//						else
//						{
//							esticount = esticount + 1;		//아닐경우에는 배열 가리키게 하는 값을 1개 증가시키고 다음 배열을 비교하게 합니다.
//						}
//
//					}
//
//					xres = referecePoints[esticount][0] + xres;		//탈출에 성공할 경우 xres에 x좌표를 넣어줍니다, 이때 esticount가 참조 좌표 데이터의 배열과 일치한 좌표를 추출하고 기존 x좌표에 계속 더하도록 합니다.
//					yres = referecePoints[esticount][1] + yres;		//y좌표 또한 위와 동일합니다.
//
//
//					mainwalker = mainwalker->next;		//RSSI근접도로 저장된 연결리스트의 다음 부분을 가르키게 함으로써 유저가 입력한 수까지 참조하도록 반복합니다.
//
//				}
//
//				estimationCal(xres, yres, mainwalker->id, knncount);		//다 되고나면 해당 함수를 실행시키는데 , 이때 x좌표, y좌표, RSSI근접도로 저장된 연결리스트의 ID, 평균을 구하기 위한 분모를 보내줍니다.
//
//			}
//
//
//		}
//
//		//사용자가 타겟의 ID를 다른 ID로 변경하고 싶을 시 변경할 수 있도록 해주는 기능
//		else if (interchoice == 4)
//		{
//			char temp[27] = "";
//			printf("변경하실 Target의 ID를 입력(26개 정확히): ");
//			scanf("%s", temp);		//사용자로부터 입력받은 문자열을 임시 공간에 넣어줍니다.
//
//			if (strlen(temp) == 26)			//만일 사용자가 26자리 정확히 넣었을 경우에 실행하는 문장입니다.
//			{
//				strcpy(targetID, temp);			
//				printf("타겟 ID의 변경이 완료되었습니다\n\n");
//			}
//		
//			else		//잘못입력할 경우에 실행하는 문장
//			{
//				printf("Error...잘못입력하셨습니다\n\n");
//			}
//		
//			
//		}
//
//		else if (interchoice == 0)		//0을 입력할경우 프로그램을 종료하도록 해줍니다.
//		{
//			printf("시스템을 종료합니다\n");
//			exit(0);
//		}
//
//		system("pause");
//	}
//
//	return 0;
//
//}
//
////1번 기능				1번 기능				1번 기능				1번 기능				1번 기능				1번 기능				
//TAGINFO* referenceRead(TAGINFO* tagreadlist, char referenceid[27])		//해당하는 참조 ID들의 데이터 불러오는 기능
//{
//	char str[200];		//txt파일에서 가져온 문장을 임시로 저장해두기 위한 공간
//	char* res;		//문자열을 가르키는 포인터
//
//	FILE* fp;		
//	fp = fopen("RFID_Data.txt", "r");		//RFID_Data.txt파일을 읽기 형식으로 엽니다.
//	
//	int count = 0;	//같은 ID에서 추출한 정보들이 몇개인지 카운트하는 변수
//	float sumrssi = 0;
//	float sumhour = 0, summinute = 0;
//	float sumseconds = 0;
//
//	float temp=0;
//
//
//	double distance = 0;
//	double timesum = 0;
//	while (!feof(fp))		//파일의 끝이 나올때까지 반복
//	{
//		fgets(str, sizeof(str), fp);	//rfid_data.txt파일에서 한줄을 가져옴
//		res = strtok(str, " =,T\n");		//가져온 문장을 =,T \n(한줄 건너뜀)이 있을경우 나눠냅니다.
//		res = strtok(NULL, " =,T\n");		//남은 문장 이어서 작업
//		res = strtok(NULL, " =,T\n");
//		
//		if (strcmp(referenceid, res) == 0)		//현재 문장에서 나눠서 뽑아낸 ID하고 참조ID가 동일할 경우
//		{
//			count = count + 1;		//같은 ID에서 추출한 데이터들이 몇개나 있는지 카운트를 1 늘려줍니다.
//
//			while (res != NULL)		//남은 문장이 없을때까지 반복
//			{
//
//
//				if (strcmp(res, "rssi") == 0)		//rssi라는 단어가 나올경우 실행
//				{
//					res = strtok(NULL, " =,T\n");
//					sumrssi = atoi(res) + sumrssi;		//해당 rssi를 int형으로 변환 후 rssi를 해당 ID RSSI 총합에 더해줍니다.
//					
//				}
//
//				else if (strcmp(res, "time") == 0)	//time이라는 단어가 나올경우 실행
//				{
//					res = strtok(NULL, " =,T");
//					
//					res = strtok(NULL, " =,T:");		//:를 함으로써 시간, 분, 초 나누는 역할을 하도록 했습니다.
//					sumhour = atoi(res);		//시간 int형으로 변환
//					
//					res = strtok(NULL, " =,T:");
//					summinute = atoi(res);		//분 int형으로 변환
//
//					res = strtok(NULL, " =,T:");
//					sumseconds = atof(res);		//초 float형으로 변환
//
//
//					timesum = sumhour * 60;	//시를 분으로 변환 넣어두기
//					summinute = (summinute + timesum) * 60;		//분을 초로 변환
//
//					timesum = summinute + sumseconds;		//초로 변환한거를 기존 초와 합하기
//					
//					if (count >= 2)		//카운트가 2가 넘을 경우
//					{
//						distance = timesum - temp + distance;	//초로 변환한 시간을 모두 더한 수에다 방금 전 시간에 읽힌 수를 뺌으로써 시간 간격을 구합니다 + 기존 저장되있던 시간간격도 더해줌으로써 시간 간격의 총합을 구해줍니다
//					}
//					temp = timesum;		//temp활용을 위해 해당 칸에 방금 한 시간의 총합을 넣어줍니다.
//
//
//				}
//
//				else		//rssi나 time이 없을경우엔 계속 나누도록 합니다.
//				{
//					res = strtok(NULL, " =,T\n");		
//				}
//			}
//
//		}
//
//		
//
//
//
//	}
//
//	fclose(fp);		//읽기 형식으로 열은 파일을 닫아줍니다.
//
//	if (sumrssi == 0)		//rssi가 0일경우에는 해당 참조 ID에서 읽힌게 없다는 뜻이므로 읽힌 데이터가 없음을 사용자에게 알려줍니다.
//	{
//		printf("ID: %s\n", referenceid);
//		return tagreadlist;
//	}
//
//	else
//	{
//		sumrssi = sumrssi / count;	//rssi평균
//		distance = distance/count;		//인터벌 평균
//		
//
//		tagreadlist = referenceInlist(tagreadlist, referenceid, distance,sumrssi);		//참조 데이터들을 연결리스트에 넣어주기 위한 함수에 참조데이터연결리스트, 참조ID, 인터벌 평균, rssi평균 이렇게 보내줍니다
//
//		return tagreadlist;		//다하고 나면 만들어진 연결리스트를 main에 돌려줍니다.
//	}
//	
//}
//
//TAGINFO* referenceInlist(TAGINFO* taglist,char inid[27],double intime,float inrssi)		//불러온 참조 데이터들을 연결리스트에 저장하는 기능
//{
//	TAGINFO* newtaginfo,*current=NULL,*follow=NULL;
//	current = taglist;		//헤더부분 가리키게 함
//	newtaginfo = (TAGINFO*)malloc(sizeof(TAGINFO));		//새로운 메모리 할당
//
//	strcpy(newtaginfo->id, inid);		//새 연결리스트의 id에는 가져온 참조ID를 넣습니다
//	newtaginfo->rssi = inrssi;		//새 연결리스트의 rssi에는 가져온 rssi의 평균을 넣습니다.
//	newtaginfo->identifiedTime = intime;		//새 연결리스틔 인터벌에는 가져온 인터벌의 평균을 넣습니다.
//
//
//	while (current != NULL)		//현재 current가 가리키고 있는 부분이 NULL이 나올때까지 반복
//	{
//		follow = current;
//		current = current->next;
//	}
//
//	newtaginfo->next = current;		//current는 지금 NULL이니까 새로운 노드의 다음은 current를 가리키게 합니다
//
//	if (current == taglist)		//연결리스트에 저장되있는 것이 하나도 없을 경우에(헤더부분부터 NULL일 경우) 실행
//	{
//		taglist = newtaginfo;		//연결리스트의 시작은 새로만든 연결리스트이다
//	}
//
//	else
//	{
//		follow->next = newtaginfo;		//마지막인 연결리스트에 새로운 연결리스트를 연결함으로써 이어지도록 함
//	}
//
//	return taglist;
//
//}
//
//
////2번 기능			//2번 기능			//2번 기능			//2번 기능			//2번 기능			//2번 기능			
//TAGINFO* targetRead(TAGINFO* tagreadlist, char targetid[27])		//해당하는 타겟 ID의 데이터를 불러오는 기능
//{
//
//	//1번 기능의 반복문을 제외하면 동일하게 문장 나누는 기능과 평균들을 구하는 기능입니다.
//	//1번 기능의 반복문을 제외하면 동일하게 문장 나누는 기능과 평균들을 구하는 기능입니다.
//	char str[200];
//	char* res;
//
//	FILE* fp;
//	fp = fopen("RFID_Data.txt", "r");
//
//	int count = 0;
//	float sumrssi = 0;
//	float sumhour = 0, summinute = 0;
//	float sumseconds = 0;
//
//	float temp = 0;
//
//
//	double distance = 0;
//	double timesum = 0;
//	while (!feof(fp))
//	{
//		fgets(str, sizeof(str), fp);	//rfid_data.txt파일에서 한줄을 가져옴
//		res = strtok(str, " =,T\n");
//		res = strtok(NULL, " =,T\n");
//		res = strtok(NULL, " =,T\n");
//
//		if (strcmp(targetid, res) == 0)
//		{
//			count = count + 1;
//
//			while (res != NULL)
//			{
//
//
//				if (strcmp(res, "rssi") == 0)
//				{
//					res = strtok(NULL, " =,T\n");
//					sumrssi = atoi(res) + sumrssi;
//
//				}
//
//				else if (strcmp(res, "time") == 0)
//				{
//					res = strtok(NULL, " =,T");
//
//					res = strtok(NULL, " =,T:");
//					sumhour = atoi(res);
//
//					res = strtok(NULL, " =,T:");
//					summinute = atoi(res);
//
//					res = strtok(NULL, " =,T:");
//					sumseconds = atof(res);
//
//
//					timesum = sumhour * 60;	//시를 분으로 변환 넣어두기
//					summinute = (summinute + timesum) * 60;		//분을 초로 변환
//
//					timesum = summinute + sumseconds;		//초로 변환한거를 기존 초와 합하기
//
//					if (count >= 2)
//					{
//						distance = timesum - temp + distance;
//					}
//					temp = timesum;
//
//				}
//
//				else
//				{
//					res = strtok(NULL, " =,T\n");
//				}
//			}
//
//		}
//
//
//
//
//
//	}
//
//	fclose(fp);
//
//	if (sumrssi == 0)
//	{
//		printf("ID: %s\n", targetid);
//		return tagreadlist;
//	}
//
//	else
//	{
//		sumrssi = sumrssi / count;	//rssi평균
//		distance = distance / count;	//인터벌 평균
//
//
//		tagreadlist = targetInlist(tagreadlist, targetid, distance, sumrssi);		//타겟ID의 데이터들을 연결리스트에 저장하도록 하는 함수에 타겟데이터연결리스트, 타겟ID, 인터벌 평균, rssi 평균 이렇게 보내줍니다.
//
//		return tagreadlist;
//	}
//
//
//}
//
//
//
//TAGINFO* targetInlist(TAGINFO* taglist, char inid[27], double intime, float inrssi)		//타겟 ID 데이터를 연결리스트에 저장해주는 기능
//{
//	TAGINFO* newtaginfo, * current = NULL, * follow = NULL;
//	current = taglist;
//	newtaginfo = (TAGINFO*)malloc(sizeof(TAGINFO));		//새로운 메모리 할당
//
//	strcpy(newtaginfo->id, inid);		//새 연결리스트의 id에 가져온 id 넣어줌
//	newtaginfo->rssi = inrssi;		//새 연결리스트의 rssi에 rssi평균 가져온거 넣어줌
//	newtaginfo->identifiedTime = intime;		//새 연결리스트의 인터벌에 가져온 인터벌 평균 넣어줌
//
//
//	while (current != NULL)		//current가 NULL이 나올때까지 반복
//	{
//		follow = current;
//		current = current->next;
//	}
//
//	newtaginfo->next = current;	//current는 NULL을 가리키고 있으니 새롭게 할당받은 공간의 다음 부분을 current를 가리키게 함으로써 연결		
//	
//	if (current == taglist)		//혹시라도 current가 헤더부분 그대로 가리키고 있을 경우
//	{
//		taglist = newtaginfo;
//	}
//
//	else
//	{
//		follow->next = newtaginfo;		//아닐경우엔 follow의 다음 부분은 새롭게 할당받은 공간을 가리킴으로써 연결리스트 연결을 완성시킴
//	}
//
//	return taglist;
//}
//
//
////3번 기능			//3번 기능			//3번 기능			//3번 기능			//3번 기능			//3번 기능
//TAGINFO* estimationRead(TAGINFO* estimationlist, TAGINFO* referencelist, float targetrssi)		//RSSI 근접도로 연결리스트 저장을 위한 기능
//{
//	TAGINFO* current = NULL,*follow=NULL,*newinfo=NULL ,*referencewalker=NULL;
//	referencewalker = referencelist;		//참조 연결리스트의 헤더부분을 가리키게함
//	while (referencewalker != NULL)		//절대값으로 만들기 위한 코드 부분(참조 연결리스트의 마지막부분까지 반복)
//	{
//		
//		referencewalker->rssi = referencewalker->rssi - targetrssi;		//referencewalker의 rssi를 타겟의 rssi 만큼 빼도록 합니다
//
//		if (0 > referencewalker->rssi)		//절대값 전환을 위한 코드 부분
//		{
//			referencewalker->rssi = referencewalker->rssi * (-1);		//혹시라도 -가 나올경우 +전환
//		}
//		
//		referencewalker = referencewalker->next;		//참조 연결리스트의 다음부분을 가리키게 함
//	}
//	
//
//	referencewalker = referencelist;		//다시 참조 연결리스트의 헤더부분을 가리키게 함
//	while (referencewalker != NULL)		//참조 연결리스트의 마지막 부분까지 반복함
//	{
//		current = estimationlist;		//current와, follow는 RSSI근접도 연결리스트의 헤더부분을 가리키게 함
//		follow = estimationlist;
//
//		newinfo = (TAGINFO*)malloc(sizeof(TAGINFO));		//새로운 메모리 공간 할당
//
//		strcpy(newinfo->id, referencewalker->id);		//새 공간의 ID에는 참조 데이터 연결리스트의 ID를 넣고
//		newinfo->rssi = referencewalker->rssi;		//새 공간의 RSSI에는 참조 데이터 연결리스트의 RSSI 평균을 넣고
//		newinfo->identifiedTime = referencewalker->identifiedTime;		//새 공간의 인터벌에는 참조 데이터 연결리스트의 인터벌 평균을 넣습니다.
//		
//		
//
//		while ((current != NULL)&& (current->rssi < newinfo->rssi))		//저장은 참조 데이터 RSSI 평균이 Target의 rssi와 최대한 비슷한 순으로 나열해야하는 조건문입니다.
//		{
//			follow = current;
//			current = current->next;
//		}
//		newinfo->next = current;
//
//		if (current == estimationlist)		//헤더부분 가리키고 있을 시 헤더부분을 newinfo로 변경
//		{
//			estimationlist = newinfo;
//		}
//
//		else
//		{
//			follow->next = newinfo;
//		}
//
//		referencewalker = referencewalker->next;		//참조 연결리스트의 다음 연결구간을 가리킴
//		
//	}
//	
//
//
//	return estimationlist;
//}
//
//TAGINFO* estimationview(TAGINFO* estimationlist)		//RSSI근접도로 저장된 연결리스트의 공간을 보게 하는 기능
//{
//
//	if (estimationlist != NULL)		//해당 연결리스트가 NULL이 나올때까지 반복
//	{
//		printf("ID:%s\n", estimationlist->id);
//		printf("rssi근접도:%.1f   \n\n", estimationlist->rssi);
//
//		estimationview(estimationlist->next);		//다음 연결리스트 공간을 가리켜서 다 표시해주기
//	}
//
//	else
//	{
//		return estimationlist;
//	}
//}
//
//
//		
//void estimationCal(int inxres, int inyres, char finalid[27], int rescount)		//예측 좌표를 계산해서 알려주는 기능
//{
//	int fx=0;	//x좌표 저장 변수
//	int fy=0;	//y좌표 저장 변수
//
//	fx = inxres / rescount;		//x의 총합에다 참조한 데이터의 개수로 나누었습니다.
//	fy = inyres / rescount;		//y의 총합에다 참조한 데이터의 개수로 나누었습니다.
//
//	printf("				타겟ID의 최종 예측 좌표는 X: %d, Y: %d 입니다", fx, fy);
//
//
//}
//
//
//
//
//
//
//TAGINFO* listInview(TAGINFO* walker)		//분석한 참조 데이터, 타겟 데이터 이 2개의 연결리스트들에 정상적으로 잘 저장이 되어있는지 사용자에게 보여주는 기능
//{
//	if (walker != NULL)		//연결리스트의 마지막 부분까지 반복
//	{
//		printf("ID: %s\n", walker->id);
//		printf("RSSI:%.1f   ", walker->rssi);
//		printf("인터벌: %.3lf \n\n",walker->identifiedTime);
//
//		listInview(walker->next);		//연결리스트의 다음 부분을 가리킴
//	}
//
//	else
//	{
//		return walker;		//다 하고나면 main에 돌려줌
//	}
//}
//
//
