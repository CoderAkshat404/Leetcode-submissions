class Solution {
public:
    int solve(int l,int r,vector<int>& cuts){
        if(l==r-1){
            return 0;
        }
        int ans=1e9;
        for(int i=l+1;i<r;i++){
            ans=min(ans,cuts[r]-cuts[l]+solve(l,i,cuts)+solve(i,r,cuts));
        }
        return ans;
    }
    int minCost(int x, vector<int>& cuts) {
        cuts.push_back(x);
        reverse(cuts.begin(),cuts.end());

        cuts.push_back(0);
        reverse(cuts.begin(),cuts.end());
        sort(cuts.begin(),cuts.end());
        int n=cuts.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<n;j++){
                if(j==i+1){
                    continue;
                }
                int ans=1e9;
                for(int k=i+1;k<j;k++){
                    ans=min(ans,cuts[j]-cuts[i]+dp[i][k]+dp[k][j]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][n-1];

        
    }
};