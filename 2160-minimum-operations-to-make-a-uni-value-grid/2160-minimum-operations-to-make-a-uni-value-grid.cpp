class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> v;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                v.push_back(grid[i][j]);
            }
        }
        sort(v.begin(),v.end());
        int tar=v[(n*m)/2];
        int ans=0;
        for(int i=0;i<n*m;i++){
            int diff=abs(tar-v[i]);
            if(diff%x!=0) return -1;
            ans+=diff/x;
        }
        return ans;
        
    }
};