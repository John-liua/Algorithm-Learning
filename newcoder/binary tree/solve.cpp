class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 求二叉树的右视图
     * @param xianxu int整型vector 先序遍历
     * @param zhongxu int整型vector 中序遍历
     * @return int整型vector
     */
    //建树
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int m=pre.size();
        int n=vin.size();
        if(n==0||m==0)
            return NULL;
        TreeNode* root=new TreeNode(pre[0]);
        for(int i=0;i<n;i++)
        {
            if(vin[i]==pre[0])
            {
                vector<int> leftpre(pre.begin()+1,pre.begin()+i+1);
                vector<int> leftvin(vin.begin(),vin.begin()+i);
                root->left=reConstructBinaryTree(leftpre, leftvin);
                vector<int> rightpre(pre.begin()+i+1,pre.end());
                vector<int> rightvin(vin.begin()+i+1,vin.end());
                root->right=reConstructBinaryTree(rightpre, rightvin);
                break;
            }
        }
        return root;
    }
    //层次遍历，保存最右元素
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size(); //队列中的大小即是这一层的结点树
            while(size--)
            {
                TreeNode* temp = q.front();
                q.pop();             
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                if(size == 0) //最右元素
                    res.push_back(temp->val);
            }
        }
        return res;
    }
    vector<int> solve(vector<int>& xianxu, vector<int>& zhongxu) {
        TreeNode* root=reConstructBinaryTree(xianxu, zhongxu);
        return rightSideView(root);
    }
};