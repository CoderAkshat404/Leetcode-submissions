class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
         priority_queue<pair<int, pair<int, int>>, 
                   vector<pair<int, pair<int, int>>>, 
                   greater<pair<int, pair<int, int>>>> q;
        vector<vector<int>> efforts(n,vector<int>(m,1e9));
        efforts[0][0]=0;
        q.push({0,{0,0}});
        while(!q.empty()){
            int d=q.top().first;
            int r=q.top().second.first;
            int c=q.top().second.second;
            q.pop();
            if(r+1<n){
                int diff=abs(heights[r+1][c]-heights[r][c]);
                int nd=max(diff,d);
                if(nd<efforts[r+1][c]){
                    q.push({nd,{r+1,c}});
                    efforts[r+1][c]=nd;
                }
            }
            if(c+1<m){
                int diff=abs(heights[r][c+1]-heights[r][c]);
                int nd=max(diff,d);
                if(nd<efforts[r][c+1]){
                    q.push({nd,{r,c+1}});
                    efforts[r][c+1]=nd;
                }

            }
            if(r-1>=0){
                int diff=abs(heights[r-1][c]-heights[r][c]);
                int nd=max(diff,d);
                if(nd<efforts[r-1][c]){
                    q.push({nd,{r-1,c}});
                    efforts[r-1][c]=nd;
                }
            }
            if(c-1>=0){
                int diff=abs(heights[r][c-1]-heights[r][c]);
                int nd=max(diff,d);
                if(nd<efforts[r][c-1]){
                    q.push({nd,{r,c-1}});
                    efforts[r][c-1]=nd;
                }
            }
        }
        return efforts[n-1][m-1];
        
    }
};