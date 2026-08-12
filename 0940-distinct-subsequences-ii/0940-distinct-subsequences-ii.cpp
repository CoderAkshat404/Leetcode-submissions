class Solution {
public:
    int distinctSubseqII(string s) {
        int mod=1e9+7;
        int n=s.length();
        vector<int> sum(n+1);
        vector<int> dp(n+1);
        map<char,int> last;
        dp[0]=1;
        sum[0]=1;
        for(int i=1;i<=n;i++){
            dp[i]=sum[i-1];
            if(last[s[i-1]]>0){
                dp[i]=(dp[i]-sum[last[s[i-1]]-1]+mod)%mod;
            }
            last[s[i-1]]=i;
            sum[i]=(dp[i]+sum[i-1])%mod;
        }
        return (sum[n]-1+mod)%mod;
        
    }
};