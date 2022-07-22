/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int n = pre.size();
        int m = vin.size();
        //每个遍历都不能为0
        if(n == 0 || m == 0) 
            return NULL;
        //构建根节点
        TreeNode *root = new TreeNode(pre[0]); 
        for(int i = 0; i < vin.size(); i++){
            //找到中序遍历中的前序第一个元素
            if(pre[0] == vin[i]){ 
                //左子树的前序遍历
                vector<int> leftpre(pre.begin() + 1, pre.begin() + i + 1);  
                //左子树的中序遍历
                vector<int> leftvin(vin.begin(), vin.begin() + i); 
                //构建左子树
                root->left = reConstructBinaryTree(leftpre, leftvin); 
                //右子树的前序遍历
                vector<int> rightpre(pre.begin() + i + 1, pre.end()); 
                //右子树的中序遍历
                vector<int> rightvin(vin.begin() + i + 1, vin.end()); 
                //构建右子树
                root->right = reConstructBinaryTree(rightpre, rightvin); 
                break;
            }
        }
        return root;
    }
};
