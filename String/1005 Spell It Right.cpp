#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int Sum = 0, LenN, LenS;
	char Num[101];
	char Result[101];

	string print1[10] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
	cin >> Num;
	LenN = strlen(Num);
	for (int i = 0;i < LenN;i++) {
		Sum += (Num[i]-'0');
	}
	//输出结果
	sprintf_s(Result, 101, "%d", Sum);
	int flag = 0;//控制格式
	LenS = strlen(Result);
	for (int i = 0;i < LenS;i++) {
		if (flag == 0) {
			flag = 1;
		}
		else
			cout << " ";
		cout << print1[Result[i] - '0'];
	}
	return 0;
}