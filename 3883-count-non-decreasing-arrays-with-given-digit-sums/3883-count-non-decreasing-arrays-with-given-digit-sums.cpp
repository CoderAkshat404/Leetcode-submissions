class Solution {
public:
    int mod = 1e9+7;

    int calcs(int n){
        int sum=0;
        while(n>0){
            sum+=(n%10);
            n=n/10;
        }
        return sum;
    }

    map<int,vector<int>> m;

    int dp[1001][5001];

    int solve(int i,int prev,vector<int>& digit){
        if(i>=digit.size()) return 1;

        if(dp[i][prev] != -1) return dp[i][prev];

        long long ans=0;

        vector<int> &v = m[digit[i]];
        int idx = lower_bound(v.begin(),v.end(),prev) - v.begin();

        if(idx < v.size()){
            if(idx+1 < v.size()){
                ans = (ans + solve(i, v[idx+1], digit)) % mod;
            }
            ans = (ans + solve(i+1, v[idx], digit)) % mod;
        }

        return dp[i][prev] = ans % mod;
    }

    int countArrays(vector<int>& digit) {

        memset(dp, -1, sizeof(dp));

        for(int i=0;i<=5000;i++){
            m[calcs(i)].push_back(i);
        }

        return solve(0,0,digit);
    }
};