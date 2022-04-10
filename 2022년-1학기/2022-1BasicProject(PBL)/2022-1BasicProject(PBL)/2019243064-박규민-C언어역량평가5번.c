//2019243064 컴퓨터공학부 박규민(Visual Studio 2022)
//5번 문제

#include <stdio.h>


int main()
{
	int first, second;
	printf("두 개의 정수를 입력해주세요=> ");
	scanf_s(" %d %d", &first, &second);			//유저가 입력한 2개의 값을

	sum(first, second);		//2개의 변수에 해당 값 보내주고
}


int sum(int first, int second)
{
	int res;
	res = 0;
	res = first + second;		//2개의 값 받은걸 계산해서
	
	printf("두 정수의 합은=> %d", res);		//출력합니다
	
	return 0;
}

