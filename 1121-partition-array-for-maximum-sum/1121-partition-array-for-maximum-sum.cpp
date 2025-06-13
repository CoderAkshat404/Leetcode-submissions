class Solution {
public:
    int solve(int l,int r,vector<int>& arr, int k,vector<vector<int>>&dp){
        if(l==r){
            return arr[l];
        }
        if(dp[l][r]!=-1){
            return dp[l][r];
        }
        int ans=0;
        int maxi=0;
        for(int i=l;i<l+k && i<arr.size();i++){
            maxi=max(maxi,arr[i]);
            ans=max(ans,solve(i+1,r,arr,k,dp)+(i-l+1)*maxi);
        }
        return dp[l][r]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<vector<int>> dp(arr.size()+1,vector<int>(arr.size()+1,-1));
        return solve(0,arr.size()-1,arr,k,dp);
        
    }
};