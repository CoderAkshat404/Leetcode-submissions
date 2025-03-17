class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto i:nums){
            m[i]++;
        }
        int ans=0;
        int neg=0;
        for(auto i:m){
            if(i.first>=0){
                ans+=i.first;
            }
            else{
                neg+=i.second;
            }
        }
        if(neg==nums.size()){
            sort(nums.begin(),nums.end());
            return nums.back();
        }
        return ans;
    }
};