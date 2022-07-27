class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param array int整型vector 
     * @return int整型vector
     */
    vector<int> FindNumsAppearOnce(vector<int>& array) {
        map<int, int> mp;
        vector<int> res;
        for(int i=0;i<array.size();i++)
        {
            mp[array[i]]++;
        }for(int i=0;i<array.size();i++)
        {
            if(mp[array[i]]==1)
                res.push_back(array[i]);
        }
        if(res[0]<=res[1])
            return res;
        else
            return {res[1],res[0]};
    }
};