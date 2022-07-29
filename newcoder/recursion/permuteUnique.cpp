//AC算法，但是不是很理解
class Solution {
public:
    void recursion(vector<vector<int>> &res,vector<int> &num,vector<int> &temp,vector<int> &vis)
    {
        if(temp.size()==num.size()){
            res.push_back(temp);
            return;
        }
        for(int i=0;i<num.size();i++){
            if(vis[i])
                continue;
            if(i>0&&num[i]==num[i-1]&&!vis[i-1])
                continue;
            vis[i]=1;
            temp.push_back(num[i]);
            recursion(res, num, temp,vis);
            vis[i]=0;
            temp.pop_back();
        }
    }
    
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int>> res;
        sort(num.begin(), num.end());
        vector<int> vis(num.size(),0);
        vector<int> temp;
        recursion(res, num,temp,vis);
        return res;
    }
};
//非字典序列算法，但是较好理解
class Solution {
public:
    bool ok(vector<int> &num,int index,int i)
    {
        if(i>index){
            for(int j=index;j<i;j++){
                if(num[j]==num[i])
                    return false;
            }
        }
        return true;
    }
    void recursion(vector<vector<int>> &res,vector<int> &num,int index)
    {
        if(index==num.size())
            res.push_back(num);
        else
        {
            for(int i=index;i<num.size();i++)
            {
                if(ok(num,index,i))
                {
                    swap(num[i],num[index]);
                    recursion(res, num, index+1);
                    swap(num[i],num[index]);
                }
            }
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int>> res;
        sort(num.begin(), num.end());
        recursion(res, num, 0);
        return res;
    }
};