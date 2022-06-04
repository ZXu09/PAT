#include<iostream>
using namespace std;

int N, M, v1, v2;
int G[501][501];
bool visited[501] = { false };

void DFS(int S)
{
	visited[S] = true;
	for (int i = 0;i < N;i++) {
		if (!visited[i] && G[S][i]) {
			DFS(i);
		}
	}
}
int main()
{
	int degree[501] = { 0 };
	scanf("%d %d", &N, &M);
	for (int i = 0;i < M;i++) {
		scanf("%d %d", &v1, &v2);
		G[v1 - 1][v2 - 1] = 1;
		G[v2 - 1][v1 - 1] = 1;
		degree[v1 - 1]++;
		degree[v2 - 1]++;
	}
	int even = 0, odd = 0;
	bool flag = true;//判断是否连通(不能单单通过degree判断，要用dfs)
	DFS(0);
	for (int i = 0;i < N;i++) {
		if (!i)
			printf("%d", degree[i]);
		else printf(" %d", degree[i]);
		if (degree[i] % 2 == 0)
			even++;
		else odd++;

		if (!visited[i])
			flag = false;//不连通
	}
	printf("\n");
	if (flag && odd == 0)
		printf("Eulerian\n");
	else if (flag && odd == 2)
		printf("Semi-Eulerian\n");
	else
		printf("Non-Eulerian\n");
	return 0;
}