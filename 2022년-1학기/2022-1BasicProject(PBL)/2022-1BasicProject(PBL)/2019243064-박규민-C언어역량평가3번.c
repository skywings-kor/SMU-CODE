//2019243064 ��ǻ�Ͱ��к� �ڱԹ�(Visual Studio 2022)
//3�� ����

#include <stdio.h>

int main(void)
{
	int first, second, third;
	int maxnumber;		//���� ū �� ����
	printf("3���� ���ڸ� �Է����ּ���=> ");
	scanf_s("%d %d %d", &first, &second, &third);

	maxnumber = 0;

	if (first > second)
	{
		if (first > third)
		{
			maxnumber = first;
			
		}

		else
		{
			maxnumber = third;
		}

		
	}

	else if (first < second)
	{
		if (second < third)
		{
			maxnumber = third;
		}
		else
		{
			maxnumber = second;
		}

	}


	else
	{
		printf("���ڸ� �߸� �Է��ϼ̽��ϴ�.");
		return 1;
	}

	printf("���� ū ���� %d �Դϴ�.",maxnumber);
	
	return 0;
}