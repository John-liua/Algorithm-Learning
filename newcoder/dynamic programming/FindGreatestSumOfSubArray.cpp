class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        vector<int> dp(array.size(),0);
        dp[0]=array[0];
        int Max=dp[0];
        for(int i=1;i<array.size();i++){
            dp[i]=max(dp[i-1]+array[i],array[i]);
            Max=max(Max,dp[i]);
        }
        return Max;
    }
};