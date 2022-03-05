#include<iostream>
using namespace std;
int main()
{
	int N, M, K;
	cin >> M >> K >> N;
	int seq[1010];

	for (int i = 0;i < N;i++) {
		for (int k = 0;k < K;k++) {
			cin >> seq[k];
		}
		int j = 0;//入过栈的元素的个数
		int num = 1;//栈内元素的起始
		int stack[1010] = { 0 }, top = 0;//创建一个栈
		stack[top] = num;
		while (j < K) {
			if (seq[j] < stack[top])//比栈顶元素小如312的情况
				break;
			while (seq[j] > stack[top]) {
				stack[++top] = ++num;
			}
			if (top >= M)//逸出的情况
				break;
			if (seq[j] == stack[top])
				top--;
			j++;
		}
		if (j == K)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}