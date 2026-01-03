class Solution {
public:
    int dp[50001][4][4][4];
    int mod=1e9+7;
    int solve(int rn,int n,int c1,int c2,int c3){
        if(rn==n){
            return 1;
        }
        if(dp[rn][c1][c2][c3]!=-1){ 
            return dp[rn][c1][c2][c3];
        }
        int ans=0;
        for(int i=1;i<=3;i++){
            for(int j=1;j<=3;j++){
                for(int k=1;k<=3;k++){
                    if(i!=j && j!=k && i!=c1 && j!=c2 && k!=c3){
                        ans=(ans+solve(rn+1,n,i,j,k))%mod;
                    }
                }
            }
        }
         return dp[rn][c1][c2][c3]=ans;
    }
    int numOfWays(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(0,n,0,0,0);
        
    }
};