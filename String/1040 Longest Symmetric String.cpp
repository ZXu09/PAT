#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string a;
	getline(cin, a);
	int len = a.length();
	int Mlength = 0;
	for (int i = 0;i < len;i++) {
		for (int j = 1;j <= len - i;j++) {
			string a1 = a.substr(i, j);
			string a2 = a1;
			reverse(a2.begin(), a2.end());
			if (a1 == a2 && Mlength < a1.length())
				Mlength = a1.length();
			
		}
	}
	cout << Mlength;
	return 0;
}