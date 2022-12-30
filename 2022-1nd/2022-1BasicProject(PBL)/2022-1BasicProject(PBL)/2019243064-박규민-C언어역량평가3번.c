////2019243064 컴퓨터공학부 박규민(Visual Studio 2022)
////3번 문제
//
//#include <stdio.h>
//
//int main(void)
//{
//	int first, second, third;
//	int maxnumber;		//제일 큰 값 변수
//	printf("3개의 숫자를 입력해주세요=> ");
//	scanf_s("%d %d %d", &first, &second, &third);
//
//	maxnumber = 0;
//
//	if (first > second)
//	{
//		if (first > third)
//		{
//			maxnumber = first;
//		}
//
//		else
//		{
//			maxnumber = third;
//		}
//
//		
//	}
//
//	else if (first < second)
//	{
//		if (second < third)
//		{
//			maxnumber = third;
//		}
//		else
//		{
//			maxnumber = second;
//		}
//
//	}
//
//
//	else
//	{
//		printf("숫자를 잘못 입력하셨습니다.");
//		return 1;
//	}
//
//	printf("가장 큰 값은 %d 입니다.",maxnumber);
//	
//	return 0;
//}