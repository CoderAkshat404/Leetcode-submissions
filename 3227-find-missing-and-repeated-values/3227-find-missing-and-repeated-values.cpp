class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> v(2);
        unordered_map<int,int> m;
        int n=grid.size();
        int c=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<c;j++){
                m[grid[i][j]]++;
            }
        }
        for(int i=1;i<=n*n;i++){
            if(m[i]==2){
                v[0]=i;
            }
            if(m[i]==0){
                v[1]=i;
            }
        }
        return v;
        
    }
};