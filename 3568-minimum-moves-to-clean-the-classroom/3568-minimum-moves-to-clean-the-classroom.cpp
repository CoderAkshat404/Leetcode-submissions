class Solution {
public:
    bool check(int r,int c,int n,int m,vector<string>& classroom){
        return (r>=0) && (r<n) && (c>=0) && (c<m) &&
               (classroom[r][c]!='X');
    }

    int minMoves(vector<string>& classroom, int energy) {
        int n=classroom.size();
        int m=classroom[0].size();

        int id[n][m];

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                id[i][j]=-1;
            }
        }

        int cnt=0;
        int stx=-1, sty=-1;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(classroom[i][j]=='S'){
                    stx=i;
                    sty=j;
                }

                if(classroom[i][j]=='L'){
                    id[i][j]=cnt++;
                }
            }
        }

        int totalMask=(1<<cnt)-1;

        bool vis[n][m][energy+1][1<<cnt];

        memset(vis, false, sizeof(vis));

        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};

        queue<vector<int>> q;

        // r, c, energy, moves, mask
        q.push({stx,sty,energy,0,0});
        vis[stx][sty][energy][0]=true;

        while(!q.empty()){

            int r=q.front()[0];
            int c=q.front()[1];
            int curren=q.front()[2];
            int moves=q.front()[3];
            int mask=q.front()[4];

            q.pop();

            // Collect current L
            if(classroom[r][c]=='L'){
                mask |= (1<<id[r][c]);
            }

            if(mask==totalMask){
                return moves;
            }

            // Recharge
            if(classroom[r][c]=='R'){
                curren=energy;
            }

            if(curren==0)
                continue;

            for(int i=0;i<4;i++){

                int nr=r+dx[i];
                int nc=c+dy[i];

                if(!check(nr,nc,n,m,classroom))
                    continue;

                int nenergy=curren-1;
                int nmask=mask;

                if(classroom[nr][nc]=='L'){
                    nmask |= (1<<id[nr][nc]);
                }

                if(classroom[nr][nc]=='R'){
                    nenergy=energy;
                }

                if(!vis[nr][nc][nenergy][nmask]){
                    vis[nr][nc][nenergy][nmask]=true;

                    q.push({
                        nr,
                        nc,
                        nenergy,
                        moves+1,
                        nmask
                    });
                }
            }
        }

        return -1;
    }
};