class Solution {
public:
     vector<vector<int>> pref(vector<vector<char>>& grid,char x){
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> ans(n,vector<int>(m));
        for(int i=0;i<n;i++){
            if(i==0){
                int a=0;
                if(grid[i][0]==x){
                    a=1;
                }
                ans[i][0]=a;
            }
            else{
                int a=0;
                if(grid[i][0]==x){
                    a=1;
                }
                ans[i][0]=(ans[i-1][0])+(a);
            }
        }
        for(int i=0;i<m;i++){
            if(i==0){
                int a=0;
                if(grid[0][i]==x){
                    a=1;
                }
                ans[0][i]=(a);
            }
            else{
                int a=0;
                if(grid[0][i]==x){
                    a=1;
                }
                ans[0][i]=(ans[0][i-1])+(a);
            }

        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                ans[i][j]+=ans[i-1][j];
                ans[i][j]+=ans[i][j-1];
                ans[i][j]-=ans[i-1][j-1];
                int a=0;
                if(grid[i][j]==x){
                    a=1;
                }
                ans[i][j]+=(a);
            }
        }
        return ans;
    }
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        vector<vector<int>>prefx=pref(grid,'X');
        vector<vector<int>>prefy=pref(grid,'Y');
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
               
                if(prefx[i][j]>0 &&(prefx[i][j]==prefy[i][j])){
                     ans++;
                }
            }
          
        }
        return ans;
        
    }
};