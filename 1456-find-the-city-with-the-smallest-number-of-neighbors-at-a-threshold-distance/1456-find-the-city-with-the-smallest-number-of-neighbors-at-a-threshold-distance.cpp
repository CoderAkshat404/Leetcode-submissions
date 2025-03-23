class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int k) {
        vector<vector<int>> v(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    v[i][j]=0;
                }
            }
        }
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int t=edges[i][1];
            int d=edges[i][2];
            v[u][t]=d;
            v[t][u]=d;
        }
        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    v[i][j]=min(v[i][j],v[i][via]+v[via][j]);
                    
                }
            }

        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //        cout<<v[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        int ans=-1;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(v[i][j]<=k){
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