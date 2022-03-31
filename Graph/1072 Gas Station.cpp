#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

#define INF 0x3f3f3f
int G[1020][1020];
bool collected[1020] = {false};
int Dis[1020];
int N, M, K, Ds;
struct Node
{
	float Min;
	float Ave;
	bool flag = false;//是否超过了服务距离
	int i;//加油站的名称
}arr[11];
bool cmp(Node a, Node b)
{
	if (a.Min == b.Min) {
		if (a.Ave == b.Ave) {
			return a.i < b.i;
		}
		else
			return a.Ave < b.Ave;
	}
	else {
		return a.Min > b.Min;
	}
}
void Dijkstra(int S)
{
	//重置数组
	fill(Dis, Dis + N+M +1, INF);
	fill(collected, collected + N + M + 1, false);
	Dis[S] = 0;
	while (1){
		int u = -1, minD = INF;
		for (int i = 1;i <= N + M;i++){
			if (!collected[i] && Dis[i] < minD) {
				u = i;
				minD = Dis[i];
			}
		}
		if (u == -1)
			return;
		collected[u] = true;//该结点已经被访问过了
		for (int i = 1;i <= N + M;i++) {
			if (!collected[i] && G[u][i] != INF) {//
				if (Dis[u] + G[u][i] < Dis[i]) {//更新最短路径
					Dis[i] = G[u][i] + Dis[u];
				}
			}
		}
	}
}
int main()
{
	fill(G[0], G[0] + 1020 * 1020, INF);
	scanf("%d %d %d %d", &N, &M, &K, &Ds);
	string P1, P2;
	int Dist,s1,s2;
	for (int i = 0;i < K;i++) {
		cin >> P1 >> P2;
		if (P1[0] != 'G')
			s1 = atoi(P1.c_str());
		else {
			if(P1.size() == 3)//G10的情况
				s1 = N + (P1[1] - '0')*10+ P1[2] - '0';
			else s1 = N + P1[1] - '0';
		}
		if (P2[0] != 'G')
			s2 = atoi(P2.c_str());
		else {
			if (P2.size() == 3)//G10的情况
				s2 = N + (P2[1] - '0') * 10 + P2[2] - '0';
			else s2 = N + P2[1] - '0';
		} 

		scanf("%d", &Dist);
		G[s1][s2] = Dist;
		G[s2][s1] = Dist;
	}
	int cnt = 0;
	//最大的Min，相同则最小的Ave，相同则最小的号码
	for (int i = N + 1;i <= N + M;i++) {
		Dijkstra(i);
		float Min = INF, Sum = 0;
		for (int j = 1;j <= N;j++) {
			if (Dis[j] < Min)
				Min = Dis[j];
			if (Dis[j] > Ds)
				arr[cnt].flag = true;//不满足了
			Sum += Dis[j];
		}
		float Ave = (float)Sum / N;
		arr[cnt].Min = Min;
		arr[cnt].Ave = Ave;
		arr[cnt++].i = i - N;
	}
	sort(arr, arr + cnt, cmp);
	bool flag = false;
	for (int i = 0;i < cnt;i++) {
		if (!arr[i].flag) {
			flag = true;
			cout << 'G' << arr[i].i << endl;
			printf("%.1f %.1f\n", arr[i].Min, arr[i].Ave);
			//%.1f会自动执行四舍五入的操作,3.25->3.2,3.26->3.3
			break;
		}
	}
	if (!flag)
		printf("No Solution\n");
	return 0;
}