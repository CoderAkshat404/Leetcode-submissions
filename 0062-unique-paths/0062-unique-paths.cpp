class Solution {
public:
    int findans(int i, int j, vector<vector<int>>&dp,int m,int n){
        if(i>=m && j>=n){
            return 0;
        }
        if(i==m-1){
            return 1;
        }
        if(j==n-1){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        dp[i][j]=findans(i+1,j,dp,m,n)+findans(i,j+1,dp,m,n);
        return dp[i][j];

    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int ans=findans(0,0,dp,m,n);
        return ans;
        
    }
};