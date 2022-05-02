#include<iostream>
#include<cmath>
using namespace std;
long long gcd(long long int a, long long int b)
{
	return b == 0 ? abs(a) : gcd(b, a % b);
}
long long int a1, b1, a2, b2;

void printn2(long long int a2, long long int b2)
{
	if (a2 < 0) {
		printf("(");
		if (abs(a2) >= b2) {
			if (a2 % b2 != 0)
				printf("%lld %lld/%lld", a2 / b2, abs(a2) % b2, b2);//分数+整数
			else printf("%lld", a2 / b2);//整数
		}
		else printf("%lld/%lld", a2, b2);//分数
		printf(")");
	}
	else {//a2>=0
		if (a2 >= b2) {
			if (a2 % b2 != 0)
				printf("%lld %lld/%lld", a2 / b2, a2 % b2, b2);//分数+整数
			else printf("%lld", a2 / b2);//整数
		}
		else if (a2 == 0)//0的情况单独考虑
			printf("0");
		else
			printf("%lld/%lld", a2, b2);//分数
	}
}
void sum()
{
	if (b1 < 0) {
		a1 = -a1;
		b1 = -b1;
	}
	printn2(a1, b1);
	printf(" + ");
	printn2(a2, b2);
	long long int suma = a1 * b2 + a2 * b1;
	long long int sumb = b1 * b2;
	long long int gcdvalue = gcd(suma, sumb);
	suma = suma / gcdvalue;
	sumb = sumb / gcdvalue;
	printf(" = ");
	printn2(suma, sumb);
	printf("\n");
}

void difference()
{
	if (b1 < 0) {
		a1 = -a1;
		b1 = -b1;
	}
	printn2(a1, b1);
	printf(" - ");
	printn2(a2, b2);
	long long int suma = a1 * b2 - a2 * b1;
	long long int sumb = b1 * b2;
	long long int gcdvalue = gcd(suma, sumb);
	suma = suma / gcdvalue;
	sumb = sumb / gcdvalue;
	printf(" = ");
	printn2(suma, sumb);
	printf("\n");
}
void product()
{
	if (b1 < 0) {
		a1 = -a1;
		b1 = -b1;
	}
	printn2(a1, b1);
	printf(" * ");
	printn2(a2, b2);
	long long int suma = a1 * a2;
	long long int sumb = b1 * b2;
	long long int gcdvalue = gcd(suma, sumb);
	suma = suma / gcdvalue;
	sumb = sumb / gcdvalue;
	printf(" = ");
	printn2(suma, sumb);
	printf("\n");
}

void quotient()
{
	if (b1 < 0) {
		a1 = -a1;
		b1 = -b1;
	}
	printn2(a1, b1);
	printf(" / ");
	printn2(a2, b2);
	long long int suma = a1 * b2;
	long long int sumb = b1 * a2;
	long long int gcdvalue = gcd(suma, sumb);
	if (gcdvalue) {
		suma = suma / gcdvalue;
		sumb = sumb / gcdvalue;
	}

	if (sumb == 0) {
		printf(" = Inf\n");
		return;
	}
	if (sumb < 0) {
		sumb = -sumb;
		suma = -suma;
	}
	printf(" = ");
	printn2(suma, sumb);
	printf("\n");
}
int main()
{
	long long int gcdvalue;
	scanf("%lld/%lld", &a1, &b1);
	gcdvalue = gcd(a1, b1);
	a1 = a1 / gcdvalue;
	b1 = b1 / gcdvalue;
	scanf("%lld/%lld", &a2, &b2);
	gcdvalue = gcd(a2, b2);
	a2 = a2 / gcdvalue;
	b2 = b2 / gcdvalue;

	sum();
	difference();
	product();
	quotient();

	return 0;
}