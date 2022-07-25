class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        priority_queue<int,vector<int>,greater<int>> q;
        vector<int> res;
        //排除特殊情况
        if(k == 0 || input.size() == 0)
            return res;
        for(int i=0;i<input.size();i++)
            q.push(input[i]);
        for(int i=0;i<k;i++)
        {
            res.push_back(q.top());
            q.pop();
        }
        return res;
    }
};