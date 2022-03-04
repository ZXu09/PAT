#include<iostream>
#include<string>
using namespace std;

int Num[10];
int i = 0;
void Transform(int N, int b)
{
	while (N > 0) {
		Num[i++] = N % b;
		N /= b;
	}
}
int main()
{
	int N, b;
	cin >> N >> b;
	Transform(N, b);
	int left = 0, right = i - 1;
	int flag = 0;
	while (left < right) {
		if (Num[left] != Num[right]) {
			flag = 1;
			break;
		}
		left++;right--;
	}
	if (!flag)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	for (int j = i - 1;j >= 0;j--) {
		cout << Num[j];
		if (j != 0)
			cout << " ";
	}
	return 0;

}