class Solution {
public:
    /**
     * 
     * @param numbers int整型vector 
     * @param target int整型 
     * @return int整型vector
     */
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int, int> hashmap;
        vector<int> res;
        for(int i=0;i<numbers.size();i++)
        {
            auto it=hashmap.find(target-numbers[i]);
            if(it!=hashmap.end())
            {
                res.push_back((it->second<i?it->second:i)+1);
                res.push_back((it->second>i?it->second:i)+1);
                return res;
            }
            hashmap[numbers[i]]=i;
        }
        return res;
    }
};