class Solution {
public:
    string trans(string s, int n) {
        if(n==0)
            return s;
        string res;
        for(int i=0;i<n;i++){
            if (s[i] <= 'Z' && s[i] >= 'A')  
                res += s[i] - 'A' + 'a';
            else if(s[i] >= 'a' && s[i] <= 'z')
                res += s[i] - 'a' + 'A';
            else
                res+=s[i]; 
        }
        reverse(res.begin(), res.end());
        for(int i=0;i<n;i++){
            int j=i;
            while(j<n&&res[j]!=' ')
                j++;
            reverse(res.begin()+i, res.begin()+j);
            i=j;
        }
        return res;
    }
};