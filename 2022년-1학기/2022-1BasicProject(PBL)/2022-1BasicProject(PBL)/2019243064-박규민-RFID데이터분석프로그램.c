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

TAGINFO* referenceRead(TAGINFO*tagreadlist, char referenceid[27]);		//�������� �����͵��� ���Ͽ��� ������ �м��ϴ� �Լ�
TAGINFO* referenceInlist(TAGINFO* taglist, char inid[27], double intime, float inrssi);		//referenceRead���� �м��� ��ģ �����͵��� reference�� ���Ḯ��Ʈ�� ����ǵ��� �ϴ� �Լ�

TAGINFO* targetRead(TAGINFO* tagreadlist, char targetid[27]);		//Ÿ���� �����͸� ���Ͽ��� ������ �м��ϴ� �Լ�
TAGINFO* targetInlist(TAGINFO* taglist, char inid[27], double intime, float inrssi);		//targetRead���� �м��� ��ģ �����Ͱ� target�� ���Ḯ��Ʈ�� ����ǵ��� �ϴ� �Լ�

TAGINFO* estimationRead(TAGINFO* estimationlist, TAGINFO* referencelist, float targetrssi);		//Ÿ�� ID�� RSSI�� ���� ���������� ������ estimation�� ���Ḯ��Ʈ�� ����ǵ��� �ϴ� �Լ�


void estimationCal(int inxres,int inyres, char finalid[27],int rescount);		//Ÿ���� ���� ���� ��ǥ�� ����ϰ� ����ϴ� �Լ�

TAGINFO* estimationview(TAGINFO* estimationlist);		//�����ϱ� ���� �ش��ϴ� �����͵��� ������ ���Ḯ��Ʈ�� ������ ������ �� �� ������ִ� �Լ�
TAGINFO* listInview(TAGINFO* walker);		//1��, 2�� ��ɿ��� ������ ���� ����ϱ� ���� ���Ḯ��Ʈ ��� �Լ�

int main()
{
	TAGINFO* referencelist = NULL,*targetlist=NULL,*estimationlist=NULL,*mainwalker=NULL;
	int interchoice;		//����ڰ� ����� �޴� ������ �� �� ����
	
	char targetID[27] = "0x35E0170044CF0D590000F5A5";		//Ÿ�� ID

	//���� ID
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
	
	//���� ��ǥ��
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


	//���� �������̽� ����
	for (int i = 0;; i++)
	{
		system("cls");		//ȭ�� �� ���������� ���ִ� ���

		printf("					Made by-2019243064 �ڱԹ�\n\n\n\n");
		printf("				<�����ϰ� ���� �ý��� ��ȣ�� �Է����ֽø� �˴ϴ�>\n\n");
		printf("					1. Reference Tag Analysis\n\n");
		printf("					2. Target Tag Analysis\n\n");
		printf("					3. Estimation Tag Analysis\n\n");
		printf("					4. Target ID �����ϱ�\n\n");
		printf("					0. Quit\n\n");

		scanf("%d", &interchoice);



		if (interchoice == 1)		//���� �±� �м� �Լ�����
		{
			printf("					<���� �±� �����Ͱ� �������� �ʴ� ID���>\n");
			referencelist = NULL, targetlist = NULL, estimationlist = NULL;		//���Ḯ��Ʈ�� ������ �ϴ��Ͱ� ���� ��� ���̸� �ȵǴϱ� �� �� �� ����ݴϴ�.

			for (int j = 0; j < 60; j++)		//���� �����͵��� 60ĭ���� ������������ �迭0��°���� 59��°���� Ȯ���ϵ��� �մϴ�.
			{
				referencelist = referenceRead(referencelist, referenceIDs[j]);		//j�� 0�ϰ�� ���� ID ����ִ� 0��° �迭�� ������ referenceRead �Լ��� �����ϴ�.(���Ḯ��Ʈ ���� ������ ���� �����ݴϴ�)

			}

			printf("\n");
			printf("					<���� �±� ������ �м� ���>\n");
			listInview(referencelist);		//���Ḯ��Ʈ�� ���� ���� �����͵��� ���� ���� �Լ�

		}

		else if (interchoice == 2)		//Ÿ�� �±� �м� �Լ�����
		{
			printf("					<Ÿ�� �±� �����Ͱ� �������� �ʴ� ID���>\n");
			referencelist = NULL, targetlist = NULL, estimationlist = NULL;		//���Ḯ��Ʈ�� ������ �ϴ��Ͱ� ���� ��� ���̸� �ȵǴϱ� �� �� �� ����ݴϴ�.

			targetlist = targetRead(targetlist, targetID);		//Ÿ�� ID�� 1���� �����������Ƿ� 1���� ��������ݴϴ�.

			printf("\n");
			printf("					<Ÿ�� �±� ������ �м� ���>\n");
			listInview(targetlist);		//���Ḯ��Ʈ�� ���� Ÿ�� �����͸� ���� ���� �Լ�


		}


		else if (interchoice == 3)		//Ÿ�� �±��� ���� ��ǥ
		{
			int xres = 0;		//x��ǥ ���� ����
			int yres = 0;		//y��ǥ ���� ����

			int esticount = 0;		//���� ID �迭�� ���°���� �����ϰ� �� Ƚ���� �������� ���� ��ǥ���� �������� ���� ����
			int knnuser = 0;		//knn�˰����� �ϱ� ���� ����ڰ� ���� ������ �����ϵ��� �ϱ� ���� ����

			referencelist = NULL, targetlist = NULL, estimationlist = NULL;		//���� �����Ϳ� ���̸� �ȵǴ� �� �� �� ����ݴϴ�.

			printf("					<���� �±� �����Ͱ� �������� �ʴ� ID���>\n");

			//���� �±� �м� �Լ� ����
			for (int j = 0; j < 60; j++)
			{
				referencelist = referenceRead(referencelist, referenceIDs[j]);		//1�� ��ɰ� ����
			}
			
			printf("\n\n");

			//Ÿ�� �±� �м� �Լ� ����
			targetlist = targetRead(targetlist, targetID);		//2�� ��ɰ� ����

			printf("					<RSSI������ �м� ���>\n");

			estimationlist = estimationRead(estimationlist, referencelist, targetlist->rssi);		//
			estimationview(estimationlist);

			printf("������ ������ ������ �Է����ּ���: ");
			scanf("%d", &knnuser);

			if ((knnuser < 1) || (60 < knnuser))
			{
				printf("error..�Է��Ͻ� ������ ���� ������ ����ϴ�");
				printf("ó������ ���ư��ϴ�.");
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
			printf("�����Ͻ� Target�� ID�� �Է�(26�� ��Ȯ��): ");
			scanf("%s", temp);

			if (strlen(temp) == 26)
			{
				strcpy(targetID, temp);
				printf("Ÿ�� ID�� ������ �Ϸ�Ǿ����ϴ�\n\n");
			}
		
			else
			{
				printf("Error...�߸��Է��ϼ̽��ϴ�\n\n");
			}
		
			
		}

		else if (interchoice == 0)
		{
			printf("�ý����� �����մϴ�\n");
			exit(0);
		}

		system("pause");
	}

	return 0;

}

//1�� ���				1�� ���				1�� ���				1�� ���				1�� ���				1�� ���				
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
		fgets(str, sizeof(str), fp);	//rfid_data.txt���Ͽ��� ������ ������
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


					timesum = sumhour * 60;	//�ø� ������ ��ȯ �־�α�
					summinute = (summinute + timesum) * 60;		//���� �ʷ� ��ȯ

					timesum = summinute + sumseconds;		//�ʷ� ��ȯ�ѰŸ� ���� �ʿ� ���ϱ�
					
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
		sumrssi = sumrssi / count;	//rssi���
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


//2�� ���			//2�� ���			//2�� ���			//2�� ���			//2�� ���			//2�� ���			
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
		fgets(str, sizeof(str), fp);	//rfid_data.txt���Ͽ��� ������ ������
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


					timesum = sumhour * 60;	//�ø� ������ ��ȯ �־�α�
					summinute = (summinute + timesum) * 60;		//���� �ʷ� ��ȯ

					timesum = summinute + sumseconds;		//�ʷ� ��ȯ�ѰŸ� ���� �ʿ� ���ϱ�

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
		sumrssi = sumrssi / count;	//rssi���
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


//3�� ���			//3�� ���			//3�� ���			//3�� ���			//3�� ���			//3�� ���
TAGINFO* estimationRead(TAGINFO* estimationlist, TAGINFO* referencelist, float targetrssi)
{
	TAGINFO* current = NULL,*follow=NULL,*newinfo=NULL ,*referencewalker=NULL;
	referencewalker = referencelist;
	while (referencewalker != NULL)		//���밪���� ����� ���� �ڵ� �κ�
	{
		
		referencewalker->rssi = referencewalker->rssi - targetrssi;

		if (0 > referencewalker->rssi)		//���밪 ��ȯ�� ���� �ڵ�
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
		printf("rssi������:%.1f   \n\n", estimationlist->rssi);
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

	printf("				Ÿ��ID�� ���� ���� ��ǥ�� X: %d, Y: %d �Դϴ�", fx, fy);


}






TAGINFO* listInview(TAGINFO* walker)
{
	if (walker != NULL)
	{
		printf("ID: %s\n", walker->id);
		printf("RSSI:%.1f   ", walker->rssi);
		printf("���͹�: %.3lf \n\n",walker->identifiedTime);

		listInview(walker->next);
	}

	else
	{
		return walker;
	}
}


