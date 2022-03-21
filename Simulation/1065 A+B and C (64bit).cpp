#include<iostream>
using namespace std;
int main()
{
	long long int A, B, C;
	int T;
	scanf("%d", &T);
	for (int i = 1;i <= T;i++) {
		scanf("%lld %lld %lld", &A, &B, &C);
		printf("Case #%d: ", i);
		bool flag;
		long long int res = A + B;
		if (A > 0 && B > 0 && res < 0)//正溢出
			flag = true;
		else if (A < 0 && B < 0 && res >= 0)//负溢出-2^63+-2^63溢出是0
			flag = false;
		else if (res > C)
			flag = true;
		else flag = false;
		if (flag)
			printf("true\n");
		else
			printf("false\n");
	}
	return 0;
}