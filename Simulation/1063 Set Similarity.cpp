#include<iostream>
#include<set>
#include<vector>
using namespace std;
int main()
{
	int N, M, K, tmp;
	cin >> N;
	vector<set<int>>v(N);
	for (int i = 0;i < N;i++) {
		cin >> M;
		set<int>s;//递增+无重复元素
		for (int j = 0;j < M;j++) {
			cin >> tmp;
			s.insert(tmp);
		}
		v[i] = s;
	}
	cin >> K;
	int a, b;
	for (int i = 0;i < K;i++) {
		cin >> a >> b;
		int Nc = 0, Nt = v[b - 1].size();
		for (auto it = v[a - 1].begin();it != v[a - 1].end(); it++) {
			if (v[b - 1].find(*it) != v[b - 1].end())
				Nc++;//有重复的
			else
				Nt++;//无重复的
		}
		printf("%.1f%%\n", (double)Nc / Nt * 100);
	}
	
	return 0;
}