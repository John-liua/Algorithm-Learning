class Solution {
public:
    /**
     * max water
     * @param arr int整型vector the array
     * @return long长整型
     */
    long long maxWater(vector<int>& arr) {
        if(arr.size() == 0)
            return 0;
        long long res=0;
        int left = 0,right = arr.size()-1;
        int maxL= 0,maxR = 0;
        while(left<right){
            maxL=max(maxL,arr[left]);
            maxR=max(maxR,arr[right]);
            if(maxR<maxL)
                res += maxR - arr[right--];
            else
                res += maxL - arr[left++];
        }
        return res;
    }
};