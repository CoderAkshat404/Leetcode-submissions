class Solution {
public:
    #define ll long long
    vector<ll> bfs(char c, vector<vector<pair<int,int>>>&adj){
        vector<ll> dist(26,1e9);
        priority_queue<pair<ll,int>,
               vector<pair<ll,int>>,
               greater<pair<ll,int>>> pq;

        pq.push({0,c-'a'});
        dist[c-'a']=0;
        while(!pq.empty()){
            int node=pq.top().second;
            ll distance=pq.top().first;
            pq.pop();
            for(auto i:adj[node]){
                if((ll)(distance+i.second)<dist[i.first]){
                    dist[i.first]=distance+i.second;
                    pq.push({dist[i.first],i.first});
                }
            }
        }
        return dist;


    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<pair<int,int>>> adj(26);
        for(int i=0;i<original.size();i++){
            adj[original[i]-'a'].push_back({changed[i]-'a',cost[i]});
        }
        vector<vector<ll>> dist;
        for(int i=0;i<26;i++){
            char c=i+'a';
            dist.push_back(bfs(c,adj));
        }
        ll ans=0;
        for(int i=0;i<source.size();i++){
            if(source[i]!=target[i]){
                if(dist[source[i]-'a'][target[i]-'a']!=1e9){
                    ans+=dist[source[i]-'a'][target[i]-'a'];
                }
                else{
                    return -1;
                }
            }
        }
        return ans;


        
    }
};