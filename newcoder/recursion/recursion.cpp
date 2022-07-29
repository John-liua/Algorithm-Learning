class Solution {
public:
    void recursion(vector<vector<int>> &res,vector<int> &num,int index)
    {
        if(index==num.size())
            res.push_back(num);
        else
        {
            for(int i=index;i<num.size();i++)
            {
                swap(num[i],num[index]);
                recursion(res, num, index+1);
                swap(num[i],num[index]);
            }
        }
    }
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int>> res;
        sort(num.begin(), num.end());
        recursion(res, num, 0);
        return res;
    }
};
