#include<iostream>
using namespace std;

//大顶堆化
void heapify(int a[],int i,int n){
    int left=2*i+1;//左子节点
    int right=2*i+2;//右子节点
    int MaxIndex=i;//默认当前节点为最大节点
    if(left<n&&a[left]>a[MaxIndex])
        MaxIndex=left;
    if(right<n&&a[right]>a[MaxIndex])
        MaxIndex=right;
    if(MaxIndex!=i){ //当前节点不是最大节点，两个数字交换
        swap(a[i],a[MaxIndex]); 
        heapify(a,MaxIndex,n); //检查交换后的子节点是否仍符合大顶堆
    }
}

//构造大顶堆
void buildMaxHeap(int a[],int n){
    //从最后一个非叶子结点开始往前遍历i=n/2-1
    for(int i=n/2-1;i>=0;i--){
        heapify(a,i,n);//对每一个非叶子结点大顶堆化
    }
}

//堆排序
void heapsort(int a[],int n){
    //特殊情况处理
    if(n==0)
        return ;
    //遍历数组，由于采用大顶堆，故从后往前遍历
    for(int i=n;i>0;i--){
        buildMaxHeap(a,i);//构造大顶堆
        swap(a[i-1],a[0]);//大顶堆堆顶（最大的数）与数组最后一位交换
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
    heapsort(a,n);
    //排序后
    for(int i=0;i<n;i++)
        cout<<a[i]<<' ';
    cout<<endl;
    return 0;
}