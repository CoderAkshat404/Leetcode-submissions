class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int,bool> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]=true;
        }
        vector<int> ans;
        for(int i=1;i<=nums.size();i++){
            if(m[i]==false){
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};