//#include <stdio.h>
//#include <stdlib.h>
//#include<string.h>
//#pragma warning (disable:4996)
//
//typedef struct taginfo
//{
//	char id[27];
//	int rssi;
//	char identifiedTime[15];
//	struct taginfo* next;
//
//
//}TAGINFO;
//
//TAGINFO* stringSplit(TAGINFO *head,char data[]);
//double avgRSSI(TAGINFO* head,char _id[]);
//
//int main()
//{
//	char testID[27] = "0x35E0170044CF0D590000F64C";
//	char str[300];
//	FILE* fp;
//	TAGINFO* list = NULL;
//
//	fp = fopen("RFID_Data.txt", "r");
//
//	while (!feof(fp))
//	{
//		fgets(str, 299,fp);
//		
//		list=stringSplit(list,str);
//
//		printf("%s", list->identifiedTime);
//
//
//	}
//
//	printf("\n\nAVG: %lf \n",avgRSSI(list,testID));
//
//
//
//	return 0;
//}
//
//TAGINFO* stringSplit(TAGINFO* head, char data[])
//{
//	char* result;
//	TAGINFO* node;
//	node = (TAGINFO*)malloc(sizeof(TAGINFO));		//요놈이 id[27], rssi, time[15] 크기 한번에 다 메모리 할당
//
//	result = strtok(data, " =,T");
//
//	while (result!=NULL)
//	{
//		
//		if (strcmp(result,"tag_id")==0)
//		{
//			result = strtok(NULL, " =,T");
//			strcpy(node->id, result);
//
//		}
//
//		else if (strcmp(result, "rssi") == 0)
//		{
//			result = strtok(NULL, " =,T");
//			node->rssi = atoi(result);
//		}
//
//		else if (strcmp(result, "time") == 0)
//		{
//			result = strtok(NULL, " =,T");
//			result = strtok(NULL, " =,T");
//			strcpy(node->identifiedTime, result);
//
//			//printf("%s", node->identifiedTime);
//		}
//
//		else
//		{
//			result = strtok(NULL, " ,T=");		//못찾으면 다음으로 넘어가게 해주는 거
//		}
//
//	}
//	
//	node->next = head;		//연결리스트 앞에다가 계속 새로운 값을 집어넣는 함수
//	head = node;
//
//	return head;
//
//
//
//}
//
//double avgRSSI(TAGINFO* head, char _id[])
//{
//	int sum = 0;
//	int cnt = 0;
//	TAGINFO* walker = head;	//초기값으로 연결리스트 시작점 가리키게 하고
//
//	if (walker == NULL)
//	{
//		return 0.0;
//	}
//
//	else
//	{
//
//		while (walker != NULL)
//		{
//			
//			if (strcmp(walker->id, _id) == 0)
//			{
//				sum = sum + walker->rssi;
//				cnt++;
//			}
//			walker = walker->next;
//
//		}
//		return (double)sum / cnt;		//sum을 double로 형변환 한 후 return 해준다
//	}
//
//}