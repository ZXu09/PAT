#include<iostream>
#include<string>
using namespace std;
int main()
{
	int N;
	string s;
	int t;
	string ones[14] = { "tret" ,"jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
	string tens[14] = { "tret" ,"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
	scanf("%d", &N);
	getchar();//输入换行符
	for (int i = 0;i < N;i++) {
		getline(cin, s);//输入
		if (s[0] >= '0' && s[0] <= '9') {//数字转化为火星文
			t = atoi(s.c_str());//转化为int类型
			if (t >= 13) {//注意个位是0不用打印
				if(t % 13 == 0)
					cout << tens[t / 13] << endl;
				else 
					cout << tens[t / 13] << " " << ones[t % 13] << endl;
			}
			else {
				cout << ones[t] << endl;
			}

		}
		else {//火星文转化为数字
			if (s.size() == 3 || s.size() == 4) {//只有一个数字的情况
				bool flag = false;
				for (int i = 0;i < 14;i++) {
					if (s == ones[i]) {
						printf("%d\n", i);
						flag = true;
						break;
					}	
				}
				if (!flag) {//在tens中
					for (int i = 0;i < 14;i++) {
						if (s == tens[i])
							printf("%d\n", i * 13);
					}
				}
			}
			else {
				string s1, s2;
				int r = 0;
				s1 = s.substr(0, 3);
				s2 = s.substr(4, 3);
				for (int i = 0;i < 14;i++) {
					if (s1 == tens[i])
						r += i * 13;
					if (s2 == ones[i])
						r += i;
				}
				printf("%d\n", r);
			}
		}
	}
	return 0;
}