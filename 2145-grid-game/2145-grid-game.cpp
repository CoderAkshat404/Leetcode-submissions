class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int idx=-1;
        vector<long long int> pre1(grid[0].size());
        vector<long long int> pre2(grid[0].size());
        pre1[0]=grid[0][0];
        for(long long int i=1;i<grid[0].size();i++){
            pre1[i]=pre1[i-1]+grid[0][i];

        }
        pre2[0]=grid[1][0];
        for(long long int i=1;i<grid[0].size();i++){
            pre2[i]=pre2[i-1]+grid[1][i];
        }
        long long int n=grid[0].size();
         long long mini = LLONG_MAX;
        for(long long int i=0;i<n;i++){
            long long int sl=0;
            long long int s1=pre1[n-1]-pre1[i];
            if(i==0){
                sl=0;
            }
            else{
                sl=pre2[i-1];
            }
            long long int maxi=max(sl,s1);
            mini=min(maxi,mini);
            
        }
        return mini;


        
    }
};