#include<iostream>
#include<queue>
using namespace std;
struct Node
{
	int x, y, z;
};
int M, N, L, T;
int X[6] = { 1, 0, 0, -1, 0, 0 };//便于DFS移动
int Y[6] = { 0, 1, 0, 0, -1, 0 };
int Z[6] = { 0, 0, 1, 0, 0, -1 };
int arr[1300][130][70];
bool visit[1300][130][70] = { false };

bool judge(int x, int y, int z) 
{
	if (x < 0 || x >= M || y < 0 || y >= N || z < 0 || z >= L)
		return false;
	if (arr[x][y][z] == 0 || visit[x][y][z] == true) 
		return false;
	return true;
}

int BFS(int x, int y, int z)
{
	int cnt = 0;//计数判断是否>=T
	Node temp;
	temp.x = x, temp.y = y, temp.z = z;
	queue<Node> q;
	q.push(temp);
	visit[x][y][z] = true;
	while (!q.empty()) {
		Node top = q.front();
		q.pop();
		cnt++;
		for (int i = 0; i < 6; i++) {
			int tx = top.x + X[i];
			int ty = top.y + Y[i];
			int tz = top.z + Z[i];
			if (judge(tx, ty, tz)) {//满足邻接点
				visit[tx][ty][tz] = true;
				temp.x = tx, temp.y = ty, temp.z = tz;
				q.push(temp);//入队
			}
		}
	}
	if (cnt >= T)
		return cnt;
	else
		return 0;

}
int main()
{
	scanf("%d %d %d %d", &M, &N, &L, &T);
	for (int k = 0;k < L;k++)
		for (int j = 0;j < M;j++)
			for (int i = 0;i < N;i++)
				scanf("%d", &arr[j][i][k]);
	int ans = 0;
	for (int k = 0;k < L;k++)
		for (int j = 0;j < M;j++)
			for (int i = 0;i < N;i++) {
				if (arr[j][i][k] == 1 && visit[j][i][k] == false)
					ans += BFS(j, i, k);
			}
	printf("%d", ans);
	return 0;
}