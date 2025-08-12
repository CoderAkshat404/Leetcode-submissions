class Solution {
public:
    int mod=1e9+7;
    int solve(int i,int n,int x,vector<vector<int>>&dp){
        if(n==0){
            return 1;
        }
        if(pow(i,x)>n){
            return 0;
        }
        if(dp[n][i]!=-1){
            return dp[n][i];
        }
        int ch1=solve(i+1,n,x,dp);
        int ch2=solve(i+1,n-pow(i,x),x,dp);
        return dp[n][i]=(ch1+ch2)%mod;
    }
    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(1,n,x,dp);
        
    }
};