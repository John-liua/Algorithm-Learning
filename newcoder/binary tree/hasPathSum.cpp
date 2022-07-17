/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @param sum int整型 
     * @return bool布尔型
     */
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL)
            return false;
        if(root->left==NULL&&root->right==NULL)
            return sum==root->val;
        return hasPathSum(root->left,sum-root->val)||hasPathSum(root->right, sum-root->val);
    }
};