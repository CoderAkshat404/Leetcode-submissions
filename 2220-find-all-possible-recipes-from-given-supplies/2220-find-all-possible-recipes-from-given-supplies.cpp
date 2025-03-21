class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,int> m;
        for(int i=0;i<recipes.size();i++){
            m[recipes[i]]=i+1;
        }
        int n=recipes.size();
        vector<vector<int>> adj(n+1);
        for(int i=0;i<ingredients.size();i++){
            for(int j=0;j<ingredients[i].size();j++){
                if(m[ingredients[i][j]]!=0){
                    adj[m[ingredients[i][j]]].push_back(i+1);
                }
            }
        }
        vector<int> ind(n+1,0);
        for(int i=1;i<=n;i++){
            for(int j=0;j<adj[i].size();j++){
                ind[adj[i][j]]++;
            }
        }
        queue<int> q;
        for(int i=1;i<ind.size();i++){
            if(ind[i]==0){
                q.push(i);
            }
        }
        unordered_map<string,bool> isp;
        for(int i=0;i<supplies.size();i++){
            isp[supplies[i]]=true;
        }
        vector<string> ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            vector<string> v=ingredients[node-1];
            bool flag=true;
            for(auto i:v){
                if(isp[i]==false){
                    flag=false;
                    break;
                }
            }
            if(flag){
                ans.push_back(recipes[node-1]);
                isp[recipes[node-1]]=true;
            }
            vector<int> x=adj[node];
            for(auto i:x){
                ind[i]--;
                if(ind[i]==0){
                    q.push(i);
                }
            }

        }
        return ans;
        
    }
};