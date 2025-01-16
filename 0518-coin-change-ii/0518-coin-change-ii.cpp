class Solution {
public:
    int findans(int amount,vector<int>& coins,int i,vector<vector<int>> &dp){
        if(amount==0){
            return 1;
        }
        if(i>=coins.size()){
            return 0;
        }
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }
        int inc=0;
        if(coins[i]<=amount){
            inc=findans(amount-coins[i],coins,i,dp);
        }
        int exc=findans(amount,coins,i+1,dp);
        return dp[i][amount]=inc+exc;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int> (amount+1,-1));
        int ans=findans(amount,coins,0,dp);
        return ans;
        
    }
};