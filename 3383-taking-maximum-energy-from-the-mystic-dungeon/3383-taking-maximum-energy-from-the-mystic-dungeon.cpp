class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        unordered_map<int,int> m;
        for(int i=0;i<energy.size();i++){
            m[i%k]+=energy[i];
        }
        unordered_map<int,int> mp;
        int maxi=INT_MIN;
        for(int i=0;i<energy.size();i++){
            maxi=max(maxi,m[i%k]-mp[i%k]);
            mp[i%k]+=energy[i];
        }
        return maxi;
        
    }
};