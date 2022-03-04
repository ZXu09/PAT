#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int M;
	cin >> M;
	int Time_In = 24 * 60 * 60;//初始化进入时间
	int Time_Out = 0;//初始化离开时间
	char ID_IN[16];
	char ID_OUT[16];
	int H1, H2, H3, O1, O2, O3;
	while (M--) {
		char ID[16];
		cin >> ID;
		scanf_s("%d:%d:%d %d:%d:%d", &H1, &H2, &H3, &O1, &O2, &O3);
		int TimeI = H1 * 60 * 60 + H2 * 60 + H3;//转换为分钟进行比较
		int TimeO = O1 * 60 * 60 + O2 * 60 + O3;
		if (TimeI < Time_In) {
			Time_In = TimeI;
			strcpy_s(ID_IN, 16, ID);
		}
		if (TimeO > Time_Out) {
			Time_Out = TimeO;
			strcpy_s(ID_OUT, 16, ID);
		}
	}
	cout << ID_IN << " " << ID_OUT;
	return 0;
}