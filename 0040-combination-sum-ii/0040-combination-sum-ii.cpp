class Solution {
public:
    map<int,int> m;
    vector<pair<int,int>> freq;
    vector<vector<int>> ans;
    vector<int> v;
    void solve(int level,int target){
     
        if(target==0){
            ans.push_back(v);
            return;
        }
        if(target<0) return;
        if(level==freq.size()) return;
        if(freq[level].second==0){
            solve(level+1,target);
        }
        else{
        freq[level].second= freq[level].second-1;
        v.push_back(freq[level].first);
        solve(level,target-freq[level].first);
        freq[level].second= freq[level].second+1;
        v.pop_back();
        solve(level+1,target);}
        




    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        for(auto i:candidates){
            m[i]++;
        }
        for(auto i:m){
            freq.push_back({i.first,i.second});
        }
        solve(0,target);
        return ans;
        
    }
};