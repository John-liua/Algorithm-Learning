#include<iostream>

using namespace std;
void countsort(int a[],int n){
    int min=a[0]; //数组中最小值初始化为a[0]
    int max=a[0]; //数组中最大值初始化为a[0]
    //找出数组最大、最小值
    for(int i=1;i<n;i++){
        if(a[i]<min)
            min=a[i];
        if(a[i]>max)
            max=a[i];
    }
    //以临时数组的下标表示待排序数组中的数值
    int len=max-min+1; //临时数组的长度
    int temp[len];//临时数组初始化为0
    for(int i=0;i<len;i++){
        temp[i]=0;
    }
    int diff=0-min; //记录待排序数组最小值与临时数组下标的偏移量
    //记录待排序数组各数值出现次数
    for(int i=0;i<n;i++){
        temp[a[i]+diff]++;
    }
    //利用临时数组排序，重置待排序数组
    for(int i=0,j=0;i<n;i++){//i为待排序数组下标，j为临时数组下标
        while(temp[j]==0){
            j++;
        }
        a[i]=j-diff;
        temp[j]--;
    }
}
int main()
{
    //测试，输入任意数组
    int n;//n为数组长度
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    //排序前
    for(int i=0;i<n;i++)
        cout<<a[i]<<' ';
    cout<<endl;
    countsort(a,n);
    //排序后
    for(int i=0;i<n;i++)
        cout<<a[i]<<' ';
    cout<<endl;
    return 0;
}