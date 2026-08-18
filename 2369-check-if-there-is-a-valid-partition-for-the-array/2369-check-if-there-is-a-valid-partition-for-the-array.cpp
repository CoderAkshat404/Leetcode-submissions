class Solution {
public:
    int dp[100100];
    int solve(int i,vector<int>& nums){
        if(i>=nums.size()) return 1;
        if(dp[i]!=-1) return dp[i];
        int ans=0;
        if(i+1<nums.size()){
            if(nums[i]==nums[i+1]){
                ans=ans | solve(i+2,nums);
            }
        }
        if(i+2<nums.size()){
            if(nums[i]==nums[i+1] && nums[i+1]==nums[i+2]){
                ans=ans | solve(i+3,nums);
            }
            if(nums[i]+1==nums[i+1] && nums[i+1]+1==nums[i+2]){
                ans=ans | solve(i+3,nums);
            }
        }
        return dp[i]=ans;
    }
    bool validPartition(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(0,nums);
        
    }
};