#include<iostream>

using namespace std;

void merge(int a[],int l,int mid,int r)
{
    //i代表左边数组当前元素，j代表右边数组当前元素，t代表临时数组当前元素
    int i=l,j=mid+1,t=0;
    //临时数组大小取决于待合并的两数组长度之和
    int temp[r-l+1];
    //两个数组都没分配完时
    while(i<=mid&&j<=r)
    {
        if(a[i]>a[j])
            temp[t++]=a[j++];
        else
            temp[t++]=a[i++];
    }
    //右边数组已经分配完时
    while(i<=mid)
    {
        temp[t++]=a[i++];
    }
    //左边数组已经分配完时
    while(j<=r)
    {
        temp[t++]=a[j++];
    }
    //更新a数组
    for(int k=l,t=0;k<=r;k++,t++)
    {
        a[k]=temp[t];
    }
}
//分数组，每次对半分，直到只剩一个元素，l代表左边界，r代表右边界
void mergesort(int a[],int l,int r)
{
    if(l<r)
    {
        int mid=(l+r)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,r);
        merge(a,l,mid,r);
    }
}
int main()
{
    //测试
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    //排序前
    for(int i=0;i<n;i++)
        cout<<a[i]<<' ';
    cout<<endl;
    mergesort(a,0,n-1);
    //排序后
    for(int i=0;i<n;i++)
        cout<<a[i]<<' ';
    cout<<endl;
    return 0;
}