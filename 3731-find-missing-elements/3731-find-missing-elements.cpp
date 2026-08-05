class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        set<int> s;
        for(auto i:nums){
            s.insert(i);
        }
        vector<int> ans;
        int l=(*s.begin());
        int r=(*s.rbegin());
        for(int i=l;i<=r;i++){
            if(s.find(i)==s.end()){
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};