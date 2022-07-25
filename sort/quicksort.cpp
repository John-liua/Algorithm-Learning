#include<iostream>

using namespace std;

//调整数组,并返回分界点
int adjustArray(int a[],int l,int r)
{
    int i=l,j=r;
    //随机选择一个位置的数，找到它应该在数组中的位置，这里选择第一个数字
    int x=a[i];
    while (i<j)
    {
        //数组最右端开始遍历，直到找到小于x的数，放入a[i]
        while (i<j&&a[j]>=x)
            j--;
        if(i<j)
        {
            a[i]=a[j];
            i++;
        }
        //数组最左端开始遍历，直到找到大于x的数，放入a[j]
        while(i<j&&a[i]<=x)
            i++;
        if(i<j)
        {
            a[j]=a[i];
            j--;
        }
    }
    //x放入它应该在数组中的位置,此时i=j
    a[i]=x;
    return i;
}
//分治排序
void quicksort(int a[],int l,int r)
{
    if(l<r)
    {
        int x=adjustArray(a,l,r);
        quicksort(a,l,x-1);
        quicksort(a,x+1,r);
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
    quicksort(a,0,n-1);
    //排序后
    for(int i=0;i<n;i++)
        cout<<a[i]<<' ';
    cout<<endl;
    return 0;
}