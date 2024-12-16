class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        vector<pair<int,int>> ans;
        for(int i=0;i<nums.size();i++){
            pair p={nums[i],i};
            ans.push_back(p);
        }
        sort(ans.begin(),ans.end());
        for(int i=0;i<k;i++){
            ans[0].first=ans[0].first*multiplier;
            sort(ans.begin(),ans.end());
        }
        for(int i=0;i<nums.size();i++){
            nums[ans[i].second]=ans[i].first;
        }
     return nums;   
    }
};