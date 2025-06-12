class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.length();
        int m=p.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        dp[n][m]=1;
         for (int j = m - 1; j >= 0; --j) {
            if (p[j] == '*') dp[n][j] = dp[n][j + 1];
            else break;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(s[i]==p[j] || p[j]=='?'){
                    dp[i][j]=dp[i+1][j+1];
                }
                else if(p[j]=='*'){
                    dp[i][j]=dp[i+1][j] || dp[i+1][j+1] || dp[i][j+1];

                }
            }
        }
        return dp[0][0];
        
    }
};