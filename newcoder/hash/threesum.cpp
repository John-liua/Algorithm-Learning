class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> res;
        int n=num.size();
        if(n<3)
            return res;
        sort(num.begin(), num.end());
        for(int i=0;i<n-2;i++)
        {
            //相等的数无需重复计算
            if(i!=0&&num[i]==num[i-1])
                continue;
            int j=i+1,k=n-1;
            while(j<k)
            {
                if(num[j]+num[k]>(-num[i]))
                    k--;
                else if(num[j]+num[k]<(-num[i]))
                    j++;
                else
                {
                    res.push_back({num[i],num[j],num[k]});
                    //降重
                    while(j+1<k&&num[j]==num[j+1])
                        j++;
                    while(j+1<k&&num[k]==num[k-1])
                        k--;
                    j++;
                    k--;
                }
            }
        }
        return res;
    }
};