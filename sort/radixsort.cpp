#include<iostream>
#include<vector>
#include<algorithm>
#define RADIX 10
using namespace std;
//找出最大数字位数
int getCounts(int a[],int n){
    int max=a[0]; //数组中最大值初始化为a[0]
    //找出数组最大、最小值
    for(int i=1;i<n;i++){
        if(a[i]>max)
            max=a[i];
    }
    int count=1;//记录位数
    while (max/10>0){
        max/=10;
        count++;
    }
    return count;
}
//寻找数字某一位上的数字大小
int getPosition(int num,int pos){
    for(int i=0;i<pos;i++)
        num/=10;
    int ret=num%10;
    return ret;
} 

void radixsort(int a[],int n){
    int maxCount=getCounts(a,n);//最大位数
    vector< vector<int> > radixArray;
    //以桶的形式存放待排序数组，RADIX为基数（桶的个数），即每一位数字的大小(0-9)
    for(int i=0;i<RADIX;i++){
        vector<int> bucket;
        radixArray.push_back(bucket);
    }
    for(int i=0;i<maxCount;i++){ //从个位开始遍历
        for(int j=0;j<n;j++){
            int num=getPosition(a[j],i); //记录每一个数字的第i位的大小
            radixArray[num].push_back(a[j]); //放入对应的桶中
        }
        int index=0;//桶中的数字重新放回原数组，完成第i位的排序
        for(int k=0;k<RADIX;k++){
            for(int s=0;s<radixArray[k].size();s++)
                a[index++]=radixArray[k][s];
            radixArray[k].clear();//桶里数字放回原数组后不要忘记清空桶中数字，便于下次push
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
    radixsort(a,n);
    //排序后
    for(int i=0;i<n;i++)
        cout<<a[i]<<' ';
    cout<<endl;
    return 0;
}