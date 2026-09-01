class Solution {
public:
    int dp[101][5001];
    int solve(int i, int sum, vector<int>& nums){
        if(sum < 0){
            return 1e9;
        }
        if(sum == 0){
            return 0;
        }
        if(i >= (int)nums.size()){
            return 1e9;
        }
        if(dp[i][sum] != -1) return dp[i][sum];
        int ans = 1e9;

        ans = min(ans, solve(i+1, sum, nums));

        if(nums[i] <= sum){
            ans = min(ans, solve(i+1, sum - nums[i], nums));
        }

       
        int cnt0 = 1;
        long long orig = (long long)nums[i] * 2;
        while(orig <= sum){
            ans = min(ans, cnt0 + solve(i+1, sum - (int)orig, nums));
            orig *= 2;
            cnt0++;
        }

        long long x = nums[i];
        int cnt = 0;

        while(x > 0){
            x = x / 2;
            cnt++;
            if(x == 0) break;

            if(x <= sum){
                ans = min(ans, cnt + solve(i+1, sum - (int)x, nums));
            }

            int cnt2 = 1;
            long long temp = x * 2;
            while(temp <= sum){
                ans = min(ans, cnt + cnt2 + solve(i+1, sum - (int)temp, nums));
                temp = temp * 2;
                cnt2++;
            }
        }

        return dp[i][sum] = ans;
    }

    int minOperations(vector<int>& nums, int sum) {
        memset(dp, -1, sizeof(dp));
        int x = solve(0, sum, nums);
        if(x >= (int)1e9) return -1;
        return x;
    }
};