class Solution {
public:
    //处理序列化的功能函数（递归）
    void SerializeFunction(TreeNode* root, string& str){
        //如果指针为空，表示左子节点或右子节点为空，用#表示
        if(root == NULL){
            str += '#';
            return;
        }
        //根节点
        string temp = to_string(root->val); 
        str += temp + '!';// 加!，区分节点 
        //左子树
        SerializeFunction(root->left, str); 
        //右子树
        SerializeFunction(root->right, str);
    }
    char* Serialize(TreeNode *root) { 
        //处理空树   
        if(root == NULL) 
            return "#";
        string res;
        SerializeFunction(root, res);
        //把str转换成char
        char* charRes = new char[res.length() + 1];
        strcpy(charRes, res.c_str());
        charRes[res.length()] = '\0';
        return charRes;
    }
    //处理反序列化的功能函数（递归）
    TreeNode* DeserializeFunction(char** str){
        //到达叶节点时，构建完毕，返回继续构建父节点
        //双**表示取值
        if(**str == '#'){ 
            (*str)++;
            return NULL;
        }
        //数字转换
        int val = 0;
        while(**str != '!' && **str != '\0'){
            val = val * 10 + ((**str) - '0');
            (*str)++;
        }
        TreeNode* root = new TreeNode(val);
        //序列到底了，构建完成
        if(**str == '\0') 
            return root;
        else
            (*str)++;
        //反序列化与序列化一致，都是前序
        root->left = DeserializeFunction(str);  
        root->right = DeserializeFunction(str);
        return root;
    }
    TreeNode* Deserialize(char *str) {
        //空序列对应空树
        if(str == "#"){ 
            return NULL;
        }
        TreeNode* res = DeserializeFunction(&str);
        return res;
    }
};
