//#include <stdio.h>
//#include <stdlib.h>
//#include <String.h>
//#pragma warning (disable:4996)
//
////event.tag.report tag_id = 0x35E0170044CF0D590000F627, type = ISOC, antenna = 1, rssi = 1955, time = 2010 - 05 - 01T02:08 : 58.404
//
//
////
////int main(void)
////{
////	char str[300] = "Park Gyu Min/2000.02.29/010-8693-0229";		//하나의 문자열로 다룰 꺼임
////	char* name;
////	char* birthDate;
////	char* tell;
////	//char* ary[11];		//캐릭터타입으로 배열을 만들었는데 그 앞에 포인터를 붙여놨음 =>  주소 11개 만든것 잘라내서 넣어주려고..+ 문자열의 주소를 저장할 11칸의 배열 생성
////	
////	int i = 0;
////	name = strtok(str, "/");
////	birthDate = strtok(NULL, "/");
////	tell = strtok(NULL, "/");
////
////
////	//strtok(str, " "/*공백으로 나누겠다는 뜻*/);		//문자열 분할을 위한 함수 string tokniger
////
////	//while (i<11)
////	//{
////	//	ary[i] = strtok(NULL, " /"/*4가지 종류를 나눈것 " , = T 4가지*/);		//방금전에 했던 문자열을 연속적으로 분할해나가는것 str 쓴게 그대로 한다는 뜻
////	//	i++;
////	//}
////
////	/*i = 0;
////	while (i < 11)
////	{
////		printf("%s \n",ary[i]);
////		i++;
////	}*/
////
////	printf("Name: %s \n", name);
////	printf("Birthdate: %s \n", birthDate);
////	printf("Tell: %s \n", tell);
////
////	int num1;
////	num1 = atoi(birthDate);
////
////	printf("%d \n", num1);
////
////
////
////
////
////
////
////
////	return 0;
////}
//
//int main()
//{
//	FILE* infile = fopen("RFID_Data.txt","r");
//	char str[500];
//	char *temp[5];
//	int num1, num2, num3, num4, num5;
//	char* id, *type, *antena, *rssi, *time;
//	if (infile == NULL)
//	{
//		printf("error");
//
//	}
//	else
//	{
//		while(!feof(infile))
//		{
//			fgets(str, sizeof(str), infile);
//			printf("%s", str);
//			
//			id = strtok(str, ",");
//			//num1 = atoi(id);
//			
//			type = strtok(NULL, ",");
//
//			antena = strtok(NULL, ",");
//			//num2 = atoi(antena);
//			
//			rssi = strtok(NULL, ",");
//			//num3 = atoi(rssi);
//			
//			time = strtok(NULL, ",");
//			//num4 = atoi(time);
//
//			printf("id=> %s \n", id);
//			printf("type=> %s \n", type);
//			printf("antena=> %s \n", antena);
//			printf("rssi=> %s \n", rssi);
//			printf("time=> %s \n", time);
//
//
//		}
//		fclose(infile);
//	}
//
//	return 0;
//}