#include<iostream>

using namespace std;
/*冒泡排序算法的原理如下： 
1.比较相邻的元素。如果第一个比第二个大，就交换他们两个。
2.对每一对相邻元素做同样的工作，从开始第一对到结尾的最后一对。在这一点，最后的元素应该会是最大的数。 
3.针对所有的元素重复以上的步骤，除了最后一个。
4.持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。*/
void bubblesort(int a[],int n)
{
    int i,j;
    for(int i=n-1;i>0;i--)
    {
        for(int j=0;j<i;j++)
        {
            if(a[j]>a[j+1])
            {
                //交换相邻两数字位置
                int temp=0;
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
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
    bubblesort(a,n);
    //排序后
    for(int i=0;i<n;i++)
        cout<<a[i]<<' ';
    cout<<endl;
    return 0;
}