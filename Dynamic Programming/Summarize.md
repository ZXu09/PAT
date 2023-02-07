
### 1007 Maximum Subsequence Sum 25-最大子列和
```C++
void MaxSubsequm2(int A[], int N)//稍作改进-O(N^2)-可以全过
{
	int i, j;
	int MaxSum = -1, ThisSum;
	int First, Last;
	for (i = 0;i < N;i++) {
		ThisSum = 0;
		for (j = i;j < N;j++) {
			ThisSum += A[j];
			if (ThisSum > MaxSum) {
				MaxSum = ThisSum;
				First = A[i];
				Last = A[j];
			}
		}
	}
	if (MaxSum < 0) {
		MaxSum = 0;
		First = A[0];
		Last = A[N - 1];
	}
	cout << MaxSum << " " << First << " " << Last << endl;
}
```
```C++
void MaxSubsequm3(int A[], int N)//动态规划-可以全过
{
	int i, MaxSum = -1, ThisSum = 0;
	int First, Last, Start = A[0];
	for (i = 0;i < N;i++) {
		ThisSum += A[i];
		if (ThisSum > MaxSum) {
			MaxSum = ThisSum;
			Last = A[i];
			First = Start;//存进First
		}
		if (ThisSum < 0) {//重新开始
			ThisSum = 0;
			Start = A[i + 1];//记录开始的地方
		}
	}
	if (MaxSum < 0) {
		MaxSum = 0;
		First = A[0];
		Last = A[N - 1];
	}
	cout << MaxSum << " " << First << " " << Last << endl;
}
```
```C++
int Max(int A, int B, int C)
{
	return A > B ? (A > C ? A : C) : (B > C ? B : C);
}

int DivideAndConquer(int A[], int left, int right)//O(NlogN)
{
	int MaxLeftSum, MaxRightSum;
	int MaxLeftBorderSum, LeftBorderSum;
	int MaxRightBorderSum, RightBorderSum;
	int First, Last;
	if (left == right) {//中止递归的条件
		if (A[left] > 0)
			return A[left];
		else return 0;
	}
	//求左右子列的最大
	int center = (left + right) / 2;
	MaxLeftSum = DivideAndConquer(A, left, center);
	MaxRightSum = DivideAndConquer(A, center + 1, right);
	//求跨越左边界的最大
	MaxLeftBorderSum = 0; LeftBorderSum = 0;
	for (int i = center;i >= left;i--) {
		LeftBorderSum += A[i];
		if (LeftBorderSum > MaxLeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;
	}
	//求跨越右边界的最大
	MaxRightBorderSum = 0; RightBorderSum = 0;
	for (int i = center + 1; i <= right; i++) {
		RightBorderSum += A[i];
		if (RightBorderSum > MaxRightBorderSum)
			MaxRightBorderSum = RightBorderSum;
	}

	return Max(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}

int MaxSubsequm4(int A[], int N)//分而治之
{
	return DivideAndConquer(A, 0, N - 1);
}
```

### 1033 To Fill or Not to Fill 25
 1. 遍历当前油站可以到达的距离
 2. 若发现有油站更便宜，直接到那个油站，（此时不补满油）
 3. 若未发现更便宜的，就到可选择的油站中最便宜的油站（此时补满油）

### 1044 Shopping in Mars 25-二分查找
**累计->sum[i]存储前i项和**因此sum数组是递增的，想到二分法
```C++
for (int i = 1; i <= n; i++) {
        cin >> sum[i];
        sum[i] += sum[i - 1];//sum[i]表示1~i的求和
}
//实现i->n 以i为起点最接近m的序列和
void Dichotomy(int i, int& j, int& tempsum) {
    int left = i, right = n;
    //寻找合适的mid，使得i->mid的值最接近m
    while (left < right) {
        int mid = (left + right) / 2;//二分
        if (sum[mid] - sum[i - 1] >= m)//i->mid的值大于等于需求(若恰好等于，在二分结束前right都不会变)
            right = mid;//左边
        else//i->mid的值小于需求
            left = mid + 1;//右边
    }
    j = right;
    tempsum = sum[j] - sum[i - 1];//i->j的所有的值
}
```
### 1046 Shortest Distance 20
给定环状路径，求最短路径
**累计->sum[i]存储前i项和**
```C+++
int b, e;//开始和结束
Sum[i] = Sum[i - 1] + Dis[i];//sum[i]代表从1到达i+1所需要的路程
dis = Sum[e - 1] - Sum[b - 1];//b~e的距离
cout << min(dis,sum-dis) << endl;//正着走和反着走
```
### 1045 Favorite Color Stripe 30
找到按照特定喜欢的颜色顺序的最长子序列（可拼接）
Input:喜欢的颜色顺序2 3 1 5 6
 1. 用book数组存储颜色的顺序`book[2]=1,book[3]=2...book[6]=5;`
 2. 利用a数组只存储喜欢的颜色，且存储内容是book数组的值，这样就得到了顺序，num计数组内元素的个数
- 输入序列：2 2 4 1 5 5 6 3 1 1 5 6
- 存储喜欢：2 2 1 5 5 6 3 1 1 5 6
- 存储内容：1 1 3 4 4 5 2 3 3 4 5
```C++
for (int i = 0; i < l; i++) {
        cin >> x;
        if (book[x] >= 1)
            a[num++] = book[x];
}
```
 3. dp[]数组存储的是到达该结点最长的序列长度
- 遍历j，j属于0-i，如果a[j]>=a[i]满足order时
- 判断dp[i] = max(dp[i], dp[j] + 1);
- 存储内容：1 1 3 4 4 5 2 3 3 4 5
- 存储dp[]：1 2 3 4 5 6 3 4 5 6 7
```C++
for (int i = 0; i < num; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++)//看i之前的a[]，若有数字更小或相等的的则更新dp[i](dp[i]按顺序1、2、3这样加上去)
            if (a[i] >= a[j])
                dp[i] = max(dp[i], dp[j] + 1);
        maxn = max(dp[i], maxn);
}
```
***

**01背包问题**
给定背包能装物品的体积，每个物品有对应的体积和价值，求背包能装的下最大的价值
- 物品编号： 1 2 3 4
- w体积：    2 3 4 5
- v价值：    3 4 5 6
- 背包最大体积 bagV = 8
```C++
int dp[5][9];//动态规划表 i*j的一个矩阵（i代表物品的数量，j代表背包的体积）
void FindMax()//找到最大值
{
	for (int i = 1;i < 5;i++) {//dp[i][j]:能够装下物品1~i的最大价值
		for (int j = 1;j < 9;j++) {
			if (j < w[i]) {//容量不够
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);//比较装下和不装下哪个价值更大
			}
		}
	}
}
```
```
dp[5][9] = 
0 0 0 0 0 0 0 0 0
0 0 3 3 3 3 3 3 3
0 0 3 4 4 7 7 7 7
0 0 3 4 5 7 8 9 9
0 0 3 4 5 7 8 9 10
```
- 判断哪些物品被使用只需要比较dp[i][j]和dp[i-1][j]即可
```C++
int item[5];//最优解路径
void FindPave(int i, int j)
{
	if (i >= 0) {
		if (dp[i][j] == dp[i - 1][j]) {
			item[i] = 0;//该物品没有用到
			FindPave(i - 1, j);
		}
		else if (j - w[i] >= 0 && dp[i][j] == dp[i - 1][j - w[i]] + v[i]) {//可能会用到
			item[i] = 1;//该物品用到了
			FindPave(i - 1, j - w[i]);
		}
	}
}
```
### 1068 Find More Coins 30
**01背包的变体，相当于不限制体积的背包，但是限制装入coins的顺序**
- 找到满足V1+V2+...Vk=M的最小序列
- **dp[i]1维，表示在求和后 <= i的最大的数**
```C++
bool choice[10010][110];//存储被访问过的dp[],方便输出哪些结点被访问过了N-10^4硬币数量,M-10^2凑的总金额
sort(w + 1, w + n + 1, cmp1);//逆序排序
//input_w[i]:5 9 8 7 2 3 4 1
//sort_w[i]:9 8 7 5 4 3 2 1
for (int i = 1; i <= n; i++) {//硬币的数量递增
        for (int j = m; j >= w[i]; j--) {//j是想要取到的序列和，若币值更大：w[i]>j，那一定不会取这个硬币
            if (dp[j] <= dp[j - w[i]] + w[i]) {//满足递推要求（在取这个硬币之后没爆）
                choice[i][j] = true;//取到数列和j可以通过硬币i
                dp[j] = dp[j - w[i]] + w[i];
            }
        }
}
```
```C++
choice[i][j] = //取到数列和j可以通过硬币i
(1 9)(2 8)
(3 7)
(4 6)(4 5)
(5 9)(5 4)
(6 8)(6 7)(6 3)
(7 9)(7 7)(7 6)(7 5)(7 2)
(8 9)(8 8)(8 7)(8 6)(8 5)(8 4)(8 3)(8 1)
```
```C++
//根据choice的结果进行输出
int v = m, index = n;//index=n从币值最小的硬币开始
while (v > 0) {
	if (choice[index][v] == true) {
                arr.push_back(w[index]);
                v -= w[index];
            }
        index--;
}
```
### 1103 Integer Factorization 30
- 求解一个整数N分解成K个数的P次方的和 N = n[1]^P + ... n[K]^P
```C++
void init()//初始化v数组为所有比N小的所有i^P
{
	int tmp = 0, i = 1;
	while (tmp <= N) {//这样i = 0时v[i] = 0;i = 1时v[i] = 1相对应
		v.push_back(tmp);
		tmp = pow(i, P);
		i++;
	}
}
```
```C++
int maxfacsum = -1;//分解因式之和
void DFS(int i, int tempK, int sum, int facsum)//从v[i]的最后(从大到小)开始进行DFS
{
	if (tempK == K) {//计数为K个时
		if (sum == N && facsum > maxfacsum) {//maximum sum of the factors
			maxfacsum = facsum;
			ans = tmpans;//存储答案
		}
		return;
	}
	while (i >= 0) {//i存储在数组v的下标,也就是该数组
		if (sum + v[i] <= N) {//把v[i]的可能的组合都试一次
			tmpans[tempK] = i;//存入tmpans
			DFS(i, tempK + 1, sum + v[i], facsum + i);
		}
		if (i == 1)//到1返回，不用统计0
			return;
		i--;//只有相加直到sum+v[i]>N时才会让i--
	}
}
```
