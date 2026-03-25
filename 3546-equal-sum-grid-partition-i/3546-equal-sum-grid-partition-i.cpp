class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long sum=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum+=grid[i][j];
            }
        }
        long long currsum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                currsum+=grid[i][j];
                if(j==m-1 && 2*1LL*currsum==sum){
                    return true;
                }
            }
        }
        currsum=0;
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                currsum+=grid[i][j];
                if(i==n-1 && 2*1LL*currsum==sum){
                    return true;
                }
            }
        }
        return false;

        
        
    }
};