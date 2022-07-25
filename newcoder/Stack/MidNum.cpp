class Solution {
public:
    vector<int> val;
    void Insert(int num) {
        if(val.empty())
            val.push_back(num);
        else
        {
            int i=0;
            for(;i<val.size();i++)
            {
                if(num<=val[i])
                    break;
            }
            val.insert(val.begin()+i,num);
        }
    }

    double GetMedian() { 
        int n=val.size();
        if(n%2==0)
        {
            double a=val[n/2];
            double b=val[n/2-1];
            return (a+b)/2;
        }
        else
            return double(val[n/2]);  
    }
};