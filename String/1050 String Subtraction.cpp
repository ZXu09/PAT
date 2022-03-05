#include<iostream>
#include<string>
using namespace std;
int main()
{
	string S1, S2;
	getline(cin, S1);
	getline(cin, S2);
	for (int i = 0;i < S2.size();i++) {
		while (S1.find(S2[i]) != -1) {
			S1.erase(S1.find(S2[i]), 1);
		}
	}
	cout << S1 <<endl;
	return 0;
}