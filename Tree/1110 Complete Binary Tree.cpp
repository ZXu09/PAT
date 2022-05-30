#include<iostream>
#include<queue>
#include<string>
using namespace std;
struct Node
{
	int left;
	int right;
}arr[21];

int last = 0;
bool BFS(int S)
{
	queue<int>q;
	q.push(S);
	bool flag = true;//判断是否是完全二叉树
	while (!q.empty()) {
		int temp = q.front();
		last = temp;//更新最后结点
		q.pop();
		if (arr[temp].left != -1) {
			q.push(arr[temp].left);
			if (!flag)//之前已经有结点没有左/右子树，现在有了说明不是完全二叉树
				return false;
		}
		else {
			//此时该结点没有了左子树
			flag = false;
		}
		if (arr[temp].right != -1) {
			q.push(arr[temp].right);
			if (!flag)//之前已经有结点没有左/右子树，现在有了说明不是完全二叉树
				return false;
		}
		else {
			//此时该结点没有了右子树
			flag = false;
		}
	}
	return true;//此时说明是完全二叉树
}
int main()
{
	int N;
	string c1, c2;
	int root[21];
	scanf("%d", &N);
	fill(root, root + N, true);
	for (int i = 0;i < N;i++) {
		cin >> c1 >> c2;
		if (c1 == "-")
			arr[i].left = -1;
		else {
			arr[i].left = stoi(c1);
			root[arr[i].left] = false;
		} 
		if (c2 == "-")
			arr[i].right = -1;
		else {
			arr[i].right = stoi(c2);
			root[arr[i].right] = false;
		} 
	}
	int r = 0;
	for (int i = 0;i < N;i++) {
		if (root[i])
			r = i;
	}
	if (BFS(r)) {
		printf("YES %d\n", last);
	}
	else printf("NO %d\n", r);
	return 0;
}