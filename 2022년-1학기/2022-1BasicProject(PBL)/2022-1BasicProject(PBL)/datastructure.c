//#include <stdio.h>
//#include<stdlib.h>
//
////int main(void) {
////    int a[15][50];
////
////    //a[9][4] = 15;
////    //*(a[0] + 454) = 15;
////    //*(&a[9][0] + 4) = 15;
////    //*(&a[0][0] + 904) = 15;       잘못된 입력!!
////    
////    printf("%d", a[9][4]);
////    
////    
////    return 0;
////
////}
//
//int main()
//{
//	char bbb[10]="abcd";
//	char* str = (char*)bbb;
//
//	printf("%s", bbb);
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>	
#include <string.h>
#pragma warning (disable:4996)
int ret(int n);
int main()
{
	ret(4);
}

int ret(int n)
{
	printf("%d \n", n);
	if (n == 0)
	{
		return 0;
	}

	else if (n == 1)
	{
		return 1;
	}
	else
	{
		return (ret(n - 1) + ret(n - 2));
	}

}