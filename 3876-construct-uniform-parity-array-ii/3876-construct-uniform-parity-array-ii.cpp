class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int oddc=0;
        int evenc=0;
        int mini=1e9;
        for(auto i:nums){
            if(i&1) oddc++;
            else evenc++;
            mini=min(mini,i);
        }
        if(evenc==0) return true;
        if(oddc==0) return true;
        return mini%2==1;
        
    }
};