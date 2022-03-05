#include<iostream>
#include<string>
using namespace std;

int CountOnes(int N)
{
	int count = 0;
	int factor = 1;//个位开始
	int higher, lower, cur;
	while (N / factor != 0) {
		higher = N / (factor * 10);//当前位的高位
		lower = N - (N / factor) * factor;//当前位的低位
		cur = (N / factor) % 10;//当前位
		switch (cur) {
		case 0://当前位为0，当前位的1数量仅由高位决定
			count += higher * factor;
			break;
		case 1://当前位为1，当前位的1数量由高位和低位+1决定
			count += higher * factor + lower + 1;
			break;
		default://当前位大于1，当前位的1数量由高位+1决定
			count += (higher + 1) * factor;
		}
		factor = factor * 10;
	}
	return count;
}
int main()
{
	int N;
	cin >> N;
	cout << CountOnes(N) << endl;
	return 0;
}