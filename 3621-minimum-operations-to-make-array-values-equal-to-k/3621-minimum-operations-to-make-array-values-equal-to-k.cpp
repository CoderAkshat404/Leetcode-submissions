class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> s;
        for(auto i:nums){
            s.insert(i);
        }
        int c=0;
        for(auto i:s){
            if(i!=k){
                c++;
            }
            if(i<k) return -1;
        }
        return c;
        
    }
};