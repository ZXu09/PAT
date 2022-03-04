#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
#define MAXN 10001
vector <int>G[MAXN];
vector <int>p;
int N;
int maxd, maxD = -1;
bool visited[MAXN] = { false };//是否访问过
int in[MAXN];//链接该结点的边数

void DFS(int S, int deep);

int main()
{
	memset(in, 0, sizeof(in));
	cin >> N;
	int S1, S2;
	for (int i = 0;i < N - 1;i++) {
		cin >> S1 >> S2;
		G[S1].push_back(S2);
		G[S2].push_back(S1);
		in[S1]++;
		in[S2]++;
	}
	int cnt = 0;//判断是否连通
	for (int k = 1;k <= N;k++) {
		fill(visited, visited + MAXN, false);//重置访问结点
		maxd = 0;//重置最大深度
		if (k == 1) {
			for (int i = 1;i <= N;i++) {//遍历图
				if (!visited[i]) {
					DFS(i, 1);
					cnt++;
				}
			}
			if (cnt > 1) {//不连通的情况
				printf("Error: %d components", cnt);
				return 0;
			}
		}
		else {
			if (in[k] != 1) {//链接的边数>1，一定不可能是最大深度的起始点
				continue;
			}
			DFS(k, 1);
		}
		if (maxd > maxD) {
			maxD = maxd;
			p.clear();
			p.push_back(k);//存储最大深度的结点
		}
		else if (maxd == maxD) {
			p.push_back(k);
		}
	}
	for (int i = 0;i < p.size();i++) {
		cout << p[i] << endl;
	}

	return 0;
}

void DFS(int S, int deep)//dfs找到最大深度
{
	visited[S] = true;
	//访问S的每个邻接点
	for (int i = 0;i < G[S].size();i++) {
		if (!visited[G[S][i]]) {
			visited[G[S][i]] = true;
			if (deep > maxd) {
				maxd = deep;
			}
			DFS(G[S][i], deep + 1);
		}
	}
}