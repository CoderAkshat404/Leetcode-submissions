class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(auto i:nums){
            sum+=i;
        }
        if((sum+target)&1 || sum<abs(target)){
            return 0;
        }
        int ntarget=(target+sum)/2;
        vector<vector<int>> dp(n+1,vector<int>(abs(sum)+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=1;

        }
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=abs(ntarget);j++){
                int take=0;
                if(nums[i]<=j){
                    take=dp[i+1][j-nums[i]];
                }
                int nottake=dp[i+1][j];
                dp[i][j]=take+nottake;
            }
        }
        return dp[0][ntarget];
        
    }
};