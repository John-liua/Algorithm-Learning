class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param str1 string字符串 
     * @param str2 string字符串 
     * @return int整型
     */
    int editDistance(string str1, string str2) {
        int m=str1.length();
        int n=str2.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++)
            dp[i][0]=dp[i-1][0]+1;
        for(int j=1;j<=n;j++)
            dp[0][j]=dp[0][j-1]+1;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(str1[i-1]==str2[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j], dp[i][j-1]))+1;
            }
        }
        return dp[m][n];
    }
};