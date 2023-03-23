### 1002 A+B for Polynomials 25
存储对应指数下的底数即可，在输入时即相加
```C++
double p[1001] = { 0.0 };//存储对应指数下的底数值
int a;
double b;
cin >> a >> b;//指数和底数b^a
if (p[a] == 0)//未存储过
	p[a] = b;
else
	p[a] += b;
```
### 1009 Product of Polynomials 25
在底数相乘，指数相加的过程中可能会产生新的指数，故需要遍历第一轮的输入（故输出结果要新数组r[]保存）
```C++
double p[1001] = { 0.0 };//存储第一次输入
double r[2001] = { 0.0 };//存储结果
cin >> a >> b;//指数和底数b^a
for (j = 0;j < 1001;j++) {//遍历第一次输入，因为可能产生新的指数，故要遍历
	if (p[j] != 0) {
		if(r[j + a] == 0)//未存储过，存储底数相乘，指数相加
			r[j + a] = p[j] * b;
		else
			r[j + a] += p[j] * b;
	}
}
```

### 1022 Digital Library 30

一本书：输入多个key值，对应一个value：ID（需要自动排序，且不能重复）

输入多本书时每个key值对应多个ID值，在query时输出这些ID值
```C++
string id, title, author, publisher, publishyear, key;//共有5个Key值
//ID值形如1111111、2222222
map<string, set<string>> mp;//key, value 对value值也就是ID进行排序
mp[title].insert(id);
mp[author].insert(id);
//key words
while (cin >> key) {//对于每一个key值进行保存
	char c = getchar();//输入空格
	mp[key].insert(id);
	if (c == '\n')break;//key值输入结束
}
mp[publisher].insert(id);
mp[publishyear].insert(id);
```
map类型的遍历方法：
```C++
if (mp[key].size() == 0) {//没找到
	cout << "Not Found" << endl;
}
else {
	for (auto it : mp[key]) {//采取auto类型+ 增强for 循环(auto迭代)
	cout << it << endl;
	}
}
```

### 1039 Course List for Student 25
输入不同课程有那些同学选择，按顺序输出不同同学的选课内容

与上题一致的思路，记录每个学生(key)对应的课程id(value)，id不重复且自动排序
```C++
#include<set>
#include<map>
map<string, set<int>>mp;//key:student,value:id
for (int i = 0;i < K;i++) {
		cin >> id >> Ni;
		for (int j = 0;j < Ni;j++) {
			cin >> s;
			mp[s].insert(id);
		}
}
```

### 1047 Student List for Course 25
输入不同同学选课的课程信息，按照顺序输出不同课程有哪些同学选择

本来按照1039的思路写：
`map<int, set<string>>mp;`
发现最后一个测试点过不去
改为：
```C++
map<int, vector<string>>mp;//key:id,value:student
sort(mp[i].begin(), mp[i].end());//对每个课程进行sort
```

### 1048 Find Coins 25
给出n个正整数和一个正整数m，问n个数字中是否存在一对数字a和b(a <= b),使a+b=m成立。如果有多个，输出a最小的那一对。

**建立数组a保存每个数字出现的次数，然后判断输出**
```C++
for(int i = 0; i < n; i++) {    
	scanf("%d", &temp);    
	a[temp]++;
}
for(int i = 0; i < 1001; i++) {
    if(a[i]) {
        a[i]--;//要先a[i]--，表示已经使用了一个，否则若只有1个4，要8的时候也会输出
        if(m > i && a[m-i]) {
            printf("%d %d", i, m - i);
            return 0;
        }
        a[i]++;
    }
}
```

### 1054 The Dominant Color 20
strictly dominant color：占据超过一半的数量的颜色，题目保证存在
```C++
int tmp;
cin >> tmp;
m[tmp]++;
if (m[tmp] > Max) {
	Max = m[tmp];
	MaxID = tmp;
}
```

### 1078 Hashing 25
在哈希表中插入key值，公式为H(key)=key%TSize，采用只有正向的平方探测法处理冲突。
```C++
for (j = 1;j < M;j++) {//这里的j当作是step，范围从1~M-1，M是哈希表的大小
	int tmp = (key + j * j) % M;
	if (a[tmp] == 0) {
		printf(" %d", tmp);
		a[tmp]++;
		break;
	}
}
if (j == M)
	printf(" -");
```

### 1169 The Judger 25
判断选手给出的数字是否是前面出现过的**数字差**的方法:（比如101 42，59是其差）  
只需要判断x+前面的任意一个数字后的结果是否出现在之前的数字中即可
```C++
unordered_set<int>num;//存储之前出现的数字
bool isdifferent(int n)
{
    for(auto it=num.begin();it!=num.end();it++){
        if(num.find(n + *it)!=num.end())//找到了,表示满足
            return true;
    }
    return false;
}
```
