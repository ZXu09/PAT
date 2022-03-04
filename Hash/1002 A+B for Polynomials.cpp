#include<iostream>
using namespace std;

#define MAXN 1001
int main()
{
	int K;
	double p[MAXN] = { 0.0 };
	for (int i = 0;i < 2;i++) {
		cin >> K;
		for (int j = 0;j < K;j++) {
			int a;
			double b;
			cin >> a >> b;
			if (p[a] == 0)
				p[a] = b;
			else
				p[a] += b;
		}
	}
	int count = 0;
	for (int i = 0;i < MAXN;i++) {
		if (p[i] != 0)
			count++;
	}
	cout << count;
	for (int i = MAXN-1;i >= 0;i--) {
		if (p[i] != 0)
			printf(" %d %.1f", i, p[i]);
	}
	return 0;
}
