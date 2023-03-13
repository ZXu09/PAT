## Traversal
- 通过两个如前序和中序的序列求另一个序列
### 1020 Tree Traversals 25
postorder and inorder -> level order后序中序输出层序
 1. `solve(int PreL, int InL, int PostL, int L, int index);`递归得到前序并记录index
 2. 利用完全二叉树存储index，利用index的大小进行排序输出
```C++
void solve(int PreL, int InL, int PostL, int index, int L)
{
	if (L == 0)//边界条件
		return;
	int root = Postorder[PostL + L - 1];//后序遍历最右侧
	Preorder[PreL].index = index;
	Preorder[PreL].value = root;
	int i;
	for (i = 0;i < N;i++) {
		if (Inorder[InL + i] == root)
			break;
	}
	int l_Length = i;//左子树的长度
	int r_Length = L - l_Length - 1;//右子树的长度
	solve(PreL + 1, InL, PostL, index * 2 + 1, l_Length);
	solve(PreL + l_Length + 1, InL + l_Length + 1, PostL + l_Length, index * 2 + 2, r_Length);
}
```

### 1159 Structure of a Binary Tree 30
通过中序和后序遍历树
- full：所有非叶子结点都有两个子结点
- 询问两个结点之间的关系比如：父子、兄弟、左右、相同层；以及树根
```C++
int inorder[40];
int postorder[40];
int N, M, nodes = 0;//nodes记录结点数量
bool full = true;
struct node
{
    int left = -1, right = -1, level = -1, siblings = -1;//siblings = -1代表无兄妹
}tree[1002];//啊啊啊数组开小了一直没AC
int solve(int length, int postl, int inl, int level)//返回当前子树根节点的数值
{
    if (length == 0)
        return -1;//空结点
    int root = postorder[postl + length - 1];
    int i;
    for (i = 0;i < N;i++) {//找到左子树，此时i就是左子树的大小
        if (inorder[i + inl] == root)
            break;
    }
    int leftlength = i;
    int rightlength = length - i - 1;

    tree[root].level = level;
    tree[root].left = solve(leftlength, postl, inl, level + 1);
    tree[root].right = solve(rightlength, postl + leftlength, inl + leftlength + 1, level + 1);
    tree[tree[root].left].siblings = tree[root].right;
    tree[tree[root].right].siblings = tree[root].left;
    if ((tree[root].left == -1 && tree[root].right != -1) ||
        (tree[root].right == -1 && tree[root].left != -1))
        full = false;
    return root;
}
```

### 1086 Tree Traversals Again 25
**栈和遍历之间的关系**：
 1. PUSH：preorder
 2. POP: inorder
 3. 利用前序和中序遍历solve后序

### 1119 Pre- and Post-order Traversals
给定先序和后序，判断中序及是否唯一  秒极！！
```C++
void Traversal(int prel, int prer, int postl, int postr)
{
	if (prel == prer) {//只有一个结点的子树
		in.push_back(pre[prel]);
		return;
	}
	int i = prel + 1;//pre中找到右子树（存在）的根
	while (i <= prer && pre[i] != post[postr - 1])
		i++;//此时i为右子树的根
	int leftlength = i - prel - 1;//i-prel-1为左子树的长度
	if (i - prel > 1) {//存在左子树()
		Traversal(prel + 1, i - 1, postl, postl + leftlength - 1);
	}
	else//此时只有一边子树，即右子树
		unique = false;
	in.push_back(pre[prel]);//访问根节点
	Traversal(i, prer, postl + leftlength, postr - 1);//若只有一个子树，默认为右子树
}
```

### 1162 Postfix Expression -后缀表达式-后序遍历
- 输入：给定对应的`data left_child right_child`，left和right对应输入的第几行的结点（输入后找到root就相当于已经**建树完成**）
- 建树：给定的输入内包括了左右子树的信息
- 输出：对应树的后缀表达式（**如果只有右子树（语法树不会存在只有左子树没有右子树的情况），那么就在输出当前结点内容后进入右孩子结点继续搜索**）
```C++
void postorder(int root)
{
    if(root == -1)
        return;
    printf("(");

    postorder(tree[root].left);
    if(tree[root].left ==-1&& tree[root].right!=-1){//只有右子树
        cout<<tree[root].data;
        postorder(tree[root].right);
    }
    else{
        postorder(tree[root].right);
        cout<<tree[root].data;
    }
    printf(")");
}
```

## CBT(Complete Binary Tree)
### 1154 Vertex Coloring 25 -完全二叉树的遍历-数组下标（因为给定层序遍历）
**保留路径的遍历->利用数组下标，仅访问叶子结点的反向先序遍历**
- 输入：给出一颗**完全二叉树的层序遍历**
- 建树：**完全二叉树的遍历用数组下标即可，通过2 * index获得左右结点，相当于已经建树完成**
- 输出：打印出从**根节点到所有叶节点的路径**，打印顺序先右后左，即先序遍历的镜像。
- 输出：然后判断该树是**大顶堆、小顶堆或者不是堆**
1. 遍历打印出所有路径（从右往左，即先序的镜像），**vector保存一路上的节点**，通过push和pop回溯，维护路径。  
2. 判断是否为堆：**从第二个节点开始遍历，如果比父节点小，就不是小顶堆**，如果比父节点大，就不是大顶堆
```C++
void traversal(int index) 
{
    //index <= n是对只有左叶节点没有右叶节点的点特判
    if (index * 2 > n && index * 2 + 1 > n) {//叶子结点
        if (index <= n) {
            for (int i = 0; i < v.size(); i++)
                printf("%d%s", v[i], i != v.size() - 1 ? " " : "\n");
        }
    }
    else {
        v.push_back(a[index * 2 + 1]);//右结点入队
        traversal(index * 2 + 1);
        v.pop_back();
        v.push_back(a[index * 2]);//左节点入队
        traversal(index * 2);
        v.pop_back();
    }
}
for (int i = 1; i <= n; i++)
    scanf("%d", &a[i]);
v.push_back(a[1]);//根节点入队
traversal(1);
for (int i = 2; i <= n; i++) {//遍历除根外每一个结点
    if (a[i/2] > a[i]) isMin = 0;
    if (a[i/2] < a[i]) isMax = 0;
}
```

### 1110 Complete Binary Tree 25
- 输入：0 to N−1的结点的左右结点，若无子结点对应"-"
- 建树：自带左右子树信息，已经建树完成
- 输出：判断是否是CBT，是则输出最后一个结点
- 我的方法：Levelorder遍历(利用flag)，若一个结点存在左/右子树且之前已经有结点没有左/右子树，说明不是完全二叉树
- 柳神方法：Inorder遍历找到最大index下标，对比结点数
```C++
struct Node {
	int left, right;
}A[21];
int last;//存储最后一个结点
bool Levelorder(int root)
{
	queue<int>q;
	q.push(root);
	bool flag = true;
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		last = tmp;//不断更新最后一个结点
		if (A[tmp].left == -1)
			flag = false;
		else {
			q.push(A[tmp].left);
			if (!flag)
				return false;
		}
		if (A[tmp].right == -1)
			flag = false;
		else {
			q.push(A[tmp].right);
			if (!flag)
				return false;
		}
	}
	return true;
}
```
## BST(Binary Search Tree)
### 1043  Is It a Binary Search Tree 25 -递归判断是否BST-交叉
- 输入：先序遍历的序列
- 建树：利用递归，即先序遍历中划分左右子树（左边比根小，右边比根大），遍历根结点
- 输出：判断是否是BST，并输出其后序遍历
- 递归思想：对每个根节点，判断其**是否满足BST的定义（左小右大）**
```C++
void PostOrder(int l, int r)//先序遍历最左为根，最右为最大值
{
	if (!flag || l > r)
		return;
	int i = l + 1, j = r;//i为左子树的根，j为右子树最大
	if (!isMirror) {//BST 左小右大
		//注意i<=r是因为存在只有左/右子树的情况，此时j为左子树最大，i要越过j
		while (i <= r && Pre[i] < Pre[l])i++;//比根Pre[l]小，递增
		while (j > l && Pre[j] >= Pre[l])j--;//比根Pre[l]大，递减
	}
	if (isMirror) {
		while (i <= r && Pre[i] >= Pre[l])i++;//比根Pre[l]大，递增
		while (j > l && Pre[j] < Pre[l])j--;//比根Pre[l]小，递减
	}
	if (i - j != 1) {//此时i对应的结点比根小，j对应的结点比根大，相差为1
		flag = false;
		return;
	}
	//后序-左右中
	PostOrder(l + 1, i - 1);//左子树
	PostOrder(i, r);//右子树
	Post.push_back(Pre[l]);//根节点入队
}
 ```
 ```
 
如:8
 6  10
5 7 8 11
pre[]=8 6 5 7 10 8 11 -> 8 6 5 7 10 8 11
 	i          j           j  i
```

### 1064 Complete Binary Search Tree 30 -递归填CBST的值-左子树
**计算左子树长度**  
- 输入：一段序列，然后我们将其排序（得到中序遍历）
- 建树：利用递归，即先序遍历填根结点的值（BST的性质，比左子树的结点都大）
- 输出：这段序列组合成的**完全二叉树的层序遍历**（index实现，也就是对index进行排序）
 1. BST -> level order traversal；排序后的**BST相当于中序遍历**
 2. 利用BST的性质，判断左子树的长度，得到根节点的值（**填值方式，类似先序遍历**），这期间顺便记录每个结点的index
 3. 层序遍历：利用index，即root
```C++
void Sort_CBT(int L, int index, int treeL, int lnode)//lnode用于累加
{
	if (L == 0)
		return;
	int level = 1;//计算N个结点的完全二叉树的高度
	int lastlevel;//最后一层的结点数
	int maxlevel;//最后一层最多的结点数
	while ((pow(2, level / 1.0) - 1) < L) {
		level++;
	}
	lastlevel = L - (pow(2, (level - 1) / 1.0) - 1);
	maxlevel = pow(2, (level - 1) / 1.0);

	int leftnode = LeftNode(maxlevel, lastlevel, level);
	int rightnode = L - leftnode - 1;

	Tree[treeL].index = index;
	Tree[treeL].value = Array[leftnode + lnode];//数值比左子树都大，同时也关乎自己的根节点的位置
	Sort_CBT(leftnode, 2 * index + 1, treeL + 1, lnode);
	//加上左子树和根节点的
	Sort_CBT(rightnode, 2 * index + 2, treeL + 1 + leftnode, lnode + leftnode + 1);
}
```

### 1099 Build A Binary Search Tree 30
- 输入：给定0 to N−1的结点的左结点和右结点的下标，以及N个待填入BST的值
- 建树：**inorder中序遍历填值**，比上面一题简单，因为已经有了树的结构
- 输出：层序遍历的结果

```C++
struct Node
{
	int left, right, data;
};
void inOrder(int root)//中序遍历填值
{
	if (root == -1) return;
	inOrder(T[root].left); //-1也要插入
	T[root].data = key[num++];
	inOrder(T[root].right);
}
void Levelorder(int root)
{
	queue<int> q;
	q.push(root);
	bool flag = false;//控制输出格式
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		if (!flag) {
			cout << Array[tmp].data;
			flag = true;
		}
		else cout << " " << Array[tmp].data;
		if (Array[tmp].left != -1)
			q.push(Array[tmp].left);
		if (Array[tmp].right != -1)
			q.push(Array[tmp].right);
	}
}
```
### 1102 Invert a Binary Tree 25
类似1099的解决方法

### 1115 Counting Nodes in a Binary Search Tree
求一个二叉搜索树最后两层的结点
```C++
struct Node
{
	int data;
	PNode left, right;
};

PNode Build(PNode root, int data)
{
	if (root == NULL) {
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if (data <= root->data)
		root->left = Build(root->left, data);
	else
		root->right = Build(root->right, data);
	return root;
}
int Num[1010];//存储对应层数的结点个数
int maxdepth = -1;//由于会递归到空结点，故为最深的层数+1

void Inorder(PNode root, int depth) {
	if (root == NULL) {
		maxdepth = max(depth, maxdepth);
		return;
	}
	Num[depth]++;
	Inorder(root->left, depth + 1);
	Inorder(root->right, depth + 1);
}
```

## 树状数组

 1. 单点修改：更改数组中一个元素的值
 2. 区间查询：查询一个区间内所有元素的和
 
- 例如11，转化为二进制数就是1011，如果我们要求前11项和，可以分别查询 [(0000),(1000)]、[(1000),(1010)]以及[(1010),(1011)]的和再相加。
- 这三个区间怎么来的呢？其实就是不断地去掉二进制数最右边的一个1的过程
- 1011->1010->1000 对应c[1011]+c[1010]+c[1000]

### 1057 Stack 30 -求栈中元素的中位数
- 树状数组，方便求sum和进行修改；时间复杂度均为O(logN)
- 本题的核心在于求第k = (s.size() + 1) / 2大的数。查询小于等于x的数的个数是否等于k

 1. `int c[maxn]`树状数组，c[i]代表其子树结点出现的次数
 2. `#define lowbit(i) ((i)&(-i))`取最低位的1，最右边的1连带后面的0，比如10100->100
 3. 
```C++
void update(int x, int v)//单点修改(v代表出现了x的次数)
{
	//1011->1100->10000(1011、1100都是10000的子树!)
	for (int i = x;i < maxn;i += lowbit(i){
		c[i] += v;//顺着树向上爬
	}
}
int getsum(int x)//区域查询,小于等于x的数的个数
{
	int sum = 0;
	//比如111->110->100
	//这个过程类似于同层进行爬，不会重复统计到共同树根1000
	for (int i = x;i >= 1;i -= lowbit(i)) 
		sum += c[i];
	}
	return sum;
}
void PeekMedian() //二分法
{
	int left = 1, right = maxn, mid;//Key保证>0
	int k = (s.size() + 1) / 2;//代表要求的第k大小的数
	while (left < right) {
		mid = (left + right) / 2;
		if (getsum(mid) >= k)//小于等于mid的数的个数大于k个
			right = mid;
		else
			left = mid + 1;
	}
	printf("%d\n", left);
}
```

## AVL树（平衡二叉树）
An AVL tree is a self-balancing binary search tree.  
利用定义实现

### 1066 Root of AVL Tree 25
- 给定一段序列要求插入AVL树中
```C++
BinTree LL(BinTree T)
{
	BinTree B = T->left;
	T->left = B->right;
	B->right = T;
	T->height = Max(GetHeight(T->left), GetHeight(T->right)) + 1;
	B->height = Max(GetHeight(B->left), T->height) + 1;
	return B;
}
BinTree LR(BinTree T)
{
	T->right = RR(T->right);
	return LL(T);
}
BinTree Insert(BinTree T, int V)
{
	if (!T)
		T = MakeTree(V);//在此处创建新的结点
	else if (V < T->data) {
		T->left = Insert(T->left, V);//一路递归到插入新结点
		//自更新结点的路径向上调整AVL树
		if (GetHeight(T->left) - GetHeight(T->right) == 2) {
			if (V < T->left->data)
				T = LL(T);
			else
				T = LR(T);
		}
	}
	else if (V > T->data) {
		T->right = Insert(T->right, V);
		//自更新结点的路径向上调整AVL树
		if (GetHeight(T->right) - GetHeight(T->left) == 2) {
			if (V > T->right->data)
				T = RR(T);
			else
				T = RL(T);
		}
	}
	T->height = Max(GetHeight(T->left), GetHeight(T->right)) + 1;
	return T;
}
```

### 1123 Is It a Complete AVL Tree 30
AVL树的知识以及1110 Complete Binary Tree的Levelorder遍历(利用flag)

