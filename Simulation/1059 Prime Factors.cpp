#include<iostream>
#include<cmath>
using namespace std;
struct node {
	int data;
	int exp = 1;
}Array[100010];
bool isprime(int a)
{
	if (a == 2)
		return true;
	for (int i = 2;i <= sqrt(a);i++) {
		if (a % i == 0)
			return false;
	}
	return true;
}
int main()
{
	long int N;
	cin >> N;
	long int N1 = N;
	int cnt = 0;
	for (int i = 2;i <= N;i++) {
		while (isprime(i) && N % i == 0) {
			if (Array[cnt].data != i) {
				Array[++cnt].data = i;
			}
			else {
				Array[cnt].exp++;
			}
			N /= i;
		}
	}
	cout << N1 << "=";
	if (N1 == 1)
		cout << 1;
	for (int i = 1;i <= cnt;i++) {
		if (Array[i].exp != 1) {
			if (i==1)
				cout << Array[i].data << "^" << Array[i].exp;
			else {
				cout<<"*" << Array[i].data << "^" << Array[i].exp;
			}
		}
		else {
			if (i==1)
				cout << Array[i].data;
			else {
				cout << "*" << Array[i].data;
			}
		}
	}
	return 0;
}