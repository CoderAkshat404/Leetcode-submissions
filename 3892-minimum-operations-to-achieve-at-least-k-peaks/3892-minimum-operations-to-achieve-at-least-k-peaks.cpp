class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        const int INF = 1e9;

        vector<vector<vector<int>>> dp(3, vector<vector<int>>(k+1, vector<int>(2, INF)));

        for(int i = 0; i <= n+1; i++)
            for(int fs = 0; fs <= 1; fs++)
                dp[i%3][0][fs] = 0;

        for(int i = n-1; i >= 0; i--){
            for(int x = 1; x <= k; x++){
                for(int fs = 0; fs <= 1; fs++){

                    int ans = INF;

                    if(i == n-1){
                        if(fs == 0){
                            int maxi = max(nums[i-1], nums[0]);
                            int cost = (nums[i] > maxi) ? 0 : maxi+1-nums[i];
                            if(dp[(i+2)%3][x-1][fs] < INF)
                                ans = min(ans, cost + dp[(i+2)%3][x-1][fs]);
                        }
                        ans = min(ans, dp[(i+1)%3][x][fs]);
                    }
                    else if(i == 0){
                        int maxi = max(nums[i+1], nums[n-1]);
                        int cost = (nums[i] > maxi) ? 0 : maxi+1-nums[i];
                        if(dp[(i+2)%3][x-1][1] < INF)
                            ans = min(ans, cost + dp[(i+2)%3][x-1][1]);
                        ans = min(ans, dp[(i+1)%3][x][0]);
                    }
                    else{
                        int maxi = max(nums[i-1], nums[i+1]);
                        int cost = (nums[i] > maxi) ? 0 : maxi+1-nums[i];
                        if(dp[(i+2)%3][x-1][fs] < INF)
                            ans = min(ans, cost + dp[(i+2)%3][x-1][fs]);
                        ans = min(ans, dp[(i+1)%3][x][fs]);
                    }

                    dp[i%3][x][fs] = ans;
                }
            }
        }

        int ans = dp[0][k][0];
        return (ans >= INF) ? -1 : ans;
    }
};