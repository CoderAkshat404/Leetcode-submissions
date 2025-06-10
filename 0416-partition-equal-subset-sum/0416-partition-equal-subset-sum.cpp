class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto i:nums){
            sum+=i;
        }
        if(sum&1) return false;
        int n=nums.size();
        int target=sum/2;
        vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=target;j++){
            bool take=false;
            if(nums[i]<=j){
            take=dp[i+1][j-nums[i]];}
            bool nottake=dp[i+1][j];
            dp[i][j]=take | nottake;}

        } 
        return dp[0][target];      
    }
};