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
        int n=nums.size();
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=-1;j<n;j++){
                int len=0+dp[i+1][j+1];
                if(j==-1 || nums[i]>nums[j]){
                    len=max(len,1+dp[i+1][i+1]);
                }
                dp[i][j+1]=len;
            }
        }
        return dp[0][0];
       
        
        
    }
};