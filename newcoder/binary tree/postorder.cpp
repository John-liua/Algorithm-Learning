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
     * @return int整型vector
     */
    void postorder(vector<int> &res,TreeNode* root)
    {
        if(root==NULL)
            return ;
        postorder(res,root->left);
        postorder(res,root->right);
        res.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder(res,root);
        return res; 
    }
};