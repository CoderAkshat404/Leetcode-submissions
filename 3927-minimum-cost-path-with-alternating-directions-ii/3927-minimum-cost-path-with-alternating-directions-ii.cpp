class Solution {
public:
    bool check(int i,int j,int n ,int m){
        return (i>=0 ) && (i<n) && (j>=0 ) && (j<m);
    }
    long long minCost(int n, int m, vector<vector<int>>& wait) {
        int dx[]={1,0};
        int dy[]={0,1};
        priority_queue<vector<long long>,vector<vector<long long>>,greater<vector<long long>>> pq;
        //cost,i,j,time
        vector<vector<long long>> dist(n,vector<long long>(m,1e18));
        dist[0][0]=1;
        pq.push({1,0,0,1});
        while(!pq.empty()){
            long long cost=pq.top()[0];
            long long i=pq.top()[1];
            long long j=pq.top()[2];
            long long time=pq.top()[3];
            if(i==n-1 && j==m-1) return cost;
            if(time%2==0){
                cost += wait[i][j];
                pq.push({cost, i, j, time + 1});
                pq.pop();
                continue; 
            }
            pq.pop();
            for(int k=0;k<2;k++){
                long long ni=i+dx[k];
                long long nj=j+dy[k];
                     if(check(ni,nj,n,m) && (long long)(cost+(ni+1)*(nj+1))<(long long)dist[ni][nj]){
                        dist[ni][nj]=cost+(ni+1)*(nj+1);
                        pq.push({dist[ni][nj],ni,nj,time+1});
                    }
                    
                
            }
        }

        return dist[n-1][m-1];
        
        
    }
};