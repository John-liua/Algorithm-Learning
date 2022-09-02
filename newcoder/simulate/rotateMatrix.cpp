class Solution {
public:
    vector<vector<int> > rotateMatrix(vector<vector<int> > mat, int n) {
        vector<vector<int>> res(n,vector<int>(n,0));
        for(int i = n-1;i >= 0;i--){
            for(int j = 0;j < n;j++){
                res[j][i] = mat[n-1-i][j];
            }
        }
        return res;
    }
};