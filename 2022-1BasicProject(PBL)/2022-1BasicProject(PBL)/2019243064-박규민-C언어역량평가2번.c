//2019243064 컴퓨터공학부 박규민(Visual Studio 2022)
//2번 문제

#include <stdio.h>

int main(void)
{
	char word;
	printf("하나의 문자를 입력해주세요-> ");
	scanf_s("%c",&word);

	
	printf("입력한 문자의 다음 아스키 코드는 %d 이며 문자로는 %c 입니다.",word+1,word+1);

	return 0;
}