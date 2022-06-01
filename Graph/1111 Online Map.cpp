#include<iostream>
#include<vector>
using namespace std;
#define INF 0x3f3f3f
struct Node
{
	int length;
	int time;
}G[510][510];
int Dist[510];
int Path[510];
int Time[510];//为了找到相同最短路径最快的那条
int Node[510];//为了找到相同时间最少结点的那条
bool visited[510] = { false };
int N, M;

void Dijkstral(int S)
{
	fill(Dist, Dist + N, INF);
	fill(visited, visited + N, false);
	fill(Time, Time + N, INF);
	Dist[S] = 0;
	Time[S] = 0;
	while (1) {
		int u = -1, Mind = INF;
		for (int i = 0;i < N;i++) {
			if (!visited[i] && Dist[i] < Mind) {
				u = i;
				Mind = Dist[i];
			}
		}
		if (u == -1)
			break;
		visited[u] = true;
		for (int i = 0;i < N;i++) {
			if (!visited[i] && G[u][i].length != INF) {
				if (Dist[i] > Dist[u] + G[u][i].length) {
					Dist[i] = Dist[u] + G[u][i].length;
					Path[i] = u;
					Time[i] = Time[u] + G[u][i].time;
				}
				else if (Dist[i] == Dist[u] + G[u][i].length &&
					Time[i] > Time[u] + G[u][i].time) {
					Path[i] = u;//找到了更短的时间的相同长度路径
					Time[i] = Time[u] + G[u][i].time;
				}
			}
		}
	}
}
void Dijkstrat(int S)
{
	fill(Dist, Dist + N, INF);
	fill(visited, visited + N, false);
	Dist[S] = 0;
	while (1) {
		int u = -1, Mind = INF;
		for (int i = 0;i < N;i++) {
			if (!visited[i] && Dist[i] < Mind) {
				u = i;
				Mind = Dist[i];
			}
		}
		if (u == -1)
			break;
		visited[u] = true;
		for (int i = 0;i < N;i++) {
			if (!visited[i] && G[u][i].time != INF) {
				if (Dist[i] > Dist[u] + G[u][i].time) {
					Dist[i] = Dist[u] + G[u][i].time;
					Path[i] = u;
					Node[i] = Node[u] + 1;
				}
				else if (Dist[i] == Dist[u] + G[u][i].time &&
					Node[i] > Node[u] + 1) {
					Path[i] = u;
					Node[i] = Node[u] + 1;
				}
			}
		}
	}
}
int main()
{
	int V1, V2, way, len, tim;
	scanf("%d %d", &N, &M);
	for (int i = 0;i < 510;i++) {
		for (int j = 0;j < 510;j++) {
			G[i][j].length = INF;
			G[i][j].time = INF;
		}
	}
	for (int i = 0;i < M;i++) {
		scanf("%d %d %d %d %d", &V1, &V2, &way, &len, &tim);
		if (!way) {//way = 0双通 
			G[V1][V2].length = len;
			G[V2][V1].length = len;
			G[V1][V2].time = tim;
			G[V2][V1].time = tim;
		}
		else {//way = 1单通
			G[V1][V2].length = len;
			G[V1][V2].time = tim;
		}
	}
	int s, d, tmpd;
	vector<int>rl ,rt;
	scanf("%d %d", &s, &d);
	Dijkstral(s);
	int Minl = Dist[d];
	tmpd = d;
	rl.push_back(tmpd);
	while (tmpd != s) {
		tmpd = Path[tmpd];
		rl.push_back(tmpd);
	} 
	
	Dijkstrat(s);
	int Mint = Dist[d];
	tmpd = d;
	rt.push_back(tmpd);
	while (tmpd != s) {
		tmpd = Path[tmpd];
		rt.push_back(tmpd);
	}
	//输出结果
	if (rt == rl) {//最短路径一致
		printf("Distance = %d; Time = %d: ", Minl, Mint);
		for (int i = rt.size() - 1;i >= 0;i--) {
			printf("%d", rt[i]);
			if (i != 0)
				printf(" -> ");
		}
	}
	else {//不一致
		printf("Distance = %d: ", Minl);
		for (int i = rl.size() - 1;i >= 0;i--) {
			printf("%d", rl[i]);
			if (i != 0)
				printf(" -> ");
		}
		printf("\n");
		printf("Time = %d: ", Mint);
		for (int i = rt.size() - 1;i >= 0;i--) {
			printf("%d", rt[i]);
			if (i != 0)
				printf(" -> ");
		}
	}
	return 0;
}