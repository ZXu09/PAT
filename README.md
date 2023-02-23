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
### git
git init
git add. 准备提交
git commit -m "备注"
git log
git checkout HEAD main.py
