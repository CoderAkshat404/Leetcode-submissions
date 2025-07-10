class Solution {
public:
    set<vector<int>> ans;
    vector<int> v;
    void rec(int i,vector<int>& candidates){
        if(i>=candidates.size()){
            ans.insert(v);
            return  ;
        }
       
            v.push_back(candidates[i]);
            rec(i+1,candidates);
            v.pop_back();
        
        while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) {
            i++;
        }
        rec(i+1,candidates);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        rec(0,nums);
        vector<vector<int>> arr;
        for(auto i:ans){
            arr.push_back(i);
        }
        return arr;

        
    }
};