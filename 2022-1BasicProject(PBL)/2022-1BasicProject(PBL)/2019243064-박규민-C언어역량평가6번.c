//2019243064 ��ǻ�Ͱ��к� �ڱԹ�(Visual Studio 2022)
//6�� ����

#include <stdio.h>


void circumference(int, double*);		//����

int main()
{
	int radius;
	radius = 0;

	double circle;
	circle = 0;
	printf("���� �������� �Է����ּ���=> ");
	scanf_s(" %d", &radius);		//������ �� �־��ְ�
	
	circumference(radius,&circle);		//������ ������ radius�� �����ְ� circle���� ��������

	printf("���� �ѷ� ����=> %.2f", circle);		//�Ҽ��� �ڸ� ��°�ڸ���ŭ ǥ�����ְ� circle�� ǥ����

	return 0;
}

void circumference(int radius, double* circle)
{
	*circle = (radius*2)*3.14;		//���� �ѷ� ���ϴ� ����

}