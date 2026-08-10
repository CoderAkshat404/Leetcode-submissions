class Solution {
public:
    bool check(int mid,vector<vector<int>>&dp){
        int n=dp.size();
        int m=dp[0].size();
        int minr=n;
        int maxr=0;
        int minc=m;
        int maxc=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[i][j]>=mid){
                    minc=min(minc,j);
                    maxc=max(maxc,j);
                    minr=min(minr,i);
                    maxr=max(maxr,i);
                }
            }
        }
        if(maxr-minr>=mid || maxc-minc>=mid){
            return true;
        }
        return false;
    }
    int maxArea(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int cnt=0;
        vector<vector<int>> dp(n,vector<int>(m));
        for(int i=0;i<n;i++){
           
            dp[i][0]=mat[i][0];
        }
        for(int i=0;i<m;i++){
           
            dp[0][i]=mat[0][i];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]){
                    cnt++;
                }
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(mat[i][j]==1){
                   
                    dp[i][j]=1+min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        int maxi=0;
        if(cnt>=2){
            maxi=1;
        }
        vector<pair<int,pair<int,int>>> v;
        
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(dp[i][j]>1){
                        v.push_back({dp[i][j],{i,j}});
                    }    
                }
            }
        int lo=2;
        int hi=min(n,m);
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(check(mid,dp)){
                maxi=mid;
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        return maxi*maxi;
        
        
    }
};