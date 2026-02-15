class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        map<int,int> m;
        for(auto i:bulbs){
            m[i]=1-m[i];
        }
        vector<int> ans;
        for(auto i:m){
            if(i.second>0){
                ans.push_back(i.first);
            }
        }
        return ans;
        
    }
};