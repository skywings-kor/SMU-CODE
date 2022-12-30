////2019243064 컴퓨터공학부 박규민(Visual Studio 2022)
////6번 문제
//
//#include <stdio.h>
//
//
//void circumference(int, double*);		//선언
//
//int main()
//{
//	int radius;
//	radius = 0;
//
//	double circle;
//	circle = 0;
//	printf("원의 반지름을 입력해주세요=> ");
//	scanf_s(" %d", &radius);		//반지름 값 넣어주고
//	
//	circumference(radius,&circle);		//선언한 변수에 radius값 보내주고 circle값은 가져오고
//
//	printf("원의 둘레 값은=> %.2f", circle);		//소수점 자리 둘째자리만큼 표시해주고 circle값 표시함
//
//	return 0;
//}
//
//void circumference(int radius, double* circle)
//{
//	*circle = (radius*2)*3.14;		//원의 둘레 구하는 공식
//
//}