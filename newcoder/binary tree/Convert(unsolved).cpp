//法一：中序遍历，把节点储存在数组里，得到从小到大的节点数组，在连接
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    void inorder(vector<TreeNode*> &res,TreeNode* root)
    {
        if(root==NULL)
            return ;
        inorder(res, root->left);
        res.push_back(root);
        inorder(res, root->right);
    }
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if(pRootOfTree==NULL)
            return pRootOfTree;
        vector<TreeNode*> res;
        inorder(res, pRootOfTree);
        for(int i=0;i<res.size()-1;i++)
        {
            res[i]->right=res[i+1];
            res[i+1]->left=res[i];
        }
        return res[0];
    }
};

/*法2:递归调用
1.明确Convert函数的功能。
  输入：输入一个二叉搜索树的根节点。
  过程：将其转化为一个有序的双向链表。
  输出：返回该链表的头节点。

2.明确成员变量pLast的功能。
  pLast用于记录当前链表的末尾节点。

3.明确递归过程。
  递归的过程就相当于按照中序遍历，将整个树分解成了无数的小树，然后将他们分别转化成了一小段一小段的双向链表。
  再利用pLast记录总的链表的末尾，然后将这些小段链表一个接一个地加到末尾。
*/
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
private:
    TreeNode* pLast=NULL; //储存链表尾部
public:
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if(!pRootOfTree)
            return NULL;
        TreeNode* head=Convert(pRootOfTree->left);
        //左子树为空，根节点为表头
        if(!head)
            head=pRootOfTree;
        //链接上一个表尾
        pRootOfTree->left=pLast;
        if(pLast)
            pLast->right=pRootOfTree;
        //更新链表尾部
        pLast=pRootOfTree;
        Convert(pRootOfTree->right);
        return head;
    }
};

//法三：自己写的，还有问题
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    TreeNode* Transform(TreeNode* pRootOfTree)
    {
        if(pRootOfTree->left->left==NULL&&pRootOfTree->left->right==NULL)
            pRootOfTree->left->right=pRootOfTree;
        else
            pRootOfTree->left=Convert(pRootOfTree->left)->right;
        
        if(pRootOfTree->right->left==NULL&&pRootOfTree->right->right==NULL)
            pRootOfTree->right->left=pRootOfTree;
        else
            pRootOfTree->right=Convert(pRootOfTree->right)->left;
        
        return pRootOfTree;
    }
    TreeNode* Convert(TreeNode* pRootOfTree) {
        TreeNode* cur= Transform(pRootOfTree);
        while(!cur->left)
            cur=cur->left;
        return cur;
    }
};