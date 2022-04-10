//2019243064 컴퓨터공학부 박규민(Visual Studio 2022)
//4번 문제

#include<stdio.h>

int main(void)
{
	int user;
	int i,j;
	int memo;

	int divisor[1000] = { 0 };		//배열 크기 선언
	int size;
	
	for (i = 0;; i++)		//무한루프
	{
		
		size = 0;
		user = 0;
		
		printf("약수를 구할 정수를 입력해주세요=> ");
		scanf_s("%d", &user);		//정수값 입력받고
		
		if (user == 0)		//0일때 반복문 탈출 조건 넣고
		{
			break;
		}

		for (j = 1; j <= user; j++)		//배열 크기 1씩 늘어나는데 이때 계속 반복하면 안되니까 유저가 넣은 값까지만 반복하도록
		{
			if (user % j == 0)		//약수 조건문
			{
				divisor[size] = j;		//약수 해당하는 것을 배열 한 칸에다 값을 저장해준다
				size = size++;		//배열 다음칸으로 넘겨주고
			}
			
		}

		printf("%d의 약수는=> ",user);

		for(memo=0;memo<size;memo++)		//배열을 불러올때 무한루프 돌면 안되니까 배열 size까지만 돌도록 (이때 배열은 무조건 한칸 더 먹기때문에 같다는(=) 가정 배제)
		{
			printf("%d ", divisor[memo]);		//구한 약수값 표출
		}
		
		printf("\n");

	}

	return 0;
}