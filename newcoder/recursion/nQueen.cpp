class Solution {
public:
    /**
     * 
     * @param n int整型 the n
     * @return int整型
     */
    bool isValid(vector<int> &pos,int row,int col){
        for(int i=0;i<row;i++){
            if(row==i||col==pos[i]||abs(row-i)==abs(col-pos[i]))
                return false;
        }
        return true;
    }
    void recursion(vector<int> &pos,int n,int row,int &res){
        if(n==row){
            res++;
            return;
        }
        for(int i=0;i<n;i++){
            if(isValid(pos,row,i)){
                pos[row]=i;
                recursion(pos, n,  row+1, res);
            }
        }
    }
    int Nqueen(int n) {
        int res=0;
        vector<int> pos(n,0);
        recursion(pos,n,0,res);
        return res;
    }
};