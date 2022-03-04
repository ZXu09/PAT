#include<iostream>
#include<vector>
using namespace std;

vector<int>Graph[1001];
bool collected[1001];
int N, M, K;
int city1, city2, lost_city;

void DFS(int S);

int main()
{
	cin >> N >> M >> K;
	int i, j;
	for (i = 0;i < M;i++) {
		cin >> city1 >> city2;
		Graph[city1].push_back(city2);//尾插
		Graph[city2].push_back(city1);
	}
	for (i = 0;i < K;i++) {
		int count = 0;
		fill(collected + 1, collected + N + 1, false);//重置数组，均未访问过
		cin >> lost_city;
		for (j = 1;j <= N;j++) {
			if (j != lost_city && !collected[j]) {
				DFS(j);
				count++;
			}
		}
		cout << count - 1 << endl;
	}
	return 0;
}

void DFS(int S)
{
	collected[S] = true;
	for (int i = 0;i < Graph[S].size();i++) {//对于S的邻接点
		int V = Graph[S][i];
		if (!collected[V] && V != lost_city)
			DFS(V);
	}
}