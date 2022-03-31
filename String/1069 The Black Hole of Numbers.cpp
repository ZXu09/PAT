#include<iostream>
#include<string>
#include <algorithm>
using namespace std;
bool cmp(char a, char b) { return a > b; }
int main() {
	string s;
	cin >> s;
	s.insert(0, 4 - s.length(), '0');
	do {
		string a = s, b = s;
		sort(a.begin(), a.end(), cmp);
		sort(b.begin(), b.end());
		int result = stoi(a) - stoi(b);
		s = to_string(result);
		s.insert(0, 4 - s.length(), '0');
		cout << a << " - " << b << " = " << s << endl;
	} while (s != "6174" && s != "0000");
	return 0;
}


//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string a;
//	cin >> a;
//	do {
//		for (int i = 0;i < 3;i++) {
//			for (int j = 0;j < 3 - i;j++) {//一趟后最小的在最右边
//				if (a[j] < a[j + 1])
//					swap(a[j], a[j + 1]);
//			}
//		}
//		string b = a;
//		reverse(b.begin(), b.end());
//		if (a == b) {
//			cout << a << " - " << b << " = 0000" << endl;
//			break;
//		}
//		string c = a;
//		for (int i = 3;i >= 0;i--) {
//			if (a[i] >= b[i]) {
//				c[i] = a[i] - b[i] + '0';
//			}
//			else {
//				c[i] = a[i] - b[i] + '0' + 10;
//				a[i - 1]--;
//			}
//		}
//		cout << a << " - " << b << " = " << c << endl;
//		a = c;
//	} while (a != "6174");
//	return 0;
//}