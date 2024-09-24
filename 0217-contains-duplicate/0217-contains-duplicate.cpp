class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,bool> m;
        bool ans=false;
        for(int i=0;i<nums.size();i++){
            if(m[nums[i]]==false){
                m[nums[i]]=true;
            }
            else{
                ans=true;
                break;
            }
        }
        if(ans){
            return true;
        }
        else{
            return false;
        }
        
    }
};