class Solution {
public:
    int mod=1e9+7;
    int specialTriplets(vector<int>& nums) {
        #define int long long
        unordered_map<int,int> m;
        for(auto i:nums){
            m[i]++;
        }
        int ans=0;
        unordered_map<int,int> curr;
        for(int i=0;i<nums.size();i++){
            int b=curr[2*nums[i]];
            int a=m[2*nums[i]]-b;
            
            if(nums[i]==0){
                a--;
            }
            long long x=(a*b)%mod;
            ans=(ans+x)%mod;
            curr[nums[i]]++;

        }
        return ans;
        #undef int
        
    }
};