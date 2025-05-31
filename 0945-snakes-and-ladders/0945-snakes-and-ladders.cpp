class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        unordered_map<int,int> m;
        int cnt=1;
        reverse(board.begin(),board.end());
        for(int i=0;i<board.size();i++){
            if(i%2==0){
                for(int j=0;j<board[0].size();j++){
                    m[cnt]=board[i][j];
                    cnt++;
                }
            }
            else{
                for(int j=board[0].size()-1;j>=0;j--){
                    m[cnt]=board[i][j];
                    cnt++;
                }
            }
        }
        queue<pair<int,int>> q;
        q.push({1,0});
        int mini=INT_MAX;
        int n=board.size();
        vector<int> vis(n*n+1);
        vis[1] = 1;  
        
        while(!q.empty()){
            int node=q.front().first;
            int time=q.front().second;
            q.pop();
            if(node==n*n){
                mini=min(mini,time);
            }
            for(int i=1;i<=6;i++){
                if(node+i<=n*n){
                    int next = (m[node+i]==-1) ? (node+i) : m[node+i];
                    if(!vis[next]){  
                        vis[next]=1;  
                        q.push({next,time+1});
                    }
                }
            }
        }
        return mini==INT_MAX ? -1 : mini;  
    }
};
