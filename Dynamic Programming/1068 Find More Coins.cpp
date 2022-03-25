#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//dp[]包含dp[1]~dp[m]
int dp[10010], w[10010];//dp[i]表示在求和后<=i的最大的数
bool choice[10010][110];//存储被访问过的dp[],N-10^4,M-10^2
int cmp1(int a, int b) { return a > b; }
int main() 
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    sort(w + 1, w + n + 1, cmp1);//逆序排序,因为要输出从小到大的排列
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= w[i]; j--) {//j要满足比该币值大，比m小
            if (dp[j] <= dp[j - w[i]] + w[i]) {//满足递推要求
                choice[i][j] = true;//取到数列和j可以通过硬币i
                dp[j] = dp[j - w[i]] + w[i];
            }
        }
    }
    if (dp[m] != m) printf("No Solution");
    else {
        vector<int> arr;
        int v = m, index = n;
        while (v > 0) {//从币值最小的硬币开始
            if (choice[index][v] == true) {//组成币值v可以通过w[index]
                arr.push_back(w[index]);
                v -= w[index];
            }
            index--;
        }
        for (int i = 0; i < arr.size(); i++) {
            if (i != 0) printf(" ");
            printf("%d", arr[i]);
        }
    }
    return 0;
}