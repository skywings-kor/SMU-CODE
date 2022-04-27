//2019243064 컴퓨터공학부 박규민(Visual Studio 2022)
//7번 문제
#include <stdio.h>
int main()
{
	char text1[20] = "this is a text";
	char text2[20] = "which is red.";
	char sumtext[100]={0};		//문자 연결할 배열 크게 선언
	
	int a, b;

	for (a = 0; a <= 20; a++)		//배열 값 만큼 반복하고
	{
		if (text1[a] == NULL)		//NULL 값일 경우 반복문 탈출
		{
			break;
		}
		printf("%c",text1[a]);		//해당 배열 칸 출력
	}

	printf(" ");

	for (b = 0; b <= 20; b++)
	{
		if (text2[b] == NULL)
		{
			break;
		}
		printf("%c", text2[b]);
	}

	return 0;

}

