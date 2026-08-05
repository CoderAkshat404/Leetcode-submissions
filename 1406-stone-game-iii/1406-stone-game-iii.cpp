class Solution {
public:
    int dp[500100];
    int solve(int i,vector<int>& s){
        if(i>=s.size()){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int ans=-1e9;
        ans=max(ans,s[i]-solve(i+1,s));
        if(i+1<s.size()){
            ans=max(ans,s[i]+s[i+1]-solve(i+2,s));
        }
        if(i+2<s.size()){
            ans=max(ans,s[i]+s[i+1]+s[i+2]-solve(i+3,s));
        }
        
        return dp[i]=ans;
    }
    string stoneGameIII(vector<int>& s) {
        memset(dp,-1,sizeof(dp));
        int x=solve(0,s);
        
        if(x>0) return "Alice";
        if(x==0) return "Tie";
        return "Bob";
        
    }
};