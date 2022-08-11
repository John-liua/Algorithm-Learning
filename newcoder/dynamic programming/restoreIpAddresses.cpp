class Solution {
private: 
    //返回答案
    vector<string> res; 
    //记录输入字符串
    string s; 
    //记录分段IP数字字符串
    string nums; 
public:
    //step表示第几个数字，index表示字符串下标
    void dfs(int step, int index){ 
        //当前分割出的字符串
        string cur = ""; 
        //分割出了四个数字
        if(step == 4){ 
            //下标必须走到末尾
            if(index != s.length()) 
                return;
            res.push_back(nums);
        }else{
            //最长遍历3位
            for(int i = index; i < index + 3 && i < s.length(); i++){ 
                cur += s[i];
                //转数字比较
                int num = stoi(cur); 
                string temp = nums;
                //不能超过255且不能有前导0
                if(num <= 255 && (cur.length() == 1 || cur[0] != '0')){ 
                    //添加点
                    if(step - 3 != 0) 
                        nums += cur + ".";
                    else
                        nums += cur;
                    //递归查找下一个数字
                    dfs(step + 1, i + 1); 
                    //回溯
                    nums = temp; 
                }
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        this->s = s;
        dfs(0, 0);
        return res;
    }
};
