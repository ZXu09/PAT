#include<iostream>
#include<vector>
using namespace std;
int pre[31];
int post[31];
vector<int>in;
int root;
bool unique = true;
void Traversal(int prel, int prer, int postl, int postr)
{
	if (prel == prer) {//该子树只有一个结点了
		in.push_back(pre[prel]);
		return;
	}
	if (pre[prel] == post[postr]) {//找到左右子树
		int i = prel + 1;//遍历preorder找到右子树（存在）的根结点
		while (i <= prer && pre[i] != post[postr - 1])
			i++;
		//左子树长度i-prel-1
		if (i - prel > 1) {//代表根和右子树之间至少隔了一个结点，也就是有左子树
			Traversal(prel + 1, i - 1, postl, postl + (i - prel - 1) - 1);
		}
		else//假设左子树为空，考虑只有右子树的情况
			unique = false;
		in.push_back(post[postr]);//根
		Traversal(i, prer, postl + (i - prel - 1), postr - 1);
	}
}
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0;i < N;i++) {
		scanf("%d", &pre[i]);
	}
	for (int i = 0;i < N;i++) {
		scanf("%d", &post[i]);
	}
	
	Traversal(0, N - 1, 0, N - 1);
	printf("%s\n%d", unique == true ? "Yes" : "No", in[0]);
	for (int i = 1; i < in.size(); i++)
		printf(" %d", in[i]);
	printf("\n");
	return 0;
}