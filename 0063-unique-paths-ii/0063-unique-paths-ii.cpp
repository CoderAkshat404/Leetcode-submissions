class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums[0].size(),0));
        int n=nums.size();
        int m=nums[0].size();
        if(nums[n-1][m-1]==1){
            return 0;
        }
        for(int i=0;i<n;i++){
            if(nums[i][m-1]){
                dp[i][m-1]=0;


            }
            else{
            dp[i][m-1]=1;}

        }
        for(int i=0;i<n;i++){
            if(dp[n-1][i]==1){
                dp[n-1][i]=0;

            }
            else{
            dp[n-1][i]=1;}

        }
        dp[n-1][m-1]=1;
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
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