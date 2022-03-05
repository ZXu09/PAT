#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
vector <int>course[2510];
char name[40010][5];
bool cmp(int a, int b)
{
	return strcmp(name[a], name[b]) < 0;//按字典顺序排序
}
int main()
{
	int N, M, C, K;
	cin >> N >> K;
	for (int i = 0;i < N;i++) {
		scanf("%s %d", name[i], &C);//i代表这个同学的姓名在name中存储的位置
		for (int j = 0;j < C;j++) {
			scanf("%d", &M);
			course[M].push_back(i);
		}
	}
	for (int i = 1;i <= K;i++) {
		printf("%d %d\n", i, course[i].size());
		sort(course[i].begin(), course[i].end(), cmp);
		for (int j = 0;j < course[i].size();j++) {
			printf("%s\n", name[course[i][j]]);
		}
	}
	return 0;
}