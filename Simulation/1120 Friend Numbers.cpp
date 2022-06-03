#include<iostream>
#include<set>
using namespace std;
int Sum(int num)
{
	int sum = 0;
	while (num > 0) {
		sum += num % 10;
		num /= 10;
	}
	return sum;
}
int main()
{
	int N, num;
	set<int>s;
	scanf("%d", &N);
	for (int i = 0;i < N;i++) {
		scanf("%d", &num);
		s.insert(Sum(num));
	}
	printf("%d\n", s.size());
	for (auto it = s.begin();it != s.end();it++) {
		if (it != s.begin())
			printf(" ");
		printf("%d", *it);
	}
	return 0;

}