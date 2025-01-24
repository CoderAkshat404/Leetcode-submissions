class Solution {
public:
    int findans(int i,int prevind,vector<int>& nums, vector<vector<int>>&dp){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i][prevind+1]!=-1){
            return dp[i][prevind+1];
        }
        int len=0+findans(i+1,prevind,nums,dp);
        if(prevind==-1 || nums[i]>nums[prevind]){
            len=max(len,1+findans(i+1,i,nums,dp));
        }
        return dp[i][prevind+1]=len;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,-1));
        int ans=findans(0,-1,nums,dp);
        return ans;
        
    }
};