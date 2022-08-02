class Solution {
public:
    int dp[50]{0};
    int jumpFloor(int number) {
        dp[0] = 1, dp[1] =1;
        for (int i = 2 ; i <= number ; i ++) dp[i] = dp[i-1]+dp[i-2];
        return dp[number];
    }
};
