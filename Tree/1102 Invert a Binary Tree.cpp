#include<iostream>
#include<queue>
using namespace std;
struct Node
{
	int left;
	int right;
}Num[11];

void Levelorder(int S)
{
	queue<int>q;
	q.push(S);
	bool flag = false;
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		if (Num[tmp].left != -1)
			q.push(Num[tmp].left);
		if (Num[tmp].right != -1)
			q.push(Num[tmp].right);
		if (!flag) {
			printf("%d", tmp);
			flag = true;
		}
		else printf(" %d", tmp);
	}
	printf("\n");
}

bool flag = false;
void Inorder(int S)
{
	if (S == -1)
		return;
	Inorder(Num[S].left);
	if (!flag) {
		printf("%d", S);
		flag = true;
	}
	else printf(" %d", S);
	Inorder(Num[S].right);
}
int main()
{
	int N;
	char s1, s2;
	bool root[11];
	scanf("%d", &N);
	fill(root, root + N, true);

	for (int i = 0;i < N;i++) {
		scanf("\n%c %c", &s1, &s2);
		//在输入时候就进行翻转
		if (s1 == '-')
			Num[i].right = -1;
		else {
			Num[i].right = s1 - 48;
			root[s1 - 48] = false;
		}	
		if (s2 == '-')
			Num[i].left = -1;
		else {
			Num[i].left = s2 - 48;
			root[s2 - 48] = false;
		}
	}
	// 找到根节点
	int Root = 0;
	for (int i = 0;i < N;i++) {
		if (root[i]) {
			Root = i;
			break;
		}
	}
	Levelorder(Root);
	Inorder(Root);

	return 0;
}