class Solution {
public:
    /**
     * longest common subsequence
     * @param s1 string字符串 the string
     * @param s2 string字符串 the string
     * @return string字符串
     */
    string ans(int i,int j,vector<vector<int>> &dir,string &s1){
        string res="";
        if(i==0||j==0)
            return res;
        if(dir[i][j]==1){
            res+=ans(i-1,j-1,dir,s1);
            res+=s1[i-1];
        }else if (dir[i][j]==2)
            res+=ans(i-1, j, dir,s1);
        else if(dir[i][j]==3)
            res+=ans(i,j-1, dir, s1);
        return res;
    }
    string LCS(string s1, string s2) {
        int len1=s1.length();
        int len2=s2.length();
        if(len1==0||len2==0)
            return "-1";
        vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));
        vector<vector<int>> dir(len1+1,vector<int>(len2+1,0));
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    dir[i][j]=1;
                }else{
                    if(dp[i-1][j]>dp[i][j-1]){
                        dp[i][j]=dp[i-1][j];
                        dir[i][j]=2;
                    }else{
                        dp[i][j]=dp[i][j-1];
                        dir[i][j]=3;
                    }
                }
            }
        }
        string res=ans(len1, len2, dir,s1);
        return res !=""?res:"-1";
    }
};