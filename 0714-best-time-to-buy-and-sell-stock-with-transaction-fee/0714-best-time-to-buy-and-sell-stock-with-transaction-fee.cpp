class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(j==0){
                    dp[i][j]=max(-prices[i]+dp[i+1][1-j],dp[i+1][j]);

                }
                else{
                     dp[i][j]=max(+prices[i]+dp[i+1][1-j]-fee,dp[i+1][j]);

                }
            }
        }
        return dp[0][0];
        
    }
};