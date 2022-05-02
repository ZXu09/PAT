#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int length = 0, num = 0;//num设置为0，只有一个结点的情况
bool collected[100010] = { false };
vector<int>v[100010];

void DFS(int S, int deep)
{
	if (v[S].size() == 0) {
		if (deep > length) {
			num = 1;
			length = deep;
		}
		else if (deep == length) {
			num++;
		}
	}
	for (int i = 0;i < v[S].size();i++) {
		DFS(v[S][i], deep + 1);
	}
	
}
int main()
{
	int N, root, temp;
	int chain[100010];
	double P, r;
	scanf("%d %lf %lf", &N, &P, &r);
	for (int i = 0;i < N;i++){
		scanf("%d", &temp);
		if (temp != -1) {
			v[temp].push_back(i);
		}
		else root = i;
	}
	//DFS
	DFS(root, 0);
	float price = P * pow(1 + r, length);
	printf("%.2f %d\n", P * pow(1 + r / 100, length), num);

	return 0;
}