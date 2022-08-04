class Solution {
public:
    /**
     * 
     * @param matrix int整型vector<vector<>> the matrix
     * @return int整型
     */
    int minPathSum(vector<vector<int> >& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[0][0]=matrix[0][0];
        for(int i=1;i<m;i++)
            dp[i][0]=matrix[i][0]+dp[i-1][0];
        for(int j=1;j<n;j++)
            dp[0][j]=matrix[0][j]+dp[0][j-1];
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] = matrix[i][j] + (dp[i - 1][j] > dp[i][j - 1] ? dp[i][j - 1] : dp[i - 1][j]);
            }
        }
        return dp[m-1][n-1];
    }
};