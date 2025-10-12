class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(auto i:nums){
            m[i]++;
        }
        int ans=0;
        for(auto i:m){
            if(i.second%k==0){
                ans+=(i.second)*(i.first);
            }
        }
        return ans;
        
    }
};