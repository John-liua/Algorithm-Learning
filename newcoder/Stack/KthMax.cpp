class Solution {
public:
    int findKth(vector<int> a, int n, int K) {
        int b[n];
        for(int i=0;i<n;i++)
            b[i]=a[i];
        sort(b, b+n);
        return b[n-K];
    }
};