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
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        if(pRoot==NULL)
            return res;
        deque<TreeNode*>qq;
        qq.push_front(pRoot);
        int cnt=1;
        while(!qq.empty())
        {
            vector<int> temp;
            int size=qq.size();
            if(cnt%2==1)
            {
                for(int i=0;i<size;i++)
                {
                    TreeNode* tt=qq.front();
                    qq.pop_front();
                    temp.push_back(tt->val);
                    if(tt->left)
                        qq.push_back(tt->left);
                    if(tt->right)
                        qq.push_back(tt->right);
                }
            }
            else
            {
                for(int i=0;i<size;i++)
                {
                    TreeNode* tt=qq.back();
                    qq.pop_back();
                    temp.push_back(tt->val);
                    if(tt->right)
                        qq.push_front(tt->right);
                    if(tt->left)
                        qq.push_front(tt->left);
                }
            }
            res.push_back(temp);
            cnt++;
        }
        return res;
    }
    
};