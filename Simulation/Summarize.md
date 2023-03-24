## 进制转换
### 1010 Radix 25
**Radix 基数（进制数）**
N1 and N2, your task is to find the radix of one number while that of the other is given.
1. 假定N1已知进制，转换为10进制Num1(方便比较)
2. 找到N2最小的可能进制**(GetMinRadix(N2), Num1 + 1)**;**Num1 + 1**表示N1最大的进制。进制越大，数值越小，假设两个数字都是6，假设进制范围就是(7,7)
3. 在N2的进制范围内，转换成10进制进行比较
```C++
//将radix进制的数转化为10进制的数N1[0]*radix^n-1 + ... + N1[n-1]*radix^0(n为个位、百位...)
long long int GetNum(string N1, long long int radix)
{
	long long int sum = 0;
	for (int i = 0;i < N1.length();i++) {
		if (N1[i] <= '9') {
			sum = sum * radix + (N1[i] - '0');
		}
		else if (N1[i] <= 'z') {
			sum = sum * radix + (N1[i] - 'a' + 10);
		}
	}
	return sum;
}
//找到N2最小的基数
int GetMinRadix(string N2)
{
	char max = '0';
	for (int i = 0;i < N2.length();i++) {
		if (N2[i] > max)//ASCII码比较
			max = N2[i];
	}
	if (max <= '9')
		return max - '0' + 1;//0-9就是10进制
	else if (max <= 'z')
		return max - 'a' + 11;//算上0-9
}
//找到满足使N2==N1的基数--二分法
long long int GetRadix(long long int Num1, string N2, long long int left, long long int right)
{
	if (left == right) {
		if (GetNum(N2, left) == Num1)
			return left;
		else
			return 0;//没有找到
	}
	else if (left < right) {
		long long int center = (left + right) / 2;
		if (GetNum(N2, center) == Num1)
			return center;
		//Num2>Num1或者Num2<0（溢出） 就大了
		else if (GetNum(N2, center) > Num1||GetNum(N2,center)<0)
			return GetRadix(Num1, N2, left, center);
		else if (GetNum(N2, center) < Num1)
			return GetRadix(Num1, N2, center + 1, right);
	}
	return 0;//left>right
}
```
### 1019 General Palindromic Number 20
将10进制的数转化为对应radix进制
```C++
int Num[10];
int i = 0;
//辗转相除法
void Transform(int N, int b)//注意此时的N是倒着的，比如121->5进制是 4 4 1，transform后是 1 4 4
{
	while (N > 0) {
		Num[i++] = N % b;
		N /= b;
	}
}
```

### 1027 Colors in Mars 20
将10进制的数转化为13进制的数
```C++
char c[14] = { "0123456789ABC" };
cin >> num;
cout << c[num / 13] << c[num % 13];
```

### 1014 Waiting in Line 30
N个窗口，对应N条黄线，黄线之前可以站M个人，第N*M+1个人要站在黄线外。

输出对应序号的人结束服务的时间（开始服务的时间+复试时长），用`finishtime[1001]`存储对应序号的人的结束服务时间。
- 选择队伍时选择最短的，相同选择序号小的
```C++
int time(int h, int m)//转换成为分钟
{
	return 60 * h + m;
}
struct Window//每个窗口的时间
{
	//队伍的最后的人服务完成花费的总时间,用于计算服务耗费时间
	int endtime = time(8, 0);
	//队首的人服务的结束时间,队首服务时间最短的(最快有缺口的)即为入队选择的窗口
	int poptime = endtime;
	queue<int>q;
}window[20];
```
```C++
int spenttime[1001] = {0};//服务耗费时间，用于输入
int finishtime[1001] = {0};//服务结束时间
//队伍满之前入队
int idx = 0;//序号，第几个人
for (i = 0;i < min(N * M, K);i++) {
	window[idx % N].q.push(idx);//第idx % N个窗口入队idx这个人
	window[idx % N].endtime += spenttime[idx];
	if (idx < N)//此时窗口还没满
		window[idx].poptime = spenttime[idx];
	finishtime[idx] = window[idx % N].endtime;
	idx++;
}
while (idx < K) {
	//寻找poptime最小的队伍
	int inx = -1, minpoptime = INF;
	for (i = 0;i < N;i++) {
		if (window[i].poptime < minpoptime) {
			inx = i;
			minpoptime = window[i].poptime;
		}
	}
	window[inx].q.pop();//队首元素出队
	window[inx].q.push(idx);//入队

	window[inx].endtime += spenttime[idx];
	window[inx].poptime += spenttime[window[inx].q.front()];
	//队首的人服务花费的时间,作为之后的人的比较因此还要把之前的也加上
	finishtime[idx] = window[inx].endtime;
	idx++;
}
```
## 队列的使用
### 1017 Queueing at Bank 25
**优先队列-时间有关**

类似1014，N个窗口，所有人都呆在一根黄线之外（黄线内容纳1人）

输出所有的人的平均等待时长（因此把每个人的等待时长相加即可）
```C++
#include<queue>
struct person
{
	int come;//来的时间
	int time;//等待的时间
}p[maxn];
sort(p, p + cnt, cmp);//按照到达银行的时间进行排序
priority_queue<int, vector<int>, greater<int>>q;//按照升序排序的优先队列，Container是低层容器，此处为vector，定义了一个元素为整数的小顶堆（默认是大顶堆）
for (int i = 0;i < K;i++) {
	q.push(begin);//将每个窗口的起始值入队
}
int total = 0;//总等待秒数
for (int i = 0;i < cnt;i++) {
	if (p[i].come < q.top()) {//来的比队首结束服务的时间要早-等待
		total += (q.top() - p[i].come);//等待的时间
		q.push(q.top() + p[i].time);//将该人完成服务的时间入队
		q.pop();//队首出队
	}
	else {//来的比队首结束服务的时间要晚-不用等待
		q.push(p[i].come + p[i].time);//直接办理业务，入队
		q.pop();//队首出队
	}
}
printf("%.1f\n", (total / 60.0) / cnt * 1.0);//计算结果
```

### 1056 Mice and Rice 25
**比赛进阶->队列queue实现**
输入Np、Ng，分别代表总共的老鼠数量和一个组的老鼠数量，胜者进入下一轮
输入一行Np：一组之中比赛的权重
输入一行Np：比赛时老鼠的顺序，也就是说比赛是用新顺序order，**排名是按照原输入老鼠的顺序**

```C++
struct Node
{
	int weight;
	int order;//存6 0 8 7...
	int rank;
	int porder;//存0 1 2 3...
};
bool cmp(Node a, Node b)
{
	return a.order < b.order;
}
vector<int>v(Np);
vector<Node>w(Np);
int num;
for (int i = 0;i < Np;i++) {
	cin >> v[i];
}
for (int i = 0;i < Np;i++) {
	cin >> num;
	w[i].order = num;//存6 0 8 7...
	w[i].porder = i;//存0 1 2 3...
	w[i].weight = v[num];//权重值按照order顺序，相当于排序后进行比赛
}
```
输入时的权值就按照**排序后的进行使用**，暂用了第6的数值，最后回到第6
- 输入：25 18 0 46 37 3 19 22 57 56 10
- 比赛：19 25 57 22 ...
- 输出：25 ...
最后按照6 0 8 7...的顺序进行排序，就变回了初始排序

```C++
queue<Node>q;
for (int i = 0; i < Np; i++)
    q.push(w[i]);//按照给定的顺序入队，
while (!q.empty()) {//队列不空的情况
    int size = q.size();
    if (size == 1) {//就一个元素
        Node temp = q.front();
        w[temp.porder].rank = 1;
        break;
    }
    int group = size / Nc;//代表鼠鼠被分成了几组
    if (size % Nc != 0)
        group += 1;
    Node maxnode;
    int maxn = -1, cnt = 0;
    for (int i = 0; i < size; i++) {
        Node temp = q.front();
        w[temp.porder].rank = group + 1;//一轮一轮地修改rank
        q.pop();
        cnt++;//记录一组的数量
        if (temp.weight > maxn) {//更新Nc中最大的结点
            maxn = temp.weight;
            maxnode = temp;
        }
        if (cnt == Nc || i == size - 1) {
            cnt = 0;
            maxn = -1;
            q.push(maxnode);//将最大的结点重新入队
        }
    }
}
```

### 1026 Table Tennis 30
N个桌子(1-N)，当一对人来时，若有空桌子，选择最小的序号的，桌子被占满时，在队列中等待，最多能玩2小时。

存在VIP桌子：若有VIP在等待，则直接使用，若无VIP在队列中，则正常使用

输出每个人的到达时间、服务时间、等待时间（chronological order of the serving time按照服务时间升序排序，The waiting time must be rounded up to an integer minutes四舍五入），以及每个桌子招待的人数。
**%d, (int)round(a)等价于 %.0f, a**
```C++
#define begin 28800//开始的时间8*60*60
#define end 75600//结束的时间21*60*60
struct Person
{
	int arrive = begin;//到达时间
	float wait = 0;//等待时间
	int serve = 0;//服务时间
	int play = 0;//训练时间
	int tag = 0;//是否是VIP
	bool served = false;//是否被服务过
}p[10001];
struct table
{
	int poptime = begin;//空闲时间，也就是当前人的服务结束时间
	int count = 0;//接待人数
	bool vip;
};
vector<table> tables;
tables.resize(K + 1);//初始化容量
```
```C++
int FindNextVIP(int vip_id) //查询队伍中第一个没有被服务的VIP
{
	vip_id++;
	while (vip_id < N && !p[vip_id].tag)
		vip_id++;
	return vip_id >= N ? 0 : vip_id;
}
void alloc(int id, int table_id)//为第id个人分配桌子
{
	if (tables[table_id].poptime <= p[id].arrive)//不需要等待
		p[id].serve = p[id].arrive;//服务时间与到达时间一致
	else
		p[id].serve = tables[table_id].poptime;//服务时间与桌子的空闲时间一致
	tables[table_id].poptime = p[id].serve + p[id].play;//服务结束时间=服务时间+训练时间
	tables[table_id].count++;//接待过的人+1
	p[id].wait = round((p[id].serve - p[id].arrive) / 60.0);//等待时间->四舍五入取分钟
	p[id].served = true;
}
```
```C++
sort(p, p + N, cmp1);//按照到来的时间进行排序
int vip_id = FindNextVIP(-1);//找到VIP所在的位置
i = 0;
while (i < N) {
    if (p[i].served) {//找到未被服务的人
        i++;
        continue;//以这种方式跳过已经服务过的VIP用户
    }
    int min_table_id = -1;//空闲且编号最小的桌子
    int min = 0x3f3f3f;//最短的空闲时间
    for (int j = 1;j <= K;j++) {//遍历所有桌子找到短等待时长的桌子
        if (tables[j].poptime < min) {
            min = tables[j].poptime;
            min_table_id = j;
        }
        if (tables[j].poptime <= p[i].arrive) {//存在空闲的桌子
            min_table_id = j;
            break;
        }
    }
    if (tables[min_table_id].poptime >= end || p[i].arrive >= end)
        break;//排队结束
    if (p[i].tag == 1) {//是VIP的情况
        int vip_table_id = -1;//vip桌子中空闲且序号最小
        for (int j = 1;j <= K;j++) {//查找是否有空闲的VIP桌子
            if (tables[j].vip && tables[j].poptime <= p[i].arrive) {//若存在空闲桌子，取序号最小的那个
                vip_table_id = j;
                break;
            }
        }
        if (i == vip_id)
            vip_id = FindNextVIP(vip_id);//更新下一个VIP的位置
        if (vip_table_id == -1) {//没有VIP，只能分配普通桌子
            alloc(i++, min_table_id);
        }
        else {
            alloc(i++, vip_table_id);
        }
    }//不是VIP的情况
    else {
        if (tables[min_table_id].vip) {//是VIP桌子
            if (!p[vip_id].serve && p[vip_id].arrive <= tables[min_table_id].poptime) {
                //有VIP用户还没被服务且该VIP入队的时候桌子还未空闲
                alloc(vip_id, min_table_id);
                vip_id = FindNextVIP(vip_id);
                continue;
            }
        }
        alloc(i++, min_table_id);//分配给该用户
    }
}
```

### 1049 Counting Ones 30
给定正整数N，统计1-N之中所有1的数量，如12, 1-12共有5个1 ： 1, 10, 11, and 12.
```C++
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
		case 0://当前位为0，当前位的1数量仅由高位决定，因为该位到不了1
            //如100，个位是0，1的数量为10*1=10(1、11...91)，十位是0，1的数量为1*10=10仅仅依靠factor的数量(10、11...19)
            //如1000，个位的1的数量为100*1(1、11...91 + 101、111...191 + 一组10个共10组)
			count += higher * factor;
			break;
		case 1://当前位为1，当前位的1数量由高位和低位+1决定
            //理解了上面的这个就很好理解，就是多了低位的1罢了。
            //若低位存在比如5，则低位可贡献6个：10-15
            //若为低位不存在比如111的个位，则+ 1的对应1、(101、11、21...91)
			count += higher * factor + lower + 1;
			break;
		default://当前位大于1，当前位的1数量由高位+1决定，这里的1对应高位为0的情况
            //若为12，个位的1的数量为2：1、11；120的十位1的个数为20：1(0-9)、11(0-9)
			count += (higher + 1) * factor;
		}
		factor = factor * 10;
	}
	return count;
}
```

### 1051 Pop Sequence 25
栈的容量是M，总共有N个数字，判断一个Pop Sequence是否可能存在
```C++
int j = 0;//入过栈的元素的个数
int num = 1;//栈内元素的起始
int stack[1010] = { 0 }, top = 0;//创建一个栈
stack[top] = num;
while (j < N) {//总共N个元素
    if (seq[j] < stack[top])//比栈顶元素小如312的情况
        break;
    while (seq[j] > stack[top]) {//入栈直到能够输出seq[j]
        stack[++top] = ++num;
    }
    if (top >= M)//逸出的情况
        break;
    if (seq[j] == stack[top])
        top--;
    j++;
}
 if (j == N)
	cout << "YES" << endl;
else
	cout << "NO" << endl;
```
