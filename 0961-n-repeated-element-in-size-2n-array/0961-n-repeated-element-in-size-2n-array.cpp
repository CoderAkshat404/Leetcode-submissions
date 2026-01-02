class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        set<int> s;
        for(auto i:nums){
            if(s.find(i)!=s.end()){
                return i;
            }
            s.insert(i);
        }
        return 0;

        
    }
};