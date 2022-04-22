#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int N)
{
	if (N <= 1)
		return false;
	for (int i = 2;i <= sqrt(N);i++) {
		if (N % i == 0)
			return false;
	}
	return true;
}
int main()
{
	int a[10010] = {0};
	int M, N, key;
	scanf("%d %d", &M, &N);
	while (!isPrime(M))
		M++;
	for (int i = 0;i < N;i++) {
		scanf("%d", &key);
		if (!i) {
			printf("%d", key % M);
			a[key % M]++;
		}
		else {
			if (a[key % M] == 0) {
				printf(" %d", key % M);
				a[key % M]++;
			}
			else {
				int j;
				for (j = 1;j < M;j++) {
					int tmp = (key + j * j) % M;
					if (a[tmp] == 0) {
						printf(" %d", tmp);
						a[tmp]++;
						break;
					}
				}
				if (j == M)
					printf(" -");
			}
		}
	}
	return 0;
}