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
     * @param t1 TreeNode类 
     * @param t2 TreeNode类 
     * @return TreeNode类
     */
    
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1==NULL)
            return t2;
        if(t2==NULL)
            return t1;
        TreeNode* head=new TreeNode(t1->val+t2->val);
        head->left=mergeTrees(t1->left, t2->left);
        head->right=mergeTrees(t1->right, t2->right);
        return head;
    }
};