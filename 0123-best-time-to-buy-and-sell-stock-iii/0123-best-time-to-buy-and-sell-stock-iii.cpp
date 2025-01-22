class Solution {
public:
    int findans(int i,int buy,int k,vector<int>& prices,vector<vector<vector<int>>>&dp){
        if(i>=prices.size()){
            return 0;
        }
        if(k==0){
            return 0;
        }
        if(dp[i][buy][k]!=-1){
            return dp[i][buy][k];
        }
        int ans=0;
        if(buy){
            ans=max(-prices[i]+findans(i+1,0,k,prices,dp),findans(i+1,1,k,prices,dp));

        }
        else{
            ans=max(prices[i]+findans(i+1,1,k-1,prices,dp),findans(i+1,0,k,prices,dp));
        }
        return dp[i][buy][k]=ans;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        int ans=findans(0,1,2,prices,dp);
        return ans;
        
    }
};