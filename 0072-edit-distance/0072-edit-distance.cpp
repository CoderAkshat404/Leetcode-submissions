class Solution {
public:
    int findans(int i,int j,string word1, string word2,vector<vector<int>>&dp){
        if(i==word1.length()){
            return word2.length()-j;
        }
        if(j==word2.length()){
             return word1.length()-i;

        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(word1[i]==word2[j]){
            return dp[i][j]=findans(i+1,j+1,word1,word2,dp);
        }
        int op1=1+findans(i,j+1,word1,word2,dp);
        int op2=1+findans(i+1,j+1,word1,word2,dp);
        int op3=1+findans(i+1,j,word1,word2,dp);
        return dp[i][j]=min(op1,min(op2,op3));
        
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length()+1,vector<int>(word2.length()+1,0));
        int n=word1.length();
        int m=word2.length();
        for(int j=0;j<=m;j++){
            dp[n][j]=m-j;

        }
        for(int i=0;i<=n;i++){
            dp[i][m]=n-i;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(word1[i]==word2[j]){
                    dp[i][j]=dp[i+1][j+1];
                }
                else{
                    int op1=1+dp[i+1][j];
                    int op2=1+dp[i+1][j+1];
                    int op3=1+dp[i][j+1];
                    dp[i][j]=min(op1,min(op2,op3));
                }
            }
        }
        return dp[0][0];
        
        
    }
};