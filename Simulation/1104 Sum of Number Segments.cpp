#include<iostream>
using namespace std;
int main()
{
	int N, cnt = 1;
	double arr[100010];
	scanf("%d", &N);
	for (int i = 0;i < N;i++)
		scanf("%lf", &arr[i]);
	long long r = 0;//double存在精度问题
	for (int i = 0;i < N;i++) {
		r += (long long)(1000 * arr[i]) * (i + 1) * (N - i);
	}
	printf("%.2f\n", r / 1000.0);
	return 0;
}