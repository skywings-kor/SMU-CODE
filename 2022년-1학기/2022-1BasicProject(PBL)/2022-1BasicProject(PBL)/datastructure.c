//////#include <stdio.h>
//////#include<stdlib.h>
//////
////////int main(void) {
////////    int a[15][50];
////////
////////    //a[9][4] = 15;
////////    //*(a[0] + 454) = 15;
////////    //*(&a[9][0] + 4) = 15;
////////    //*(&a[0][0] + 904) = 15;       �߸��� �Է�!!
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
////�⸻��� ����
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
//	if (key == node->key)		//�������� ���� ��尡 ����Ű�� �ִ� ���� ���� ��쿣 ������
//		return node;
//
//	else if (key < node->key)	//���� ���� ��尡 ����Ű�� �ִ� ������ ���� ���
//		return search(node->left, key);		//�������� �̵�
//
//	else
//		return search(node->right, key);		//Ŭ��쿡�� ������!
//}
//
//Treenode* searchtry(Treenode* node, int key)
//{
//	while (node != NULL)		//����� ������ �κб��� �ݺ��ϰ�
//	{
//		if (key == node->key)		//������ ���� ��尡 ����Ű�� �ִ� �� 
//			return node;
//
//		else if (key < node->key)
//			node = node->left;
//
//		else
//			node = node->right;		
//	}
//
//	return NULL;		//Ž�� ���и� NULL
//}