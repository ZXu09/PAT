#include<iostream>
using namespace std;
#define INF 100000
typedef struct GNode* MGraph;
struct GNode {
	int Nv;//点数
	int Ne;//边数
	int G[501][501];
};

typedef struct ENode* Edge;
struct ENode {
	int V1, V2;
	int Weight;//权重
};
int c1, c2;
int Weight[501] = { 0 };//存储路径权重
int collected[501] = { 0 };//该结点是否被访问
int Dist[501];//最短路径长度
int Num[501] = { 0 };//最短路径的条数
int Gather[501] = { 0 };//最大支援队集结数
MGraph CreateGraph(int N)
{
	MGraph Graph;
	Graph = (MGraph)malloc(sizeof(struct GNode));
	Graph->Ne = 0;
	Graph->Nv = N;
	fill(Graph->G[0], Graph->G[0] + 501 * 501, INF);
	return Graph;
}
void InsertGraph(MGraph Graph, Edge E)
{
	/*插入边<V1,V2>*/
	Graph->G[E->V1][E->V2] = E->Weight;
	/*无向图*/
	Graph->G[E->V2][E->V1] = E->Weight;
}
MGraph BuildGraph()
{
	MGraph Graph;
	Edge E;
	int Nv;
	cin >> Nv;
	Graph = CreateGraph(Nv);
	cin >> Graph->Ne;
	cin >> c1 >> c2;
	for (int i = 0;i < Graph->Nv;i++)
	{
		cin >> Weight[i];
	}
	if (Graph->Ne != 0) {
		for (int i = 0;i < Graph->Ne;i++) {
			E = (Edge)malloc(sizeof(struct ENode));
			cin >> E->V1 >> E->V2 >> E->Weight;
			InsertGraph(Graph, E);
		}
	}
	
	return Graph;
}
void Dijikstra(MGraph Graph)
{
	fill(Dist, Dist + 501, INF);
	Dist[c1] = 0;//起始点
	Gather[c1] = Weight[c1];//在起始点的救援队个数
	Num[c1] = 1;//最短路径的条数1条

	while (1)
	{
		int u = -1, mindist = INF;
		for (int j = 0;j < Graph->Nv;j++) {
			if (collected[j] == 0 && Dist[j] < mindist) {
				mindist = Dist[j];
				u = j;//未收录顶点中Dist最小者
			}
		}
		if (u == -1)//这样的顶点不存在
			break;
		collected[u] = -1;//被访问过了
		for (int j = 0;j < Graph->Nv;j++) {
			if (collected[j] == 0 && Graph->G[u][j] != INF) {//未访问过的邻结点
				if (Dist[j] > Dist[u] + Graph->G[u][j]) {
					Dist[j] = Dist[u] + Graph->G[u][j];//更新最短路径长度
					Num[j] = Num[u];//更新最短路径的条数
					Gather[j] = Gather[u] + Weight[j];//这条路径上的救援队数
				}
				else if (Dist[j] == Dist[u] + Graph->G[u][j]) {
					Num[j] += Num[u];//两种路都可以
					if (Gather[j] < Gather[u] + Weight[j])//此时就要找救援队数量大的
						Gather[j] = Gather[u] + Weight[j];
				}
			}
		}
	}
}
int main()
{
	MGraph Graph;
	Graph = BuildGraph();
	Dijikstra(Graph);
	cout << Num[c2] << " " << Gather[c2];
	return 0;
}