#include<iostream>
#include<string>
using namespace std;
int main() {
	string s1, s2;
	cin >> s1;
	int r = 0;
	for (int i = s1.length() - 1; i >= 0; i--) {
		int a = (s1[i] - '0') * 2 + r;//当前位
		s2 += to_string(a % 10);//存储×2之后的结果(与结果相反)
		r = a / 10;//进位
	}
	if (r != 0)
		s2 += to_string(r);
	int flag = 1;
	int arr1[10] = { 0 }, arr2[10] = {0};//存储每个数字出现的次数
	for (int i = 0; i < s1.length(); i++)
		arr1[s1[i] - '0']++;
	for (int i = 0; i < s2.length(); i++)
		arr2[s2[i] - '0']++;
	for (int i = 0; i < 10; i++) {
		if (arr1[i] != arr2[i]) {
			flag = 0; //表示不一样
			break;
		}
	}
	if (flag)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	for (int i = s2.length() - 1; i >= 0; i--)
		cout << s2[i];
	return 0;
}
