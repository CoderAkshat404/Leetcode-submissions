class Solution {
public:
    bool check(vector<int>& nums,int j){
        unordered_map<int,int> m;
        for(int i=j;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(auto i:m){
            if(i.second>1){
                return true;
            }
        }
        return false;

    }
    int minimumOperations(vector<int>& nums) {
        int j=0;
        int count=0;
        while(check(nums,j)){
            count++;
            j=j+3;
        }
        return count;
        
        
    }
};