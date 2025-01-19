class Solution {
public:
int lcs(string s,string t){
        int n=s.length();
        int m=t.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(s[i]==t[j]){
                    dp[i][j]=1+dp[i+1][j+1];
                }
                else{
                    dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
         return dp[0][0];
    }
    int minDistance(string s1, string s2) {
        int x=lcs(s1,s2);
    return s1.length()-x+s2.length()-x;
        
    }
};