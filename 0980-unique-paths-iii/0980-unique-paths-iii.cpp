class Solution {
public:
    set<pair<int,int>> s;
    int total = 0;

    vector<int> dx = {1,0,-1,0};
    vector<int> dy = {0,1,0,-1};

    int solve(int i,int j,vector<vector<int>>& grid,int n,int m){

        if(i>=n || j>=m || i<0 || j<0){
            return 0;
        }

        if(grid[i][j] == -1){
            return 0;
        }

        if(s.find({i,j}) != s.end()){
            return 0;
        }

        if(grid[i][j] == 2){
            if(s.size() == total - 1){
                return 1;
            }
            return 0;
        }

        s.insert({i,j});

        int ans = 0;

        for(int r=0;r<4;r++){
            int nr = i + dx[r];
            int nc = j + dy[r];
            ans += solve(nr,nc,grid,n,m);
        }

        s.erase({i,j});

        return ans;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int sti = -1, stj = -1;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid[i][j] == 1){
                    sti = i;
                    stj = j;
                }

                if(grid[i][j] != -1){
                    total++;
                }
            }
        }

        return solve(sti,stj,grid,n,m);
    }
};