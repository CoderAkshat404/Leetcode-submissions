class Solution {
public:
    int minJumps(vector<int>& nums) {
         int n=nums.size();
         int maxi=*max_element(nums.begin(),nums.end());
        vector<int> spf(maxi+1);
        for(int i=0;i<maxi+1;i++){
            spf[i]=i;
        }
        for(int i=2;i<maxi+1;i++){
            if(spf[i]==i){
                for(int j=2*i;j<maxi+1;j+=i){
                    if(spf[j]==j){
                        spf[j]=i;
                    }
                }
            }
        }
        vector<vector<int>> adj(maxi+1);
        for(int i=0;i<nums.size();i++){
            int ele=nums[i];
            set<int> s;
            while(ele!=1){
                int x=spf[ele];
                s.insert(x);
                ele=ele/x;
            }
            for(auto j:s){
                adj[j].push_back(i);
            }
        }
        // for(auto i:adj[5]){
        //     cout<<i<<" ";
        // }
        spf[0]=-1;
        spf[1]=-1;
        vector<int> vis(n,0);
        vector<int> dis(n,1e9);
        dis[0]=0;
        map<int,bool> prime;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            int dist=pq.top().first;
            int idx=pq.top().second;
            pq.pop();
            if(vis[idx]==1){
                continue;
            }
            if(idx==n-1){
                return dist;
            }
            vis[idx]=1;
            if(spf[nums[idx]]==nums[idx] &&  prime[nums[idx]]==0){ 
                prime[nums[idx]]=1;

                for(auto i:adj[nums[idx]]){
                    if(i!=idx){
                        if(dist+1<dis[i]){
                            dis[i]=dist+1;
                        pq.push({dist+1,i});}
                    }
                    
                }
            }
            if(idx-1>=0){
                if(dist+1<dis[idx-1]){
                    dis[idx-1]=dist+1;
                pq.push({dist+1,idx-1});
                }
            }
            if(idx+1<n){
                if(dist+1<dis[idx+1]){
                    dis[idx+1]=dist+1;
            pq.push({dist+1,idx+1});}
            
            }

        }
        return 1;

    }
};