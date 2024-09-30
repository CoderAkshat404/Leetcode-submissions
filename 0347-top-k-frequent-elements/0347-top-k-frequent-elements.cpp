class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        vector<pair<int,int>> v;
        for(auto i:m){
            pair p={i.second,i.first};
            v.push_back(p);
        }
        sort(v.begin(),v.end());
        vector<int> ans;
        int j=v.size()-1;
        for(int i=0;i<k;i++){
            pair p=v[j];
            ans.push_back(p.second);
            j--;
        }
    return ans;
    }
};