#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int N;
	long long int p;
	int a[100010];
	scanf("%d %lld", &N, &p);
	for (int i = 0;i < N;i++)
		scanf("%d", &a[i]);
	sort(a, a + N);
	int length = 0, temp = 0;
	for (int i = 0;i < N;i++) {
		for (int j = i + length; j < N;j++) {
			if (a[j] <= a[i] * p) {//有一个long long 就自动转换
				temp = j - i + 1;
				if (temp > length)
					length = temp;
			}
			else break;
		}
	}
	printf("%d\n", length);
	return 0;
}
