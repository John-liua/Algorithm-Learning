class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 递增路径的最大长度
     * @param matrix int整型vector<vector<>> 描述矩阵的每个数
     * @return int整型
     */
    int dirs[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
    int m,n;
    int dfs(vector<vector<int> >& matrix,int i,int j,vector<vector<int>> &dp){
        if(dp[i][j]!=0)
            return dp[i][j];
        dp[i][j]++;
        for(int k=0;k<4;k++){
            int nexti=i+dirs[k][0];
            int nextj=j+dirs[k][1];
            if(nexti>=0&&nexti<n&&nextj>=0&&nextj<m&&matrix[nexti][nextj]>matrix[i][j])
                dp[i][j]=max(dp[i][j],dfs(matrix, nexti, nextj,dp)+1);
        }
        return dp[i][j];
    }
    int solve(vector<vector<int> >& matrix) {
        int res=0;
        n=matrix.size();
        m=matrix[0].size();
        if(n==0||m==0)
            return 0;
        vector<vector<int>> dp(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dfs(matrix,i,j,dp)>res)
                    res=dfs(matrix, i, j, dp);
            }
        }
        return res;
    }
};