class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        set<int> s;
        for(auto i:nums){
            s.insert(i);
        }
        vector<int> temp;
        for(int i=lower;i<=upper;i++){
            if(s.find(i)==s.end()){
                temp.push_back(i);
            }
        }
        if(temp.empty()) return {};
        int prev=temp[0];
        int curr=temp[0];
        vector<vector<int>> ans;
        for(int i=1;i<temp.size();i++){
            if(temp[i]==curr+1){
                curr=temp[i];
            }
            else{
                ans.push_back({prev,curr});
                prev=temp[i];
                curr=temp[i];
            }
        }
        ans.push_back({prev,curr});
        return ans;

        
    }
};