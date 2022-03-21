#include<iostream>
using namespace std;
typedef struct TreeNode* BinTree;
struct TreeNode
{
	BinTree left, right;
	int data;
	int height;
};
BinTree MakeTree(int V);
int GetHeight(BinTree T);
int Max(int a, int b);
BinTree Insert(BinTree T, int V);
BinTree LL(BinTree T);
BinTree RR(BinTree T);
BinTree LR(BinTree T);
BinTree RL(BinTree T);
int main()
{
	int N;
	BinTree T = NULL;//初始化
	scanf("%d", &N);
	for (int i = 0;i < N;i++) {
		int V;
		scanf("%d", &V);
		T = Insert(T, V);
	}
	printf("%d", T->data);
	return 0;
}

BinTree MakeTree(int V)
{
	BinTree T = (BinTree)malloc(sizeof(struct TreeNode));
	T->left = T->right = NULL;
	T->data = V;
	T->height = 0;
	return T;
}
int GetHeight(BinTree T)
{
	if (!T)
		return -1;
	else return T->height;
}
int Max(int a, int b)
{
	return a > b ? a : b;
}
BinTree Insert(BinTree T, int V)
{
	if (!T)
		T = MakeTree(V);//在此处创建新的结点
	else if (V < T->data) {
		T->left = Insert(T->left, V);
		//自更新结点的路径向上调整AVL树
		if (GetHeight(T->left) - GetHeight(T->right) == 2) {
			if (V < T->left->data)
				T = LL(T);
			else
				T = LR(T);
		}
	}
	else if (V > T->data) {
		T->right = Insert(T->right, V);
		//自更新结点的路径向上调整AVL树
		if (GetHeight(T->right) - GetHeight(T->left) == 2) {
			if (V > T->right->data)
				T = RR(T);
			else
				T = RL(T);
		}
	}
	T->height = Max(GetHeight(T->left), GetHeight(T->right)) + 1;
	return T;
}
BinTree LL(BinTree T)
{
	BinTree B = T->left;
	T->left = B->right;
	B->right = T;
	T->height = Max(GetHeight(T->left), GetHeight(T->right)) + 1;
	B->height = Max(GetHeight(B->left), T->height) + 1;
	return B;
}
BinTree RR(BinTree T)
{
	BinTree B = T->right;
	T->right = B->left;
	B->left = T;
	T->height = Max(GetHeight(T->left), GetHeight(T->right)) + 1;
	B->height = Max(GetHeight(B->right), T->height) + 1;
	return B;
}
BinTree LR(BinTree T)
{
	T->left = RR(T->left);
	return LL(T);
}
BinTree RL(BinTree T)
{
	T->right = LL(T->right);
	return RR(T);
}