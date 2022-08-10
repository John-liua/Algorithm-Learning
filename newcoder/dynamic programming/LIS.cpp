class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 给定数组的最长严格上升子序列的长度。
     * @param arr int整型vector 给定的数组
     * @return int整型
     */
    int LIS(vector<int>& arr) {
        vector<int> dp(arr.size(),1);
        int res=0;
        for(int i=1;i<arr.size();i++){
            for(int j=0;j<i;j++){
                if(arr[i]>arr[j]&&dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    res=max(res,dp[i]);
                }
            }
        }
        return res;
    }
};