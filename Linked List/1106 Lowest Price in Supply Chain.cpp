#include<iostream>
#include<vector>
#include<cmath>
#define INF 0x3f3f3f
using namespace std;
vector<int>v[100010];
int maxdeep = INF, cnt = 1;//记录深度和个数
void DFS(int S, int deep)
{
	if (v[S].size() == 0) {//零售商
		if (deep < maxdeep) {
			cnt = 1;
			maxdeep = deep;
		}
		else if (deep == maxdeep)
			cnt++;
		return;
	}
	for (int i = 0;i < v[S].size();i++) {
		DFS(v[S][i], deep + 1);
	}
}
int main()
{
	int N, K, tmp;
	double r, P;
	scanf("%d %lf %lf", &N, &P, &r);
	r /= 100;
	for (int i = 0;i < N;i++) {
		scanf("%d", &K);
		for (int j = 0;j < K;j++) {
			scanf("%d", &tmp);
			v[i].push_back(tmp);
		}
	}
	DFS(0, 0);
	double result = P * pow(1 + r, maxdeep);
	printf("%.4lf %d", result, cnt);
	return 0;
}