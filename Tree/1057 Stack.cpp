#include<iostream>
#include<stack>
#include<string>
using namespace std;
#define lowbit(i) ((i)&(-i))//取最低位的1
const int maxn = 100010;
stack<int>s;
//树状数组，方便求sum和进行修改
int c[maxn];//树状数组，每个结点代表其子树结点出现的次数
void update(int x, int v)//单点修改(v代表出现了x的次数)
{
	for (int i = x;i < maxn;i += lowbit(i)) {
		c[i] += v;//顺着树向上爬
	}
}
int getsum(int x)//区域查询,小于等于x的数的个数
{
	int sum = 0;
	for (int i = x;i >= 1;i -= lowbit(i)) {
		sum += c[i];
	}
	return sum;
}

void PeekMedian() //二分法
{
	int left = 1, right = maxn, mid;//Key保证>0
	int k = (s.size() + 1) / 2;//代表要求的第k大小的数
	while (left < right) {
		mid = (left + right) / 2;
		if (getsum(mid) >= k)//小于等于mid的数的个数大于k个
			right = mid;
		else
			left = mid + 1;
	}
	printf("%d\n", left);
}
int main()
{
	int N, Key;
	cin >> N;
	string cmd;
	for (int i = 0;i < N;i++) {
		cin >> cmd;
		if (cmd == "Push") {
			cin >> Key;
			s.push(Key);
			update(Key, 1);
		}
		else if (cmd == "Pop") {
			if (!s.empty()) {
				update(s.top(), -1);
				printf("%d\n", s.top());
				s.pop();
			}
			else {
				printf("Invalid\n");
			}
		}
		else {//寻找中间值
			if (!s.empty())
				PeekMedian();
			else
				printf("Invalid\n");
		}
	}
	return 0;
}