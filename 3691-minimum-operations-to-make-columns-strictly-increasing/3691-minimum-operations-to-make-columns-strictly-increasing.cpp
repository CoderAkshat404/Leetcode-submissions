class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        if(grid.size()==1){
            return 0;
        }
        int ans=0;
        for(int i=1;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]<=grid[i-1][j]){
                    int x=grid[i-1][j]+1;
                    ans+=x-grid[i][j];
                    grid[i][j]=x;
                }
            }
        }
       return ans; 
    }
};