#define ll  long long
class Solution {
public:
    int solve(string&s,ll i,ll k,ll len,ll sum,vector<vector<ll>>&dp){
        if(i<0){
            return 0;
        }
        if(dp[i][len]!=-1){
            return  dp[i][len];
        }
        ll ans=0;
        if(s[i]=='1'){
            ll take=0;
            ll nottake=solve(s,i-1,k,len,sum,dp);
            if(sum+pow(2,len)<=k){
                take=1+solve(s,i-1,k,len+1,sum+pow(2,len),dp);
            }
            ans=max(take,nottake);
        }
        else{
            ll nottake=solve(s,i-1,k,len,sum,dp);
            ll take=1+solve(s,i-1,k,len+1,sum,dp);
            ans=max(ans,max(take,nottake));

        }
        return  dp[i][len]=ans;

    }
    int longestSubsequence(string s, int k) {
        vector<vector<ll>> dp(s.length(),vector<ll>(s.length(),-1));
        return solve(s,s.length()-1,k,0,0,dp);
        
    }
};