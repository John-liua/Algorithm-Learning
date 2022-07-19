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
    bool isCompleteTree(TreeNode* root) {
        if(!root)
            return true;
        queue<TreeNode*> q;
        bool flag=false;
        q.push(root);
        while(!q.empty())
        {
            for(int i=0;i<q.size();i++)
            {
                TreeNode* cur=q.front();
                q.pop();
                if(!cur)
                    flag=true;
                else{
                    if(flag)
                        return false;
                    q.push(cur->left);
                    q.push(cur->right);
                }
            }
        }
        return true;
    }
};