#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>v[1010];//代表每种爱好对应的人
vector<int>s[1010];//代表每个人对应的爱好
bool visited[1010] = { false };
int cnt;
void DFS(int S)//用人来遍历
{
	cnt++;
	visited[S] = true;
	for (int i = 0;i < s[S].size();i++) {//s[S][i]代表爱好v[s[S][i]][j]代表人
		for (int j = 0;j < v[s[S][i]].size();j++) {
			if (!visited[v[s[S][i]][j]])
				DFS(v[s[S][i]][j]);
		}
	}
}
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	int N, K, h;

	scanf("%d", &N);
	for (int i = 0;i < N;i++) {
		scanf("%d: ", &K);
		for (int j = 0;j < K;j++) {
			scanf("%d", &h);
			v[h].push_back(i);
			s[i].push_back(h);
		}
	}
	vector<int>ans;
	for (int i = 0;i < N;i++) {
		if (!visited[i]) {
			cnt = 0;
			DFS(i);
			ans.push_back(cnt);
		}
	}
	sort(ans.begin(), ans.end(), cmp);
	printf("%d\n", ans.size());
	for (int i = 0;i < ans.size();i++) {
		if (!i)
			printf("%d", ans[i]);
		else printf(" %d", ans[i]);
	}
	return 0;
}