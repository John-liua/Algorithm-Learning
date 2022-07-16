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
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL)
            return res;
        queue<TreeNode*>qq;
        qq.push(root);
        while(!qq.empty())
        {
            vector<int> temp;
            int size=qq.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* tt=qq.front();
                qq.pop();
                temp.push_back(tt->val);
                if(tt->left)
                    qq.push(tt->left);
                if(tt->right)
                    qq.push(tt->right);
            }
            res.push_back(temp);
        }
        return res;
    }
};