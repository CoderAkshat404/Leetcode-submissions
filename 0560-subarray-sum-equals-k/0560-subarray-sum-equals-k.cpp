class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int presum=0;
        unordered_map<int,int> m;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            presum+=nums[i];
            int x=presum-k;
            if(x==0){
                ans++;
                ans+=m[x];
            }
            else{
                ans+=m[x];
            }
            m[presum]++;

        }
        return ans;
        
    }
};