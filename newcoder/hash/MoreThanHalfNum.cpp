class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        map<int, int> hashmap;
        int n=numbers.size();
        for(int i=0;i<n;i++)
        {
            hashmap.insert({numbers[i],i});
            if(hashmap.count(numbers[i])>n/2)
                return numbers[i];
        }
        return 0;
    }
};