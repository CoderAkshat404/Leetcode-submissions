class Solution {
public:
    int mod=1e9+7;
    int dp[201][201][2][201];

    int solve(int one,int zero,int prev,int cont,int &limit){

        if(cont>limit) return 0;
        if(one<0 || zero<0) return 0;

        if(one==0 && zero==0) return 1;

        if(prev!=-1 && dp[one][zero][prev][cont]!=-1)
            return dp[one][zero][prev][cont];

        int ch=0;

        if(prev==-1){
            if(one>0) ch=(ch+solve(one-1,zero,1,1,limit))%mod;
            if(zero>0) ch=(ch+solve(one,zero-1,0,1,limit))%mod;
            return ch;
        }

        if(zero>0){
            if(prev==0)
                ch=(ch+solve(one,zero-1,0,cont+1,limit))%mod;
            else
                ch=(ch+solve(one,zero-1,0,1,limit))%mod;
        }

        if(one>0){
            if(prev==1)
                ch=(ch+solve(one-1,zero,1,cont+1,limit))%mod;
            else
                ch=(ch+solve(one-1,zero,1,1,limit))%mod;
        }

        return dp[one][zero][prev][cont]=ch;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp,-1,sizeof(dp));
        return solve(one,zero,-1,0,limit);
    }
};