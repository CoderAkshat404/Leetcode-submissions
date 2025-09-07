class Solution {
public:
    int minOperations(vector<int>& nums) {
        set<int> s;
        for(auto i:nums){
            s.insert(i);
        }
        if(s.size()==1){
            return 0;
        }
        return 1;
        
    }
};