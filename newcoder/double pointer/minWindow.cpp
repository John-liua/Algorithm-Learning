class Solution {
public:
    /**
     * 
     * @param S string字符串 
     * @param T string字符串 
     * @return string字符串
     */
    bool check(unordered_map<char, int> &hash){
        for(auto iter = hash.begin(); iter != hash.end(); iter++){
            if(iter->second<0)
                return false;
        }
        return true;
    }
    string minWindow(string S, string T) {
        int cnt = S.length()+1;
        unordered_map<char, int> hash;
        for(int i = 0; i<T.length(); i++)
            hash[T[i]] -=1;
        int slow = 0,fast = 0;
        int left = -1,right = -1;
        for(; fast < S.length(); fast++){
            char c = S[fast];
            if(hash.count(c))
                hash[c]++;
            while(check(hash)){
                if(cnt > fast - slow + 1){
                    cnt = fast - slow + 1;
                    left = slow;
                    right = fast;
                }
                char c = S[slow];
                if(hash.count(c))
                    hash[c]--;
                slow++;
            }
        }
        if(left == -1)
            return "";
        return string(S.begin() + left, S.begin() + (right + 1));
    }
};