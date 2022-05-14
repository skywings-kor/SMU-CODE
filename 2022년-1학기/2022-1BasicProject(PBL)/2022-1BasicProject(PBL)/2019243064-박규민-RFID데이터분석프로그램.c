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
	//referencelist-> ���������� ���Ḯ��Ʈ
	//targetlist-> Ÿ�ٵ����� ���Ḯ��Ʈ
	//estimationlist->Ÿ�� ID�� RSSI������ ���Ḯ��Ʈ
	//mainwalker-> �� ���Ḯ��Ʈ ������ ���� �뵵
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

		printf("					Made by-2019243064 �ڱԹ�\n\n\n");
		printf("			<�����ϰ� ���� �ý��� ��ȣ�� �Է����ֽø� �˴ϴ�>)\n");
		printf("									(���� Ÿ��ID: %s)\n\n", targetID);
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
				referencelist = referenceRead(referencelist, referenceIDs[j]);		//���� ID �м��ϴ� �Լ��� �����Ͽ� ���� ������ ���Ḯ��Ʈ�� �����ϵ�����
			}
			
			printf("\n\n");

			//Ÿ�� �±� �м� �Լ� ����
			targetlist = targetRead(targetlist, targetID);		//Ÿ�� ID �м��ϴ� �Լ��� �����Ͽ� Ÿ�� ������ ���Ḯ��Ʈ�� �����ϵ��� ��

			printf("					<RSSI������ �м� ���>\n");

			estimationlist = estimationRead(estimationlist, referencelist, targetlist->rssi);		//Ÿ�� ID�� RSSI�� ���� ����� ������ ���Ḯ��Ʈ�� �����ϴ� �Լ��� �����Ͽ� ���� ���Ḯ��Ʈ�� ����ǵ��� ��
			estimationview(estimationlist);		//����ڿ��� RSSI �������� ����� ���� ���Ḯ��Ʈ�� ���������ν� ����� �м��� �Ǿ����� Ȯ���� �� �ֵ��� �մϴ�.

			printf("������ ������ ������ �Է����ּ���: ");		//KNN�˰����� ���� ����ڰ� ���� ������ �ŷڼ��� ���ϵ��� �մϴ�
			scanf("%d", &knnuser);

			if ((knnuser < 1) || (60 < knnuser))		//����ڰ� 1~60������ ���ڰ� �ƴ� �� ���� ���� �־��� ��� ������ ǥ�����ݴϴ�.
			{
				printf("error..�Է��Ͻ� ������ ���� ������ ����ϴ�");
				printf("ó������ ���ư��ϴ�.");
			}

			else
			{
				mainwalker = estimationlist;	//mainwalker�� RSSI�������� ����� ���Ḯ��Ʈ ����κ��� ����Ű�� �մϴ�.	
				int knncount = 0;	//knn�� ��� �����ϴ��� �˱����� ����

				for (int f = 0; f <= knnuser - 1; f++)		//�ݺ��� 0���� ����(�迭�� ������ ����)�̹Ƿ� ���� ������ �Է��� ������ 1�� ���� �� �½��ϴ� 
				{
					esticount = 0;		//esticount�� x��ǥ y��ǥ�� �迭�� ����Ű�� �ϱ� ���� �ش��ϴ� ���� �����ϱ� ���� �����Դϴ�
					knncount = knncount + 1;		//x��ǥ�� ��հ� y��ǥ�� ����� ���ϱ� ���� �ش� �����Ͱ� �� �� ���������� ī��Ʈ�ϵ��� �մϴ�
					for (int e = 0; e < 60; e++)
					{
						if (strcmp(mainwalker->id, referenceIDs[e]) == 0)	//RSSI�������� ����� ���Ḯ��Ʈ�� ID�� ����ID�� �迭�� �ִ� ID�� ���� ��� �ش� �ݺ����� Ż���ϰ� �մϴ�.
						{
							break;
						}
						else
						{
							esticount = esticount + 1;		//�ƴҰ�쿡�� �迭 ����Ű�� �ϴ� ���� 1�� ������Ű�� ���� �迭�� ���ϰ� �մϴ�.
						}

					}

					xres = referecePoints[esticount][0] + xres;		//Ż�⿡ ������ ��� xres�� x��ǥ�� �־��ݴϴ�, �̶� esticount�� ���� ��ǥ �������� �迭�� ��ġ�� ��ǥ�� �����ϰ� ���� x��ǥ�� ��� ���ϵ��� �մϴ�.
					yres = referecePoints[esticount][1] + yres;		//y��ǥ ���� ���� �����մϴ�.


					mainwalker = mainwalker->next;		//RSSI�������� ����� ���Ḯ��Ʈ�� ���� �κ��� ����Ű�� �����ν� ������ �Է��� ������ �����ϵ��� �ݺ��մϴ�.

				}

				estimationCal(xres, yres, mainwalker->id, knncount);		//�� �ǰ��� �ش� �Լ��� �����Ű�µ� , �̶� x��ǥ, y��ǥ, RSSI�������� ����� ���Ḯ��Ʈ�� ID, ����� ���ϱ� ���� �и� �����ݴϴ�.

			}


		}

		//����ڰ� Ÿ���� ID�� �ٸ� ID�� �����ϰ� ���� �� ������ �� �ֵ��� ���ִ� ���
		else if (interchoice == 4)
		{
			char temp[27] = "";
			printf("�����Ͻ� Target�� ID�� �Է�(26�� ��Ȯ��): ");
			scanf("%s", temp);		//����ڷκ��� �Է¹��� ���ڿ��� �ӽ� ������ �־��ݴϴ�.

			if (strlen(temp) == 26)			//���� ����ڰ� 26�ڸ� ��Ȯ�� �־��� ��쿡 �����ϴ� �����Դϴ�.
			{
				strcpy(targetID, temp);			
				printf("Ÿ�� ID�� ������ �Ϸ�Ǿ����ϴ�\n\n");
			}
		
			else		//�߸��Է��� ��쿡 �����ϴ� ����
			{
				printf("Error...�߸��Է��ϼ̽��ϴ�\n\n");
			}
		
			
		}

		else if (interchoice == 0)		//0�� �Է��Ұ�� ���α׷��� �����ϵ��� ���ݴϴ�.
		{
			printf("�ý����� �����մϴ�\n");
			exit(0);
		}

		system("pause");
	}

	return 0;

}

//1�� ���				1�� ���				1�� ���				1�� ���				1�� ���				1�� ���				
TAGINFO* referenceRead(TAGINFO* tagreadlist, char referenceid[27])		//�ش��ϴ� ���� ID���� ������ �ҷ����� ���
{
	char str[200];		//txt���Ͽ��� ������ ������ �ӽ÷� �����صα� ���� ����
	char* res;		//���ڿ��� ����Ű�� ������

	FILE* fp;		
	fp = fopen("RFID_Data.txt", "r");		//RFID_Data.txt������ �б� �������� ���ϴ�.
	
	int count = 0;	//���� ID���� ������ �������� ����� ī��Ʈ�ϴ� ����
	float sumrssi = 0;
	float sumhour = 0, summinute = 0;
	float sumseconds = 0;

	float temp=0;


	double distance = 0;
	double timesum = 0;
	while (!feof(fp))		//������ ���� ���ö����� �ݺ�
	{
		fgets(str, sizeof(str), fp);	//rfid_data.txt���Ͽ��� ������ ������
		res = strtok(str, " =,T\n");		//������ ������ =,T \n(���� �ǳʶ�)�� ������� �������ϴ�.
		res = strtok(NULL, " =,T\n");		//���� ���� �̾ �۾�
		res = strtok(NULL, " =,T\n");
		
		if (strcmp(referenceid, res) == 0)		//���� ���忡�� ������ �̾Ƴ� ID�ϰ� ����ID�� ������ ���
		{
			count = count + 1;		//���� ID���� ������ �����͵��� ��� �ִ��� ī��Ʈ�� 1 �÷��ݴϴ�.

			while (res != NULL)		//���� ������ ���������� �ݺ�
			{


				if (strcmp(res, "rssi") == 0)		//rssi��� �ܾ ���ð�� ����
				{
					res = strtok(NULL, " =,T\n");
					sumrssi = atoi(res) + sumrssi;		//�ش� rssi�� int������ ��ȯ �� rssi�� �ش� ID RSSI ���տ� �����ݴϴ�.
					
				}

				else if (strcmp(res, "time") == 0)	//time�̶�� �ܾ ���ð�� ����
				{
					res = strtok(NULL, " =,T");
					
					res = strtok(NULL, " =,T:");		//:�� �����ν� �ð�, ��, �� ������ ������ �ϵ��� �߽��ϴ�.
					sumhour = atoi(res);		//�ð� int������ ��ȯ
					
					res = strtok(NULL, " =,T:");
					summinute = atoi(res);		//�� int������ ��ȯ

					res = strtok(NULL, " =,T:");
					sumseconds = atof(res);		//�� float������ ��ȯ


					timesum = sumhour * 60;	//�ø� ������ ��ȯ �־�α�
					summinute = (summinute + timesum) * 60;		//���� �ʷ� ��ȯ

					timesum = summinute + sumseconds;		//�ʷ� ��ȯ�ѰŸ� ���� �ʿ� ���ϱ�
					
					if (count >= 2)		//ī��Ʈ�� 2�� ���� ���
					{
						distance = timesum - temp + distance;	//�ʷ� ��ȯ�� �ð��� ��� ���� ������ ��� �� �ð��� ���� ���� �����ν� �ð� ������ ���մϴ� + ���� ������ִ� �ð����ݵ� ���������ν� �ð� ������ ������ �����ݴϴ�
					}
					temp = timesum;		//tempȰ���� ���� �ش� ĭ�� ��� �� �ð��� ������ �־��ݴϴ�.


				}

				else		//rssi�� time�� ������쿣 ��� �������� �մϴ�.
				{
					res = strtok(NULL, " =,T\n");		
				}
			}

		}

		



	}

	fclose(fp);		//�б� �������� ���� ������ �ݾ��ݴϴ�.

	if (sumrssi == 0)		//rssi�� 0�ϰ�쿡�� �ش� ���� ID���� ������ ���ٴ� ���̹Ƿ� ���� �����Ͱ� ������ ����ڿ��� �˷��ݴϴ�.
	{
		printf("ID: %s\n", referenceid);
		return tagreadlist;
	}

	else
	{
		sumrssi = sumrssi / count;	//rssi���
		distance = distance/count;		//���͹� ���
		

		tagreadlist = referenceInlist(tagreadlist, referenceid, distance,sumrssi);		//���� �����͵��� ���Ḯ��Ʈ�� �־��ֱ� ���� �Լ��� ���������Ϳ��Ḯ��Ʈ, ����ID, ���͹� ���, rssi��� �̷��� �����ݴϴ�

		return tagreadlist;		//���ϰ� ���� ������� ���Ḯ��Ʈ�� main�� �����ݴϴ�.
	}
	
}

TAGINFO* referenceInlist(TAGINFO* taglist,char inid[27],double intime,float inrssi)		//�ҷ��� ���� �����͵��� ���Ḯ��Ʈ�� �����ϴ� ���
{
	TAGINFO* newtaginfo,*current=NULL,*follow=NULL;
	current = taglist;		//����κ� ����Ű�� ��
	newtaginfo = (TAGINFO*)malloc(sizeof(TAGINFO));		//���ο� �޸� �Ҵ�

	strcpy(newtaginfo->id, inid);		//�� ���Ḯ��Ʈ�� id���� ������ ����ID�� �ֽ��ϴ�
	newtaginfo->rssi = inrssi;		//�� ���Ḯ��Ʈ�� rssi���� ������ rssi�� ����� �ֽ��ϴ�.
	newtaginfo->identifiedTime = intime;		//�� ���Ḯ��Ʒ ���͹����� ������ ���͹��� ����� �ֽ��ϴ�.


	while (current != NULL)		//���� current�� ����Ű�� �ִ� �κ��� NULL�� ���ö����� �ݺ�
	{
		follow = current;
		current = current->next;
	}

	newtaginfo->next = current;		//current�� ���� NULL�̴ϱ� ���ο� ����� ������ current�� ����Ű�� �մϴ�

	if (current == taglist)		//���Ḯ��Ʈ�� ������ִ� ���� �ϳ��� ���� ��쿡(����κк��� NULL�� ���) ����
	{
		taglist = newtaginfo;		//���Ḯ��Ʈ�� ������ ���θ��� ���Ḯ��Ʈ�̴�
	}

	else
	{
		follow->next = newtaginfo;		//�������� ���Ḯ��Ʈ�� ���ο� ���Ḯ��Ʈ�� ���������ν� �̾������� ��
	}

	return taglist;

}


//2�� ���			//2�� ���			//2�� ���			//2�� ���			//2�� ���			//2�� ���			
TAGINFO* targetRead(TAGINFO* tagreadlist, char targetid[27])		//�ش��ϴ� Ÿ�� ID�� �����͸� �ҷ����� ���
{

	//1�� ����� �ݺ����� �����ϸ� �����ϰ� ���� ������ ��ɰ� ��յ��� ���ϴ� ����Դϴ�.
	//1�� ����� �ݺ����� �����ϸ� �����ϰ� ���� ������ ��ɰ� ��յ��� ���ϴ� ����Դϴ�.
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
		distance = distance / count;	//���͹� ���


		tagreadlist = targetInlist(tagreadlist, targetid, distance, sumrssi);		//Ÿ��ID�� �����͵��� ���Ḯ��Ʈ�� �����ϵ��� �ϴ� �Լ��� Ÿ�ٵ����Ϳ��Ḯ��Ʈ, Ÿ��ID, ���͹� ���, rssi ��� �̷��� �����ݴϴ�.

		return tagreadlist;
	}


}



TAGINFO* targetInlist(TAGINFO* taglist, char inid[27], double intime, float inrssi)		//Ÿ�� ID �����͸� ���Ḯ��Ʈ�� �������ִ� ���
{
	TAGINFO* newtaginfo, * current = NULL, * follow = NULL;
	current = taglist;
	newtaginfo = (TAGINFO*)malloc(sizeof(TAGINFO));		//���ο� �޸� �Ҵ�

	strcpy(newtaginfo->id, inid);		//�� ���Ḯ��Ʈ�� id�� ������ id �־���
	newtaginfo->rssi = inrssi;		//�� ���Ḯ��Ʈ�� rssi�� rssi��� �����°� �־���
	newtaginfo->identifiedTime = intime;		//�� ���Ḯ��Ʈ�� ���͹��� ������ ���͹� ��� �־���


	while (current != NULL)		//current�� NULL�� ���ö����� �ݺ�
	{
		follow = current;
		current = current->next;
	}

	newtaginfo->next = current;	//current�� NULL�� ����Ű�� ������ ���Ӱ� �Ҵ���� ������ ���� �κ��� current�� ����Ű�� �����ν� ����		
	
	if (current == taglist)		//Ȥ�ö� current�� ����κ� �״�� ����Ű�� ���� ���
	{
		taglist = newtaginfo;
	}

	else
	{
		follow->next = newtaginfo;		//�ƴҰ�쿣 follow�� ���� �κ��� ���Ӱ� �Ҵ���� ������ ����Ŵ���ν� ���Ḯ��Ʈ ������ �ϼ���Ŵ
	}

	return taglist;
}


//3�� ���			//3�� ���			//3�� ���			//3�� ���			//3�� ���			//3�� ���
TAGINFO* estimationRead(TAGINFO* estimationlist, TAGINFO* referencelist, float targetrssi)		//RSSI �������� ���Ḯ��Ʈ ������ ���� ���
{
	TAGINFO* current = NULL,*follow=NULL,*newinfo=NULL ,*referencewalker=NULL;
	referencewalker = referencelist;		//���� ���Ḯ��Ʈ�� ����κ��� ����Ű����
	while (referencewalker != NULL)		//���밪���� ����� ���� �ڵ� �κ�(���� ���Ḯ��Ʈ�� �������κб��� �ݺ�)
	{
		
		referencewalker->rssi = referencewalker->rssi - targetrssi;		//referencewalker�� rssi�� Ÿ���� rssi ��ŭ ������ �մϴ�

		if (0 > referencewalker->rssi)		//���밪 ��ȯ�� ���� �ڵ� �κ�
		{
			referencewalker->rssi = referencewalker->rssi * (-1);		//Ȥ�ö� -�� ���ð�� +��ȯ
		}
		
		referencewalker = referencewalker->next;		//���� ���Ḯ��Ʈ�� �����κ��� ����Ű�� ��
	}
	

	referencewalker = referencelist;		//�ٽ� ���� ���Ḯ��Ʈ�� ����κ��� ����Ű�� ��
	while (referencewalker != NULL)		//���� ���Ḯ��Ʈ�� ������ �κб��� �ݺ���
	{
		current = estimationlist;		//current��, follow�� RSSI������ ���Ḯ��Ʈ�� ����κ��� ����Ű�� ��
		follow = estimationlist;

		newinfo = (TAGINFO*)malloc(sizeof(TAGINFO));		//���ο� �޸� ���� �Ҵ�

		strcpy(newinfo->id, referencewalker->id);		//�� ������ ID���� ���� ������ ���Ḯ��Ʈ�� ID�� �ְ�
		newinfo->rssi = referencewalker->rssi;		//�� ������ RSSI���� ���� ������ ���Ḯ��Ʈ�� RSSI ����� �ְ�
		newinfo->identifiedTime = referencewalker->identifiedTime;		//�� ������ ���͹����� ���� ������ ���Ḯ��Ʈ�� ���͹� ����� �ֽ��ϴ�.
		
		

		while ((current != NULL)&& (current->rssi < newinfo->rssi))		//������ ���� ������ RSSI ����� Target�� rssi�� �ִ��� ����� ������ �����ؾ��ϴ� ���ǹ��Դϴ�.
		{
			follow = current;
			current = current->next;
		}
		newinfo->next = current;

		if (current == estimationlist)		//����κ� ����Ű�� ���� �� ����κ��� newinfo�� ����
		{
			estimationlist = newinfo;
		}

		else
		{
			follow->next = newinfo;
		}

		referencewalker = referencewalker->next;		//���� ���Ḯ��Ʈ�� ���� ���ᱸ���� ����Ŵ
		
	}
	


	return estimationlist;
}

TAGINFO* estimationview(TAGINFO* estimationlist)		//RSSI�������� ����� ���Ḯ��Ʈ�� ������ ���� �ϴ� ���
{

	if (estimationlist != NULL)		//�ش� ���Ḯ��Ʈ�� NULL�� ���ö����� �ݺ�
	{
		printf("ID:%s\n", estimationlist->id);
		printf("rssi������:%.1f   \n\n", estimationlist->rssi);

		estimationview(estimationlist->next);		//���� ���Ḯ��Ʈ ������ �����Ѽ� �� ǥ�����ֱ�
	}

	else
	{
		return estimationlist;
	}
}


		
void estimationCal(int inxres, int inyres, char finalid[27], int rescount)		//���� ��ǥ�� ����ؼ� �˷��ִ� ���
{
	int fx=0;	//x��ǥ ���� ����
	int fy=0;	//y��ǥ ���� ����

	fx = inxres / rescount;		//x�� ���տ��� ������ �������� ������ ���������ϴ�.
	fy = inyres / rescount;		//y�� ���տ��� ������ �������� ������ ���������ϴ�.

	printf("				Ÿ��ID�� ���� ���� ��ǥ�� X: %d, Y: %d �Դϴ�", fx, fy);


}






TAGINFO* listInview(TAGINFO* walker)		//�м��� ���� ������, Ÿ�� ������ �� 2���� ���Ḯ��Ʈ�鿡 ���������� �� ������ �Ǿ��ִ��� ����ڿ��� �����ִ� ���
{
	if (walker != NULL)		//���Ḯ��Ʈ�� ������ �κб��� �ݺ�
	{
		printf("ID: %s\n", walker->id);
		printf("RSSI:%.1f   ", walker->rssi);
		printf("���͹�: %.3lf \n\n",walker->identifiedTime);

		listInview(walker->next);		//���Ḯ��Ʈ�� ���� �κ��� ����Ŵ
	}

	else
	{
		return walker;		//�� �ϰ��� main�� ������
	}
}


