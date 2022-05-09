//////2019243064 컴퓨터공학부-데이터공학-박규민
//////2022-05-04 Test Debug End;
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <time.h>
//#pragma warning (disable:4996)
//
//typedef struct node 
//{
//	int correct;		//무작위 숫자 저장하기 위한 int형 변수
//	struct node* next;		//노드 다음 구간 가리키기 위한 선언
//}NODE;
//
//NODE* randnumin(NODE* in_list);		//연결리스트에 랜덤값 넣어주는 함수
//NODE* viewnode(NODE* walker);		//연결리스트 보여주는 함수(임시용)
//NODE* strikecorrectcheck(NODE*list,int f1,int f2,int f3,int f4,int f5,int strikecount);		//노드와 유저가 입력한 값 5개 받아와서 정답 맞는지 확인하는 함수
//NODE* ballcorrectcheck(NODE*list,int f1,int f2,int f3,int f4,int f5,int ballcount);		//노드와 유저가 입력한 값 5개 받아와서 정답 맞는지 확인하는 함수
//
//int loginpage(char userinid[20], char userinpw[20]);		//로그인 기능 함수
//int usercreate(char createid[20], char createpw[20]);		//회원가입 기능 함수
//int userfind(char findid[20]);		//비밀번호 찾는 기능 함수
//int highscore(char loginid[20]);		//제일 잘 나온 점수 표시해주는 함수
//int scoresave(char loginid[20], char inscore);		//정답 맞추고나면 점수 저장해주는 함수
//
//int main(void)
//{
//	
//	//로그인 구간ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
//	int userlogin;		//유저 로그인할건지 회원가입할건지 비밀번호찾기할건지 프로그램 종료할건지 나누는 변수
//
//	int success;		//로그인 성공시 반환값 받는거
//	char userid[20];		//로그인->아이디 입력한거
//	char userpw[20];		//로그인->비번입력한거
//
//	char createid[20];		//회원가입->아이디 입력 받은거
//	char createpw[20];		//회원가입->비밀번호 입력 받은거
//	int createsuccess;		//회원가입 성공시 반환받는 변수
//
//	char findid[20];		//비밀번호찾기->아이디 입력 받은거
//
//
//	for (int k = 0;; k++)		//로그인이나 회원가입이나 비밀번호 찾기 실패시 돌아오게 하기위한 for문
//	{
//		system("cls");
//		printf("                               <SMU-2019243064-컴퓨터공학부-박규민-숫자야구게임>\n\n");
//		success = 0;
//		createsuccess = 0;
//		userlogin = 0;
//
//		printf("                       <1> 로그인           <2> 회원가입           <3> 비밀번호 찾기           <0> 프로그램 종료 \n");
//		scanf("%d", &userlogin);
//	
//		
//		if (userlogin == 1)		//로그인
//		{
//
//			printf("아이디를 입력해주세요: ");
//			scanf("%s", userid);
//
//			printf("비밀번호를 입력해주세요: ");
//			scanf("%s", userpw);
//
//			success=loginpage(userid,userpw);		//로그인기능을 담당하는 함수에서 로그인 성공시 반환받는 부분입니다.
//
//			if (success == 1)		
//			{
//				printf("                       로그인 성공\n\n");
//				break;
//			}
//
//			else
//			{
//				printf("                       ID또는 PW가 잘못되었습니다\n\n");
//				system("pause");
//			}
//		}
//
//		else if (userlogin == 2)		//회원가입
//		{
//			printf("만드실 ID입력: ");
//			scanf("%s", createid);
//
//			printf("만드실 PW입력: ");
//			scanf("%s", createpw);
//
//			createsuccess=usercreate(createid, createpw);		//회원가입을 담당하는 함수에서 회원가입 성공시 반환받는 부분입니다.
//
//			if (createsuccess == 1)
//			{
//				printf("동일한 아이디가 있어 회원가입에 실패하였습니다");
//				system("pause");
//			}
//
//			else
//			{
//				printf("회원가입 성공!");
//				system("pause");
//			}
//
//		}
//
//		else if (userlogin == 3)		//비밀번호 찾기
//		{
//			printf("찾으실 ID입력: ");
//			scanf("%s", findid);
//
//			userfind(findid);		//사용자가 비밀번호 찾기 위한 함수 부분 실행합니다.
//
//			system("pause");
//		}
//
//		else if (userlogin == 0)			//프로그램 종료
//		{
//			printf("프로그램을 종료합니다.");
//			system("pause");
//			exit(0);
//		}
//
//		else
//		{
//		
//		}
//
//	}
//
//	int highnum;		//최단 횟수 저장 변수
//	system("cls");		//한번 싹 깨끗하게 해줍니다(콘솔창)
//	printf("                               <SMU-2019243064-컴퓨터공학부-박규민>-숫자야구게임\n\n");
//	highnum=highscore(userid);		//사용자가 로그인한 ID로 저장되어있는 점수를 찾아 최단 횟수가 표시됩니다(저장 되어있는 점수가 없을 경우 0이 출력)
//	printf("                                                                               <최단횟수 : %d번>\n\n",highnum);
//	NODE* list;		//연결리스트 선언~!
//	list= NULL;		//노드 리스트 초기화
//	int userin;		//유저가 5자리 입력한 값
//	int res5,res4, res3, res2, res1;		//사용자가 5자리 수 입력한거 나누기 위한 임시 변수
//	int ballcount = 0;		//볼카운트
//	int strikecount = 0;		//스트라이크 카운트
//
//	list=randnumin(list);		//메인 연결리스트에 랜덤값 넣어주는 함수 실행된 리턴값 넣어주기
//
//
//	//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
//	//printf("테스트 및 수정+디버깅용을 위한 정답표출:");		//테스트 컴파일을 위한 정답 알려주는 부분
//	//viewnode(list);	//테스트 컴파일을 위한 정답 알려주는 함수
//	//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
//
//
//	for (int i = 1;; i++)		//무한루프
//	{
//		printf("\nㅡㅡㅡㅡ%d번째 기회ㅡㅡㅡㅡ",i);
//		userin = 0;
//		ballcount = 0;
//		strikecount = 0;
//		//유저가 다시 입력했을 때 기존 값이 남아있으면 안되니 초기화 해주기 위한 것
//	
//
//		printf("\n맞추실 중복되지 않는 숫자5자리를 입력(1~9, tip:0을 입력시 종료됩니다)->");
//
//		scanf("%d", &userin);
//		if (userin == 0)	//게임 중 사용자가 게임 종료하고 싶을때 0 입력하면 종료되게 한 것
//		{
//			printf("\n!!프로그램을 종료합니다!!");
//			system("pause");
//			exit(0);		//종료
//		}
//
//		else if ((10000>userin) || (99999 < userin))		//사용자가 입력한 값이 5자리수가 넘거나 적을경우 실행하는 부분
//		{
//			printf("\n<error> 숫자가 잘못 입력되었습니다.\n");
//			i = i - 1;
//		}
//
//		
//		else
//		{
//			res5 = userin / 10000;		//첫 번째 자리
//			userin = userin - res5 * 10000;
//				
//			res4 = userin / 1000;		//두 번째 자리
//			userin = userin - res4 * 1000;
//
//			res3 = userin / 100;		//세 번째 자리
//			userin = userin - res3 * 100;
//
//			res2 = userin / 10;		//네 번째 자리
//			userin = userin - res2 * 10;
//
//			res1 = userin;		//다섯 번째 자리
//			
//
//			if ((res5 == res4) || (res5 == res3) || (res5 == res2) || (res5 == res1) || (res4 == res3) || (res4 == res2) || (res4 == res1) || (res3 == res2) || (res3 == res1) || (res2 == res1))
//			{//사용자가 중복된 숫자를 입력한 것이 있을경우 오류 나타내주는것
//				printf("중복된 숫자가 입력되었습니다.\n");
//				i = i - 1;
//			}
//
//			else
//			{
//				printf("%d %d %d %d %d", res5, res4, res3, res2, res1);		//사용자가 어떤 숫자를 입력하였는지 보여줌
//
//				strikecount = strikecorrectcheck(list, res5, res4, res3, res2, res1, ballcount, strikecount);		//스트라이크 개수 세는 함수 실행
//				ballcount = ballcorrectcheck(list, res5, res4, res3, res2, res1, ballcount, strikecount);		//볼 개수 세는 함수 실행
//				printf("\n%d스트라이크 %d볼입니다.\n", strikecount, ballcount);
//
//				if (strikecount == 5)//사용자가 정답을 맞출경우(스트라이크 5개)
//				{
//					printf("축하드립니다! %d번째 만에 성공하셨습니다! \n\n", i);		
//					char changescore = i + '0';		//i가 int형이다보니 여기다 0을 더해서 char형으로 바꿔줍니다
//					scoresave(userid, changescore);		//점수 저장하는 함수에 유저id, char형으로 변경한 점수를 보내줍니다.
//					printf("!점수가 저장되었습니다! \n");
//					break;
//				}
//
//				system("pause");
//			}
//			
//			
//
//		}
//		
//
//
//
//	}
//	
//	//반복문 탈출시 실행하는 부분
//	printf("게임을 종료합니다...\n");		
//	system("pause");
//	exit(0);
//
//}
//
////랜덤 숫자 연결리스트 삽입 함수			랜덤 숫자 연결리스트 삽입 함수			랜덤 숫자 연결리스트 삽입 함수			랜덤 숫자 연결리스트 삽입 함수
//NODE* randnumin(NODE* in_list)
//{
//	int count=0;
//	int errorcount = 0;		//중복 숫자 카운트
//	NODE* current = NULL, * follow = NULL,*checker=NULL,*walker=NULL;
//	NODE* newnode;
//	
//
//	int temp = 0;		//임시저장역할인 int형 변수
//
//	srand(time(NULL));		//랜덤함수 쓰기위한 선언
//
//	for (int i = 1; i<=5; i++)
//	{
//		checker = in_list;		//노드 돌아다니면 값 같을 경우 랜덤함수 다시 하도록 하는거
//		
//		follow = in_list;
//		current = in_list;
//		newnode = (NODE*)malloc(sizeof(NODE));		//새로운 연결리스트 메모리 할당
//
//		temp = rand() % 9 + 1;		//임시 변수에 랜덤값 1개 넣음
//
//		while (checker != NULL)		//중첩되는 숫자 검사하기 위한 연결리스트 돌아다니는 부분
//		{
//			
//			walker = in_list;
//			errorcount = 0;		//0으로 초기화
//			while (walker != NULL)		//연결리스트에서 중복 숫자 검사하는 부분 역할임(만일 중복 숫자 겹치는게 없으면 해당 부분이 아무일 없이 지나감)
//			{
//				if (walker->correct == temp)		//연결리스트에 저장되있는 변수가 임시 넣어논 값이랑 같을경우 errorcount 1을 줘서 다시 돌게 한다.
//				{
//					errorcount = 1;		//중복 숫자인것을 알려주는것
//					break;
//				}
//
//				else  //아닐경우 연결리스트 다음칸을 가리키게 하여 연결리스트 중복 오류 확인을 이어 나간다.
//				{
//					walker = walker->next;
//				}
//			}
//
//			if (errorcount==1)	//중복 숫자가 있을경우 temp에 다시 랜덤값을 준다
//			{
//				temp = rand() % 9 + 1;
//			}
//
//			else
//			{
//				checker = checker->next;
//			}
//			
//		}
//
//
//		
//		newnode->correct = temp;	//다 검사하고 탈출했을 경우 이상이 없을시 새 노드에 temp에 들어있는 변수를 넣는다.
//
//		while (current != NULL)		//연결리스트가 마지막이 나올때까지 반복
//		{
//			
//			follow = current;
//			current = current->next;
//		}
//		newnode->next = current;
//		if (current == in_list)
//		{
//			in_list = newnode;		//혹시라도 연결리스트가 아무것도 없어서 처음 부분일 경우 헤더가 현재 newnode를 가리키게 하는 것
//		}
//
//		else
//		{
//			follow->next = newnode;		//아닐 경우는 follow의 다음이 newnode를 연결시켜 연결리스트 완성되게함
//		}
//		
//	}
//
//	return in_list;		//다 완성했을 경우 연결리스트를 돌려줌으로써 랜덤 값들이 들어있는 연결리스트 완성~!
//
//}
//
////랜덤 값으로 들어간 숫자 보여주는 함수			랜덤 값으로 들어간 숫자 보여주는 함수			랜덤 값으로 들어간 숫자 보여주는 함수
//
//NODE* viewnode(NODE* walker)		//너무 제가 못맞춰서 랜덤값 편히 보고 테스트 하려고 만든 일종의 정답지 코드입니다...(ㅠㅠ...)
//{
//	
//	if (walker != NULL)
//	{
//		printf("%d ", walker->correct);
//		viewnode(walker->next);
//	}
//
//	else
//	{
//		return walker;
//	}
//}
//
////스트라이크 개수 확인하는 함수			스트라이크 개수 확인하는 함수			스트라이크 개수 확인하는 함수			스트라이크 개수 확인하는 함수
//NODE* strikecorrectcheck(NODE* list, int f1, int f2, int f3, int f4, int f5,int strikecount)	//노드와 유저가 입력한 값 5개 받아와서 정답 맞는지 확인하는 함수
//{
//	NODE* walker;
//	walker = list;
//
//	//첫번째자리
//	if (walker->correct == f1)
//	{
//		strikecount = strikecount + 1;
//	}
//
//	walker = walker->next;
//
//	//두번째자리
//	if (walker->correct == f2)
//	{
//		strikecount = strikecount + 1;
//	}
//
//	walker = walker->next;
//
//	//세번째자리
//	if (walker->correct == f3)
//	{
//		strikecount = strikecount + 1;
//	}
//
//	walker = walker->next;
//
//	//네번째자리
//	if (walker->correct == f4)
//	{
//		strikecount = strikecount + 1;
//	}
//
//	walker = walker->next;
//
//	//다섯번째자리
//	if (walker->correct == f5)
//	{
//		strikecount = strikecount + 1;
//	}
//
//
//	return strikecount;		//스트라이크 개수 메인 함수에 전달
//}
//
////볼개수 확인하는 함수			볼개수 확인하는 함수			볼개수 확인하는 함수			볼개수 확인하는 함수
//NODE* ballcorrectcheck(NODE* list, int f1, int f2, int f3, int f4, int f5, int ballcount)
//{
//	NODE* walker;
//	walker = list;
//
//	//첫번째자리
//	if ((walker->correct == f2)||(walker->correct==f3) || (walker->correct == f4) || (walker->correct == f5))
//	{
//		ballcount = ballcount + 1;
//	}
//
//	walker = walker->next;
//
//	//두번째자리
//	if ((walker->correct == f1) || (walker->correct == f3) || (walker->correct == f4) || (walker->correct == f5))
//	{
//		ballcount = ballcount + 1;
//	}
//
//	walker = walker->next;
//
//	//세번째자리
//	if ((walker->correct == f2) || (walker->correct == f1) || (walker->correct == f4) || (walker->correct == f5))
//	{
//		ballcount = ballcount + 1;
//	}
//
//	walker = walker->next;
//
//	//네번째자리
//	if ((walker->correct == f2) || (walker->correct == f3) || (walker->correct == f1) || (walker->correct == f5))
//	{
//		ballcount = ballcount + 1;
//	}
//
//	walker = walker->next;
//
//	//다섯번째자리
//	if ((walker->correct == f2) || (walker->correct == f3) || (walker->correct == f4) || (walker->correct == f1))
//	{
//		ballcount = ballcount + 1;
//	}
//
//
//	return ballcount;		//볼 개수 메인 함수에 전달
//}
//
////로그인 함수			로그인 함수				로그인 함수			로그인 함수					로그인 함수					로그인 함수
//int loginpage(char userinid[20], char userinpw[20])		
//{
//	FILE* fp;
//	fp = fopen("user.txt", "r");		//user.txt파일을 읽는 형식으로 열음
//
//	char str[60];
//	char* id;
//	char* pw;
//	while (!feof(fp))		//열은 파일에서 마지막 부분까지 나올때까지 반복
//	{
//		fgets(str, sizeof(str), fp);		//한 줄 가져옴
//		id = strtok(str, " ");		//스페이스바 하나로 문자열을 나눠서 id에 넣음
//		pw = strtok(NULL, " \n");		//나눈 것을 이어 받아 줄바꿈 나오기 전까지 그 문장을 pw에 넣음
//
//		if ((strcmp(userinid, id) == 0) && (strcmp(userinpw, pw) == 0))		//유저가 입력한 아이디하고 비밀번호가 user.txt에 적혀있는 것과 동일할 경우 실행
//		{
//			fclose(fp);		//파일 열었던거 닫아줌
//			return 1;	//로그인에 성공할경우
//			break;
//		}
//
//
//	}
//	fclose(fp);		//실패해도 닫아줌!
//	return 0;		//로그인에 실패할 경우
//
//}
//
////회원가입 함수		회원가입 함수		회원가입 함수		회원가입 함수		회원가입 함수		회원가입 함수		회원가입 함수
//int usercreate(char createid[20], char createpw[20])
//{
//	FILE* fp;
//	fp = fopen("user.txt", "r");		//user.txt파일을 읽는 형식으로 열음
//
//	char str[60];
//	char* id;
//	char* pw;
//	while (!feof(fp))		//열은 파일에서 마지막 부분까지 나올때까지 반복
//	{
//		fgets(str, sizeof(str), fp);	
//		id = strtok(str, " ");		
//		pw = strtok(NULL, " ");		//위 로그인 코드와 동일한 역할
//
//		if (strcmp(createid, id) == 0)		//같은 아이디가 이미 존재시
//		{
//			return 1;		
//			break;
//		}
//
//
//	}
//
//
//	//같은 아이디가 없고 새로운 아이디일때 실행
//	fclose(fp);		//파일 r형식으로 열었던거 닫아주고
//
//
//	fp = fopen("user.txt", "a");		//user.txt파일에 추가 작성으로 하도록 열고
//	
//	fputs(createid, fp);		//user.txt파일에 유저가 입력한 id 넣고
//	fputs(" ", fp);		//한칸 띄어주고
//	fputs(createpw, fp);		//user.txt파일에 유저가 입력한 pw넣고
//
//	fputs("\n", fp);		//enter하나 해주고(한칸 밑으로)
//
//
//	fclose(fp);		//다 작성했으면 닫아주고
//
//	return 0;
//
//	
//
//}
//
////비밀번호 찾기 함수		비밀번호 찾기 함수				비밀번호 찾기 함수				비밀번호 찾기 함수				비밀번호 찾기 함수
//int userfind(char findid[20])
//{
//	FILE* fp;
//	fp = fopen("user.txt", "r");		//파일 읽기 형식으로 열음
//	char str[60];
//	char* resid;
//	char* respw;
//	
//
//	while (!feof(fp))		//파일 마지막 문장 나올때까지 반복함
//	{
//		fgets(str, sizeof(str), fp);		//한 줄씩 가져와서 str 변수에 넣고
//
//		resid = strtok(str, " ");
//		respw = strtok(NULL, " \n");
//
//		if (strcmp(resid, findid) == 0)		//찾으려는 ID와 저장되어있는 ID 가 같을경우 해당 비번 표시
//		{
//			printf("해당 ID의 비번은 < %s > 입니다.", respw);
//
//			return 1;
//		}
//
//
//	}
//	fclose(fp);
//	printf("해당 ID가 존재하지 않습니다");
//	return 0;
//}
//
////로그인한 ID로 제일 단시간에 성공한 횟수 표시				로그인한 ID로 제일 단시간에 성공한 횟수 표시				로그인한 ID로 제일 단시간에 성공한 횟수 표시
//int highscore(char loginid[20])		//해당 ID의 최고점수(횟수) 불러오는거
//{
//	FILE* fp;
//	fp = fopen("score.txt", "r");
//
//	char str[60];
//	char* resid;		//로그인한 사용자 id
//	int highnum = 1000;		//점수가 1000점(최악점수)	
//	while (!feof(fp))
//	{
//		char* resscore;		//score.txt파일에 적혀있는 점수 저장하는 것
//		int changescore;		//resscore를 atoi로 int형 변환해서 넣어두기 위한 int형 변수
//		fgets(str, sizeof(str), fp); 
//		resid = strtok(str, " ");
//		resscore = strtok(NULL, " \n");
//		
//		changescore = atoi(resscore);		//atoi로 char를 int로 변환해서 changescore에 넣어줌
//		if ((strcmp(resid, loginid) == 0)&&(changescore<highnum))		//아이디가 같고 현재 파일이 끝나기전 최단횟수가 더 작은게 나타날경우 저장
//		{
//			highnum = changescore;
//		}
//		
//	}
//	
//	fclose(fp);
//	
//	if (highnum == 1000)		//score.txt 파일에 로그인한 id와 일치하는 점수가 존재하지 않을 경우
//	{
//		return 0;		//숫자 0을 돌려줘서 없다는 것을 알려줌
//	}
//
//	else
//	{
//		return highnum;		//최단 횟수 저장된걸 main에 보내줌
//	}
//	
//}
//
////점수 저장 함수			점수 저장 함수			점수 저장 함수			점수 저장 함수				점수 저장 함수			점수 저장 함수
//int scoresave(char loginid[20], char inscore)		//메인으로부터 로그인한 id하고 최종 달성한 점수를 받음
//{
//	FILE* fp;
//	fp = fopen("score.txt","a");	//파일 추가작성 형식으로 열음
//	fputs("\n", fp);
//	fputs(loginid, fp);		//score.txt파일에 id 작성
//	fputs(" ", fp);
//
//	fputc(inscore, fp);		//score.txt파일에 pw 작성
//
//	
//
//
//	fclose(fp);		//파일 열었던거 닫아줌
//
//	return 0;
//}