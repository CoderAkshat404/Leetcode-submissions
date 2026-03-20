class Solution {
public:
    int solve(int row,int col,vector<vector<int>>& grid, int k){
        set<int> s;
        for(int i=row;i<row+k;i++){
            for(int j=col;j<col+k;j++){
                s.insert(grid[i][j]);
            }
        }
        if(s.size()==1){
            return 0;
        }
        int mini=1e9;
        for(auto i:s){
            for(auto j:s){
                if(i==j){
                    continue;
                }
                mini=min(mini,abs(i-j));
            }
        }
        return mini;
    }
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> ans(n-k+1,vector<int>(m-k+1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i+k-1<n && j+k-1<m){
                    ans[i][j]=solve(i,j,grid,k);
                }
            }
        }
        return ans;
        
    }
};