#include<iostream>
#include<vector>
using namespace std;
#define INF 0x3f3f3f
#define maxn 501
struct Graph
{
	int distance;
	int cost;
}G[maxn][maxn];
int Dist[maxn];
bool visited[maxn] = { false };
vector<int>prenode[maxn];
vector<int>tmppath, path;
int N, M, S, D;
int MINcost = INF;

void Dijikstra(int S);
void DFS(int D);

int main()
{
	for (int i = 0;i < maxn;i++) {
		for (int j = 0;j < maxn;j++) {
			G[i][j].cost = G[i][j].distance = INF;
		}
	}
	int C1, C2;
	cin >> N >> M >> S >> D;
	for (int i = 0;i < M;i++) {
		cin >> C1 >> C2;
		cin >> G[C1][C2].distance >> G[C1][C2].cost;
		G[C2][C1].distance = G[C1][C2].distance;
		G[C2][C1].cost = G[C1][C2].cost;
	}

	Dijikstra(S);
	DFS(D);

	for (int i = path.size() - 1;i >= 0;i--) {
		cout << path[i] << " ";
	}
	cout << Dist[D] << " " << MINcost;
	return 0;
}

void Dijikstra(int S)
{
	fill(Dist, Dist + N, INF);
	Dist[S] = 0;
	
	while (1){
		int u = -1, minD = INF;
		for (int i = 0;i < N;i++) {
			if (!visited[i] && Dist[i] < minD) {
				u = i;
				minD = Dist[i];
			}
		}
		if (u == -1)
			return;
		visited[u] = true;
		for (int i = 0;i < N;i++) {
			if (!visited[i] && G[u][i].distance != INF) {
				if (Dist[u] + G[u][i].distance < Dist[i]) {
					Dist[i] = Dist[u] + G[u][i].distance;
					prenode[i].clear();
					prenode[i].push_back(u);
				}
				else if(Dist[i] == Dist[u] + G[u][i].distance)
					prenode[i].push_back(u);
			}
		}
	}
}

void DFS(int D)
{
	if (D == S) {
		tmppath.push_back(S);
		int cost = 0;
		for (int i = 0;i < tmppath.size() - 1;i++) {
			cost += G[tmppath[i]][tmppath[i + 1]].cost;
		}
		if (cost < MINcost) {
			path = tmppath;
			MINcost = cost;
		}
		tmppath.pop_back();
	}
	tmppath.push_back(D);
	for (int i = 0;i < prenode[D].size();i++) {
		DFS(prenode[D][i]);
	}
	tmppath.pop_back();
}