#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	int cnt = 0;
	bool visited[1010] = { false };
	for (int i = 0;i < s2.length();i++) {
		for (int j = 0;j < s1.length();j++) {
			if (s1[j] == s2[i] && !visited[j]) {
				visited[j] = true;
				cnt++;
				break;
			}
		}
	}
	if (cnt == s2.length()) {
		printf("Yes %d\n", s1.length() - cnt);
	}
	else printf("No %d\n", s2.length() - cnt);
	return 0;
}