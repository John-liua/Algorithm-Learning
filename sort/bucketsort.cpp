#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
void bucketsort(int a[],int n){
    int min=a[0]; //数组中最小值初始化为a[0]
    int max=a[0]; //数组中最大值初始化为a[0]
    //找出数组最大、最小值
    for(int i=1;i<n;i++){
        if(a[i]<min)
            min=a[i];
        if(a[i]>max)
            max=a[i];
    }
    int bucketCounts=(max-min)/n+1;//选取合适的桶数量
    vector< vector<int> > bucketArray; 
    //以桶的形式存放待排序数组
    for(int i=0;i<bucketCounts;i++){
        vector<int> bucket;
        bucketArray.push_back(bucket);
    }
    //待排序数组存入桶
    for(int i=0;i<n;i++){
        int num=(a[i]-min)/n;
        bucketArray[num].push_back(a[i]);
    }
    //对每一个桶用比较好的排序算法排序
    for(int i=0;i<bucketCounts;i++){
        sort(bucketArray[i].begin(),bucketArray[i].end());
    }
    int index=0;//存回原数组
    for(int i=0;i<bucketCounts;i++){
        for(int j=0;j<bucketArray[i].size();j++){
            a[index++]=bucketArray[i][j];
        }
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
    bucketsort(a,n);
    //排序后
    for(int i=0;i<n;i++)
        cout<<a[i]<<' ';
    cout<<endl;
    return 0;
}