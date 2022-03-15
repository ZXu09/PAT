#include<iostream>
using namespace std;
int main()
{
	int A_Galleon, A_Sickle, A_Knut;
	int B_Galleon, B_Sickle, B_Knut;
	int R_Galleon, R_Sickle, R_Knut;
	scanf_s("%d.%d.%d %d.%d.%d", &A_Galleon, &A_Sickle, &A_Knut, &B_Galleon, &B_Sickle, &B_Knut);
	R_Knut = (A_Knut + B_Knut) % 29;
	if (A_Knut + B_Knut >= 29)
		A_Sickle++;
	R_Sickle = (A_Sickle + B_Sickle) % 17;
	if (A_Sickle + B_Sickle >= 17)
		A_Galleon++;
	R_Galleon = A_Galleon + B_Galleon;
	printf("%d.%d.%d\n", R_Galleon, R_Sickle, R_Knut);
	return 0;
}