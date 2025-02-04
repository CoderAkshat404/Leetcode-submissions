class Solution {
public:
    int solve(int i,int j,vector<int> &v,int k, vector<vector<int>>&dp){
        if(i==j) return 0;
        if(v[j]-v[i]<=k) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=min(v[i]+solve(i+1,j,v,k,dp),v[j]-v[i]-k+solve(i,j-1,v,k,dp));
    }
    int minimumDeletions(string word, int k) {
        unordered_map<int,int> m;
        for(int i=0;i<word.length();i++){
            m[word[i]]++;
        }
        vector<int> v;
        for(auto i:m){
            v.push_back(i.second);
        }
        sort(v.begin(),v.end());
        vector<vector<int>> dp(v.size(),vector<int>(v.size(),-1));
        int ans=solve(0,v.size()-1,v,k,dp);
        return ans;
        
    }
};