1. 小写字母比大写字母的ASCII码值大32
``
3. char类型的0~9 -> int类型的0~9使ASCII-48 当N<=10

string->int stoi() N为任意值时通用, stoi()需要string头文件

最大公约数：int gcd(int a,int b){return b=0?a:gcd(b,a%b)}

**输入**
- getline(cin,string s)，接收一个字符串，可以接收空格、回车等
- String类的getline()
- cin>>会自动过滤掉不可见字符（如空格 回车 tab等）故需要getchar
```C++
#include<string>
//Input: 
3
The Testing Book

int ID;
string title;

cin >>ID;
getchar();//输入换行符
getline(cin, title);
```
### 重点细节
- atoi()函数：`atoi(S1.c_str());//string->int`
- 
### 并查集
```C++
int Union[1010];//实现并查集，存储该结点的父结点
int Find(int a) {//一直查询直到父结点为自己（无父结点）
    if (Union[a] != a) 
    	return Union[a] = Find(Union[a]);
    return a;
}
void add(int a, int b) {//序号小的为根
    int f1 = Find(a), f2 = Find(b);
    if (f1 < f2) Union[f2] = f1;
    else Union[f1] = f2;
}
for(int i=1;i<=1000;i++)
     Union[i]=i;//初始化父结点为当前结点
```
**素数**
```C++
#include<cmath>
bool isPrime(int N)
{
	if (N <= 1)
		return false;
	for (int i = 2;i <= sqrt(N);i++) {
		if (N % i == 0)
			return false;
	}
	return true;
}
```

### map
map内部实现红黑树
```C++
map<string, int> m;//实现string->int(key:string, value:int)
int cnt = 0, t;
string s1;
m[s1] = cnt;
if(m.find(s1) != m.end())//m内存在元素
	t = m[s1];
```
### unordered_map
unordered_map查询单个key的时候效率比map高，但是要查询某一范围内的key值时比map效率低
map内部实现了一个红黑树，该结构具有自动排序的功能，因此map内部的所有元素都是有序的
unordered_map内部实现了一个哈希表，因此其元素的排列顺序是杂乱的，无序的
```C++
unordered_map<string, int> m;
for (int j = 0; j < n; j++)
    if (v[j].t.substr(4, 6) == s) //满足考场日期一样
    	//key->v[j].t.substr(1, 3)
    	m[v[j].t.substr(1, 3)]++;//该考生对应的site的num++
for (auto it : m) //遍历unordered_map内元素
	ans.push_back({it.first, it.second});
```
### set
默认按照升序的排列方式，且元素不重复
```C++
set<int>s;
int a;
s.insert(a);
for(auto it=s.begin();it!=s.end();it++)//遍历set内元素
    	cout<<*it<<" ";
```

### unordered_set
元素不重复
### git
git init
git add. 准备提交
git commit -m "备注"
git log
git checkout HEAD main.py
