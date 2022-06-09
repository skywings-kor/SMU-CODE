//////#include <stdio.h>
//////#include<stdlib.h>
//////
////////int main(void) {
////////    int a[15][50];
////////
////////    //a[9][4] = 15;
////////    //*(a[0] + 454) = 15;
////////    //*(&a[9][0] + 4) = 15;
////////    //*(&a[0][0] + 904) = 15;       잘못된 입력!!
////////    
////////    printf("%d", a[9][4]);
////////    
////////    
////////    return 0;
////////
////////}
//////
//////int main()
//////{
//////	char bbb[10]="abcd";
//////	char* str = (char*)bbb;
//////
//////	printf("%s", bbb);
//////	return 0;
//////}
////
////#include <stdio.h>
////#include <stdlib.h>	
////#include <string.h>
////#pragma warning (disable:4996)
////int ret(int n);
////int main()
////{
////	ret(4);
////}
////
////int ret(int n)
////{
////	printf("%d \n", n);
////	if (n == 0)
////	{
////		return 0;
////	}
////
////	else if (n == 1)
////	{
////		return 1;
////	}
////	else
////	{
////		return (ret(n - 1) + ret(n - 2));
////	}
////
////}\
//
//
////기말고사 연습
//
//#include <stdio.h>
//#include <stdlib.h>
//#pragma warning (disable:4996)
//
//typedef struct Treenode
//{
//	int data;
//	struct Treenode* left, * right;
//}Treenode;
//
//
//
//int main()
//{
//
//
//
//
//
//	return 0;
//}
//
//
//void preorder(struct Node* root)
//{
//	struct Node* p;
//	p = root;
//	while (p != NULL)
//	{
//		printf("%d", p->data);
//		p = p->left;
//	}
//}
//
//Treenode* search(Treenode* node, int key)
//{
//	if (node == NULL)
//	{
//		return NULL;
//	}
//
//	if (key == node->key)		//넣으려는 값과 노드가 가리키고 있는 값이 같을 경우엔 끝내고
//		return node;
//
//	else if (key < node->key)	//값이 현재 노드가 가리키고 있는 값보다 작을 경우
//		return search(node->left, key);		//왼쪽으로 이동
//
//	else
//		return search(node->right, key);		//클경우에는 오른쪽!
//}
//
//Treenode* searchtry(Treenode* node, int key)
//{
//	while (node != NULL)		//노드의 마지막 부분까지 반복하고
//	{
//		if (key == node->key)		//값에서 현재 노드가 가리키고 있는 값 
//			return node;
//
//		else if (key < node->key)
//			node = node->left;
//
//		else
//			node = node->right;		
//	}
//
//	return NULL;		//탐색 실패면 NULL
//}