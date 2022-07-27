#include<iostream>

using namespace std;

void insertsort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j>0;j--)
        {
            //只要当前a[j]比前一位小，就交换位置，直到a[j]换到合适的位置
            if(a[j]<a[j-1])
                swap(a[j],a[j-1]);
            else
                break;       
        }
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
    insertsort(a,n);
    //排序后
    for(int i=0;i<n;i++)
        cout<<a[i]<<' ';
    cout<<endl;
    return 0;
}