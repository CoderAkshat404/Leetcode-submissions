class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            maxi=maxi| nums[i];
        }
        vector<vector<int>> ans;
        for(int i=0;i<(1<<nums.size());i++){
            vector<int> v;
            for(int j=0;j<nums.size();j++){
                if((i>>j)&1){
                    v.push_back(nums[j]);
                }
            }
            ans.push_back(v);

        }
        
        int r=0;
        for(int i=0;i<ans.size();i++){
            int o=0;
            for(int j=0;j<ans[i].size();j++){
                o=o | ans[i][j];
            }
            if(o==maxi){
                r++;
            }
        }
      return r;  
    }
};