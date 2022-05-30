#include<iostream>
#include<string>
using namespace std;
int main()
{
	int N;
	scanf("%d", &N);
	string s;
	int cnt = 0;//计数
	double sum = 0;//加和
	for (int i = 0;i < N;i++) {
		bool flag = true;//判断是否合法
		cin >> s;
		int j = 0;
		if (s[0] == '-') {
			j = 1;
		}
		bool visit = false;//判断 '.' 是否出现过
		for (j;j < s.size();j++) {
			if (s[j] == '.') {
				if(!visit)
					visit = true;
				else {
					flag = false;
					break;
				}
				if (s.size() - j - 1 > 2) {
					flag = false;
					break;
				}
			}
			else if (s[j] < '0' || s[j] > '9') {
				flag = false;
				break;
			}
		}

		if (flag) {
			double num = atof(s.c_str());
			if (num <= 1000 && num >= -1000) {
				sum += num;
				cnt++;
			}
			else flag = false;
		}
		if (!flag)
			cout << "ERROR: " << s << " is not a legal number\n";

	}
	if (cnt != 0) {
		if(cnt == 1)
			printf("The average of %d number is %.2f\n", cnt, sum / cnt);
		else 
			printf("The average of %d numbers is %.2f\n", cnt, sum / cnt);
	}
	else
		printf("The average of %d numbers is Undefined\n", cnt);
	return 0;
}