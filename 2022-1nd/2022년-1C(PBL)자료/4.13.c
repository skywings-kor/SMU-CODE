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
//	node = (TAGINFO*)malloc(sizeof(TAGINFO));		//����� id[27], rssi, time[15] ũ�� �ѹ��� �� �޸� �Ҵ�
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
//			result = strtok(NULL, " ,T=");		//��ã���� �������� �Ѿ�� ���ִ� ��
//		}
//
//	}
//	
//	node->next = head;		//���Ḯ��Ʈ �տ��ٰ� ��� ���ο� ���� ����ִ� �Լ�
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
//	TAGINFO* walker = head;	//�ʱⰪ���� ���Ḯ��Ʈ ������ ����Ű�� �ϰ�
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
//		return (double)sum / cnt;		//sum�� double�� ����ȯ �� �� return ���ش�
//	}
//
//}