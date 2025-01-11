class Solution {
public:
    bool findans(vector<int> &nums,int i,vector<int> &dp){
        if(i>=nums.size()){
            return false;
        }
        if(i==nums.size()-1){
            return true;
        }
        if(nums[i]==0){
            return false;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans=false;
        for(int j=1;j<=nums[i];j++){
            ans=ans | findans(nums,i+j,dp);
            if(ans==true){
                break;
            }
        }
        return dp[i]=ans;
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        bool ans=findans(nums,0,dp);
        return ans;
        
    }
};