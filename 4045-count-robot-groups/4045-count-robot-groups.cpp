class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        vector<pair<int,int>> v;
        for(int i=0;i<position.size();i++){
            v.push_back({position[i],speed[i]});
        }
        int n=v.size();
        int ans=1;
        for(int i=n-2;i>=0;i--){
            if((v[i].second>v[i+1].second) || (v[i+1].first-v[i].first)<=distance){
                v[i].second=v[i+1].second;
            }
            else{
              
                ans++;
            }
        }
        return ans;
        
    }
};