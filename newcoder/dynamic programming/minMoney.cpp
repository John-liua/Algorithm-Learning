class Solution {
public:
    int minMoney(vector<int>& arr, int aim) {
        //小于1的都返回0
        if(aim < 1) 
            return 0;
        //dp[i]表示凑齐i元最少需要多少货币数
        vector<int> dp(aim + 1, aim + 1);  
        dp[0] = 0; 
        //遍历1-aim元
        for(int i = 1; i <= aim; i++){ 
            //每种面值的货币都要枚举
            for(int j = 0; j < arr.size(); j++){ 
                //如果面值不超过要凑的钱才能用
                if(arr[j] <= i) 
                    //维护最小值
                    dp[i] = min(dp[i], dp[i - arr[j]] + 1); 
            }
        }
        //如果最终答案大于aim代表无解
        return dp[aim] > aim ? -1 : dp[aim]; 
    }
};

class Solution {
public:
    int recursion(vector<int>& arr, int aim, vector<int>& dp){
        //组合超过了，返回-1
        if(aim < 0) 
            return -1;
        //组合刚好等于需要的零钱
        if(aim == 0) 
            return 0;
        //剩余零钱是否已经被运算过了
        if(dp[aim] != 0) 
            return dp[aim];
        int Min = INT_MAX;
        //遍历所有面值
        for(int i = 0; i < arr.size(); i++){ 
            //递归运算选择当前的面值
            int res = recursion(arr, aim - arr[i], dp); 
            //获取最小值
            if(res >= 0 && res < Min) 
                Min = res + 1;
        }
        //更新最小值
        dp[aim] = Min == INT_MAX ? -1 : Min; 
        return dp[aim];
    }
    int minMoney(vector<int>& arr, int aim) {
        //小于1的都返回0
        if(aim < 1) 
            return 0;
        //记录递归中间的值
        vector<int> dp(aim+1, 0); 
        return recursion(arr, aim, dp);
    }
};
