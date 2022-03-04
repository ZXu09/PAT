#include<iostream>
#include<vector>
using namespace std;
#define maxn 501
#define INF 0x3f3f3f

int G[maxn][maxn];//邻接矩阵
int Dist[maxn];//存储最短距离
bool visited[maxn] = { false };//是否访问过
vector<int> prenode[maxn];//存储上一个结点
vector<int> path, tmppath;
int CMax, N, Sp, M;
int C[501];//存储每个地点的单车数
int minsend = INF, minback = INF;//最小发送值和最小返回值

void Dijkstra(int S);
void DFS(int vi);

int main()
{
	fill(G[0], G[0] + maxn * maxn, INF);
	cin >> CMax >> N >> Sp >> M;
	int i;
	for (i = 1;i <= N;i++) {
		cin >> C[i];
	}
	int S1, S2, T;
	for (i = 0;i < M;i++) {
		cin >> S1 >> S2 >> T;
		G[S1][S2] = T;
		G[S2][S1] = T;
	}
	Dijkstra(0);
	DFS(Sp);
	printf("%d ", minsend);
	for (int i = path.size() - 1; i >= 0; i--) {
		printf("%d", path[i]);
		if (i)
			printf("->");
	}
	printf(" %d\n", minback);
	return 0;	
}

void Dijkstra(int S)//单源最短路径
{
	fill(Dist, Dist + maxn, INF);
	Dist[S] = 0;
	while (1) {
		int u = -1;//未收录顶点中权值最小
		int mint = INF;
		for (int i = 0;i < N;i++) {
			if (!visited[i] && Dist[i] < mint) {
				mint = Dist[i];
				u = i;
			}
		}
		if (u == -1)//没有找到
			return;
		visited[u] = true;//已经被访问过
		for (int i = 0; i <= N; i++) {
			if (!visited[i] && G[u][i] != INF) {
				if (Dist[u] + G[u][i] < Dist[i]) {
					Dist[i] = Dist[u] + G[u][i];
					prenode[i].clear();
					prenode[i].push_back(u);
				}
				else if (Dist[u] + G[u][i] == Dist[i]) {
					prenode[i].push_back(u);
				}
			}
		}
	}
}

void DFS(int vi)//传入有问题的地点
{
	if (vi == 0) {//此时已经是到了原点了
		tmppath.push_back(0);
		int minsendtmp = 0, minbacktmp = 0;
		for (int i = tmppath.size() - 2; i >= 0; i--) {//不考虑有困难的地点
			int t = tmppath[i];//起始点为有困难的地点前一个
			if (minbacktmp + C[t] < CMax / 2)//判断是否要返回车
				//说明不用返回车，要带过去车
				minsendtmp += CMax / 2 - (minbacktmp + C[t]), minbacktmp = 0;
			else {//要返回车
				if (C[t] > CMax / 2)//多了
					minbacktmp += C[t] - CMax / 2;//多的就要回去的时候带上
				else//少了
					minbacktmp -= CMax / 2 - C[t];//直接减去
			}
		}
		if (minsendtmp < minsend)//更新路径
			path = tmppath, minsend = minsendtmp, minback = minbacktmp;
		else if (minsendtmp == minsend && minbacktmp < minback)
			path = tmppath, minback = minbacktmp;
		tmppath.pop_back();//原点(0)弹出
		return;//此时这一条路径已经走完了
	}
	tmppath.push_back(vi);
	for (int i = 0; i < prenode[vi].size(); i++)//遍历该结点之前的结点
		DFS(prenode[vi][i]);
	tmppath.pop_back();//将vi这个结点弹出
}