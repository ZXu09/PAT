#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Node {
	int weight;
	vector <int>next;
}Array[101];
vector<int>v;
vector<vector<int>> ans;//存放所有路径
int N, M, S;
bool cmp(vector<int> v1, vector<int> v2) {
	return v1 > v2;
}
void DFS(int index, int sum)//遍历第index个结点的结点
{
	if (sum == S) {
		if (Array[index].next.size() != 0)//非叶子结点，直接返回
			return;
		ans.push_back(v);
		return;
	}
	if (sum > S)
		return;//这条路径找不到了
	for (int i = 0;i < Array[index].next.size();i++) {
		v.push_back(Array[Array[index].next[i]].weight);//需要的是权重
		DFS(Array[index].next[i], sum + Array[Array[index].next[i]].weight);//权重增加
		v.pop_back();
	}
}
int main()
{
	cin >> N >> M >> S;
	for (int i = 0;i < N;i++)
		cin >> Array[i].weight;
	int ID, IDS, K;
	for (int i = 0;i < M;i++) {
		cin >> ID >> K;
		for (int j = 0;j < K;j++) {
			cin >> IDS;
			Array[ID].next.push_back(IDS);
		}
	}
	v.push_back(Array[0].weight);//根结点
	DFS(0, Array[0].weight);
	//对每种情况按字典序从大到小排序
	//sort(ans.begin(), ans.end(), greater<vector<int>>());
	sort(ans.begin(), ans.end(), cmp);
	for (int i = 0; i < ans.size(); i++) {
		printf("%d", ans[i][0]);
		for (int j = 1; j < ans[i].size(); j++) {
			printf(" %d", ans[i][j]);
		}
		printf("\n");
	}

	return 0;
}