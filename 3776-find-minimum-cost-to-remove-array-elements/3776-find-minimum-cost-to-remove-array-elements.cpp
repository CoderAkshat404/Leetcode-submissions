class Solution {
public:
    int solve(int i,int j,int k,vector<int>& nums,vector<vector<int>>&dp){
        if(i>=nums.size()){
            return 0;
        }
        if(j>=nums.size()){
            return nums[i];
        }
        if(j+1>=nums.size()){
            return max(nums[i],nums[j]);
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=INT_MAX;
        ans=min(ans,max(nums[i],nums[j])+solve(j+1,j+2,j+3,nums,dp));
        ans=min(ans,max(nums[i],nums[j+1])+solve(j,j+2,j+3,nums,dp));
        ans=min(ans,max(nums[j],nums[j+1])+solve(i,j+2,j+3,nums,dp));
        return dp[i][j]=ans;
    }
    int minCost(vector<int>& nums) {
        if(nums.size()==2){
            return max(nums[0],nums[1]);
        }
        if(nums.size()==1){
            return nums[0];
        }
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
        int ans=solve(0,1,2,nums,dp);
        return ans;
        
    }
};