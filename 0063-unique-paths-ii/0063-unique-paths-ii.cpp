class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& nums) {
        vector<vector<long long>> dp(nums.size()+1,vector<long long>(nums[0].size()+1,0));
        int n=nums.size();
        int m=nums[0].size();
        if(nums[n-1][m-1]==1){
            return 0;
        }
        dp[n-1][m-1]=1;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1 && j==m-1){
                    continue;
                }
                if(nums[i][j]==1){
                    dp[i][j]=0;
                }
                else{
                    dp[i][j]=dp[i][j+1]+dp[i+1][j];
                }
            }
        }
        return dp[0][0];

        
    }
};