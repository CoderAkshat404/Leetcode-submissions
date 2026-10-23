class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int currR=0;
        int currC=0;
        int lastR=0;
        int lastC=0;
        int n=grid.size();
        int m=grid[0].size();
        set<pair<int,int>> vis;
        while(currR>=0 && currC>=0 && currR<n && currC<m){
            pair<int,int> p={currR,currC};
            if(vis.find(p)!=vis.end()){
                break;
            }
            vis.insert(p);
            lastR=currR;
            lastC=currC;
            if(grid[currR][currC]=='R'){
                currC++;
            }
            else if(grid[currR][currC]=='L'){
                currC--;
            }
            else if(grid[currR][currC]=='D'){
                currR++;
            }
            else{
                currR--;
            }

        }
        return {lastR,lastC};
        
    }
};