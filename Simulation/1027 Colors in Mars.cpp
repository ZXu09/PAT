#include<iostream>
using namespace std;

char c[14] = { "0123456789ABC" };
int main()
{
	int num;
	cout << "#";
	for (int i = 0;i < 3;i++) {
		cin >> num;
		cout << c[num / 13] << c[num % 13];
	}
	return 0;
}