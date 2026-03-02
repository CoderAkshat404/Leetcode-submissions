class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        map<int,int> m;
        for(auto i:nums){
            m[i]++;
        }
        sort(nums.begin(),nums.end());
        vector<int> ans={-1,-1};
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]<nums[j] && m[nums[i]]!=m[nums[j]]){
                    ans={nums[i],nums[j]};
                    return ans;
                }
            }
        }
        return ans;
        
    }
};