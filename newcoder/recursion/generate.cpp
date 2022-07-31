class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param n int整型 
     * @return string字符串vector
     */
    void recursion(vector<string> &res,int n,string temp,int l,int r){
        if(l==n&&r==n){
            res.push_back(temp);
            return;
        }
        if(l<n){
            recursion(res, n, temp+'(', l+1, r);
        }
        if(r<l&&r<n){
            recursion(res, n, temp+')', l, r+1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string temp;
        recursion(res,n,temp,0,0);
        return res;
    }
};