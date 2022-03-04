#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
vector<string> v;

int flag = 0;
bool cmp(string a, string b)
{
	return a + b < b + a;
}
void print(string s)
{
	int i;
	for (i = 0; i < s.size(); i++) {
		if (s[i] != '0') break;
	}
	for (; i < s.size(); i++) {
		cout << s[i];
		flag = 1; //到了第一个不为0的位置
	}
}

int main()
{
	int N;
	cin >> N;
	string a;
	for (int i = 0;i < N;i++) {
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) {
		if (!flag) print(v[i]);
		else cout << v[i];
	}
	if (!flag) cout << "0";//全为0的情况
	return 0;
}