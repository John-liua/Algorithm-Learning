#include<iostream>

using namespace std;

void shellsort(int a[],int n){
    //设置gap，即要比较的两个数字在数组中相隔的距离
    for(int gap=n/2;gap>0;gap/=2){
        //下面就是插入排序，不过把每次比较的是相邻gap的数字
        for(int i=gap;i<n;i++){
            for(int j=i;j>=gap;j-=gap){
                if(a[j-gap]>a[j])
                    swap(a[j],a[j-gap]);
                else
                    break;
            }
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
    shellsort(a,n);
    //排序后
    for(int i=0;i<n;i++)
        cout<<a[i]<<' ';
    cout<<endl;
    return 0;
}