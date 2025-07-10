class Solution {
public:
    set<vector<int>> ans;
    vector<int> v;
    void rec(int i,vector<int>& candidates, int target){
        if(target==0){
            ans.insert(v);
            return ;
        }
        if(i>=candidates.size()){
            return  ;
        }
        if(target-candidates[i]>=0){
            v.push_back(candidates[i]);
            rec(i+1,candidates,target-candidates[i]);
            v.pop_back();
        }
        while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) {
            i++;
        }
        rec(i+1,candidates,target);

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        rec(0,candidates,target);
        vector<vector<int>> arr;
        for(auto i:ans){
            arr.push_back(i);
        }
        return arr;
    }
};