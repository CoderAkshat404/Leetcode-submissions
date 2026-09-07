class Solution {
public:
    int dp[501][501];
    int solve(int i,int j,vector<int>&v,int x){
        if(i>=v.size()) return 0;
        if(j<0) return 0;
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=1e9;
        ans=min(ans,v[i+1]-v[i]+solve(i+2,j,v,x));
        ans=min(ans,v[j]-v[j-1]+solve(i,j-2,v,x));
        ans=min(ans,x+solve(i+1,j-1,v,x));
        return dp[i][j]=ans;
    }
    int minOperations(string s1, string s2, int x) {
        vector<int> v;
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i]){
                v.push_back(i);
            }
        }
        memset(dp,-1,sizeof(dp));
        if(v.size()%2==1) return -1;
        if(v.size()==0) return 0;
        int n=v.size();
        return solve(0,n-1,v,x);

        
    }
};