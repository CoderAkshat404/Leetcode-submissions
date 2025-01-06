#define ll long long
class Solution {
public:
    bool findans(ll i,ll s,ll n,vector<vector<int>>&dp,vector<int>& nums){
        if(s==0){
            return true;
        }
        if(i==n-1){
            if(s==nums[i]){
                return true;
            }
            else{
                return false;
            }
        }
        if(dp[i][s]!=-1){
            return dp[i][s];
        }
        bool x=0;
        if(nums[i]<=s){
            x=findans(i+1,s-nums[i],n,dp,nums);
        }
        int ans=x | findans(i+1,s,n,dp,nums);
        return dp[i][s]=ans;
    }
    bool canPartition(vector<int>& nums) {
       ll s=0;
      ll n=nums.size();
        for(ll i=0;i<nums.size();i++){
            s+=nums[i];
        }
        if(s&1){
            return false;
        }
       ll i=s/2;
        vector<vector<int>>dp(n,vector<int>(i+1,-1));
        bool c=findans(0,i,n,dp,nums);
        return c;
        
      
        
    }
};