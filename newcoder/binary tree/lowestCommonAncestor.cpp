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
     * @param p int整型 
     * @param q int整型 
     * @return int整型
     */
    int res=0;
    int lowestCommonAncestor(TreeNode* root, int p, int q) {
        res=root->val;
        TreeNode* cur=root;
        if(p<res&&q<res){
            cur=cur->left;
            lowestCommonAncestor(cur,  p,  q);
        }
        if(p>res&&q>res){
            cur=cur->right;
            lowestCommonAncestor(cur,  p,  q);
        }
        return res;
    }
};