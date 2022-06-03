#include<iostream>
#include<vector>
using namespace std;
typedef struct Node* PNode;
struct Node
{
	int data;
	PNode left, right;
};

PNode Build(PNode root, int data)
{
	if (root == NULL) {
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if (data <= root->data)
		root->left = Build(root->left, data);
	else
		root->right = Build(root->right, data);
	return root;
}
int Num[1010];
int maxdepth = -1;

void DFS(PNode root, int depth) {
	if (root == NULL) {
		maxdepth = max(depth, maxdepth);
		return;
	}
	Num[depth]++;
	DFS(root->left, depth + 1);
	DFS(root->right, depth + 1);
}

int main()
{
	int N, T;
	scanf("%d", &N);
	PNode root = NULL;
	for (int i = 0;i < N;i++) {
		scanf("%d", &T);
		root = Build(root, T);
	}
	DFS(root, 0);
	printf("%d + %d = %d", Num[maxdepth - 1], Num[maxdepth - 2], Num[maxdepth - 1] + Num[maxdepth - 2]);
	return 0;
}