class Solution {
public:
    int dp[251][251];  

    int solve(int i, vector<int>& pre, int moves) {
        if(i==0 && moves>1){
            return 1e9;
        }
        if(moves==1){
            return pre[i];
        }
        if (dp[i][moves] != -1) {
            return dp[i][moves];
        }

        int ans = 1e9;
        for (int k = 0; k <i; k++) {
            int partXor = (pre[i] ^ pre[k]);
            int cost = max(partXor, solve(k, pre, moves - 1));
            ans = min(ans, cost);
        }
        return dp[i][moves] = ans;
    }

    int minXor(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n);
        pre[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] ^ nums[i];
        }
        memset(dp, -1, sizeof(dp));
        return solve(n - 1, pre, k);
    }
};
