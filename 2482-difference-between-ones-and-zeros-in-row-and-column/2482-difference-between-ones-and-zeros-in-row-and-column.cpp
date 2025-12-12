class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<pair<int,int>> rows(n);
        vector<pair<int,int>> cols(m);
        for(int i=0;i<grid.size();i++){
            int z=0;
            int o=0;
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){
                    z++;
                }
                else{
                    o++;
                }
            }
            rows[i]={o,z};

        }
        for(int j=0;j<grid[0].size();j++){
            int z=0;
            int o=0;
            for(int i=0;i<grid.size();i++){
                if(grid[i][j]==0){
                    z++;
                }
                else{
                    o++;
                }
            }
            cols[j]={o,z};

        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                grid[i][j]=rows[i].first+cols[j].first-rows[i].second-cols[j].second;

            }
        }
        return grid;

        
    }
};