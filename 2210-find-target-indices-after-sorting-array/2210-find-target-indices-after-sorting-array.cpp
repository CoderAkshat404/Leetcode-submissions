class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        int lo=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int hi=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        int count=hi-lo;
        cout<<count<<endl;
        int s=lo;
        while(count--){
            ans.push_back(lo);
            lo=lo+1;
        }
        return ans;

        
    }
};