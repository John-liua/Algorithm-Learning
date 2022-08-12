class Solution {
public:
    /**
     * 
     * @param s string字符串 
     * @return int整型
     */
    int longestValidParentheses(string s) {
        int res=0;
        int start=-1;
        stack<int> stk;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')
                stk.push(i);
            else{
                if(stk.empty())
                    start=i;
                else{
                    stk.pop();
                    if(!stk.empty())
                        res=max(res,i-stk.top());
                    else
                        res=max(res,i-start);
                }
            }
        }
        return res;
    }
};