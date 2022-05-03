#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int cntp = 0, cnta = 0, cntt = 0;
	for (int i = 0;i < s.length();i++) {
		if (s[i] == 'P')
			cntp++;
		else if (s[i] == 'A')
			cnta += cntp;
		else if (s[i] == 'T') {
			cntt += cnta;
		}
	}
	printf("%d", cntt % 1000000007);
	return 0;
}