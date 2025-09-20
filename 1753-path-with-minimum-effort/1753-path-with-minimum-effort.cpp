class Solution {
public:
    bool check(int i,int j,vector<vector<int>>& grid){
        return (i>=0) && (i<grid.size()) && (j>=0) && (j<grid[0].size());
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        int dx[]={1,0,-1,0};
        int dy[]={0,1,0,-1};

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;

        pq.push({0,0,0});
        dist[0][0] = 0;

        while(!pq.empty()){
            int d = pq.top()[0];
            int i = pq.top()[1];
            int j = pq.top()[2];
            pq.pop();

            if(i==n-1 && j==m-1){
                return d;
            }

            for(int k=0;k<4;k++){
                int ni=i+dx[k];
                int nj=j+dy[k];
                if(check(ni,nj,heights)){
                    int nd = max(d, abs(heights[ni][nj]-heights[i][j]));
                    if(nd < dist[ni][nj]){
                        dist[ni][nj] = nd;
                        pq.push({nd,ni,nj});
                    }
                }
            }
        }
        return -1;
    }
};
