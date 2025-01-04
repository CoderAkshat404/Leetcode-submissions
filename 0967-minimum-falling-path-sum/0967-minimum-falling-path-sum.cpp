class Solution {
public:
    int findans(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp){    if(j>=matrix.size() || j<0){
        return 1e9;
    }
        if(i==matrix.size()-1){
            return matrix[i][j];
        }
        if(dp[i][j]!=-1e9){
            return dp[i][j];
        }
        int ans=min(matrix[i][j]+findans(i+1,j,matrix,dp),matrix[i][j]+findans(i+1,j+1,matrix,dp));
        ans=min(ans,matrix[i][j]+findans(i+1,j-1,matrix,dp));
        return dp[i][j]=ans;

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=INT_MAX;
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-1e9));
        for(int i=0;i<matrix[0].size();i++){
            ans=min(ans,findans(0,i,matrix,dp));
        }
        return ans;
        
    }
};