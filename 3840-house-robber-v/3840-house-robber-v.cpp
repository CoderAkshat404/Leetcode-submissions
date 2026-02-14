class Solution {
public:
    long long dp[100100];
    long long solve(int i,vector<int>& nums, vector<int>& colors){
        if(i>=nums.size()){
            return 0;
        }
        if(i==nums.size()-1){
            return nums[i];
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        long long ans=0;
        ans=max(ans,solve(i+1,nums,colors));
         ans=max(ans,nums[i]+solve(i+2,nums,colors));
         if(colors[i+1]!=colors[i]){
            ans=max(ans,nums[i]+solve(i+1,nums,colors));
         }
         return  dp[i]=ans;
        
        
    }
    long long rob(vector<int>& nums, vector<int>& colors) {
        memset(dp,-1,sizeof(dp));
        return solve(0,nums,colors);
        
    }
};