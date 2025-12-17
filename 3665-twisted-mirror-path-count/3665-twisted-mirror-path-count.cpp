class Solution {
public:
    int dp[501][501][2];
    int mod=1e9+7;
    int solve(int i,int j,int prev,int n,int m,vector<vector<int>>& grid){
        if(i==n-1 && j==m-1){
            return 1;
        }
        if(i>=n || j>=m){
            return 0;
        }
        if(dp[i][j][prev]!=-1){
            return dp[i][j][prev];
        }
        if(grid[i][j]==0){
            return dp[i][j][prev]=(solve(i+1,j,0,n,m,grid)+solve(i,j+1,1,n,m,grid))%mod;
        }
        else{
            if(prev==0){
                return dp[i][j][prev]=solve(i,j+1,1,n,m,grid);
            }
            if(prev==1){
                return dp[i][j][prev]=solve(i+1,j,0,n,m,grid);
            }
        }
        return 69;

    }
    int uniquePaths(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int n=grid.size();
        int m=grid[0].size();
        return solve(0,0,0,n,m,grid);

        
        
    }
};