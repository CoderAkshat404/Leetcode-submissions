class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
 
        bool flag=true;
        vector<vector<int>> ans;
        vector<int> v;
        int mini=1e9;
        for(int i=0;i<n;i++){
            mini=min(mini,nums[i]);
            if(nums[i]-mini<=k){
                v.push_back(nums[i]);
                if(v.size()==3){
                    mini=1e9;
                    ans.push_back(v);
                    v.clear();
                }
            }
            else{
                flag=false;
                break;
            }
        }
        if(flag){
            return ans;
        }
        return {};
        
    }
};