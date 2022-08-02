//普通递归
class Solution {
public:
    int Fibonacci(int n) {
        if(n==1||n==2)
            return 1;
        return Fibonacci(n-1)+Fibonacci(n-2);
    }
};
//数组储存结果
class Solution {
public:
    int f[50]{0};
    int Fibonacci(int n) {
        if(n==1||n==2)
            return 1;
        if(f[n]>0)
            return f[n];
        return f[n]=(Fibonacci(n-1)+Fibonacci(n-2));
    }
};
//动态规划
class Solution {
public:
    int dp[50]{0};
    int Fibonacci(int n) {
        dp[1]=1,dp[2]=1;
        for(int i=3;i<n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
//最优解
class Solution {
public:
    int Fibonacci(int n) {
        int a=1,b=1,c=1;
        for(int i=3;i<n;i++){
            c=a+b,a=b,b=c;
        }
        return c;
    }
};