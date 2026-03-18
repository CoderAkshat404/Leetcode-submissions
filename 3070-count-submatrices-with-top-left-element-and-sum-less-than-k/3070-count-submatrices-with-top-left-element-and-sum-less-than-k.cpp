class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> pre(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(i==0){
            pre[0][i]=grid[0][i];}
            else{
                pre[0][i]=grid[0][i]+pre[0][i-1];
            }
        }
        for(int i=0;i<n;i++){
            if(i==0){
            pre[i][0]=grid[i][0];}
            else{
                pre[i][0]=grid[i][0]+pre[i-1][0];
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+grid[i][j];
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // cout<<pre[i][j]<<" ";
                if(pre[i][j]<=k){
                
                    ans++;
                }
            }
            // cout<<endl;
        }
        return ans;
        
    }
};