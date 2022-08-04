class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * longest common substring
     * @param str1 string字符串 the string
     * @param str2 string字符串 the string
     * @return string字符串
     */
    string LCS(string str1, string str2) {
        int max=0;
        int index=0;
        int len1=str1.length();
        int len2=str2.length();
        vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                if(dp[i][j]>max){
                    max=dp[i][j];
                    index=i-1;
                }
            }
        }
        string res;
        for(int i=index-max+1;i<=index;i++){
            res+=str1[i];
        }
        return res;
    }
};