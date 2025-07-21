class Solution {
public:
    
   long long  int solve(int i,vector<int>& nums,vector<int>&dp){
        if(i>=nums.size()-1) return 0;
        if(dp[i]!=-1){
            return dp[i];
        }
       long long  int ans=INT_MAX;
        for(int j=i+1;j<=i+nums[i] && j<nums.size();j++){
            if(nums[j]!=0 || j==nums.size()-1){
            ans=min(ans,1+solve(j,nums,dp));}
        }
        return  dp[i]= ans;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return solve(0,nums,dp);
        
    }
};