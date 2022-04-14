#include <stdio.h>
#include<stdlib.h>

//int main(void) {
//    int a[15][50];
//
//    //a[9][4] = 15;
//    //*(a[0] + 454) = 15;
//    //*(&a[9][0] + 4) = 15;
//    //*(&a[0][0] + 904) = 15;       잘못된 입력!!
//    
//    printf("%d", a[9][4]);
//    
//    
//    return 0;
//
//}

int main()
{
	char bbb[10]="abcd";
	char* str = (char*)bbb;

	printf("%s", bbb);
	return 0;
}