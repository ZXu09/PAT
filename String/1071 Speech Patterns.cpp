#include<iostream>
#include<string>
#include<cctype>
#include<map>
using namespace std;
int main()
{
	string s, t;
	getline(cin, s);
	map<string, int>m;
	for (int i = 0;i < s.length();i++) {
		s[i] = tolower(s[i]);//统一小写
		if (isalnum(s[i])) {//满足数字字母
			t += s[i];
		}
		if (!isalnum(s[i]) || i == s.length() - 1) {
			if (t.length() != 0)
				m[t]++;//存储出现次数
			t = "";//清空t
		}
	}
	int maxn = 0;
	string a;
	for (auto it = m.begin();it != m.end();it++) {
		if (it->second > maxn) {
			a = it->first;
			maxn = it->second;
		}
	}
	cout << a << " " << maxn;
	return 0;
}