class Solution {
public:
    map<int,long long> m;
    set<pair<long,long>> s;
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        vector<long long> ans;
        for(int i=0;i<nums.size();i++){
            int x=m[nums[i]];
            if(s.find({x,nums[i]})!=s.end()){
                s.erase({x,nums[i]});
            }
            m[nums[i]]+=freq[i];
            s.insert({m[nums[i]],nums[i]});
            ans.push_back((*s.rbegin()).first);
        }
        
        return ans;
    }
};