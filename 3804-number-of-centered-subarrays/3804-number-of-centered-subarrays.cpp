class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int ans=0;
        for(int l=0;l<nums.size();l++){
            set<int> s;
            int sum=0;
            for(int r=l;r<nums.size();r++){
                sum+=nums[r];
                s.insert(nums[r]);
                if(s.find(sum)!=s.end()) ans++;

            }
        }
        return ans;
        
    }
};