#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	int N;
	int Num[100010];
	scanf("%d", &N);
	for (int i = 0;i < N;i++)
		scanf("%d", &Num[i]);
	sort(Num, Num + N, cmp);
	int n1, s, suma = 0, sumb = 0;
	if (N % 2 == 0) {
		printf("0 ");
		n1 = N / 2;
	}
	else {
		printf("1 ");
		n1 = N / 2 + 1;
	}
	for (int i = 0;i < n1;i++) {
		suma += Num[i];
	}
	for (int i = n1;i < N;i++) {
		sumb += Num[i];
	}
	printf("%d", suma - sumb);
	return 0;
}