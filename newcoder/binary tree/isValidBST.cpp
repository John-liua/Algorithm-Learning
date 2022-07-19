/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param root TreeNode类 
     * @return bool布尔型
     */
    void inorder(vector<int> &res,TreeNode* root)
    {
        if(!root)
            return ;
        inorder(res, root->left);
        res.push_back(root->val);
        inorder(res, root->right);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> res;
        inorder(res, root);
        for(int i=0;i<res.size()-1;i++)
        {
            if(res[i]>=res[i+1])
                return false;
        }
        return true;
    }
};