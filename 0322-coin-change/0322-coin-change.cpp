class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,1e8));
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=amount;j++){
                int take=1e9;
                if(j>=coins[i]){
                    take=1+dp[i][j-coins[i]];
                }
                int nottake=dp[i+1][j];
                dp[i][j]=min(take,nottake);
            }
        }
        if(dp[0][amount]>=1e8){
            return -1;
        }
        return dp[0][amount];
        
        
    }
};