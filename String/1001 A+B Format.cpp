#include<iostream>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	char ans[8];//存放数据字符串类型
	sprintf_s(ans, sizeof(ans), "%d", a + b);
	int len = strlen(ans);
	for (int i = 0;i < len;i++) {
		cout << ans[i];
		if (ans[i] != '-' && (i != len - 1) && (len - i - 1) % 3 == 0) 
			cout << ",";//后面剩下3n个数时 要加',' 
	}
	return 0;
}
