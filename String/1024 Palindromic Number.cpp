#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string N;

void add(string M)
{
    int n = M.length();
    int r = 0;
    for (int i = 0;i < n;i++) {//前后开始都一样
        N[i] = N[i] + M[i] - '0' + r;
        r = 0;
        if (N[i] > '9') {
            N[i] = N[i] - 10;//char类型
            r = 1;//进位
        }
    }
    if (r)
        N += '1';
    reverse(N.begin(), N.end());
}
int main()
{
	int K, i;
	cin >> N >> K;
    for (i = 0; i <= K; i++) {
        string M = N;
        reverse(M.begin(), M.end());
        if (M == N || i == K) break;
        add(M);
    }
    cout << N << endl << i;
    return 0;
}