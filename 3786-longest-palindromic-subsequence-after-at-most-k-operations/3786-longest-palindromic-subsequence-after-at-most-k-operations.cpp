class Solution {
public:
    int help(char a,char b){
        int d=abs(a-b);
        return min(d,26-d);
    }
    int solve(int i,int j,string &s, int k, vector<vector<vector<int>>> &dp){
        if(i>j){
            return 0;
        }
        if(i==j){
            return 1;
        }
        if(dp[i][j][k]!=-1){
            return dp[i][j][k];
        }
        int ans=solve(i+1,j,s,k,dp);
        ans=max(ans,solve(i,j-1,s,k,dp));
        int c=help(s[i],s[j]);
        if(c<=k){
            ans=max(ans,solve(i+1,j-1,s,k-c,dp)+2);
        }
        return dp[i][j][k]=ans;
    }
    int longestPalindromicSubsequence(string s, int k) {
        vector<vector<vector<int>>>dp(s.length()+1,vector<vector<int>>(s.length()+1,vector<int>(201,-1)));
        int ans=solve(0,s.length()-1,s,k,dp);
        return ans;
    }
};