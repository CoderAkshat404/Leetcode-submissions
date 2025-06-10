class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int  n=matrix.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,1e8));
        for(int i=0;i<n;i++){
            dp[n-1][i]=matrix[n-1][i];

        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<n;j++){
            int op1=1e9;
            int op2=dp[i+1][j];
            int op3=1e9;
            if(j-1>=0){
                op1=dp[i+1][j-1];
            }
            if(j+1<n){
                op3=dp[i+1][j+1];
            }
            dp[i][j]=matrix[i][j]+min(op1,min(op2,op3));
            
            
            }
        }
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            mini=min(dp[0][i],mini);
        }
        return mini;

        
    }
};