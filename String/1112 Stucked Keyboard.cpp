#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
	int K;
	string s, r, t;
	map<char, bool>m;
	int cnt = 0;//为map计数
	scanf("%d", &K);
	cin >> s;
	//判断哪些字母属于stucked
	int i = 0;
	while(i < s.size()) {
		bool flag = true;
		if ((i + K) <= s.size()) {//有可能是
			for (int j = i;j < i + K;j++) {
				if (s[j] != s[i]) {
					flag = false;
					break;
				}
			}
		}
		else//剩余长度都不够了，肯定不是
			flag = false;
		
		if (flag) {//该字符目前是stucked
			if (m.find(s[i]) != m.end()) {//判断该字符之前是不是stucked
				if (m[s[i]] == true) {//之前是
					if (r.find(s[i]) == -1)//没有存储过的情况
						r += s[i];
				}
			}
			else {//该字符第一次出现
				m[s[i]] = true;
				if (r.find(s[i]) == -1)
					r += s[i];
			}
			i += K;
		}
		else {//该字符不stucked
			m[s[i]] = false;
			while (r.find(s[i]) != -1)//删除该元素
				r.erase(r.find(s[i]));
			i++;
		}
	}
	//从原本的字符串中进行调整
	i = 0;
	while (i < s.size()) {
		if (r.find(s[i]) == -1) {
			t += s[i];
			i++;
		}
		else {//要进行修改的元素
			t += s[i];
			i += K;
		}
	}
	cout << r << endl;
	cout << t << endl;
	return 0;
}