#include<iostream>
#include<string>
#include<iostream>
using namespace std;
string wk[7] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
int main() {
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	int temp;
	int len1 = (s1.length() > s2.length()) ? s2.length() : s1.length();
	int len2 = (s3.length() > s4.length()) ? s4.length() : s3.length();
	for (int i = 0; i < len1; i++) {
		if (s1[i] == s2[i] && (s1[i] >= 'A' && s1[i] <= 'G')) {
			cout << wk[s1[i] - 'A'] << " ";
			temp = i;
			break;
		}
	}
	for (int i = temp + 1; i < len1; i++) {
		if (s1[i] == s2[i]) {
			if (s1[i] >= 'A' && s1[i] <= 'N') {
				cout << 10 + s1[i] - 'A' << ":";
				break;
			}
			else if (s1[i] >= '0' && s1[i] <= '9') {
				cout << "0" << s1[i] << ":";
				break;
			}
		}
	}
	for (int i = 0; i < len2; i++) {
		if (s3[i] == s4[i] && ((s3[i] >= 'a' && s3[i] <= 'z') || (s3[i] >= 'A' && s3[i] <= 'Z'))) {
			printf("%02d", i);
			break;
		}
	}
	return 0;
}
