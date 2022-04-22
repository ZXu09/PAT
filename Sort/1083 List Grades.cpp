#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct Node
{
	string name;
	string ID;
	int grade;
}Student[10010];
bool cmp(Node a, Node b)
{
	return a.grade > b.grade;
}
int main()
{
	int N, grade1, grade2;
	scanf("%d", &N);
	for (int i = 0;i < N;i++) {
		cin >> Student[i].name >> Student[i].ID >> Student[i].grade;
	}
	scanf("%d %d", &grade1, &grade2);
	sort(Student, Student + N, cmp);
	bool flag = false;//ÅĞ¶ÏÓĞÎŞÊä³ö
	for (int i = 0;i < N;i++) {
		if (Student[i].grade >= grade1 && Student[i].grade <= grade2) {
			flag = true;
			cout << Student[i].name << " " << Student[i].ID << endl;
		}
	}
	if (!flag)
		printf("NONE\n");
	return 0;
}