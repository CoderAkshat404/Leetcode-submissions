class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> s;
        for(int i=0;i<(1<<nums.size());i++){
            vector<int> v;
            for(int j=0;j<nums.size();j++){
                if((i>>j)&1){
                    v.push_back(nums[j]);
                }
            }
            sort(v.begin(),v.end());
            s.insert(v);

        }
        vector<vector<int>> ans;
        for(auto i:s){
            ans.push_back(i);
        }
       return ans;
        
    }
};