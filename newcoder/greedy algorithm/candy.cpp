class Solution {
public:
    /**
     * pick candy
     * @param arr int整型vector the array
     * @return int整型
     */
    int candy(vector<int>& arr) {
        vector<int> nums(arr.size(),1);
        for(int i = 1;i <arr.size();i++){
            if(arr[i]>arr[i-1])
                nums[i]=nums[i-1] + 1;
        }
        int res = nums[arr.size()-1];
        for(int i=arr.size()-2;i>=0;i--){
            if(arr[i]>arr[i+1]&&nums[i]<=nums[i+1])
                nums[i]=nums[i+1]+1;
            res+= nums[i];
        }
        return res;
    }
};