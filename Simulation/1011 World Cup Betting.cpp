#include<iostream>
using namespace std;

float max(float a, float b, float c)
{
	return a > b ? (a > c ? a : c) : (b > c ? b : c);
}
int main()
{
	float A[3][3];//存储3个队伍胜利的几率
	float a[3];//存储利润最大
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			cin >> A[i][j];
		}
	}
	for (int i = 0;i < 3;i++) {
		if (max(A[i][0], A[i][1], A[i][2]) == A[i][0]) {
			cout << "W" << " ";
			a[i] = A[i][0];
		}
		else if (max(A[i][0], A[i][1], A[i][2]) == A[i][1]) {
			cout << "T" << " ";
			a[i] = A[i][1];
		}
		else {
			cout << "L" << " ";
			a[i] = A[i][2];
		}	
	}
	float res = (a[0] * a[1] * a[2] * 0.65 - 1) * 2;
	printf("%.2f", res);
	return 0;
}