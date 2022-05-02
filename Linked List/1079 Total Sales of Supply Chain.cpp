#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
struct Node
{
	int data;
	vector<int>child;
};
vector<Node>v;
int N, K, ID;
double P, r, cnt = 0.0;//cnt 一定要是double类型
void DFS(int index, int depth)
{
	if (v[index].child.size() == 0) {//叶子结点
		cnt += v[index].data * P * pow(1 + r, depth);
		return;
	}
	for (int i = 0;i < v[index].child.size();i++)
		DFS(v[index].child[i], depth + 1);
}
int main()
{
	scanf("%d %lf %lf", &N, &P, &r);
	r /= 100;
	v.resize(N);
	for (int i = 0;i < N;i++) {
		scanf("%d", &K);
		if (!K) {
			scanf("%d", &v[i].data);
		}
		else {
			for (int j = 0;j < K;j++) {
				scanf("%d", &ID);
				v[i].child.push_back(ID);
			}
		}
	}
	DFS(0, 0);
	printf("%.1f", cnt);
	return 0;
}