class Solution {
public:
    int findans(vector<int>& nums, int target,int i,int x,vector<vector<int>>&dp){
        if(i==nums.size()){
            if(x==target){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dp[i][x+1000]!=-1){
            return dp[i][x+1000];
        }
        int ans=findans(nums,target,i+1,nums[i]+x,dp)+findans(nums,target,i+1,x-nums[i],dp);
        return dp[i][x+1000]=ans;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size(),vector<int>(2001,-1));
        int ans=findans(nums,target,0,0,dp);
        return ans;
        
    }
};