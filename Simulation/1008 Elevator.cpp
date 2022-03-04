#include<iostream>
using namespace std;
int main()
{
	int N;
	cin >> N;
	int Num, BNum = 0, Sum = 0;
	for (int i = 0;i < N;i++) {
		cin >> Num;
		if (Num > BNum) {
			Sum += (Num - BNum) * 6 + 5;
		}
		if (Num < BNum) {
			Sum += (BNum - Num) * 4 + 5;
		}
		if (Num == BNum) {
			Sum += 5;
		}
		BNum = Num;
	}
	cout << Sum << endl;
	return 0;
}