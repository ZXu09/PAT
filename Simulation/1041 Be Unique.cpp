#include<iostream>
using namespace std;
int main()
{
	int num[10010] = {0};
	int input[100010];
	int N, Number;
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> Number;
		num[Number]++;
		input[i] = Number;
	}
	int flag = 0;
	for (int i = 0;i < N;i++) {
		if (num[input[i]] == 1) {
			cout << input[i];
			flag = 1;
			break;
		}
	}
	if (!flag)
		cout << "None";
	return 0;
}