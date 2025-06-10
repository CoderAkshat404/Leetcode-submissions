class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle.back().size();
        vector<vector<long long>> dp(n+1,vector<long long>(m+1,1e8));
        for(int i=0;i<m;i++){
            dp[n-1][i]=triangle[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            int x=triangle[i].size();
            for(int j=0;j<x;j++){
                dp[i][j]=triangle[i][j]+min(dp[i+1][j+1],dp[i+1][j]);
                
            }
        }
        return dp[0][0];
        
    }
};