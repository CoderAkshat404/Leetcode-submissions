class Solution {
public:
    int dp[501][501];
    int solve(int l,int r,vector<int>& s){
        if(l==r) return 0;
        if(dp[l][r]!=-1){ return dp[l][r];}
        int totsum=0;
        for(int i=l;i<=r;i++){
            totsum+=s[i];
        }
        int maxi=0;
        int lsum=0;
        int rsum=0;
        for(int i=l;i<r;i++){
            lsum+=s[i];
            rsum=totsum-lsum;
            if(lsum<rsum){
                maxi=max(maxi,lsum+solve(l,i,s));
            }
            else if(lsum>rsum){
                maxi=max(maxi,rsum+solve(i+1,r,s));
            }
            else{
                maxi=max(maxi,max(lsum+solve(l,i,s),rsum+solve(i+1,r,s)));
            }
        }
        return dp[l][r]=maxi;
    }
    int stoneGameV(vector<int>& stoneValue) {
        memset(dp,-1,sizeof(dp));
        return solve(0,stoneValue.size()-1,stoneValue);
        
    }
};