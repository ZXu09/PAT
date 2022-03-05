#include <iostream>
#include <vector>
using namespace std;
vector<int> sum, resultArr;
int n, m;
void Func(int i, int& j, int& tempsum) {
    int left = i, right = n;
    while (left < right) {
        int mid = (left + right) / 2;//二分
        if (sum[mid] - sum[i - 1] >= m)//i->mid的值大于需求
            right = mid;//左边
        else//i->mid的值小于需求
            left = mid + 1;//右边
    }
    j = right;
    tempsum = sum[j] - sum[i - 1];//i->j的所有的值
}
int main() {
    cin >> n >> m;
    sum.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> sum[i];
        sum[i] += sum[i - 1];//表示1-i所有数字的综合
    }
    int minans = sum[n];
    for (int i = 1; i <= n; i++) {
        int j, tempsum;
        Func(i, j, tempsum);
        if (tempsum > minans) continue;
        if (tempsum >= m) {
            if (tempsum < minans) {
                resultArr.clear();//清空，从最小和的起点处开始记录
                minans = tempsum;//更新最小和
            }
            resultArr.push_back(i);
            resultArr.push_back(j);
        }
    }
    for (int i = 0; i < resultArr.size(); i += 2)
        printf("%d-%d\n", resultArr[i], resultArr[i + 1]);
    return 0;
}