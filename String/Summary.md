### print()
```C++
printf("%.1f %.1f\n", arr[i].Min, arr[i].Ave);
//%.1f会自动执行四舍六入的操作,3.26->3.3，3.24->3.2
//3.250->3.2，3.251->3.3
//%.0f相当于四舍五入round()函数
```
### int <-> char
**sprint() int->char**
```C++
int a, b;
cin >> a >> b;
char ans[10];//存放数据字符串类型
sprintf_s(ans, sizeof(ans), "%d", a + b);//VS
sprintf(ans, "%d", a + b);//PAT

```

**char->int**（单个字符类型，string a, a[i]同理）
```C++
char Num[101];
Sum += (Num[i]-'0');//ASCII-48
```

**strlen()**
```C++
#include<cstring>//PAT
char ans[10];
int len = strlen(ans);
```
***
### string<->int
**string->int**（多个字符类型）
```C++
string s;
int b = atoi(s.c_str());
```
**int->string**
```C++
string s;
int a;
s+=to_string(a);
```
### 1023 Have Fun with Numbers 20
to_string的应用->string类型实现×2
```C++
//s1: 1234567899
//s2: 存储s1×2之后的逆置结果
//reverse_s2: 2469135798
string s1, s2;
cin >> s1;
int r = 0;
for (int i = s1.length() - 1; i >= 0; i--) {
    int a = (s1[i] - '0') * 2 + r;//当前位
    s2 += to_string(a % 10);//存储×2之后的结果(与结果相反)
    r = a / 10;//进位
}
if (r != 0)
    s2 += to_string(r);
```
### string函数
**1、substr()函数**
```C++
key = key.substr(3);//从第三位到末尾复制
```
**2、compare()函数**

如果相等则输出为0，不等则输出为-1。
```C++
str1.compare(str2);
```
**3、== !=**
string可以直接用!=以及==
```C++
//相等则输出为0，不等则输出为1，a和b的name不相等时，按照字母顺序排序
if (a.name != b.name)//对name升序排序
	return a.name < b.name;
```
**4、reverse()函数**
```C++
#include<algorithm>
string s ="abc";
reverse(s.begin(), s.end());//s: cba
```
int a,b;
char ans[];
sprintf(ans, "%d", a + b);
//char类型 -> char类型
char A[],char B[];
strcpy(A,B);将B赋值给A
strcmp(A,B);==0相等，<0 A在B的前面

string str1, str2;
int b;
//子串
str1.substr (3,5);从位置为3的位置开始，长度为5
//int -> string
str1=to_string(b);
//string -> int
b = stoi(str1.c_str());字符串类型->int
//string之间比较
str1<str2;
str1.compare(str2)<0;
//查找
str1.find('1') != -1找到了'1'
//替换
str1.replace(str1.find('1'),2,"@");//在str1中1开始位置的两个字符替换为@
//翻转
reverse(str1.begin(), str1.end());//要algorithm头文件
//删除
str1.erase(str1.find(str2[i]), 1);//在str1中删除字符str2[i]
//插入
str.insert(str.end(),10,'s');//在str的结尾插入10个s
1071 Speech Patterns

1.tolower(s[i]);//统一小写
2.isalnum(s[i]);//满足数字字母
3.遍历map找到出现次数最多的pattern
for (auto it = m.begin();it != m.end();it++) {
		if (it->second > maxn) {
			a = it->first;
			maxn = it->second;
		}
	}
	
1077 Kuchiguse
我的思路其实挺麻烦的：输入的过程中判断新两对之间的后缀和已经存储的后缀进行比较，长/短 取共同的后缀
柳神：求后缀就先把输入逆转；首先ans = s；后来每输入的一个字符串，都和ans比较，如果后面不相同的就把它截取掉～最后输出ans即可
