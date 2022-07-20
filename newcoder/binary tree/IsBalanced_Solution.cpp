class Solution {
public:
    //树的最大深度
    int Depth(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        return max(Depth(root->left),Depth(root->right))+1;
    }
    //子树高度差
    int childHeight(TreeNode* root1,TreeNode* root2)
    {
        int h1,h2;
        h1=Depth(root1);
        h2=Depth(root2);
        return abs(h1-h2);
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(!pRoot)//空树为平衡二叉树
            return true;
        if(childHeight(pRoot->left, pRoot->right)>1)
            return false;
        return IsBalanced_Solution(pRoot->left)&&IsBalanced_Solution(pRoot->right);
    }
};