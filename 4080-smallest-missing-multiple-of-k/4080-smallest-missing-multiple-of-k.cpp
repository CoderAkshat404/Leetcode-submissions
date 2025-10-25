class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int x=1;
        for(int i=0;i<nums.size();i++){
            auto it = find(nums.begin(), nums.end(), x*k);
            if(it!=nums.end()){
                x++;
            }
            else{
                return x*k;
            }
        }
        return x*k;
        
    }
};