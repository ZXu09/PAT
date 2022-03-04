#include<iostream>
using namespace std;

int main()
{
	int K, i, j;
	double p[1001] = { 0.0 };//存储第一次输入
	double r[2001] = { 0.0 };//存储结果
	cin >> K;
	int a;
	double b;
	for (i = 0;i < K;i++) {
		cin >> a >> b;
		p[a] = b;
	}
	cin >> K;
	for (i = 0;i < K;i++) {
		cin >> a >> b;
		for (j = 0;j < 1001;j++) {
			if (p[j] != 0) {
				if (r[j + a] == 0)
					r[j + a] = p[j] * b;
				else
					r[j + a] += p[j] * b;
			}
		}
	}
	//输出多项式
	int cnt = 0;
	for (i = 0;i < 2001;i++) {
		if (r[i] != 0)
			cnt++;
	}
	cout << cnt;
	for (i = 2000;i >= 0;i--) {
		if (r[i] != 0)
			printf(" %d %.1f", i, r[i]);
	}
	return 0;
}