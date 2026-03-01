class Solution {
public:
    vector<vector<int>> ans;
    vector<int> v;
    map<int,int> m;
    vector<pair<int,int>> freq;
     void rec(int level,int n){
        if(n==level){
            ans.push_back(v);
            return;
        }
        rec(level+1,n);
        if(freq[level].second>0){
            v.push_back(freq[level].first);
            freq[level].second=freq[level].second-1;
            rec(level,n);
            freq[level].second=freq[level].second+1;
             v.pop_back();


        }
      
       
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        for(auto i:nums){
            m[i]++;
        }
        for(auto i:m){
            freq.push_back({i.first,i.second});

        }
        rec(0,freq.size());
        return ans;
        
    }
};