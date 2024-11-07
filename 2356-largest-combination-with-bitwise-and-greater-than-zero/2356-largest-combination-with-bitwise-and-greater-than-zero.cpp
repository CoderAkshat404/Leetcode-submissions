class Solution {
public:
    int largestCombination(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int j=0;j<nums.size();j++){
            for(int i=0;i<32;i++){
                if((nums[j]>>i)&1){
                    m[i]++;
                }
            }
        }
        int maxi=INT_MIN;
        for(auto i:m){
            maxi=max(maxi,i.second);
        }
        return maxi;
        
    }
};