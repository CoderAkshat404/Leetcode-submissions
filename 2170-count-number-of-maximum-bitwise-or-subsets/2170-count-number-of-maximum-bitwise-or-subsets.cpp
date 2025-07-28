class Solution {
public:
    int maxi=-1e9;
    int cnt;
    vector<int> v;
    void solve(int i,vector<int>& nums){
        if(i==nums.size()){
            int o=0;
            for(int j=0;j<v.size();j++){
                o=(o | v[j]);
            }
            if(o>maxi){
                maxi=o;
                cnt=1;
            }
            else if(o==maxi){
                cnt++;
            }
            return;

        }
        v.push_back(nums[i]);
        solve(i+1,nums);
        v.pop_back();
        solve(i+1,nums);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        solve(0,nums);
        return cnt;

        
    }
};