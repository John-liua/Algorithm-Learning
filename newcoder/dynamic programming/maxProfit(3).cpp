class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 两次交易所能获得的最大收益
     * @param prices int整型vector 股票每一天的价格
     * @return int整型
     */
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(5,-10000));
        dp[0][0]=0;
        dp[0][1]=-prices[0];
        for(int i=1;i<n;i++){
            dp[i][0]=dp[i-1][0];
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i]);
            dp[i][2]=max(dp[i-1][2],dp[i-1][1]+prices[i]);
            dp[i][3]=max(dp[i-1][3],dp[i-1][2]-prices[i]);
            dp[i][4]=max(dp[i-1][4],dp[i-1][3]+prices[i]);
        }
        return max(dp[n-1][2],max(0,dp[n-1][4]));
    }
};