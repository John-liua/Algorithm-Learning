class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int l=0,r=rotateArray.size()-1;
        if(r==-1)
            return 0;
        while(l<r)
        {
            int mid=(l+r)/2;
            if(rotateArray[mid]>rotateArray[r])
                l=mid+1;
            else if(rotateArray[mid]<rotateArray[r])
                r=mid;
            else
                r=r-1;
        }
        return rotateArray[l];
    }
};