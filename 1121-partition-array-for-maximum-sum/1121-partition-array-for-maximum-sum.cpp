class Solution {
public:
    int solve(int l,int r,vector<int>& arr, int k,vector<vector<int>>&dp){
        if(l==r){
            return arr[l];
        }
        if(dp[l][r]!=-1){
            return dp[l][r];
        }
        int ans=0;
        int maxi=0;
        for(int i=l;i<l+k && i<arr.size();i++){
            maxi=max(maxi,arr[i]);
            ans=max(ans,solve(i+1,r,arr,k,dp)+(i-l+1)*maxi);
        }
        return dp[l][r]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<vector<int>> dp(arr.size()+1,vector<int>(arr.size()+1,0));
        for(int i=0;i<arr.size();i++){
            dp[i][i]=arr[i];
        }
        int n=arr.size();
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<n;j++){
                // if(i==j){
                //     continue;
                // }
                int ans=0;
                int maxi=0;
                for(int l=i;l<i+k && l<n;l++){
                    maxi = max(maxi, arr[l]);

                    ans=max(ans,dp[l+1][j]+(l-i+1)*maxi);

                }
                dp[i][j]=ans;
            }
        }
        return dp[0][n-1];
        
    }
};