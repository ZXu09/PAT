#include <iostream>
using namespace std;
int main() 
{
    int Num[100010];
    int N;
    scanf("%d", &N);
    for (int i = 0;i < N;i++) {
        scanf("%d", &Num[i]);
    }
    int num = 0;
    for (int i = 0;i < N;i++) {
        if (Num[i] != i) {
            num++;
            while (Num[i] != i) {//环的开始
                if (Num[i] == 0)
                    num--;//有0在的环为环元素个数-1
                else
                    num++;//无0在的环为环元素个数+1
                int tmp = Num[i];
                Num[i] = i;
                i = tmp;//更新i和Num[i]的值
            }
        }
    }
    printf("%d", num);
    return 0;
}
