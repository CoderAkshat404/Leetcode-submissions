class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& grid, vector<vector<int>>&dp){
        if(i>=grid.size() || j>=grid[0].size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(j+1<grid[0].size() && grid[i][j+1]>grid[i][j]){
            ans=max(ans,1+solve(i,j+1,grid,dp));
        }
        if(i+1<grid.size() && j+1<grid[0].size() && grid[i+1][j+1]>grid[i][j]){
            ans=max(ans,1+solve(i+1,j+1,grid,dp));
        }
        if(i-1<grid.size() && j+1<grid[0].size() && grid[i-1][j+1]>grid[i][j]){
            ans=max(ans,1+solve(i-1,j+1,grid,dp));
        }
    return dp[i][j]=ans;


    }
    int maxMoves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=INT_MIN;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            ans=max(ans,solve(i,0,grid,dp));

        }
        return ans;
        
    }
};