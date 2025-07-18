class Solution {
public:
    int solve(int i,int prev,int col,int n,map<int,map<int,int>>&m,vector<vector<int>>&dp){
        if(i>=col){
            return 0;
        }
        if(prev!=-1 && dp[i][prev]!=-1){
            return dp[i][prev];
        }
        int ans=INT_MAX;
        for(int j=0;j<=9;j++){
            if(prev!=j){
                ans=min(ans,n-m[i][j]+solve(i+1,j,col,n,m,dp));
            }
        }
        if(prev==-1){
            return ans;
        }
        return dp[i][prev]=ans;
    }
    int minimumOperations(vector<vector<int>>& grid) {
        int n=grid.size();
        int col=grid[0].size();
        map<int,map<int,int>> m;
        for(int i=0;i<n;i++){
            for(int j=0;j<col;j++){
                m[j][grid[i][j]]++;
            }
        }
        vector<vector<int>> dp(col,vector<int>(10,-1));
        return solve(0,-1,col,n,m,dp);
        
    }
};