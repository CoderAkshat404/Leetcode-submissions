class Solution {
public:
    int solve(int i,int j,vector<int> &v,int k, vector<vector<int>>&dp){
        if(i>=j){
            return 0;
        }
        if(v[j]-v[i]<=k){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int op1=v[i]+solve(i+1,j,v,k,dp);
        int op2=v[j]-(k+v[i])+solve(i,j-1,v,k,dp);
        return dp[i][j]=min(op1,op2);
    }
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> m;
        for (char c : word) {
            m[c]++;
        }

        vector<int> v;
        for (auto i : m) {
            v.push_back(i.second);
        }
        sort(v.begin(), v.end());
        int n=v.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(0,v.size()-1,v,k,dp);
    }
};
