class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++){
            dist[i][i]=0;
        }
        for(int i=0;i<edges.size();i++){
                dist[edges[i][0]][edges[i][1]]=edges[i][2];
                dist[edges[i][1]][edges[i][0]]=edges[i][2];
            
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        int mini=1e9;
        int ans=-1;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(dist[i][j]<=distanceThreshold && i!=j){
                    count++;
                }
            }
            if(count<=mini){
                mini=count;
                ans=i;
            }
        }
        return ans;
        
    }
};