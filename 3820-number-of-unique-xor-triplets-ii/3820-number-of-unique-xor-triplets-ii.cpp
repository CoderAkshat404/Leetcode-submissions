class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                s.insert(nums[i]^nums[j]);
            }
        }
        unordered_set<int> ans;
        for(auto i:s){
            for(int j=0;j<nums.size();j++){
                ans.insert(i^nums[j]);
            }
        }
        return ans.size();

        
    }
};