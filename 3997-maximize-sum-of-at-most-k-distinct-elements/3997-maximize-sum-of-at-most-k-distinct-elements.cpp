class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        set<int> s(nums.begin(),nums.end());
        vector<int> ans;
        while(s.size()>0 && k>0){
            int x=*s.rbegin();
            s.erase(x);
            ans.push_back(x);
            k--;
        }
        return ans;
        
    }
};