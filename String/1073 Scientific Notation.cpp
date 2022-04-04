#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a, b="";
	cin >> a;
	int i = 0, cnt = 0;
	
	while (a[i] != 'E') {
		if (a[i] >= '0' && a[i] <= '9') {
			b += a[i];
			cnt++;//记录有几位数字
		}
		i++;
	}
	//此时a[i]=='E'
	string s;
	i++;
	if (a[i] == '+') {
		i++;
		for (;i < a.size();i++) {
			s += a[i];
		}
		int len = atoi(s.c_str());
		if (len >= cnt - 1)
			b.insert(b.end(), len - cnt + 1, '0');//结尾的地方插入
		else
			b.insert(cnt - len + 1, 1, '.');
	}
	else if (a[i] == '-') {
		i++;
		for (;i < a.size();i++) {
			s += a[i];
		}
		int len = atoi(s.c_str());
		b.insert(0, len, '0');//开始的地方插入
		b.insert(1, 1, '.');//插入小数点
	}
	if (a[0] == '-')
		printf("-");

	cout << b;

	return 0;
}