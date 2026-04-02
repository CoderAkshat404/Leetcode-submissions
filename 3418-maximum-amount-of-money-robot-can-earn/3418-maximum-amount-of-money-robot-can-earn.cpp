class Solution {
public:
    int n,m;
    int dp[501][501][3];
    int solve(int i,int j,int k,vector<vector<int>>& coins){
        if(k<0) return -1e9;
        if(i<0 || i>=n || j<0 || j>=m) return -1e9;
        if(i==n-1 && j==m-1){
            if(coins[i][j]<0 && k>0) return 0;
            else return coins[i][j];   
        }
        if(dp[i][j][k]!=-1e9) return dp[i][j][k];
        int ans=-1e9;
        if(coins[i][j]<0){
            ans=max(ans,solve(i+1,j,k-1,coins));
            ans=max(ans,solve(i,j+1,k-1,coins));
            ans=max(ans,coins[i][j]+solve(i+1,j,k,coins));
            ans=max(ans,coins[i][j]+solve(i,j+1,k,coins));


        }
        else{
             ans=max(ans,coins[i][j]+solve(i+1,j,k,coins));
            ans=max(ans,coins[i][j]+solve(i,j+1,k,coins));

        }
        return dp[i][j][k]=ans;
    }
    int maximumAmount(vector<vector<int>>& coins) {
        n=coins.size();
        m=coins[0].size();
for(int i=0;i<501;i++)
    for(int j=0;j<501;j++)
        for(int k=0;k<3;k++)
            dp[i][j][k] = -1e9;
        return solve(0,0,2,coins);
        
    }
};