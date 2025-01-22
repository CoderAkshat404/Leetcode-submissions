class Solution {
public:
    int findans(int i,int buy,vector<int>& prices, vector<vector<int>>&dp){
        if(i>=prices.size()){
            return 0;
        }
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }
        int ans=0;
        if(buy){
            ans=max(-prices[i]+findans(i+1,0,prices,dp),findans(i+1,1,prices,dp));

        }
        else{
            ans=max(prices[i]+findans(i+1,1,prices,dp),findans(i+1,0,prices,dp));
        }
        return dp[i][buy]=ans;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                int ans=0;
                if(j==1){
                    ans=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                }
                else{
                    ans=max(prices[i]+dp[i+1][1],dp[i+1][0]);
                }
                dp[i][j]=ans;
            }
        }
        return dp[0][1];
        
    }
};