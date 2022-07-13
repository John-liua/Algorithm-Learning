//暴力搜索，从头开始搜索峰值，找到即return，若无峰值返回0
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 
     * @return int整型
     */
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(nums[0]>nums[1])//首元素处理
            return 0;
        if(nums[n-1]>nums[n-2])//尾元素处理
            return n-1;
        for(int i=1;i<n-1;i++)
        {
            if(nums[i]>nums[i-1]&&nums[i]>nums[i+1])
                return i;
        }
        return 0;
    }
};
//二分查找，因为每个相邻元素不等，且nums[-1],nums[n]都是负无穷，故0到n-1一定存在波峰
//每次取中间值mid和mid+1比较，mid大意味着left到mid中间一定有一个波峰，因此想做压缩区间。向右同理
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 
     * @return int整型
     */
    int findPeakElement(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;
        while(left<right)
        {
            int mid=(left+right)/2;
            if(nums[mid]>nums[mid+1])
                right=mid;
            else
                left=mid+1;
        }
        return left;
    }
};