#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;
#define INF 0x3f3f3f

int G[210][210];
bool collected[210] = { false };
int Dist[201];
int N, K, cnt = 0;
vector<int>prenode[210];
vector<int>tmppath, path;
int Hap[210];

void Dijkstra(int S)
{
	fill(Dist, Dist + N, INF);
	Dist[S] = 0;
	while (1){
		//找与S相邻的最小的值
		int minD = INF, u = -1;
		for (int i = 0;i < N;i++) {
			if (!collected[i]&& Dist[i] < minD) {
				u = i;
				minD = Dist[i];
			}
		}
		if (u == -1)
			return;
		collected[u] = true;
		for (int i = 0;i < N;i++) {
			if (!collected[i] && G[u][i] != INF) {
				if (Dist[u] + G[u][i] < Dist[i]) {
					Dist[i] = Dist[u] + G[u][i];
					prenode[i].clear();
					prenode[i].push_back(u);//表示i结点之前的结点是u
				}
				else if (Dist[u] + G[u][i] == Dist[i]) {
					prenode[i].push_back(u);
				}
			}
		}
	}
}

int routes = 0, max_hap = 0, hap;
void DFS(int D)
{
	if (D == 0) {//说明回到了起始点
		tmppath.push_back(0);
		routes++;
		hap = 0;//初始化hap
		for (int i = 0;i < tmppath.size() - 1;i++) {
			hap += Hap[tmppath[i]];
		}
		if (hap > max_hap) {
			max_hap = hap;
			path = tmppath;
		}
		tmppath.pop_back();
	}
	tmppath.push_back(D);
	for (int i = 0;i < prenode[D].size();i++) {
		DFS(prenode[D][i]);
	}
	tmppath.pop_back();//表明这一条路到底了
}
int main()
{

	string name, name1, name2;
	string city[210];
	map<string, int>mp;
	int s1, s2, dis;

	scanf("%d %d", &N, &K);
	cin >> name;
	city[cnt] = name;
	mp[name] = cnt++;

	for (int i = 0;i < N - 1;i++) {
		cin >> name1;
		cin >> Hap[cnt];
		city[cnt] = name1;
		mp[name1] = cnt++;
	}

	fill(G[0], G[0] + 210 * 210, INF);
	for (int i = 0;i < K;i++) {
		cin >> name >> name2 >> dis;
		s1 = mp[name], s2 = mp[name2];
		G[s1][s2] = dis;
		G[s2][s1] = dis;
	}

	Dijkstra(0);
	DFS(mp["ROM"]);

	printf("%d %d %d %d\n", routes, Dist[mp["ROM"]], max_hap, max_hap / (path.size() - 1));
	for (int i = path.size() - 1;i >= 0;i--) {
		if (i)
			cout << city[path[i]] << "->";
		else cout << city[path[i]];
	}
	return 0;
}