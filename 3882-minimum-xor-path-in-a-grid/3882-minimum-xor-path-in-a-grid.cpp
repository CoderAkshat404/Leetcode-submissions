class Solution {
public:
    int n,m;
    
    int solve(int i,int j,int xori,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
        if(i>=n || j>=m){
            return 1e9;
        }
        if(i==n-1 && j==m-1){
            return xori^grid[i][j];
        }
         if (dp[i][j][xori] != -1) return dp[i][j][xori];
        int ch1=((solve(i+1,j,grid[i][j] ^xori,grid,dp)));
        int ch2=((solve(i,j+1,grid[i][j] ^xori,grid,dp)));
        return dp[i][j][xori] =min(ch1,ch2);
    }
    int minCost(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
       vector<vector<vector<int>>> dp(n,
            vector<vector<int>>(m, vector<int>(1024, -1)));
        return solve(0,0,0,grid,dp);
        
        
    }
};