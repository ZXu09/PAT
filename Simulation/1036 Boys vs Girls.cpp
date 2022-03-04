#include<iostream>
#include<string>
using namespace std;

struct Student
{
	string name;
	char gender;
	string ID;
	int grade;
}Student[1001];
int main()
{
	int N, i;
	cin >> N;
	for (i = 0;i < N;i++) {
		cin >> Student[i].name >> Student[i].gender >> Student[i].ID >> Student[i].grade;
	}
	int MaxFemale = -1, Minmale = 101;
	int MaxID = -1, MinID = -1;
	for (i = 0;i < N;i++) {
		if (Student[i].gender == 'F' && Student[i].grade > MaxFemale) {
			MaxFemale = Student[i].grade;
			MaxID = i;
		}
		if (Student[i].gender == 'M' && Student[i].grade < Minmale) {
			Minmale = Student[i].grade;
			MinID = i;
		}
	}
	if (MaxID == -1) {
		cout << "Absent" << endl;
	}
	else {
		cout << Student[MaxID].name << " " << Student[MaxID].ID << endl;
	}
	if (MinID == -1) {
		cout << "Absent" << endl;
	}
	else {
		cout << Student[MinID].name << " " << Student[MinID].ID << endl;
	}
	if (MaxID == -1 || MinID == -1) {
		cout << "NA" << endl;
	}
	else {
		cout << MaxFemale - Minmale << endl;
	}
	return 0;
}