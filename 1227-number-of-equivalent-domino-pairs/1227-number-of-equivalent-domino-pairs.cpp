class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int,int>,int> m;
        for(int i=0;i<dominoes.size();i++){
            vector<int> v=dominoes[i];
            sort(v.begin(),v.end());
            pair<int,int> p={v[0],v[1]};
            m[p]++;
        }
        int ans=0;
        for(auto i:m){
            int y=i.second;
            y--;
            ans+=((y)*(y+1))/2;
        }
        return ans;
        
    }
};