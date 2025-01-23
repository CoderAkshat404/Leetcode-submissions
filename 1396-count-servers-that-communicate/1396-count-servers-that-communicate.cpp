class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        int ans=0;
        for(int j=0;j<grid[0].size();j++){
            int c=0;
            for(int i=0;i<grid.size();i++){
                if(grid[i][j]==1){
                    c++;
                }
            }
            if(c>1){
                ans+=c;
                cout<<"here";
                for(int i=0;i<grid.size();i++){
                if(grid[i][j]==1){
                    dp[i][j]++;
                }
            }


            }
        }
        cout<<endl;
        cout<<ans;
        for(int i=0;i<grid.size();i++){
            int c=0;
                int disc=0;
            for(int j=0;j<grid[0].size();j++){
                
                if(grid[i][j]==1 && dp[i][j]==-1){
                    disc++;
                    c++;
                }
                else if(grid[i][j]==1 && dp[i][j]==0){
                    c++;
                }
            }
            if(c>1){
                ans+=disc;
            }
        }
        return ans;
        
    }
};