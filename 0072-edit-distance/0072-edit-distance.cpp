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
        vector<vector<int>> dp(word1.length()+1,vector<int>(word2.length()+1,-1));
        int ans=findans(0,0,word1,word2,dp);
        return ans;
        
    }
};