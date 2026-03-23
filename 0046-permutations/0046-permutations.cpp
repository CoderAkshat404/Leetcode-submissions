class Solution {
public:
    vector<vector<int>> ans;
    vector<int> v;
    void solve(int i,int n, set<int>&s){
        if(i==n){
            ans.push_back(v);
            return;
        }
        for(auto ele : vector<int>(s.begin(), s.end())){
            v.push_back(ele);
            s.erase(ele);
            solve(i+1,n,s);
            v.pop_back();
            s.insert(ele);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        set<int> s(nums.begin(),nums.end());
        solve(0,nums.size(),s);
        return ans;
        
    }
};