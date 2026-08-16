class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        sort(lights.begin(),lights.end());
        int maxi=0;
        for(auto i:arrivalTime){
            int x=i%period;
            auto it=upper_bound(lights.begin(),lights.end(),x)-lights.begin();
            if(it==lights.size()){
                maxi=max(maxi,period-x);
            }
        }
        return maxi;
        
    }
};