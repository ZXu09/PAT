#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct Node
{
	int Ge;
	int Gi;
	int App[6];
	int list;
}s[40010];
bool cmp(Node a, Node b)
{
	if (a.Ge + a.Gi != b.Ge + b.Gi)
		return a.Ge + a.Gi > b.Ge + b.Gi;
	else return a.Ge > b.Ge;
}
int main()
{
	
	int N, M, K;
	int school[110] = {0};
	scanf("%d %d %d", &N, &M, &K);
	vector<vector<int>>v(M);//M×M的二维数组
	for (int i = 0;i < M;i++)
		scanf("%d", &school[i]);
	for (int i = 0;i < N;i++) {
		scanf("%d %d", &s[i].Ge, &s[i].Gi);
		s[i].list = i;//原始次序
		for (int j = 0;j < K;j++) {
			scanf("%d", &s[i].App[j]);
		}
	}
	sort(s, s + N, cmp);
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < K;j++) {
			if (v[s[i].App[j]].size() < school[s[i].App[j]]) {
				v[s[i].App[j]].push_back(s[i].list);
				break;
			}
			//当前学校人满了,看满不满足共同录用的条件
			else if (s[i].Ge + s[i].Gi == s[i - 1].Ge + s[i - 1].Gi && s[i].Ge == s[i - 1].Ge &&
				v[s[i].App[j]][v[s[i].App[j]].size() - 1] == s[i - 1].list) {
				v[s[i].App[j]].push_back(s[i].list);
				break;
			}

		}
	}
	//排序
	for (auto it = v.begin();it != v.end();it++) {
		sort(it->begin(),it->end());
	}
	//输出
	for (int i = 0;i < M;i++) {
		for (int j = 0;j < v[i].size();j++) {
			if (!j)
				printf("%d", v[i][j]);
			else printf(" %d", v[i][j]);
		}
		printf("\n");
	}
	return 0;
}