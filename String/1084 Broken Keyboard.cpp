#include<iostream>
using namespace std;
int main()
{
	string letter = { "abcdefghijklmnopqrstuvwxyz"};
	string s1, s2, t;
	cin >> s1 >> s2;
	for (int i = 0;i < s1.length();i++) {
		if (s2.find(s1[i]) == -1 && t.find(s1[i]) == -1) {//缺失的元素且未存储
			if (letter.find(s1[i]) != -1) {//是小写英文字母的情况
				if (t.find(s1[i] - 32) != -1)//已经存过了它的大写
					continue;
				t += s1[i] - 32;//存大写英文字母
			}
			else t += s1[i];
		}
	}
	cout << t << endl;
	return 0;
}