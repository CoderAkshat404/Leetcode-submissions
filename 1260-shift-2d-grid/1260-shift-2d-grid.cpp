class Solution {
public:
    void shift(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        int x=grid[n-1][m-1];
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==0 && j==0) grid[i][j]=x;
                else if(j==0){
                    grid[i][j]=grid[i-1][m-1];
                }
                else
                grid[i][j]=grid[i][j-1];
                
            }
        }
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        for(int i=0;i<k;i++){
            shift(grid);
        }
        return grid;
        
    }
};