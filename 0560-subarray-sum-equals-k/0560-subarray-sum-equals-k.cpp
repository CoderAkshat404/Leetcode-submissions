class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int presum=0;
        unordered_map<int,int> m;
        m[0]++;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            presum+=nums[i];
            int x=presum-k;
           
            
            ans+=m[x];
            
            m[presum]++;

        }
        return ans;
        
    }
};