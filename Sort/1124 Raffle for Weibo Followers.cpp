#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
int main()
{
	int M, N, S, cnt = 0;
	vector<string>v;
	map<string, bool>m;
	bool flag = false;
	string s;
	scanf("%d %d %d", &M, &N, &S);
	for (int i = 0;i < M;i++) {
		cin >> s;
		if (i == S - 1) {//起始位置
			cnt = 0;
			flag = true;
			v.push_back(s);
			m[s] = true;//表明这个元素已经入队
		}
		if (cnt >= N && m.find(s)==m.end()) {//保证这个人没被抽中过
			cnt = 0;
			v.push_back(s);
			m[s] = true;
		}
		if (flag) {
			cnt++;
		}
	}
	if (!v.size())
		printf("Keep going...\n");
	for (int i = 0;i < v.size();i++)
		cout << v[i] << endl;
	return 0;
}