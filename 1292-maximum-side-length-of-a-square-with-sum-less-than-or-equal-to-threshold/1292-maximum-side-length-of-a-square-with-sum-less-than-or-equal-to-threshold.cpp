class Solution {
public:
   
    int P[300][300];
    vector<vector<int>> Arr; 

    void computePrefixSum(int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            P[i][j] = Arr[i][j];
            if (i > 0) P[i][j] += P[i - 1][j];
            if (j > 0) P[i][j] += P[i][j - 1];
            if (i > 0 && j > 0) P[i][j] -= P[i - 1][j - 1];
        }
    }
    }
    int queryRectangleSum(int U, int L, int D, int R) {
    int ans = P[D][R];
    if (L > 0) ans -= P[D][L - 1];
    if (U > 0) ans -= P[U - 1][R];
    if (U > 0 && L > 0) ans += P[U - 1][L - 1];
    return ans;
    }
    int maxSideLength(vector<vector<int>>& grid, int threshold) {
        Arr=grid;
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        computePrefixSum(n,m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<min(n,m);k++){
                    if(i+k<n && j+k<m){
                    int u=i;
                    int l=j;
                    int d=i+k;
                    int r=j+k;
                    if(queryRectangleSum(u,l,d,r)<=threshold){
                        ans=max(ans,k+1);

                    }}


                   
                }
            }
        }
        return ans;
        
    }
};