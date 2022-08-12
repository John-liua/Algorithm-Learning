class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param str string字符串 
     * @param pattern string字符串 
     * @return bool布尔型
     */
    bool match(string str, string pattern) {
        int m=str.length();
        int n=pattern.length();
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
        dp[0][0]=true;
        for(int i=2;i<=n;i++){
            if(pattern[i-1]=='*')
                dp[0][i]=dp[0][i-2];
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(str[i-1]==pattern[j-1]||pattern[j-1]=='.')
                    dp[i][j]=dp[i-1][j-1];
                if(pattern[j-1]=='*'&&j>=2){
                    if(pattern[j-2]=='.'||pattern[j-2]==str[i-1])
                        dp[i][j]=dp[i-1][j]||dp[i][j-2];
                    else
                        dp[i][j]=dp[i][j-2];
                }
            }
        }
        return dp[m][n];
    }
};