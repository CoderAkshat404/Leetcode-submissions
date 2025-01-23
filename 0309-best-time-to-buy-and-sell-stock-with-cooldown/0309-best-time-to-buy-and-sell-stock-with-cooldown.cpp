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
            ans=max(prices[i]+findans(i+2,1,prices,dp),findans(i+1,0,prices,dp));
        }
        return dp[i][buy]=ans;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        int ans=findans(0,1,prices,dp);
        return ans;
        
    }
};