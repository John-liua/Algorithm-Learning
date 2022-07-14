class Solution {
private:
    const int kmod=1000000007;
public:
    void merge(vector<int>&arr,int l,int mid,int r,int &ret)
    {
        vector<int>tmp(r-l+1);
        int i=l;
        int j=mid+1;
        int k=0;
        while(i<=mid&&j<=r)
        {
            if(arr[i]>arr[j])
            {
                tmp[k++]=arr[j++];
                ret+=(mid-i+1);
                ret%=kmod;
            }
            else
            {
                tmp[k++]=arr[i++];
            }
        }
        while(i<=mid)
            tmp[k++]=arr[i++];
        while(j<=r)
            tmp[k++]=arr[j++];
        for(i=l,k=0;i<=r;++i,++k)
            arr[i]=tmp[k];
    }
    void merge_sort(vector<int>&arr,int l,int r,int &ret)
    {
        if(l>=r)
            return ;
        int mid=(l+r)/2;
        merge_sort(arr, l, mid,ret);
        merge_sort(arr, mid+1, r,ret);
        merge(arr,l,mid,r,ret);
    }
    int InversePairs(vector<int> data) 
    {
        int ret=0;
        merge_sort(data,0,data.size()-1,ret);
        return ret;
    }
};