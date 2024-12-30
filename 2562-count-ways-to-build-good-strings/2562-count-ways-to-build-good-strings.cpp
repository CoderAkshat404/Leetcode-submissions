class Solution {
public:
    int findans(int s, vector<int>&dp,int low, int high, int zero, int one){
        if(s>high){
            return 0;
        }
        if(dp[s]!=-1){
            return dp[s];
        }
        int ans=0;
         if(s>=low && s<=high){
            ans++;
        }
        ans+=(findans(s+zero,dp,low,high,zero,one)+findans(s+one,dp,low,high,zero,one))%1000000007;
        return dp[s]=ans;

    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1,-1);
        int ans=findans(0,dp,low,high,zero,one);
        return ans;
        
    }
};