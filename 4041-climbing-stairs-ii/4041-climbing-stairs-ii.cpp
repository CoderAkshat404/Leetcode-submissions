class Solution {
public:
    int solve(int i,int n,vector<int>& costs,vector<long long>& dp){
        if(i==n){
            return 0;
        }
        if(i>n){
            return INT_MAX;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        long long op1=INT_MAX;
        long long op2=INT_MAX;
        long long op3=INT_MAX;
        if(i+1<=n){
            op1=costs[i+1]+(1)+solve(i+1,n,costs,dp);
        }
         if(i+2<=n){
            op2=costs[i+2]+(4)+solve(i+2,n,costs,dp);
        }
         if(i+3<=n){
            op3=costs[i+3]+(9)+solve(i+3,n,costs,dp);
        }
        return dp[i]= min(op1,min(op2,op3));
        
    }
    int climbStairs(int n, vector<int>& costs) {
        costs.insert(costs.begin(),0);
        vector<long long> dp(vector<long long>(n+1,-1));
        return solve(0,n,costs,dp);
        
    }
};