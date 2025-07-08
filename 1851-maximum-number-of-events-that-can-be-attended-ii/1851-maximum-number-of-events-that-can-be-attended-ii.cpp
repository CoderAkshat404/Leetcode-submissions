const int INF=100000000;
class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        int n=events.size();
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=k;j++){
                int nottake=dp[i+1][j];
                int next=upper_bound(events.begin(),events.end(),vector<int>{events[i][1],INF,INF})-events.begin();
                int take=events[i][2]+dp[next][j-1];
                dp[i][j]=max(take,nottake);
            }
        }
        return dp[0][k];
        
    }
};