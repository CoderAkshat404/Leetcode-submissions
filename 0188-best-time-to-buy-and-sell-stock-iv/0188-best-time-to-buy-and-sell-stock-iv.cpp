class Solution {
public:
    int maxProfit(int p, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(p+1,0)));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                for(int k=p;k>=1;k--){
                if(j==0){
                    dp[i][j][k]=max(-prices[i]+dp[i+1][1-j][k],dp[i+1][j][k]);

                }
                else{
                     dp[i][j][k]=max(+prices[i]+dp[i+1][1-j][k-1],dp[i+1][j][k]);

                }}
            }
        }
        return dp[0][0][p];
        
    }
};