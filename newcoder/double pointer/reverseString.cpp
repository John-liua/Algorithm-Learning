class Solution {
public:
    string solve(string str) {
        string ans = str;
        int len = str.length();
        for(int i = 0 ; i < len ;i++)
        {
                ans[i] = str[len-1-i];
        }
        return ans;
    }
};