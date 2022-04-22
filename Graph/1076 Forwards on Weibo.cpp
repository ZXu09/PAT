#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
#define MAXN 1010
int N, L;
int G[MAXN][MAXN];

struct Node
{
	int data;
	int level;
};
int  BFS(Node S)
{
	bool collected[MAXN] = { false };//重置collected
	collected[S.data] = true;//该结点已经被访问
	queue<Node>q;
	q.push(S);
	int cnt = 0;
	while (!q.empty()) {
		Node top = q.front();//首结点
		q.pop();
		int topdata = top.data;
		for (int i = 1;i <= N;i++) {
			if (G[topdata][i] == 1 && !collected[i] && top.level < L) {
				//是下一层的结点且未访问过且层数满足条件
				Node Next = { i,top.level + 1 };
				q.push(Next);
				collected[Next.data] = true;
				cnt++;
			}
		}
	}
	return cnt;
}
int main()
{
	scanf("%d %d", &N, &L);
	int M, S;
	for (int i = 1;i <= N;i++) {
		scanf("%d", &M);
		for (int j = 0;j < M;j++) {
			scanf("%d", &S);
			G[S][i] = 1;//i follows S 因此要找到被订阅的人
		}
	}
	int K;
	scanf("%d", &K);
	for (int i = 0;i < K;i++) {
		scanf("%d", &S);
		Node node = { S,0 };
		printf("%d\n", BFS(node));
	}
	return 0;
}