class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            unordered_map<int,int> m;
            for(int j=i;j<nums.size();j++){
                m[nums[j]]++;
                if(m[target]>((j-i+1)/2)){
                    ans++;
                }
            }
        }
        return ans;
    }
};