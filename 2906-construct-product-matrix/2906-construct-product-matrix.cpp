class Solution {
public: 
    int mod=12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        long long pro=1;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> pre(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pro=(pro*grid[i][j])%mod;
                pre[i][j]=pro;
            }
        }
        pro=1;
        vector<vector<int>> suff(n,vector<int>(m));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                pro=(pro*grid[i][j])%mod;
                suff[i][j]=pro;
            }
        }
        vector<vector<int>> ans(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int left=1;
                int right=1;
                if(j-1<0){
                    if(i-1>=0){
                        left=pre[i-1].back();
                    }
                }
                else{
                    left=pre[i][j-1];
                }
                if(j+1>=m){
                    if(i+1<n){
                        right=suff[i+1][0];
                    }
                }
                else{
                    right=suff[i][j+1];
                }
                ans[i][j]=(left*right*1LL)%mod;
            }
        }
        return ans;
        
    }
};