//法一：暴力搜索，不多细讲。
//法二：对一行内二分查找；从上往下遍历每一行。
//法三：线性搜索：对于一个位置上的数，它上面的一定比他小，它右面的一定比他大，构成线性序列。从左下角开始搜索。
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.size()==0)
            return false;
        int col=array[0].size();
        int row=array.size();
        int x=row-1;
        int y=0;
        while(0<=x&&x<=row-1&&0<=y&&y<=col-1)
        {
            if(array[x][y]==target)
                return true;
            if(array[x][y]>target)
                x=x-1;
            else
                y=y+1;
        }
        return false;
    }
};
//法四：双二分查找：
class Solution {
public:
    bool double_binary(vector<vector<int>> arr,int x1,int x2,int y1, int y2,int target){
        //边界值处理
        if(x1 == x2 || y1 == y2) 
            return false;
        int xmid = (x1+x2)/2, ymid = (y1+y2)/2;
        int num = arr[xmid][ymid];
        if(num == target)
            return true;
        if(num > target) //排除右下的四分之一
        {
           if(double_binary(arr, x1, xmid, y1, y2, target))   //左边部分
                return true;
           if(double_binary(arr,xmid,x2,y1,ymid,target))    //右上部分
                return true;
        }
        else //排除左上的四分之一
        {
            if(double_binary(arr, xmid+1, x2, y1, y2, target))   //右边部分
                return true;
            if(double_binary(arr, x1, xmid+1, ymid+1, y2, target))   //左下部分
                return true;
        }
        return false;
    }
    bool Find(int target, vector<vector<int> > array) {
        if(array.size() == 0) 
            return false;
        return double_binary(array, 0, array.size(), 0, array[0].size(), target);
    }
};
