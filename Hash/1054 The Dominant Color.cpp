#include<iostream>
#include<map>
using namespace std;
int main()
{
	map<int, int>m;
	int M, N;
	cin >> M >> N;
	int Max = -1, MaxID = -1;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			int tmp;
			cin >> tmp;
			m[tmp]++;
			if (m[tmp] > Max) {
				Max = m[tmp];
				MaxID = tmp;
			}
		}
	}
	cout << MaxID;
	return 0;
}