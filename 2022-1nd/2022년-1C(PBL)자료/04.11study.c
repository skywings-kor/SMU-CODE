#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#pragma warning (disable:4996)

//event.tag.report tag_id = 0x35E0170044CF0D590000F627, type = ISOC, antenna = 1, rssi = 1955, time = 2010 - 05 - 01T02:08 : 58.404



int main(void)
{
	char str[300]="Park Gyu Min/2000.02.29/010-8693-0229";		//�ϳ��� ���ڿ��� �ٷ� ����
	char* name;
	char* birthDate;
	char* tell;
	//char* ary[11];		//ĳ����Ÿ������ �迭�� ������µ� �� �տ� �����͸� �ٿ����� =>  �ּ� 11�� ����� �߶󳻼� �־��ַ���..+ ���ڿ��� �ּҸ� ������ 11ĭ�� �迭 ����

	int i = 0;
	name = strtok(str, "/");
	birthDate = strtok(NULL, "/");
	tell = strtok(NULL, "/");
	
	
	//strtok(str, " "/*�������� �����ڴٴ� ��*/);		//���ڿ� ������ ���� �Լ� string tokniger

	//while (i<11)
	//{
	//	ary[i] = strtok(NULL, " /"/*4���� ������ ������ " , = T 4����*/);		//������� �ߴ� ���ڿ��� ���������� �����س����°� str ���� �״�� �Ѵٴ� ��
	//	i++;
	//}

	/*i = 0;
	while (i < 11)
	{
		printf("%s \n",ary[i]);
		i++;
	}*/

	printf("Name: %s \n", name);
	printf("Birthdate: %s \n", birthDate);
	printf("Tell: %s \n", tell);










	return 0;
}