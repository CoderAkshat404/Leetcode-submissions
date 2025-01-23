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
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int i=0;i<=n;i++){
            for(int j=0;j<2;j++){
                dp[i][j][0]=0;
            }

        }
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int k=1;k<3;k++){
                    int ans=0;
                    if(j==1){
                        ans=max(-prices[i]+dp[i+1][0][k],dp[i+1][1][k]);
                    }
                    else{
                        ans=max(prices[i]+dp[i+1][1][k-1],dp[i+1][0][k]);
                    }
                    dp[i][j][k]=ans;
                }
            }
        }

        return dp[0][1][2];
    }
};