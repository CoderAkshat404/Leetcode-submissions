class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1){
                sum+=nums[i];
            }
            else{
                break;
            }
        }
        set<int> s;
        for(auto i:nums){
            s.insert(i);
        }
        for(int i=sum;i<=100100;i++){
            if(s.find(i)==s.end()){
                return i;
            }
        }
        return -1;
        
    }
};