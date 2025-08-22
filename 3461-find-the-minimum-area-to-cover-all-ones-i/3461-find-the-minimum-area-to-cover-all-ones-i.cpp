class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
    
        int u=1e9;
        int d=-1;
        int l=1e9;
        int r=-1;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    u=min(u,i);
                    d=max(d,i);
                    l=min(l,j);
                    r=max(r,j);
                }
            }
        }
        
        return (d-u+1)*(r-l+1);
    }
};