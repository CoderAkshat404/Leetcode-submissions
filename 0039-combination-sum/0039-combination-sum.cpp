class Solution {
public:
    vector<vector<int>> ans;
    vector<int> v;
    void rec(int i,vector<int>& candidates, int target){
        if(target==0){
            ans.push_back(v);
            return ;
        }
        if(i>=candidates.size()){
            return  ;
        }
        if(target-candidates[i]>=0){
            v.push_back(candidates[i]);
            rec(i,candidates,target-candidates[i]);
            v.pop_back();
        }
        rec(i+1,candidates,target);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        rec(0,candidates,target);
        return ans;
        
    }
};