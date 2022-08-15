class Solution {
public:
    /**
     * 
     * @param strs string字符串vector 
     * @return string字符串
     */
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(n==0)
            return "";
        for(int i=0;i<strs[0].length();i++){
            char temp=strs[0][i];
            for(int j=1;j<n;j++){
                if(i==strs[j].length()||strs[j][i]!=temp)
                    return strs[0].substr(0,i);
            }
        }
        return strs[0];
    }
};