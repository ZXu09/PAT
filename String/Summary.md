### print()
```C++
printf("%.1f %.1f\n", arr[i].Min, arr[i].Ave);
//%.1f会自动执行四舍六入的操作,3.26->3.3，3.24->3.2
//3.250->3.2，3.251->3.3
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
Sum += (Num[i]-'0');
```

**strlen()**
```C++
#include<cstring>//PAT
char ans[10];
int len = strlen(ans);
```

### string<->int
**string->int**（多个字符类型）
```C++
string s;
int b = atoi(s.c_str());
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
