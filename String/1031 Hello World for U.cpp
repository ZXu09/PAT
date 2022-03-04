#include<iostream>
#include<string>
using namespace std;
int main()
{
	string N;
	cin >> N;
	int len = N.size();
	int N1 = 0;
	int N2 = len;
	while (N1 < N2) {
		N1++;
		N2 -= 2;
	}//此时2N1+N2=len
	int l = 0, r = len - 1;
	for (int i = 0;i < N1 - 1;i++) {//打印除最后一行之外的结果
		cout << N[l];
		for (int k = 0;k < N2;k++)
			cout << " ";
		cout << N[r] << endl;
		l++;r--;
	}
	//打印结果
	for (int i = l;i <= r;i++)
		cout << N[i];

	return 0;
}
