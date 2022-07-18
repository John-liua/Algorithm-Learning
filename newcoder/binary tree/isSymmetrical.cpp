/*思路：

前序遍历的时候我们采用的是“根左右”的遍历次序，如果这棵二叉树是对称的，即相应的左右节点交换位置完全没有问题，那我们是不是可以尝试“根右左”遍历，
按照轴对称图像的性质，这两种次序的遍历结果应该是一样的。

不同的方式遍历两次，将结果拿出来比较看起来是一种可行的方法，但也仅仅可行，太过于麻烦。我们不如在遍历的过程就结果比较了。而遍历方式依据前序递归可以使用递归：

终止条件： 当进入子问题的两个节点都为空，说明都到了叶子节点，且是同步的，因此结束本次子问题，返回true；当进入子问题的两个节点只有一个为空，或是元素值不相等，说明这里的对称不匹配，同样结束本次子问题，返回false。
返回值： 每一级将子问题是否匹配的结果往上传递。
本级任务： 每个子问题，需要按照上述思路，“根左右”走左边的时候“根右左”走右边，“根左右”走右边的时候“根右左”走左边，一起进入子问题，需要两边都是匹配才能对称。
具体做法：

step 1：两种方向的前序遍历，同步过程中的当前两个节点，同为空，属于对称的范畴。
step 2：当前两个节点只有一个为空或者节点值不相等，已经不是对称的二叉树了。
step 3：第一个节点的左子树与第二个节点的右子树同步递归对比，第一个节点的右子树与第二个节点的左子树同步递归比较。
*/
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    bool recursion(TreeNode* root1,TreeNode* root2)
    {
        if(root1==NULL&&root2==NULL)
            return true;
        if(root1==NULL||root2==NULL||root1->val!=root2->val)
            return false;
        return recursion(root1->left, root2->right)&&recursion(root1->right, root2->left);
    }
    bool isSymmetrical(TreeNode* pRoot) {
        return recursion(pRoot,pRoot);
    }
};