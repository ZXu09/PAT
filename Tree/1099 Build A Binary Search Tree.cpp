#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

struct Node
{
	int left;
	int right;
	int data;
}T[110];
int key[110];
int tree[110];
int num = 0;
void Findlength(int root, int& l)
{

	if (T[root].left != -1) {
		l = l + 1;
		Findlength(T[root].left, l);
	}
	else if (T[root].right != -1) {
		l = l + 1;
		Findlength(T[root].right, l);
	}
	else return;
}

void inOrder(int root)//中序遍历填值
{
	if (root == -1) return;
	inOrder(T[root].left); //-1也要插入
	T[root].data = key[num++];
	inOrder(T[root].right);
}

void Levelorder(int root)
{
	queue<int> q;
	q.push(root);
	bool flag = false;
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		if (!flag) {
			printf("%d", T[tmp].data);
			flag = true;
		}
		else printf(" %d", T[tmp].data);
		if (T[tmp].left != -1)
			q.push(T[tmp].left);
		if (T[tmp].right != -1)
			q.push(T[tmp].right);
	}
}
int main()
{
	int N;
	scanf("%d" ,&N);
	for (int i = 0;i < N;i++) {
		scanf("%d %d", &T[i].left, &T[i].right);
	}
	for (int i = 0;i < N;i++)
		scanf("%d", &key[i]);
	sort(key, key + N);
	inOrder(0);
	Levelorder(0);
	return 0;
}