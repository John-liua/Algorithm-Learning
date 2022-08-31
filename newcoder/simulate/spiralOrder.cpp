class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        int n = matrix.size();
        int m = matrix[0].size();
        if(n == 0)
            return res;
        int left = 0,right = m-1;
        int up = 0,down = n-1;
        while(left <= right&&up <= down){
            for(int i = left;i <= right;i++)
                res.push_back(matrix[up][i]);
            up++;
            if(up > down)
                break;
            for(int i = up;i <= down;i++)
                res.push_back(matrix[i][right]);
            right--;
            if(left > right)
                break;
            for(int i = right;i >= left;i--)
                res.push_back(matrix[down][i]);
            down--;
            if(up > down)
                break;
            for(int i = down;i >= up;i--)
                res.push_back(matrix[i][left]);
            left++;
            if(left > right)
                break;
        }
        return res;
    }
};