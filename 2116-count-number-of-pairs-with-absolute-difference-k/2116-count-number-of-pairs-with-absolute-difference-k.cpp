class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int x=k+nums[i];
            int y=nums[i]-k;
            ans+=m[x]+m[y];
            m[nums[i]]++;
        }
        return ans;

        
    }
};