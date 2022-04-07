//////2019243064 컴퓨터공학부-데이터공학-박규민
//////2022-04-05 Test Debug End;
////
////<개발 개요> 
////1.사용자로부터 입력받는 10진수 정수를 사용자가 지정한 진법(2진수~ 9진수)로 변환
////2.스택을 이용한 구현
////3.나머지 연산(%)과 나누기 연산(/)를 이용한 진법변환과정 구현  
//
//
//#include <stdio.h>
//#include <stdlib.h>
//#include<string.h>
//#pragma warning (disable:4996)
//#define MAX 16		 //스택 사이즈(노드의 최대 개수) 정의
//
//typedef struct snode		//연결리스트 노드용 구조체 
//{
//	int data;			//<박규민>: 연결리스트에 넣을 data 공간 선언 
//	struct snode* next;		//<박규민>: 연결리스트 다음 주소를 가리키기 위한 공간
//}STACKNODE;
//
//
//typedef struct stack		// 스택용 연결리스트 제어용 구조체 
//{
//	int counter;		// 연결리스트에 연결된 노드 개수 
//	STACKNODE* top;		 // 연결리스트 시작점(또는 스택의 최상위) 
//}STACK;
//
//void initiation(STACK* stp);		//스택 초기화 
//int checkEmpty(STACK* stp);		// 스택이 비어있는지 확인 (0 또는 1반환) 
//int checkFull(STACK* stp);		// 스택이 가득 차있는지  확인 (0 또는 1반환) 
//void push(STACK* stp, int data);		//스택에서 푸쉬 동작 
//int pop(STACK* stp);		//스택에서 팝 동작
//
//void main()
//{
//	STACK st;
//
//	int poppedData;		//<박규민>:POP할(뺄) 숫자를 잠시 저장해두는 공간
//	int typeOfCode = 0;		// 사용자가 입력할 변환 진법 (2 ~ 9) 
//	int decimalValue = 0;		// 사용자가 입력할 10진수  
//	int remainder = 0;		//나머지
//	int quotient = 0;		// 몫 
//
//	printf("Stduent Name: 박규민 \n");
//
//	initiation(&st);		//<박규민>: 초기화 한 번 해주는 함수
//
//	printf("Enter a Decimal Value: ");
//	scanf("%d", &decimalValue);		//<박규민>: 사용자가 입력한 임의 숫자를 decimalValue에 넣습니다
//
//	printf("Enter a Type of Code(2~9): ");
//	scanf("%d", &typeOfCode);		//<박규민>: 사용자가 입력한 진법 변환할 숫자를 typeOfCode에 넣습니다
//
//	if (decimalValue < typeOfCode)		// 진법변환 과정의 도출물을 스택에 Push
//	{
//		push(&st, decimalValue);
//	}
//
//	else
//	{//진법 변환 부분
//		quotient = decimalValue;		//<박규민>: quotient에 사용자가 임의 숫자를 넣은 것을 넣습니다.
//		while (quotient >= typeOfCode)		//<박규민>:quotient에 들어가는 값이 사용자가 진법 변환할 숫자를 넣은 것 보다 크면 계속 반복합니다.
//		{
//			push(&st, quotient % typeOfCode);		//<박규민>: quotient를 사용자가 입력한 진법변환할 숫자로 나눈 나머지를 push함수에 보냅니다.
//			quotient = quotient / typeOfCode;		//<박규민>: quotient를 사용자가 입력한 진법변환할 숫자로 나눠서 결과를 quotient에 저장합니다. 
//		}
//		if (quotient != 0)		 
//		{
//			push(&st, quotient);
//		}
//
//	}
//
//
//	//POP 하는 구간
//	poppedData = 0;
//	printf("Converted Value (Radix = %d): ", typeOfCode);
//	while (poppedData != -1)		//<박규민>: pop에서 return한 값이 -1이 아니면 계속 반복합니다.
//	{
//		poppedData = pop(&st);		//<박규민>: 여기부분에서는 pop에서 return 한 data가 poppedData에 들어갑니다
//		if (poppedData != -1)		//<박규민>: pop에서 return 한 값이 -1이 아니면 해당 조건문을 실행합니다
//		{
//			printf("%d ", poppedData);		//<박규민>: 사용자에게 어떤 값이 pop 되었는지 알려줍니다.
//			
//		}
//	}
//	printf("\n");		//<박규민>: 마지막까지 표출한 후 반복문을 탈출했으면 해당 시스템은 멈추게 해줍니다.(아랫줄)
//	system("pause");
//}
//
//
//void initiation(STACK* stp)
//{
//	stp->counter = 0;		//<박규민>:노드 개수 카운트 하기 위해서 0으로 초기화 해줬습니다!
//	stp->top = NULL;		//<박규민>:헤더 부분을 NULL로 한 번 초기화 해줬습니다.
//
//}
//
//int checkEmpty(STACK* stp)
//{
//
//	if (stp->top == NULL)		//<박규민>: 스택에서의 최상단 값이 NULL이면 스택이 비어있다는 뜻이니까 1을 반환해주고 아닐경우에는 0을 반환하여 스택이 존재함을 알려줍니다.
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//int checkFull(STACK* stp)		//<박규민>:가장 먼저 push에서 사용되어지는 함수로 STACK이 꽉차있는지 확인하여 반환값을 주어야합니다.
//{//<박규민>:이때 반환값이 0이면 push를 실행하게 되고 아니면은 스택이 꽉찼다고 메시지를 전달하게 됩니다.
//	if (stp->counter < MAX)		//<박규민>: 스택 최대 사이즈(MAX=16)를 정해놓았기에 만일 스택을 카운트한 것이 MAX보다 같거나 클경우 return 1을 해주고 아닐경우엔 0을 해줍니다.
//	{
//		
//		return 0;
//	}
//	else
//	{
//		return 1;
//	}
//
//
//}
//
//void push(STACK* stp, int data)
//{
//	if (checkFull(stp) == 0)		//<박규민>: checkFull이라는 함수를 통하여 스택이 꽉차있는지 검사해주는데 이때 return이 0이면 진행합니다.
//	{
//		STACKNODE* newnode = (STACKNODE*)malloc(sizeof(STACKNODE));		//<박규민>:새로운 노드를 만들어서 기존 링크드 리스트에 연결시켜주기 위한 newnode라는 노드를 한개 만듭니다.
//		newnode->data = data;		//<박규민>: newnode->data에 해당하는 공간에 사용자가 입력한 숫자에서 해당 진법으로 나눠서 나오는 나머지 값을(data) 넣습니다.
//		newnode->next = stp->top;		//<박규민>: 그리고 data만 넣는 것이 아닌 next 공간에는 링크드 리스트를 연결시켜줍니다.
//		stp->top = newnode; //<박규민>: 최상단에 이제 새로 넣은 newnode가 들어가도록 해줍니다.
//		stp->counter += 1;		//<박규민>: 이제 그러면 노드가 한개 정상적으로 추가 되었으니 카운트를 하나해줍니다.
//		
//		return stp;		//<박규민>: 위에 main에 최종 push된 결과를 전달해주기 위해 return stp를 해줍니다
//	}
//
//	else               //<박규민>:return 1이 반환되면 실행되는 곳-꽉찼다고 안내합니다
//	{
//		printf("The stack is Full! \n");
//	}
//}
//
//int pop(STACK* stp)
//{
//	STACKNODE* current;
//	int data;
//	if (checkEmpty(stp) == 1)		//<박규민>: 스택이 혹시라도 비어있거나 스택을 끝까지 다 돌경우 해당 if문을 실행하게 합니다.
//	{
//		printf("The stack is empty! \n");
//		return -1;		//data값으로는 음수가 없다는 가정
//	}
//	else
//	{
//		data = stp->top->data;		//<박규민>: 연결리스트 내의 data라는 공간에 있는 값을 pop에 선언된 data에 임시로 넣어놓습니다
//		current = stp->top;		//<박규민>: 연결리스트에서 delete한 것처럼 현재 current가 현재 top을 가리키게 합니다
//		stp->top = stp->top->next;		//<박규민>: 그리고 top은 top의 다음 부분을 가르키게 하여 current가 현재 가지고 있는 메모리를 반납할 준비를 합니다.
//
//		free(current);		//<박규민>: 메모리 반납!
//
//		
//		return data;		//<박규민>: 다했으면 임시로 넣어논 값을 뺐다는 것을 알려주기 위해 pop의 data 변수를 돌려줍니다.
//	}
//}