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

TAGINFO* targetRead(TAGINFO* tagreadlist, char targetid[27]);
TAGINFO* targetInlist(TAGINFO* taglist, char inid[27], double intime, float inrssi);

TAGINFO* listInview(TAGINFO* walker);

int main()
{
	TAGINFO* referencelist = NULL,*targetlist=NULL;
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
		printf("					Made by-2019243064 �ڱԹ�\n\n\n\n");
		printf("				<�����ϰ� ���� �ý��� ��ȣ�� �Է����ֽø� �˴ϴ�>\n\n");
		printf("					1. Reference Tag Analysis\n\n");
		printf("					2. Target Tag Analysis\n\n");
		printf("					3. Estimation Tag Analysis\n\n");
		printf("					0. Quit\n\n");

		scanf("%d", &interchoice);

		if (interchoice == 1)		//���� �±� �м� �Լ�����
		{
			if (referencelist == NULL)
			{
				for (int j = 0; j < 60; j++)
				{
					referencelist = referenceRead(referencelist, referenceIDs[j]);

				}
			}
			

			listInview(referencelist);		//���Ḯ��Ʈ�� ���� ���� ������ ���� ���� �Լ�
			
		}

		else if (interchoice == 2)		//Ÿ�� �±� �м� �Լ�����
		{
			if (targetlist == NULL)
			{
				targetlist = targetRead(targetlist, targetID);
			}
			
			listInview(targetlist);


		}

		else if (interchoice == 3)

		{

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
		//printf("�ش�Ǵ� �����Ͱ� �������� �ʽ��ϴ�\n");
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
		printf("�ش�Ǵ� �����Ͱ� �������� �ʽ��ϴ�\n");
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










TAGINFO* listInview(TAGINFO* walker)
{
	double hour=0, minute=0, seconds=0;
	if (walker != NULL)
	{
		printf("���̵�: %s   ", walker->id);
		printf("���rssi:%.1f   ", walker->rssi);
		printf("������͹�: %.3lf \n",walker->identifiedTime);

		listInview(walker->next);
	}

	else
	{
		return walker;
	}
}


