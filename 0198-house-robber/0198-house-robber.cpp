class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(nums.size()+1,0);
        dp[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            int ans;
            int a=INT_MIN;
            int b=INT_MIN;
           a=nums[i]+dp[i+2];
            b=dp[i+1];
            ans=max(a,b);
            dp[i]=ans;
            
        }
        return dp[0];

        
    }
};