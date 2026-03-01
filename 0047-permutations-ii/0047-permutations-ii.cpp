class Solution {
public:
    vector<vector<int>> ans;
    vector<int> v;
    map<int,int> m;
    void rec(int level,int n){
        if(n==level){
            ans.push_back(v);
            return;
        }
        for(auto i:m){
            if(i.second>0){
            v.push_back(i.first);
            m[i.first]--;
            rec(level+1,n);
            m[i.first]++;
            v.pop_back();}
        }
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for(auto i:nums){
            m[i]++;
        }
        rec(0,nums.size());
        return ans;
        
        
    }
};