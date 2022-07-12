//最简单容易想到方法，遍历数组，完全没用到有序这个特性
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 
     * @param target int整型 
     * @return int整型
     */
    int search(vector<int>& nums, int target) {
        int len=nums.size();
        if(len==0)
            return -1;
        for(int i=0;i<len;i++)
        {
            if(nums[i]==target)
                return i;
        }
        return -1;
    }
};
//二分查找，通过不断选取中间值，缩小查找范围。
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 
     * @param target int整型 
     * @return int整型
     */
    int search(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        while(l<=r)
        {
            int m=(l+r)/2;
            if(nums[m]==target)
                return m;
            if(target>nums[m])
                l=m+1;
            else
                r=m-1;
        }
        return -1;
    }
};