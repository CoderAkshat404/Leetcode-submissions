class Solution {
public:
    int solve(int i, int j,string &s,vector<vector<int>> &dp){
        if(i>j){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==s[j]){
            return dp[i][j]=solve(i+1,j-1,s,dp);
        }
        else{
            return dp[i][j]=0;
        }
        
    }
    string longestPalindrome(string &s) {
        // code here
        int st=0;
        int n=s.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(i,j,s,dp)){
                    if(j-i+1>maxi){
                        maxi=j-i+1;
                        st=i;
                    }
                }
            }
        }
        return s.substr(st,maxi);
    }
};