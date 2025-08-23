class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        map<int,int> m;
        for(auto i:nums){
            m[i]++;
        }
        int maxi=0;
        for(auto i:m){
            maxi=max(maxi,i.second);
        }
        if(maxi>nums.size()/2){
            return 2*maxi-nums.size();
        }
        else return nums.size()%2;
    }
};