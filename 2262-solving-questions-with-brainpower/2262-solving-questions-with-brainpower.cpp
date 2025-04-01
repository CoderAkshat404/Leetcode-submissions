class Solution {
public:
    long long solve(long long  i,vector<vector<int>>& questions,vector<long long>&dp){
        if(i>=questions.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        
        long long op1=questions[i][0]+solve(i+questions[i][1]+1,questions,dp);
        long long op2=solve(i+1,questions,dp);
        return dp[i]=max(op1,op2);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(),-1);
        return solve(0,questions,dp);
        
    }
};