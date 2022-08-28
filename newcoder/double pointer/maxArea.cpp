class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param height int整型vector 
     * @return int整型
     */
    int maxArea(vector<int>& height) {
        if(height.size()<2)
            return 0;
        int left = 0,right = height.size()-1;
        int res=0;
        while(left<right){
            int capacity=min(height[left],height[right])*(right-left);
            res = max(res,capacity);
            if(height[left]<height[right])
                left++;
            else
                right--;
        }
        return res;
    }
};