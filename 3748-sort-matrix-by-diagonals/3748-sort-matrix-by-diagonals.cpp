class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dia;
        for(int i=1;i<n;i++){
            vector<int> v;
            int p=0;
            int j=i;
            while(p<n && j<n){
                v.push_back(grid[p][j]);
                p++;
                j++;
            }
            sort(v.begin(),v.end());
            p=0;
            j=i;
            int x=0;
            while(p<n && j<n){
                grid[p][j]=v[x];
                x++;
                p++;
                j++;
            }

        }
        for(int i=0;i<n;i++){
            vector<int> v;
            int p=i;
            int j=0;
            while(p<n && j<n){
                v.push_back(grid[p][j]);
                p++;
                j++;
            }
             sort(v.rbegin(),v.rend());
             p=i;
             j=0;
             int x=0;
              while(p<n && j<n){
                grid[p][j]=v[x];
                x++;
                p++;
                j++;
            }
            
        }
       

 return grid;
            

        
        
    }
};