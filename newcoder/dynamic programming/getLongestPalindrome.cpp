class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param A string字符串 
     * @return int整型
     */
    int getLongestPalindrome(string A) {
        int res=0;
        int step;
        for(int i=0;i<A.size();i++){
            int l=i-1,r=i+1;
            step=1;
            while(r<A.size()&&A[i]==A[r]){
                r++;
                step++;
            }
            while(l>=0&&r<A.size()&&A[l]==A[r]){
                r++;
                l--;
            }
            res=max(res,r-l-1);
        }
        return res;
    }
};